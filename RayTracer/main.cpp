#pragma once
#include "precomp.h"
#include "renderer.h"
#include "SDL.h"
#include <chrono>

//Source used to help me create the basic window
//https://dzone.com/articles/sdl2-pixel-drawing
//https://wiki.libsdl.org For setups as well as documentation regarding the SDL library
//Jacco Template from block A. Reading through template.h gave me a general understanding
//https://wiki.libsdl.org/SDL_CreateWindowAndRenderer

//Thanks to Wessel Frijters for helping me getting the project to build
//with x86 and x64 by copying the SDL.dll. This is something i had no idea existed and how it would work
//and couldn't find the solution with his help!

//SDL_bool enum warning was fixed with the help of Abdulla Donmez
//I wouldnt otherwise fix this issue myself by disabling the warning since i personally dont like tempering with the library


int main()
{
	//Init SDL
	SDL_SetMainReady();
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	bool exit = false;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Init own classes
	Renderer render;
	float horizon = 0.0f;
	float vertic = 0.0f;
	Vec3 cameraPos(0.0f, 0.0f, 0.0f);
	Vec3 movement(0.0f, 0.0f, 0.0f);
	Matrix RotX;
	RotX.Identity();
	Matrix RotY;
	RotY.Identity();

	//Deltatime
	//Thanks to Wessel Frijters for explaining how chrono works and its implementation
	std::chrono::high_resolution_clock clock;
	std::chrono::steady_clock::time_point lastTime = clock.now();
	float deltaTime = 0.0f;
	

	//Screen draw loop
	const Uint8* state = SDL_GetKeyboardState(NULL);
	while (!exit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT: exit = true;
			break;
		}

		//Rotation using arrow keys
		if (state[SDL_SCANCODE_RIGHT])
		{
			horizon += 0.00075f * deltaTime;
		}
		if (state[SDL_SCANCODE_LEFT])
		{
			horizon -= 0.00075f * deltaTime;
		}
		if (state[SDL_SCANCODE_UP])
		{
			vertic -= 0.00075f * deltaTime;
		}

		if (state[SDL_SCANCODE_DOWN])
		{
			vertic += 0.00075f * deltaTime;
		}

		RotY.RotateY(horizon);
		RotX.RotateX(vertic);

		//Movement using WASD
		if (state[SDL_SCANCODE_W])
		{
			movement = RotY * RotX * Vec3(0.0f, 0.0f, 0.004f);
			movement *= deltaTime;
			cameraPos += movement;
		}
		if (state[SDL_SCANCODE_S])
		{
			movement = RotY * RotX * Vec3(0.0f, 0.0f, -0.004f);
			movement *= deltaTime;
			cameraPos += movement;
		}
		if (state[SDL_SCANCODE_A])
		{
			movement = RotY * RotX * Vec3(-0.004f, 0.0f, 0.0f);
			movement *= deltaTime;
			cameraPos += movement;
		}
		if (state[SDL_SCANCODE_D])
		{
			movement = RotY * RotX * Vec3(0.004f, 0.0f, 0.0f);
			movement *= deltaTime;
			cameraPos += movement;
		}

		//Thanks to Phil de Groot for explaining why my movement wasn't working. With a code example below
		//Vec3 moveTemp = Vec3(-0.25f, 0.0f, 0.0f);
		//move += moveTemp * cameraOrientation;

		//Render the rays and scene
		render.Render(renderer, RotY, RotX, cameraPos);

		SDL_RenderPresent(renderer);

		//Deltatime with thanks to Wessel Frijters
		std::chrono::steady_clock::time_point currentTime = clock.now();
		deltaTime = static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count());
		lastTime = currentTime;
	}

	//Destruction
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}