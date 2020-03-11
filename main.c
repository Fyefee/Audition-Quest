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

//Create variable for menu's background
SDL_Surface* menu_bg_surface = NULL;
SDL_Texture* menu_bg_texture = NULL;

//Create variable for main menu's button
SDL_Surface* menu_main_button_surface = NULL;
SDL_Texture* menu_main_button_texture = NULL;

//Create variable for menu's selector
SDL_Surface* menu_selector_surface = NULL;
SDL_Texture* menu_selector_texture = NULL;

SDL_Surface* ingame_bg_surface = NULL;
SDL_Texture* ingame_bg_texture = NULL; 

SDL_Surface* ingame_bg2_surface = NULL;
SDL_Texture* ingame_bg2_texture = NULL;

SDL_Surface* box_surface = NULL;
SDL_Texture* box_texture = NULL;

SDL_Surface* arrow_surface = NULL;
SDL_Texture* arrow_texture = NULL;

int running;
int width = 1200, height = 720; //Create width and height of program

const int FPS = 60;
int frameTime = 0; //Create frametime
int x = 0, y = 200;
int boxx = 800;
int left = 0;
int check = 25000;
int arrow_random = 0, arrow_stop = 0;
int arrow_running = 0;
int menu_bg_count = 0 , menu_main_on = 1, menu_bg = 1, menu_how = 0, menu_diffi = 0; //Create menu checker
int selector_main = 1, selector_diff = 1; //Create Selector in menu

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
			if (event.type == SDL_QUIT) { //If click close window turn off program
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym){
				case SDLK_UP:
					if (menu_main_on == 1) {
						if (selector_main == 2 || selector_main == 3) {
							selector_main--;
						}
					}

					else if (menu_diffi == 1) {
						if (selector_diff == 2 || selector_diff == 3 || selector_diff == 4) {
							selector_diff--;
						}
					}
					break;
				case SDLK_DOWN:
					if (menu_main_on == 1) {
						if (selector_main == 1 || selector_main == 2) {
							selector_main++;
						}
					}

					else if (menu_diffi == 1) {
						if (selector_diff == 1 || selector_diff == 2 || selector_diff == 3) {
							selector_diff++;
						}
					}
					break;
				case SDLK_LEFT:
					
					break;
				case SDLK_RIGHT:
					
					break;
				case SDLK_RETURN:

					if (menu_main_on == 1) {
						switch (selector_main)
						{
							case 1:
								menu_diffi = 1;
								menu_main_on = 0;
								break;
							case 2:
								menu_how = 1;
								menu_main_on = 0;
								break;
							case 3:
								running = 0;
								break;
							default:
								break;
						}
					}

					else if (menu_how == 1) {
						menu_how = 0;
						menu_main_on = 1;
					}

					else if (menu_diffi == 1) {
						switch (selector_diff)
						{
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							menu_diffi = 0;
							menu_main_on = 1;
							break;
						default:
							break;
						}
					}
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
		
		if (frameTime % 35000 == 0 && menu_bg == 1) {
			SDL_RenderClear(renderer);
			if (menu_bg_count > 7) {
				menu_bg_count = 0;
			}
			menu(menu_bg_count);
			if (menu_main_on == 1) {
				menu_main_button(selector_main);
			}
			
			if (menu_how == 1) {
				menu_howtoplay();
			}

			if (menu_diffi == 1) {
				menu_diff(selector_diff);
			}

			menu_bg_count++;
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
	
int menu(num) {

	SDL_Rect menu_bg_rect = { 0, 0, 1200, 720 };

	switch (num) {

		case 0:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_0.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		case 1:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_1.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		case 2:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_2.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		case 3:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_3.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		case 4:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_4.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		case 5:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_5.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		case 6:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_6.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		case 7:
			menu_bg_surface = IMG_Load("background/img/frame2/menu_frame_7.png");
			menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);
			SDL_RenderCopy(renderer, menu_bg_texture, NULL, &menu_bg_rect);
			break;

		default:
			break;
	}
	return 0;

	SDL_RenderCopy(renderer, arrow_texture, NULL, &arrow);
}

int menu_main_button(selector) {

	int y = 0;
	switch (selector)
	{
		case 1:
			y = 240;
			break;
		case 2:
			y = 360;
			break;
		case 3:
			y = 510;
			break;
		default:
			break;
	}

	SDL_Rect menu_main_button_rect = { 0, 0, 1200, 720 };
	SDL_Rect menu_selector_rect = { 270, y, 163, 128 };

	menu_selector_surface = IMG_Load("image/arrow_cool/arrow_cool_right.png");
	menu_selector_texture = SDL_CreateTextureFromSurface(renderer, menu_selector_surface);
	SDL_RenderCopy(renderer, menu_selector_texture, NULL, &menu_selector_rect);

	menu_main_button_surface = IMG_Load("image/menu_main_button.png");
	menu_main_button_texture = SDL_CreateTextureFromSurface(renderer, menu_main_button_surface);
	SDL_RenderCopy(renderer, menu_main_button_texture, NULL, &menu_main_button_rect);

}

int menu_howtoplay() {

	SDL_Rect menu_main_button_rect = { 0, 0, 1200, 720 };
	menu_main_button_surface = IMG_Load("image/menu_howtoplay.png");
	menu_main_button_texture = SDL_CreateTextureFromSurface(renderer, menu_main_button_surface);
	SDL_RenderCopy(renderer, menu_main_button_texture, NULL, &menu_main_button_rect);

}

int menu_diff(selector) {

	int y = 0;
	switch (selector)
	{
	case 1:
		y = 90;
		break;
	case 2:
		y = 240;
		break;
	case 3:
		y = 390;
		break;
	case 4:
		y = 570;
		break;
	default:
		break;
	}

	SDL_Rect menu_main_button_rect = { 0, 0, 1200, 720 };
	SDL_Rect menu_selector_rect = { 200, y, 163, 128 };

	menu_selector_surface = IMG_Load("image/arrow_cool/arrow_cool_right.png");
	menu_selector_texture = SDL_CreateTextureFromSurface(renderer, menu_selector_surface);
	SDL_RenderCopy(renderer, menu_selector_texture, NULL, &menu_selector_rect);

	menu_main_button_surface = IMG_Load("image/menu_diff.png");
	menu_main_button_texture = SDL_CreateTextureFromSurface(renderer, menu_main_button_surface);
	SDL_RenderCopy(renderer, menu_main_button_texture, NULL, &menu_main_button_rect);

}