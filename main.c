#include <SDL.h> // โหลด library SDL
#include <SDL_image.h> // โหลด library SDL_image
#include <stdio.h>  // โหลด library stdio
#include <string.h>  // โหลด library string.h
#include <stdlib.h>  // โหลด library stdlib.h
#include <ctype.h>  // โหลด library ctype
#include <stdbool.h>
#include <SDL_ttf.h>
#include <time.h> 
#include <conio.h>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;


SDL_Surface* ingame_bg_surface = NULL;
SDL_Texture* ingame_bg_texture = NULL; 

SDL_Surface* ingame_bg2_surface = NULL;
SDL_Texture* ingame_bg2_texture = NULL;

SDL_Surface* box_surface = NULL;
SDL_Texture* box_texture = NULL;

int running;
int width = 800, height = 600;

int arrow();
const int FPS = 60;
int frameTime = 0, num = 1, frameTime2 = 0;
int stop = 0, keyboard_bug_fix = 1;
int x = 0, y = 200;
int boxx = 800;
int left = 0;
int check = 25000;
int arrow_random = 0, arrow_check, arrow_stop = 0, arrow_old = 10;

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = 1;
	int lastTime = 0, currentTime;
	int delay_diff = 60000;
	int delay = delay_diff / 60 - SDL_GetTicks() + SDL_GetTicks();

	while (running) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym){
				case SDLK_UP:
					if (arrow_random == 0) {
						printf("Yes\n");
						arrow_stop = 0;
						SDL_RenderClear(renderer);
						SDL_RenderPresent(renderer);
						SDL_Delay(delay);
					}
					else {
						printf("No\n");
					}
					break;
				case SDLK_DOWN:
					if (arrow_random == 1) {
						printf("Yes\n");
						arrow_stop = 0;
						SDL_RenderClear(renderer);
						SDL_RenderPresent(renderer);
						SDL_Delay(delay);
					}
					else {
						printf("No\n");
					}
					break;
				case SDLK_LEFT:
					if (arrow_random == 2) {
						printf("Yes\n");
						arrow_stop = 0;
						SDL_RenderClear(renderer);
						SDL_RenderPresent(renderer);
						SDL_Delay(delay);
					}
					else {
						printf("No\n");
					}
					break;
				case SDLK_RIGHT:
					if (arrow_random == 3) {
						printf("Yes\n");
						arrow_stop = 0;
						SDL_RenderClear(renderer);
						SDL_RenderPresent(renderer);
						SDL_Delay(delay);
					}
					else {
						printf("No\n");
					}
					break;
				default:
					break;
				}
			}
			
		}
		int a = 1;
		/*int delay_diff = 60000;
		int delay = delay_diff / 60 - SDL_GetTicks() + SDL_GetTicks();
		SDL_Delay(delay);*/


		frameTime++;
		
		if (arrow_stop == 0) {
			SDL_RenderClear(renderer);
			srand(time(0));
			arrow_random = rand() % 4;
			arrow(arrow_random);
			SDL_RenderPresent(renderer);

			arrow_stop = 1;
		}

		
	}
	SDL_DestroyRenderer(renderer); // ทําลายตัว renderer
	SDL_DestroyWindow(window); // ทําลายหน้าต่างโปรแกรม
	SDL_Quit(); // ออกจากโปรแกรม
	return 0;

}

int arrow(num) {
	SDL_Rect arrow = { 0, 0, 300, 400 };
	switch (num) {
	case 0:
		ingame_bg_surface = IMG_Load("image/up.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &arrow);
		break;
	case 1:
		ingame_bg_surface = IMG_Load("image/down.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &arrow);
		break;

	case 2:
		ingame_bg_surface = IMG_Load("image/left.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &arrow);
		break;

	case 3:
		ingame_bg_surface = IMG_Load("image/right.png");
		ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);
		SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &arrow);
		break;

	default:
		break;
	}
	return 0;

}

int animate(num, x, y, boxx) {
	SDL_Rect menu2 = { x, y, 700, 300 };
	SDL_Rect menu1 = { 0, 0, 800, 600 };
	SDL_Rect box = { 0, 0, boxx, 100 };


	ingame_bg2_surface = IMG_Load("image/bg.jpg");
	ingame_bg2_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg2_surface);
	SDL_RenderCopy(renderer, ingame_bg2_texture, NULL, &menu1);

	//box_surface = IMG_Load("image/yellow.png");
	//box_texture = SDL_CreateTextureFromSurface(renderer, box_surface);
	//SDL_RenderCopy(renderer, box_texture, NULL, &box);

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