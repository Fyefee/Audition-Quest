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
SDL_Surface* menu_howtoplay_surface = NULL;
SDL_Texture* menu_howtoplay_texture = NULL;

SDL_Surface* menu_info_surface = NULL;
SDL_Texture* menu_info_texture = NULL;

SDL_Surface* menu_difficulty_surface = NULL;
SDL_Texture* menu_difficulty_texture = NULL;

SDL_Surface* arrow_right_surface = NULL;
SDL_Texture* arrow_right_texture = NULL;

SDL_Surface* cha_surface = NULL;
SDL_Texture* cha_texture = NULL; 

SDL_Surface* ingame_bg2_surface = NULL;
SDL_Texture* ingame_bg2_texture = NULL;

SDL_Surface* box_surface = NULL;
SDL_Texture* box_texture = NULL;

SDL_Surface* arrow_surface = NULL;
SDL_Texture* arrow_texture = NULL;

int running;
int width = 1200, height = 720;    //Create width and height of program

const int FPS = 60;
long long frameTime = 0;    //Create frametime
int x = 0, y = 200;
int boxx = 800;
int left = 0;
int check = 25000;
int arrow_random = 0, arrow_stop = 0;
int arrow_running = 0;
int menu_bg_count = 0 , menu_main_on = 1, menu_bg = 1, menu_how = 0, menu_diffi = 0, menu_info_on = 0;    //Create menu checker
int selector_main = 1, selector_diff = 1;    //Create Selector in menu

int score = 0, fail = 0;

int pos_x = 0;
int pos_selector_y = 0;

int main(int argc, char* args[]) {
	TTF_Init();                              //SDL_ttf init
	SDL_Init(SDL_INIT_EVERYTHING);           //SDL init
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = 1;   //set running to true
	int lastTime = 0, currentTime;
	int delay_diff = 60000;
	int delay = delay_diff / 60 - SDL_GetTicks() + SDL_GetTicks();

	TTF_Font* sans = TTF_OpenFont("font/HACKED.ttf", 100);   //Load font Hacked
	SDL_Color black = { 0, 0, 0 };   //Set black color

	SDL_Surface* message_surface_enter = TTF_RenderText_Solid(sans, "Press \"Enter\" to start", black);
	SDL_Texture* message_texture_enter = SDL_CreateTextureFromSurface(renderer, message_surface_enter);
	SDL_Rect message_rect = { 150, 300, 900, 120 };

	menu_bg_surface = IMG_Load("background/img/frame2/allframe_2.png");
	menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);

	menu_main_button_surface = IMG_Load("image/menu_main_button.png");   //render button
	menu_main_button_texture = SDL_CreateTextureFromSurface(renderer, menu_main_button_surface);
	SDL_Rect menu_main_button_rect = { 0, 0, 1200, 720 };

	arrow_right_surface = IMG_Load("image/arrow_cool/arrow_cool_right.png");  //render selector
	arrow_right_texture = SDL_CreateTextureFromSurface(renderer, arrow_right_surface);

	menu_howtoplay_surface = IMG_Load("image/menu_howtoplay.png");  //Render How To Play
	menu_howtoplay_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_surface);

	menu_info_surface = IMG_Load("image/menu_info.png");   //Render Info
	menu_info_texture = SDL_CreateTextureFromSurface(renderer, menu_info_surface);

	menu_difficulty_surface = IMG_Load("image/menu_diff.png");   //Render Button
	menu_difficulty_texture = SDL_CreateTextureFromSurface(renderer, menu_difficulty_surface);

	while (running) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {   //If click close window turn off program
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN) {    //Check Keyboard Event
				switch (event.key.keysym.sym){
				case SDLK_UP:    //Check button arrow up
					if (menu_main_on == 1) {   //For move selector in main menu
						if (selector_main == 2 || selector_main == 3 || selector_main == 4) {
							selector_main--;
						}
					}

					else if (menu_diffi == 1) {   //For move selector in difficulty selector
						if (selector_diff == 2 || selector_diff == 3 || selector_diff == 4) {
							selector_diff--;
						}
					}
					break;
				case SDLK_DOWN:  //Check button arrow down
					if (menu_main_on == 1) {   //For move selector in main menu
						if (selector_main == 1 || selector_main == 2 || selector_main == 3) {
							selector_main++;
						}
					}

					else if (menu_diffi == 1) {  //For move selector in difficulty selector
						if (selector_diff == 1 || selector_diff == 2 || selector_diff == 3) {
							selector_diff++;
						}
					}
					break;
				case SDLK_LEFT:
					
					break;
				case SDLK_RIGHT:
					
					break;
				case SDLK_RETURN:   //Check button ENTER

					if (menu_main_on == 1) {    //Check where selector in main menu is
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
								menu_info_on = 1;
								menu_main_on = 0;
								break;
							case 4:
								running = 0;
								break;
							default:
								break;
						}
					} 

					else if (menu_how == 1) {   //For return to main menu in how to play screen
						menu_how = 0;
						menu_main_on = 1;
					}

					else if (menu_info_on == 1) {   //For return to main menu in info screen
						menu_info_on = 0;
						menu_main_on = 1;
					}

					else if (menu_diffi == 1) {    //Check where selector in diffulty select is
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
		
		if (frameTime % 35000 == 0 && menu_bg == 1) {  //render background and function in main menu

			SDL_RenderClear(renderer);  //clear renderer

			if (menu_bg_count > 7) {   //check for loop background
				menu_bg_count = 0;
			}

			pos_x = menu_bg_count * 560;
			SDL_Rect menu_bg_rect = { 0, 0, 1200, 720 };
			SDL_Rect menu_bg_srcrect = { pos_x ,0, 560, 272 };
			SDL_RenderCopy(renderer, menu_bg_texture, &menu_bg_srcrect, &menu_bg_rect);  //background render function

			if (menu_main_on == 1) {  //render button in mainmenu
				SDL_RenderCopy(renderer, menu_main_button_texture, NULL, &menu_main_button_rect);
				pos_selector_y = menu_main_button(selector_main);
				SDL_Rect menu_main_selector_rect = { 270, pos_selector_y, 163, 128 };
				SDL_RenderCopy(renderer, arrow_right_texture, NULL, &menu_main_selector_rect);
			}
			
			if (menu_how == 1) {   //render how to play menu
				SDL_RenderCopy(renderer, menu_howtoplay_texture, NULL, &menu_main_button_rect);
			}

			if (menu_diffi == 1) {  //render difficulty select menu
				SDL_RenderCopy(renderer, menu_difficulty_texture, NULL, &menu_main_button_rect);
				pos_selector_y = menu_diff(selector_diff);
				SDL_Rect menu_main_selector_rect = { 200, pos_selector_y, 163, 128 };
				SDL_RenderCopy(renderer, arrow_right_texture, NULL, &menu_main_selector_rect);
			}

			if (menu_info_on == 1) {  //render info menu
				SDL_RenderCopy(renderer, menu_info_texture, NULL, &menu_main_button_rect);
			}

			menu_bg_count++;  //move background
			SDL_RenderPresent(renderer);  //render

		}

		if (frameTime == 3500000) {
			frameTime = 0;
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
	
int menu_main_button(selector) {  //check where selector is

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
			y = 450;
			break;
		case 4:
			y = 560;
			break;
		default:
			break;
	}

	return y;

}

int menu_diff(selector) {

	int y = 0;
	switch (selector)  //Check where selector is
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

	return y;
}