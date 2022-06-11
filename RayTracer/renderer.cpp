#pragma once
#include "precomp.h"
#include "renderer.h"

//https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/alistofhittableobjects
//RayTracingInOneWeekend was used to give me a basic foundation as well as the correct values for the color of the background
//Thanks to Phil de Groot for helping me understand how the plane and plane intersection work.

//Jacco's slides were used as reference for my code layout and is based on his pseudo code
Vec3 Reflect(const Vec3& direction, const Vec3& normal);
Vec3 Refract(const Vec3& direction, const Vec3& normal, float n1, float n2, float dot);

float Clamp(float value, float min, float max);

//Constructor
Renderer::Renderer() :
	m_Camera(Camera()),
	m_Scene(Scene()),
	m_Ray(Ray()),
	m_ShadowRay(Ray()),
	m_Color(Color(0.0f, 0.0f, 0.0f)),
	m_LightPos(Vec3(0.0f, 5.0f, 0.0f)),
	m_LightColor(Color(10.0f, 10.0f, 10.0f)),
	m_MirrorBounce(0)
{}

//Main trace functions for each ray
Color Renderer::Trace(Vec3 origin, Vec3 direction, int glassBounce)
{
	RayResults container = m_Scene.RayIntersection(origin, direction);
	Color transparency;

	if (container.distance == INFINITY)
	{
		m_MirrorBounce = 0;
		return SkyColor(direction);
	}
	else if (glassBounce >= 5)
	{
		return SkyColor(direction);
	}

	if (container.specular == 1.0f && m_MirrorBounce < 5) //Mirror
	{
		m_MirrorBounce++;
		Vec3 newDirection = Reflect(direction, container.normal);
		return Trace((container.intersect + EPSILON * newDirection), newDirection, glassBounce);
	}
	else if (container.specular > 0.0f && m_MirrorBounce < 5) //Partially Mirror
	{
		m_MirrorBounce++;
		Vec3 newDirection = Reflect(direction, container.normal);
		return container.specular * Trace((container.intersect + EPSILON * newDirection), newDirection, glassBounce) * container.color +
			(1 - container.specular) * Illumination(container, direction);
	}
	else if (container.glass) //Glass
	{
		glassBounce++;
		
		float n1 = 1.0f;
		float n2 = 1.51f;
		float dotI = container.normal.dot((direction * -1.0f));

		//Thanks to Wessel Frijters for helping me debug a problem with swapping the values
		if (dotI < 0)
		{
			n1 = 1.51f;
			n2 = 1.0f;
			container.normal = (container.normal * -1.0f);
			dotI = container.normal.dot((direction * -1.0f));
		}

		float F = FresnelEquation(n1, n2, dotI);
		Vec3 reflect = Reflect(direction, container.normal);
		Vec3 refract = Refract(direction, container.normal, n1, n2, dotI);
		transparency = (F * Trace((container.intersect + EPSILON * reflect), reflect, glassBounce) +
			(1 - F) * Trace((container.intersect + EPSILON * refract), refract, glassBounce));

		//Beer's Law
		if (glassBounce >= 2) //Start at second ray since the first one is from origin -> sphere. Not inside
		{
			Color absorb;
			container.color = Color(1.0f, 1.0f, 1.0f) - container.color;
			absorb.x(expf((-container.color.x() * container.distance)));
			absorb.y(expf((-container.color.y() * container.distance)));
			absorb.z(expf((-container.color.z() * container.distance)));
			return transparency * absorb;
		}
		else
			return transparency;
	}
	else //Diffuse
	{
		m_MirrorBounce = 0;
		return Illumination(container, direction);
	}
}

//Reflect direction
Vec3 Reflect(const Vec3& direction, const Vec3& normal)
{
	return (direction - 2 * (direction.dot(normal)) * normal);
}

