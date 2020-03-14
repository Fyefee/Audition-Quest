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
#include <math.h>

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

SDL_Surface* character_surface = NULL;
SDL_Texture* character_texture = NULL;

SDL_Surface* easy_1_mission_surface = NULL;
SDL_Texture* easy_1_mission_texture = NULL;

SDL_Surface* easy_background_surface = NULL;
SDL_Texture* easy_background_texture = NULL;

SDL_Surface* easy_background_idle_surface = NULL;
SDL_Texture* easy_background_idle_texture = NULL;

SDL_Surface* monster_easy_1_surface = NULL;
SDL_Texture* monster_easy_1_texture = NULL;

SDL_Surface* health_bar_surface = NULL;
SDL_Texture* health_bar_texture = NULL;

SDL_Surface* health_bar_bg_surface = NULL;
SDL_Texture* health_bar_bg_texture = NULL;

SDL_Surface* slime_surface = NULL;
SDL_Texture* slime_texture = NULL;

SDL_Surface* slime_attacked_surface = NULL;
SDL_Texture* slime_attacked_texture = NULL;

SDL_Surface* text_start_attack_surface = NULL;
SDL_Texture* text_start_attack_texture = NULL;

SDL_Surface* attack_surface = NULL;
SDL_Texture* attack_texture = NULL;

SDL_Surface* attack_2_surface = NULL;
SDL_Texture* attack_2_texture = NULL;

// Test
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
int mission_on = 0, easy_1_mission = 0, easy = 0, easy_1 = 0, easy_bg_count = 0, character_count = 0, monster_count = 0;
int monster_health = 0, turn_left = 0;
int health_bar = 0;
char health[100], turn[100];
int easy_1_idle = 0, attack_on = 0;

int score = 0, fail = 0;

