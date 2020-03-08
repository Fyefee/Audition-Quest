#include <SDL.h> // โหลด library SDL
#include <SDL_image.h> // โหลด library SDL_image
#include <stdio.h>  // โหลด library stdio
#include <string.h>  // โหลด library string.h
#include <stdlib.h>  // โหลด library stdlib.h
#include <ctype.h>  // โหลด library ctype
#include <stdbool.h>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

SDL_Surface* ingame_bg_surface = NULL;
SDL_Texture* ingame_bg_texture = NULL; 


int running;
int width = 800, height = 600;

const int FPS = 60;
int frameTime = 0, num = 1;
int stop = 0, keyboard_bug_fix = 1;
int x = 0, y = 200;

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = 1;

	while (running) {

		SDL_Rect menu2 = { x, y, 400, 300 };
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym){
				case SDLK_UP:
					stop = 0;
					printf("0");
					break;
				case SDLK_DOWN:
					stop = 1;
					printf("1");
					frameTime == 99999;
					break;
				case SDLK_LEFT:
					x -= 50;
					break;
				case SDLK_RIGHT:
					x += 50;
					break;
				default:
					break;
				}
			}
			
		}
			
		frameTime++;
			
		if (frameTime == 100000 && stop == 0) {
			SDL_RenderClear(renderer);
			frameTime = 0;
			animate(num, x, y);
			if (num == 3) {
				num = 1;
			}
			num++;
			SDL_RenderPresent(renderer);
		}

		else if (frameTime == 100000 && stop == 1) {
			SDL_RenderClear(renderer);
			frameTime = 0;
			num++;
			kick(num);
			if (num == 7) {
				num = 1;
				stop = 0;
			}

			SDL_RenderPresent(renderer);
		}

		if (frameTime == 100000) {
			frameTime = 0;
		}
	}
	SDL_DestroyRenderer(renderer); // ทําลายตัว renderer
	SDL_DestroyWindow(window); // ทําลายหน้าต่างโปรแกรม
	SDL_Quit(); // ออกจากโปรแกรม
	return 0;

}

int animate(num, x, y) {
	SDL_Rect menu2 = { x, y, 400, 300 };

	switch (num){
	case 1:
		ingame_bg_surface = IMG_Load("image/kick/frame_00_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;
	case 2:
		ingame_bg_surface = IMG_Load("image/kick/frame_19_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;

	case 3:
		ingame_bg_surface = IMG_Load("image/kick/frame_20_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;

	default:
		break;
	}
	return 0;
}

int kick(num) {
	SDL_Rect menu2 = { 0, 200, 400, 300 };

	switch (num) {
	case 1:
		ingame_bg_surface = IMG_Load("image/kick/frame_8_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;
	case 2:
		ingame_bg_surface = IMG_Load("image/kick/frame_9_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;

	case 3:
		ingame_bg_surface = IMG_Load("image/kick/frame_10_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;
	case 4:
		ingame_bg_surface = IMG_Load("image/kick/frame_11_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;
	case 5:
		ingame_bg_surface = IMG_Load("image/kick/frame_12_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;
	case 6:
		ingame_bg_surface = IMG_Load("image/kick/frame_13_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		break;
	case 7:
		ingame_bg_surface = IMG_Load("image/kick/frame_14_delay-0.07s.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		SDL_Delay(100);
		break;

	default:
		break;
	}

	return 0;
}
/*else if (event.type == SDL_KEYDOWN) {

SDL_Rect menu2 = { 0, 200, 400, 300 };


if (event.key.keysym.sym == SDLK_DOWN) {
	while (1) {
		ingame_bg_surface = IMG_Load("image/frame_0.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);

		SDL_Delay(100);

		ingame_bg_surface = IMG_Load("image/frame_1.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);

		SDL_Delay(100);

		ingame_bg_surface = IMG_Load("image/frame_2.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);

		SDL_Delay(100);

		ingame_bg_surface = IMG_Load("image/frame_3.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);

		SDL_Delay(100);

		ingame_bg_surface = IMG_Load("image/frame_4.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &menu2);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);

		SDL_Delay(100);

		if (event.key.keysym.sym == SDLK_UP) {
			break;
		}

	}
}
*/