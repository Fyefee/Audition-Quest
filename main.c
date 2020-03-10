#include <SDL.h> // โหลด library SDL
#include <SDL_image.h> // โหลด library SDL_image
#include <SDL_ttf.h>
#include <stdio.h>  // โหลด library stdio
#include <string.h>  // โหลด library string.h
#include <stdlib.h>  // โหลด library stdlib.h
#include <ctype.h>  // โหลด library ctype
#include <stdbool.h>
#include <time.h> 
#include <conio.h>
#include <string.h>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;


SDL_Surface* ingame_bg_surface = NULL;
SDL_Texture* ingame_bg_texture = NULL; 

SDL_Surface* ingame_bg2_surface = NULL;
SDL_Texture* ingame_bg2_texture = NULL;

SDL_Surface* box_surface = NULL;
SDL_Texture* box_texture = NULL;

SDL_Surface* arrow_surface = NULL;
SDL_Texture* arrow_texture = NULL;

int running;
int width = 1200, height = 720;

const int FPS = 60;
int frameTime = 0, frameTime2 = 0;
int x = 0, y = 200;
int boxx = 800;
int left = 0;
int check = 25000;
int arrow_random = 0, arrow_stop = 0;
int arrow_running = 0;

int score = 0, fail = 0;

int main(int argc, char* args[]) {
	TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = 1;
	int lastTime = 0, currentTime;
	int delay_diff = 60000;
	int delay = delay_diff / 60 - SDL_GetTicks() + SDL_GetTicks();

	SDL_Rect bg = { 0, 0, 1200, 720 };
	ingame_bg_surface = IMG_Load("background/img/frame2/frame_0_delay-0.1s.png");
	ingame_bg_texture = SDL_CreateTextureFromSurface(renderer, ingame_bg_surface);

	TTF_Font* sans = TTF_OpenFont("font/HACKED.ttf", 100);
	SDL_Color black = { 0, 0, 0 };

	SDL_Surface* message_surface_enter = TTF_RenderText_Solid(sans, "Press \"Enter\" to start", black);
	SDL_Texture* message_texture_enter = SDL_CreateTextureFromSurface(renderer, message_surface_enter);
	SDL_Rect message_rect = { 150, 300, 900, 120 };

	SDL_Surface* message_surface_score = TTF_RenderText_Solid(sans, "xxxxxx", black);
	SDL_Texture* message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
	SDL_Rect message_score_rect = { 250, 450, 200, 60 };
	SDL_Rect message_score_ingame_rect = { 0, 0, 200, 60 };

	char score_str[10000];

	while (running) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym){
				case SDLK_UP:
					if (arrow_running == 1) {
						if (arrow_random == 0) {
							printf("Yes\n");
							arrow_stop = 0;
							score += 1;
							SDL_RenderClear(renderer);
							SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &bg);
							bar(boxx);
							score_ingame(score, fail);
							SDL_RenderPresent(renderer);
							SDL_Delay(delay);
						}
						else {
							printf("No\n");
							fail += 1;
						}
					}
					break;
				case SDLK_DOWN:
					if (arrow_running == 1) {
						if (arrow_random == 1) {
							printf("Yes\n");
							arrow_stop = 0;
							score += 1;
							SDL_RenderClear(renderer);
							SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &bg);
							bar(boxx);
							score_ingame(score, fail);
							SDL_RenderPresent(renderer);
							SDL_Delay(delay);
						}
						else {
							printf("No\n");
							fail += 1;
						}
					}
					break;
				case SDLK_LEFT:
					if (arrow_running == 1) {
						if (arrow_random == 2) {
							printf("Yes\n");
							arrow_stop = 0;
							score += 1;
							SDL_RenderClear(renderer);
							SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &bg);
							bar(boxx);
							score_ingame(score, fail);
							SDL_RenderPresent(renderer);
							SDL_Delay(delay);
						}
						else {
							printf("No\n");
							fail += 1;
						}
					}
					break;
				case SDLK_RIGHT:
					if (arrow_running == 1) {
						if (arrow_random == 3) {
							printf("Yes\n");
							arrow_stop = 0;
							score += 1;
							SDL_RenderClear(renderer);
							SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &bg);
							bar(boxx);
							score_ingame(score, fail);
							SDL_RenderPresent(renderer);
							SDL_Delay(delay);
						}
						else {
							printf("No\n");
							fail += 1;
						}
					}
					break;
				case SDLK_RETURN:
					if (arrow_running == 0) {
						arrow_running = 1;
					}
					fail = 0;
					score = 0;
					break;
				default:
					break;
				}
			}
			
		}
		/*int delay_diff = 60000;
		int delay = delay_diff / 60 - SDL_GetTicks() + SDL_GetTicks();
		SDL_Delay(delay);*/


		frameTime++;
		
		if (arrow_stop == 0) {
			SDL_RenderClear(renderer);
			srand(time(0));
			arrow_random = rand() % 4;
			arrow_stop = 1;
		}
		if (boxx == 0) {
			//int delay2 = 1000000000 / 60 - SDL_GetTicks() + SDL_GetTicks();
			//SDL_Delay(delay2);
			boxx = 800;
			arrow_running = 0;
		}
		if (frameTime % 20000 == 0) {
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, ingame_bg_texture, NULL, &bg);
			if (arrow_running == 1) {
				boxx -= 10;
				bar(boxx);
				arrow(arrow_random);
				score_ingame(score, fail);

			}
			if (arrow_running == 0) {
				//SDL_RenderCopy(renderer, text_enter_texture, NULL, &text);
				SDL_RenderCopy(renderer, message_texture_enter, NULL, &message_rect);

				sprintf(score_str, "Score : %01d", score-fail);
				message_surface_score = TTF_RenderText_Solid(sans, score_str, black);
				message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
				SDL_RenderCopy(renderer, message_texture_score, NULL, &message_score_rect);
			}
			SDL_RenderPresent(renderer);
		}
		
	}
	SDL_DestroyRenderer(renderer); // ทําลายตัว renderer
	SDL_DestroyWindow(window); // ทําลายหน้าต่างโปรแกรม
	TTF_Quit();
	SDL_Quit(); // ออกจากโปรแกรม
	return 0;

}