int pos_x = 0, pos_x_cha = 0, pos_x_mon = 0, pos_attack = 250;
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
	SDL_Color white = { 255, 255, 255 };

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

	easy_1_mission_surface = IMG_Load("image/mission/easy_1.png");   //Render Button
	easy_1_mission_texture = SDL_CreateTextureFromSurface(renderer, easy_1_mission_surface);
	SDL_Rect mission_rect = { 0, 0, 1200, 720 };

	easy_background_surface = IMG_Load("background/cave4.png");   //Render Button
	easy_background_texture = SDL_CreateTextureFromSurface(renderer, easy_background_surface);

	character_surface = IMG_Load("image/human_1/human_idle.png");   //Render Button
	character_texture = SDL_CreateTextureFromSurface(renderer, character_surface);

	slime_surface = IMG_Load("image/slime/slime_idle_sprite.png");   //Render Button
	slime_texture = SDL_CreateTextureFromSurface(renderer, slime_surface);

	health_bar_surface = IMG_Load("image/yellow.png");   //Render Button
	health_bar_texture = SDL_CreateTextureFromSurface(renderer, health_bar_surface);

	health_bar_bg_surface = IMG_Load("image/black.png");   //Render Button
	health_bar_bg_texture = SDL_CreateTextureFromSurface(renderer, health_bar_bg_surface);

	SDL_Surface* message_surface_health = TTF_RenderText_Solid(sans, "xxxxxx", black);
	SDL_Texture* message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);
	SDL_Rect message_health_ingame_rect = { 750, 110, 240, 40 };

	SDL_Surface* message_surface_turn = TTF_RenderText_Solid(sans, "xxxxxx", black);
	SDL_Texture* message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
	SDL_Rect message_turn_ingame_rect = { 200, 110, 180, 40 };

	text_start_attack_surface = IMG_Load("image/text/attack_easy.png");   //Render Button
	text_start_attack_texture = SDL_CreateTextureFromSurface(renderer, text_start_attack_surface);
	SDL_Rect start_attack_rect = { 0, 0, 1200, 720 };

	attack_surface = IMG_Load("image/human_1/while_attack.png");   //Render Button
	attack_texture = SDL_CreateTextureFromSurface(renderer, attack_surface);

	attack_2_surface = IMG_Load("image/human_1/human_attack_sprite.png");   //Render Button
	attack_2_texture = SDL_CreateTextureFromSurface(renderer, attack_2_surface);

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
							menu_diffi = 0;
							menu_bg = 0;
							easy_1_mission = 1;
							easy = 1;
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

					else if (easy == 1) {
						if (easy_1_mission == 1) {
							easy_1_mission = 0;
							easy_1 = 1;
							monster_health = 30;
							sprintf(health, "Monster HP : %01d", monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turn Left : %01d", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);

							easy_1_idle = 1;
						}

						else if (easy_1_idle == 1) {
							easy_1_idle = 0;
							attack_on = 1;
							pos_attack = 250;
							character_count = 0;
						}
					}
					break;
				default:
					break;
				}
			}
			
		}
		/*delay_diff = 60000;
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

		if (frameTime % 50000 == 0 && easy == 1) {

			if (easy_bg_count == 17) {
				easy_bg_count = 0;
			}
			SDL_RenderClear(renderer);

			if (easy_1_mission == 1) {
				SDL_RenderCopy(renderer, easy_1_mission_texture, NULL, &mission_rect);
			}

			if (easy_1 == 1 && monster_health == 0) {
			}
			if (easy_1 == 1) {

				if (monster_count == 9) {
					monster_count = 0;
				}

				pos_x = easy_bg_count * 672;
				SDL_Rect easy_bg_rect = { 0, 0, 1200, 720 };
				SDL_Rect easy_bg_srcrect = { pos_x ,0, 672, 378 };
				SDL_RenderCopy(renderer, easy_background_texture, &easy_bg_srcrect, &easy_bg_rect);

				pos_x_mon = monster_count * 80;
				SDL_Rect slime_rect = { 830, 490, 140, 140 };
				SDL_Rect slime_srcrect = { pos_x_mon, 0, 80, 80 };
				SDL_RenderCopy(renderer, slime_texture, &slime_srcrect, &slime_rect);
				monster_count++;

				if (easy_1_idle == 1) {
					if (character_count == 11) {
						character_count = 0;
					}
					pos_x_cha = character_count * 91;
					SDL_Rect character_rect = { 250, 440, 158, 187 };
					SDL_Rect character_srcrect = { pos_x_cha, 0, 91, 113 };
					SDL_RenderCopy(renderer, character_texture, &character_srcrect, &character_rect);
					character_count++;

					health_bar = ((double)monster_health / 30) * 800;
					SDL_Rect health_bg_rect = { 200, 150, 800, 80 };
					SDL_Rect health_rect = { 200, 150, health_bar, 80 };
					SDL_RenderCopy(renderer, health_bar_bg_texture, NULL, &health_bg_rect);
					SDL_RenderCopy(renderer, health_bar_texture, NULL, &health_rect);


					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);

					SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
				}
			}
			if (attack_on == 1) {
				if (pos_attack >= 750) {
					if (character_count == 15) {
						character_count = 0;
						attack_on = 0;
						easy_1_idle = 1;
						
						monster_health -= 10;
						sprintf(health, "Monster HP : %01d", monster_health);
						message_surface_health = TTF_RenderText_Solid(sans, health, white);
						message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

						turn_left -= 1;
						sprintf(turn, "Turn Left : %01d", turn_left);
						message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
						message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
					}
					pos_x_cha = character_count * 154;
					SDL_Rect character_rect = { 720, 360, 248, 297 };
					SDL_Rect character_srcrect = { pos_x_cha, 0, 154, 181 };
					SDL_RenderCopy(renderer, attack_2_texture, &character_srcrect, &character_rect);

					character_count++;

				}
				if (pos_attack < 750) {
					SDL_Rect character_rect = { pos_attack, 440, 200, 180 };
					SDL_RenderCopy(renderer, attack_texture, NULL, &character_rect);

					pos_attack += 50;
				}

			}
			easy_bg_count++;
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
