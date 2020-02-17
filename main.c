#include <SDL.h> // ��Ŵ library SDL
#include <SDL_image.h> // ��Ŵ library SDL_image
#include <stdio.h>  // ��Ŵ library stdio
#include <string.h>  // ��Ŵ library string.h
#include <stdlib.h>  // ��Ŵ library stdlib.h
#include <ctype.h>  // ��Ŵ library ctype

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

SDL_Surface* ingame_bg_surface = NULL;
SDL_Texture* ingame_bg_texture = NULL;

int running;
int width = 800, height = 600;

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = 1;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = 0;
			}
		}

		/* ��Ŵ�Ҿ�����ѧ��� */
		ingame_bg_surface = IMG_Load("image/tt.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);

		SDL_Rect menu = { 0, 0, 800, 600 };
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
	return 0;

}