int arrow(num) {
	SDL_Rect arrow = { 420, 80, 300, 400 };
	switch (num) {
	case 0:
		arrow_surface = IMG_Load("image/arrow_cool/arrow_cool_up.png");
		arrow_texture = SDL_CreateTextureFromSurface(renderer, arrow_surface);
		SDL_RenderCopy(renderer, arrow_texture, NULL, &arrow);
		break;
	case 1:
		arrow_surface = IMG_Load("image/arrow_cool/arrow_cool_down.png");
		arrow_texture = SDL_CreateTextureFromSurface(renderer, arrow_surface);
		SDL_RenderCopy(renderer, arrow_texture, NULL, &arrow);
		break;

	case 2:
		arrow_surface = IMG_Load("image/arrow_cool/arrow_cool_left.png");
		arrow_texture = SDL_CreateTextureFromSurface(renderer, arrow_surface);
		SDL_RenderCopy(renderer, arrow_texture, NULL, &arrow);
		break;

	case 3:
		arrow_surface = IMG_Load("image/arrow_cool/arrow_cool_right.png");
		arrow_texture = SDL_CreateTextureFromSurface(renderer, arrow_surface);
		SDL_RenderCopy(renderer, arrow_texture, NULL, &arrow);
		break;

	default:
		break;
	}
	return 0;

}

int bar(x) {
	SDL_Rect box = { 100, 500, x, 100 };
	box_surface = IMG_Load("image/yellow.png");
	box_texture = SDL_CreateTextureFromSurface(renderer, box_surface);
	SDL_SetTextureBlendMode(box_texture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(renderer, box_texture, NULL, &box);
	return 0;
}

int score_ingame(score, fail) {

	char score_str[100];
	char fail_str[100];
	TTF_Font* sans = TTF_OpenFont("font/HACKED.ttf", 100);
	SDL_Color black = { 0, 0, 0 };

	SDL_Surface* message_surface_score = TTF_RenderText_Solid(sans, "xxxxxx", black);
	SDL_Texture* message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
	SDL_Rect message_score_ingame_rect = { 50, 50, 200, 60 };

	sprintf(score_str, "Score : %01d", score);
	message_surface_score = TTF_RenderText_Solid(sans, score_str, black);
	message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
	SDL_RenderCopy(renderer, message_texture_score, NULL, &message_score_ingame_rect);

	sprintf(fail_str, "Fail : %01d", fail);
	SDL_Surface* message_surface_fail = TTF_RenderText_Solid(sans, fail_str, black);
	SDL_Texture* message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
	SDL_Rect message_fail_ingame_rect = { 50, 100, 150, 60 };
	SDL_RenderCopy(renderer, message_texture_fail, NULL, &message_fail_ingame_rect);
}