//Refract direction
Vec3 Refract(const Vec3& direction, const Vec3& normal, float n1, float n2, float dot)
{
	float division = n1 / n2;

	if (sinf(acosf(dot)) > n2 / n1)
	{ 
		return Vec3(0.0f, 0.0f, 0.0f);
	}

	float k = 1 - (division * division) * (1 - (dot * dot));

	if (k < 0)
	{
		return Vec3(0.0f, 0.0f, 0.0f);
	}

	return division * direction + normal * (division * dot - sqrtf(k));
}

//Fresnel's equation
float Renderer::FresnelEquation(float n1, float n2, float cosI)
{
	float cosT = sqrtf(1 - (powf(n1 / n2 * sinf(acosf(cosI)), 2)));

	float s_polarized = (n1 * cosI - n2 * cosT) / (n1 * cosI + n2 * cosT);
	float p_polarized = (n1 * cosT - n2 * cosI) / (n1 * cosT + n2 * cosI);

	float F = (s_polarized * s_polarized + p_polarized * p_polarized) * 0.5f;

	return F;
}

//Light brightness & color
Vec3 Renderer::Illumination(const RayResults& container, const Vec3& direction)
{
	Color light(0.0f, 0.0f, 0.0f);

	if (!Occluded(container.intersect))
	{
		float lightDistance = container.intersect.distance(m_LightPos);
		lightDistance = 1 / (lightDistance * lightDistance);

		float brightness = container.normal.dot((m_LightPos - container.intersect));

		if (brightness < 0)
			brightness = 0.0f;

		//Blinn-Phong model, thanks to:
		//Wessel Frijters &
		//https://paroj.github.io/gltut/Illumination/Tut11%20BlinnPhong%20Model.html
		Vec3 viewDirection = (direction * -1.0f);
		Vec3 lightDirection = (m_LightPos - container.intersect).normalize();
		Vec3 halfWay = (lightDirection + viewDirection).normalize();
		float blinn = container.normal.dot(halfWay);
		Clamp(blinn, 0.0f, 1.0f);
		blinn = powf(blinn, 50.0f);

		light = m_LightColor * lightDistance * brightness;
		return (container.color* light + blinn * light).clamp(0.0f, 1.0f);
	}
	else
		return light;
}

//Checks for shadows
bool Renderer::Occluded(const Vec3& intersect)
{
	m_ShadowRay.SetDirection((m_LightPos - intersect).normalize());
	m_ShadowRay.SetOrigin(intersect + EPSILON * m_ShadowRay.GetDirection());

	RayResults secContainer = m_Scene.RayIntersection(m_ShadowRay.GetOrigin(), m_ShadowRay.GetDirection());

	if(secContainer.distance > EPSILON && secContainer.distance < (m_ShadowRay.GetOrigin().distance(m_LightPos) - (2 * EPSILON)) && !secContainer.glass)
		return true;
	else
		return false;
}

//Sky color from Ray Tracer in a weekend
Color Renderer::SkyColor(const Vec3& direction)
{
	float T = 0.5f * (direction.y() + 1.0f);
	return (1.0f - T) * Color(1.0f, 1.0f, 1.0f) + T * Color(0.5f, 0.7f, 1.0f);
}

//Main screen loop for each pixel
void Renderer::Render(SDL_Renderer* renderer, Matrix& RotY, Matrix& RotX, Vec3& move)
{
	for (int y = 0; y < SCREENHEIGHT; y++)
	{
		for (int x = 0; x < SCREENWIDTH; x++)
		{
			m_Color = Color(0.0f, 0.0f, 0.0f);
			for (int aa = 0; aa < AA_RAY; aa++) //Thanks to Sam Boots for explaining AA in code
			{
				m_Ray = m_Camera.SetupRay(x, y, aa, RotY, RotX, move);
				m_Color += Trace(m_Ray.GetOrigin(), m_Ray.GetDirection(), 0); //Every new ray starts with 0 glass bounces
			}
			m_Color *= 0.5f;

			SDL_SetRenderDrawColor(renderer, static_cast<Uint8>(m_Color.x() * 255.999f),
				static_cast<Uint8>(m_Color.y() * 255.999f), static_cast<Uint8>(m_Color.z() * 255.999f), 0x00);

			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

//Clamp values
float Clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;

	return value;
}