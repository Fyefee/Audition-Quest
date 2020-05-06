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
SDL_Surface* menu_howtoplay_1_eng_surface = NULL;
SDL_Texture* menu_howtoplay_1_eng_texture = NULL;
SDL_Surface* menu_howtoplay_2_eng_surface = NULL;
SDL_Texture* menu_howtoplay_2_eng_texture = NULL;
SDL_Surface* menu_howtoplay_1_thai_surface = NULL;
SDL_Texture* menu_howtoplay_1_thai_texture = NULL;
SDL_Surface* menu_howtoplay_2_thai_surface = NULL;
SDL_Texture* menu_howtoplay_2_thai_texture = NULL;

//Create variable for menu's info scene
SDL_Surface* menu_info_surface = NULL;
SDL_Texture* menu_info_texture = NULL;

//Create variable for menu's difficulty scene
SDL_Surface* menu_difficulty_surface = NULL;
SDL_Texture* menu_difficulty_texture = NULL;

//Create variable for cool arrow right
SDL_Surface* arrow_cool_right_surface = NULL;
SDL_Texture* arrow_cool_right_texture = NULL;

//Create variable for arrow right
SDL_Surface* arrow_right_surface = NULL;
SDL_Texture* arrow_right_texture = NULL;

//Create variable for arrow left
SDL_Surface* arrow_left_surface = NULL;
SDL_Texture* arrow_left_texture = NULL;

//Create variable for arrow up
SDL_Surface* arrow_up_surface = NULL;
SDL_Texture* arrow_up_texture = NULL;

//Create variable for arrow down
SDL_Surface* arrow_down_surface = NULL;
SDL_Texture* arrow_down_texture = NULL;

//Create variable for character
SDL_Surface* character_surface = NULL;
SDL_Texture* character_texture = NULL;

//Create variable for easy mode mission 1 scene
SDL_Surface* easy_1_mission_surface = NULL;
SDL_Texture* easy_1_mission_texture = NULL;
SDL_Surface* easy_2_mission_surface = NULL;
SDL_Texture* easy_2_mission_texture = NULL;
SDL_Surface* easy_3_mission_surface = NULL;
SDL_Texture* easy_3_mission_texture = NULL;

SDL_Surface* medium_1_mission_surface = NULL;
SDL_Texture* medium_1_mission_texture = NULL;
SDL_Surface* medium_2_mission_surface = NULL;
SDL_Texture* medium_2_mission_texture = NULL;
SDL_Surface* medium_3_mission_surface = NULL;
SDL_Texture* medium_3_mission_texture = NULL;

SDL_Surface* hard_1_mission_surface = NULL;
SDL_Texture* hard_1_mission_texture = NULL;
SDL_Surface* hard_2_mission_surface = NULL;
SDL_Texture* hard_2_mission_texture = NULL;
SDL_Surface* hard_3_mission_surface = NULL;
SDL_Texture* hard_3_mission_texture = NULL;
SDL_Surface* hard_4_mission_surface = NULL;
SDL_Texture* hard_4_mission_texture = NULL;

//Create variable for easy mode 1 pass scene
SDL_Surface* easy_1_pass_surface = NULL;
SDL_Texture* easy_1_pass_texture = NULL;
SDL_Surface* easy_2_pass_surface = NULL;
SDL_Texture* easy_2_pass_texture = NULL;
SDL_Surface* easy_3_pass_surface = NULL;
SDL_Texture* easy_3_pass_texture = NULL;

SDL_Surface* medium_1_pass_surface = NULL;
SDL_Texture* medium_1_pass_texture = NULL;
SDL_Surface* medium_2_pass_surface = NULL;
SDL_Texture* medium_2_pass_texture = NULL;
SDL_Surface* medium_3_pass_surface = NULL;
SDL_Texture* medium_3_pass_texture = NULL;

SDL_Surface* hard_1_pass_surface = NULL;
SDL_Texture* hard_1_pass_texture = NULL;
SDL_Surface* hard_2_pass_surface = NULL;
SDL_Texture* hard_2_pass_texture = NULL;
SDL_Surface* hard_3_pass_surface = NULL;
SDL_Texture* hard_3_pass_texture = NULL;
SDL_Surface* hard_4_pass_surface = NULL;
SDL_Texture* hard_4_pass_texture = NULL;

//Create variable for fail scene
SDL_Surface* fail_surface = NULL;
SDL_Texture* fail_texture = NULL;

//Create variable for easy mode background
SDL_Surface* easy_background_surface = NULL;
SDL_Texture* easy_background_texture = NULL;
SDL_Surface* medium_background_surface = NULL;
SDL_Texture* medium_background_texture = NULL;
SDL_Surface* hard_background_surface = NULL;
SDL_Texture* hard_background_texture = NULL;

//Create variable for easy mode 1 background while idle
SDL_Surface* easy_background_idle_surface = NULL;
SDL_Texture* easy_background_idle_texture = NULL;

//Create variable for health bar
SDL_Surface* health_bar_surface = NULL;
SDL_Texture* health_bar_texture = NULL;

//Create variable for health bar background
SDL_Surface* health_bar_bg_surface = NULL;
SDL_Texture* health_bar_bg_texture = NULL;

//Create variable for slime
SDL_Surface* slime_surface = NULL;
SDL_Texture* slime_texture = NULL;
SDL_Surface* slime_attack_surface = NULL;
SDL_Texture* slime_attack_texture = NULL;

SDL_Surface* eye_surface = NULL;
SDL_Texture* eye_texture = NULL;
SDL_Surface* eye_attack_surface = NULL;
SDL_Texture* eye_attack_texture = NULL;
SDL_Surface* eye_moving_surface = NULL;
SDL_Texture* eye_moving_texture = NULL;

SDL_Surface* fire_tiger_surface = NULL;
SDL_Texture* fire_tiger_texture = NULL;
SDL_Surface* fire_tiger_attack_surface = NULL;
SDL_Texture* fire_tiger_attack_texture = NULL;

SDL_Surface* fire_knight_surface = NULL;
SDL_Texture* fire_knight_texture = NULL;
SDL_Surface* fire_knight_attack_surface = NULL;
SDL_Texture* fire_knight_attack_texture = NULL;

SDL_Surface* fire_golem_surface = NULL;
SDL_Texture* fire_golem_texture = NULL;
SDL_Surface* fire_golem_attack_surface = NULL;
SDL_Texture* fire_golem_attack_texture = NULL;

SDL_Surface* fire_dragon_surface = NULL;
SDL_Texture* fire_dragon_texture = NULL;
SDL_Surface* fire_dragon_attack_surface = NULL;
SDL_Texture* fire_dragon_attack_texture = NULL;

SDL_Surface* dark_hammer_surface = NULL;
SDL_Texture* dark_hammer_texture = NULL;
SDL_Surface* dark_hammer_attack_surface = NULL;
SDL_Texture* dark_hammer_attack_texture = NULL;

SDL_Surface* dark_mage_surface = NULL;
SDL_Texture* dark_mage_texture = NULL;
SDL_Surface* dark_mage_attack_surface = NULL;
SDL_Texture* dark_mage_attack_texture = NULL;

SDL_Surface* dark_lord_surface = NULL;
SDL_Texture* dark_lord_texture = NULL;
SDL_Surface* dark_lord_attack_surface = NULL;
SDL_Texture* dark_lord_attack_texture = NULL;

SDL_Surface* dark_knight_surface = NULL;
SDL_Texture* dark_knight_texture = NULL;
SDL_Surface* dark_knight_attack_surface = NULL;
SDL_Texture* dark_knight_attack_texture = NULL;

//Create variable for text "start attack"
SDL_Surface* text_start_attack_surface = NULL;
SDL_Texture* text_start_attack_texture = NULL;

//Create variable for character attack scene
SDL_Surface* attack_2_surface = NULL;
SDL_Texture* attack_2_texture = NULL;

//Call Variable
int running;
int width = 1200, height = 720;    //Create width and height of program
long long frameTime = 0, frameTime_2 = 0, keyboard_bug_fix = 0;    //Create frametime

int menu_bg_count = 0 , menu_main_on = 1, menu_bg = 1, menu_how_1 = 0, menu_how_2 = 0, menu_how_language = 1, menu_diffi = 0, menu_info_on = 0;    //Create menu checker
int selector_main = 1, selector_diff = 1;    //Create Selector in menu

int easy_1_mission = 0, easy_2_mission = 0, easy_3_mission = 0;
int easy = 0, easy_1 = 0, easy_2 = 0, easy_3 = 0;
int easy_1_pass = 0, easy_2_pass = 0, easy_3_pass = 0;
int easy_1_idle = 0, easy_2_idle = 0, easy_3_idle = 0;

int medium_1_mission = 0, medium_2_mission = 0, medium_3_mission = 0;
int medium = 0, medium_1 = 0, medium_2 = 0, medium_3 = 0;
int medium_1_pass = 0, medium_2_pass = 0, medium_3_pass = 0;
int medium_1_idle = 0, medium_2_idle = 0, medium_3_idle = 0;

int hard_1_mission = 0, hard_2_mission = 0, hard_3_mission = 0, hard_4_mission = 0;
int hard = 0, hard_1 = 0, hard_2 = 0, hard_3 = 0, hard_4 = 0;
int hard_1_pass = 0, hard_2_pass = 0, hard_3_pass = 0, hard_4_pass = 0;
int hard_1_idle = 0, hard_2_idle = 0, hard_3_idle = 0, hard_4_idle = 0;

int bg_count = 0, character_count = 0, monster_count = 0;

int health_bar = 0, time_bar = 800, monster_health = 0, max_monster_health = 0, turn_left = 0;
char health[100], turn[100], score_text[100], fail_text[100];
int attack_on = 0, cha_idle_on = 0;
int arrow_on = 0, arrow_random_on = 0, arrow_random = 5, arrow_stop = 0;
int score = 0, fail = 0;
int death_on = 0, start_attack_on = 1, fail_scene = 0;
int monster_position = 830, monster_idle = 1, monster_move = 0;

int pos_x = 0, pos_x_cha = 0, pos_x_mon = 0, pos_attack = 250, pos_x_cha_attack = 0, pos_selector_y = 0;
int healthbar_position_x = 0, healthbar_position_y = 0;
int menu_bg_srcrect_x = 560, easy_bg_srcrect_x = 672;

int main(int argc, char* args[]) {
	TTF_Init();                              //SDL_ttf init
	SDL_Init(SDL_INIT_EVERYTHING);           //SDL init
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Audition Quest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = 1;   //set running to true
	int lastTime = 0, currentTime;

	TTF_Font* sans = TTF_OpenFont("font/MesseDuesseldorf-O1d3.ttf", 100);   //Load font Hacked
	SDL_Color black = { 0, 0, 0 };   //Set black color
	SDL_Color white = { 255, 255, 255 };

	menu_bg_surface = IMG_Load("background/menu_bg.png");
	menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);

	menu_main_button_surface = IMG_Load("image/menu/main_menu.png");   //render button
	menu_main_button_texture = SDL_CreateTextureFromSurface(renderer, menu_main_button_surface);

	SDL_Rect arrow = { 470, 120, 250, 250 };
	arrow_cool_right_surface = IMG_Load("image/arrow/arrow_wood.png");  //render selector
	arrow_cool_right_texture = SDL_CreateTextureFromSurface(renderer, arrow_cool_right_surface);

	arrow_right_surface = IMG_Load("image/arrow/yellow/arrow_right.png");  //render selector
	arrow_right_texture = SDL_CreateTextureFromSurface(renderer, arrow_right_surface);

	arrow_left_surface = IMG_Load("image/arrow/yellow/arrow_left.png");  //render selector
	arrow_left_texture = SDL_CreateTextureFromSurface(renderer, arrow_left_surface);

	arrow_up_surface = IMG_Load("image/arrow/yellow/arrow_up.png");  //render selector
	arrow_up_texture = SDL_CreateTextureFromSurface(renderer, arrow_up_surface);

	arrow_down_surface = IMG_Load("image/arrow/yellow/arrow_down.png");  //render selector
	arrow_down_texture = SDL_CreateTextureFromSurface(renderer, arrow_down_surface);

	menu_howtoplay_1_eng_surface = IMG_Load("image/menu/menu_howtoplay_1_eng.png");  //Render How To Play
	menu_howtoplay_1_eng_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_1_eng_surface);

	menu_howtoplay_2_eng_surface = IMG_Load("image/menu/menu_howtoplay_2_eng.png");  //Render How To Play
	menu_howtoplay_2_eng_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_2_eng_surface);

	menu_howtoplay_1_thai_surface = IMG_Load("image/menu/menu_howtoplay_1_thai.png");  //Render How To Play
	menu_howtoplay_1_thai_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_1_thai_surface);

	menu_howtoplay_2_thai_surface = IMG_Load("image/menu/menu_howtoplay_2_thai.png");  //Render How To Play
	menu_howtoplay_2_thai_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_2_thai_surface);

	menu_info_surface = IMG_Load("image/menu/menu_howtoplay_1_eng.png");   //Render Info
	menu_info_texture = SDL_CreateTextureFromSurface(renderer, menu_info_surface);

	menu_difficulty_surface = IMG_Load("image/menu/menu_difficulty.png");   //Render Button
	menu_difficulty_texture = SDL_CreateTextureFromSurface(renderer, menu_difficulty_surface);

	easy_1_mission_surface = IMG_Load("image/mission/easy_1.png");   //Render Button
	easy_1_mission_texture = SDL_CreateTextureFromSurface(renderer, easy_1_mission_surface);
	easy_2_mission_surface = IMG_Load("image/mission/easy_2.png");   //Render Button
	easy_2_mission_texture = SDL_CreateTextureFromSurface(renderer, easy_2_mission_surface);
	easy_3_mission_surface = IMG_Load("image/mission/easy_3.png");   //Render Button
	easy_3_mission_texture = SDL_CreateTextureFromSurface(renderer, easy_3_mission_surface);

	medium_1_mission_surface = IMG_Load("image/mission/medium_1.png");   //Render Button
	medium_1_mission_texture = SDL_CreateTextureFromSurface(renderer, medium_1_mission_surface);
	medium_2_mission_surface = IMG_Load("image/mission/medium_2.png");   //Render Button
	medium_2_mission_texture = SDL_CreateTextureFromSurface(renderer, medium_2_mission_surface);
	medium_3_mission_surface = IMG_Load("image/mission/medium_3.png");   //Render Button
	medium_3_mission_texture = SDL_CreateTextureFromSurface(renderer, medium_3_mission_surface);

	hard_1_mission_surface = IMG_Load("image/mission/hard_1.png");   //Render Button
	hard_1_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_1_mission_surface);
	hard_2_mission_surface = IMG_Load("image/mission/hard_2.png");   //Render Button
	hard_2_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_2_mission_surface);
	hard_3_mission_surface = IMG_Load("image/mission/hard_3.png");   //Render Button
	hard_3_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_3_mission_surface);
	hard_4_mission_surface = IMG_Load("image/mission/hard_4.png");   //Render Button
	hard_4_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_4_mission_surface);

	easy_1_pass_surface = IMG_Load("image/mission/easy_1_pass.png");   //Render Button
	easy_1_pass_texture = SDL_CreateTextureFromSurface(renderer, easy_1_pass_surface);
	easy_2_pass_surface = IMG_Load("image/mission/easy_2_pass.png");   //Render Button
	easy_2_pass_texture = SDL_CreateTextureFromSurface(renderer, easy_2_pass_surface);
	easy_3_pass_surface = IMG_Load("image/mission/easy_3_pass.png");   //Render Button
	easy_3_pass_texture = SDL_CreateTextureFromSurface(renderer, easy_3_pass_surface);

	medium_1_pass_surface = IMG_Load("image/mission/medium_1_pass.png");   //Render Button
	medium_1_pass_texture = SDL_CreateTextureFromSurface(renderer, medium_1_pass_surface);
	medium_2_pass_surface = IMG_Load("image/mission/medium_2_pass.png");   //Render Button
	medium_2_pass_texture = SDL_CreateTextureFromSurface(renderer, medium_2_pass_surface);
	medium_3_pass_surface = IMG_Load("image/mission/medium_3_pass.png");   //Render Button
	medium_3_pass_texture = SDL_CreateTextureFromSurface(renderer, medium_3_pass_surface);

	hard_1_pass_surface = IMG_Load("image/mission/hard_1_pass.png");   //Render Button
	hard_1_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_1_pass_surface);
	hard_2_pass_surface = IMG_Load("image/mission/hard_2_pass.png");   //Render Button
	hard_2_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_2_pass_surface);
	hard_3_pass_surface = IMG_Load("image/mission/hard_3_pass.png");   //Render Button
	hard_3_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_3_pass_surface);
	hard_4_pass_surface = IMG_Load("image/mission/hard_4_pass.png");   //Render Button
	hard_4_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_4_pass_surface);

	fail_surface = IMG_Load("image/mission/fail.png");   //Render Button
	fail_texture = SDL_CreateTextureFromSurface(renderer, fail_surface);

	easy_background_surface = IMG_Load("background/easy_bg.png");   //Render Button
	easy_background_texture = SDL_CreateTextureFromSurface(renderer, easy_background_surface);

	medium_background_surface = IMG_Load("background/medium/medium_bg_4_sprite.png");   //Render Button
	medium_background_texture = SDL_CreateTextureFromSurface(renderer, medium_background_surface);

	hard_background_surface = IMG_Load("background/hard_bg.png");   //Render Button
	hard_background_texture = SDL_CreateTextureFromSurface(renderer, hard_background_surface);

	character_surface = IMG_Load("image/human_1/human_idle.png");   //Render Button
	character_texture = SDL_CreateTextureFromSurface(renderer, character_surface);

	slime_surface = IMG_Load("image/slime/slime_idle_sprite.png");   //Render Button
	slime_texture = SDL_CreateTextureFromSurface(renderer, slime_surface);
	slime_attack_surface = IMG_Load("image/slime/slime_attack_sprite.png");   //Render Button
	slime_attack_texture = SDL_CreateTextureFromSurface(renderer, slime_attack_surface);

	eye_surface = IMG_Load("image/monster_eye/eye_idle_sprite.png");   //Render Button
	eye_texture = SDL_CreateTextureFromSurface(renderer, eye_surface);
	eye_attack_surface = IMG_Load("image/monster_eye/eye_attack_sprite.png");   //Render Button
	eye_attack_texture = SDL_CreateTextureFromSurface(renderer, eye_attack_surface);
	eye_moving_surface = IMG_Load("image/monster_eye/eye_walk_sprite.png");   //Render Button
	eye_moving_texture = SDL_CreateTextureFromSurface(renderer, eye_moving_surface);

	fire_tiger_surface = IMG_Load("image/monster_fire_tiger/fire_tiger_idle_sprite.png");   //Render Button
	fire_tiger_texture = SDL_CreateTextureFromSurface(renderer, fire_tiger_surface);
	fire_tiger_attack_surface = IMG_Load("image/monster_fire_tiger/fire_tiger_attack_sprite.png");   //Render Button
	fire_tiger_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_tiger_attack_surface);

	fire_knight_surface = IMG_Load("image/monster_fire_knight/fire_knight_idle_sprite.png");   //Render Button
	fire_knight_texture = SDL_CreateTextureFromSurface(renderer, fire_knight_surface);
	fire_knight_attack_surface = IMG_Load("image/monster_fire_knight/fire_knight_attack_sprite.png");   //Render Button
	fire_knight_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_knight_attack_surface);

	fire_golem_surface = IMG_Load("image/monster_fire_golem/fire_golem_idle_sprite.png");   //Render Button
	fire_golem_texture = SDL_CreateTextureFromSurface(renderer, fire_golem_surface);
	fire_golem_attack_surface = IMG_Load("image/monster_fire_golem/fire_golem_attack_sprite.png");   //Render Button
	fire_golem_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_golem_attack_surface);

	fire_dragon_surface = IMG_Load("image/monster_fire_dragon/fire_dragon_idle_sprite.png");   //Render Button
	fire_dragon_texture = SDL_CreateTextureFromSurface(renderer, fire_dragon_surface);
	fire_dragon_attack_surface = IMG_Load("image/monster_fire_dragon/fire_dragon_attack_sprite.png");   //Render Button
	fire_dragon_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_dragon_attack_surface);

	dark_hammer_surface = IMG_Load("image/monster_dark_hammer/dark_hammer_idle_sprite.png");   //Render Button
	dark_hammer_texture = SDL_CreateTextureFromSurface(renderer, dark_hammer_surface);
	dark_hammer_attack_surface = IMG_Load("image/monster_dark_hammer/dark_hammer_attack_sprite.png");   //Render Button
	dark_hammer_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_hammer_attack_surface);

	dark_mage_surface = IMG_Load("image/monster_dark_mage/dark_mage_idle_sprite.png");   //Render Button
	dark_mage_texture = SDL_CreateTextureFromSurface(renderer, dark_mage_surface);
	dark_mage_attack_surface = IMG_Load("image/monster_dark_mage/dark_mage_attack_sprite.png");   //Render Button
	dark_mage_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_mage_attack_surface);

	dark_lord_surface = IMG_Load("image/monster_dark_lord/dark_lord_idle_sprite.png");   //Render Button
	dark_lord_texture = SDL_CreateTextureFromSurface(renderer, dark_lord_surface);
	dark_lord_attack_surface = IMG_Load("image/monster_dark_lord/dark_lord_attack_sprite.png");   //Render Button
	dark_lord_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_lord_attack_surface);

	dark_knight_surface = IMG_Load("image/monster_dark_knight/dark_knight_idle_sprite.png");   //Render Button
	dark_knight_texture = SDL_CreateTextureFromSurface(renderer, dark_knight_surface);
	dark_knight_attack_surface = IMG_Load("image/monster_dark_knight/dark_knight_attack_sprite.png");   //Render Button
	dark_knight_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_knight_attack_surface);

	health_bar_surface = IMG_Load("image/yellow.png");   //Render Button
	health_bar_texture = SDL_CreateTextureFromSurface(renderer, health_bar_surface);

	health_bar_bg_surface = IMG_Load("image/black.png");   //Render Button
	health_bar_bg_texture = SDL_CreateTextureFromSurface(renderer, health_bar_bg_surface);

	SDL_Surface* message_surface_health = TTF_RenderText_Solid(sans, "xxxxxx", black);   //Create Variable for health text
	SDL_Texture* message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);
	SDL_Rect message_health_ingame_rect = { 720, 110, 280, 40 };

	SDL_Surface* message_surface_turn = TTF_RenderText_Solid(sans, "xxxxxx", black);   //Create Variable for turn text
	SDL_Texture* message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
	SDL_Rect message_turn_ingame_rect = { 200, 110, 220, 40 };

	sprintf(score_text, "Score : %01d", score);   //turn int to string
	SDL_Surface* message_surface_score = TTF_RenderText_Solid(sans, score_text, white);   //Create Variable for score text
	SDL_Texture* message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
	SDL_Rect message_score_ingame_rect = { 850, 200, 210, 60 };

	sprintf(fail_text, "Fail : %01d/3", fail);   //turn int to string
	SDL_Surface* message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);   //Create Variable for fail text
	SDL_Texture* message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
	SDL_Rect message_fail_ingame_rect = { 850, 260, 180, 60 };

	text_start_attack_surface = IMG_Load("image/text/attack_easy.png");   //Render Button
	text_start_attack_texture = SDL_CreateTextureFromSurface(renderer, text_start_attack_surface);
	SDL_Rect start_attack_rect = { 0, 0, 1200, 720 };

	attack_2_surface = IMG_Load("image/human_1/human_attack_sprite.png");   //Render Button
	attack_2_texture = SDL_CreateTextureFromSurface(renderer, attack_2_surface);

	while (running) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {   //If click close window turn off program
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN && keyboard_bug_fix == 0) {    //Check Keyboard Event
				switch (event.key.keysym.sym){
				case SDLK_UP:    //Check button arrow up
					keyboard_bug_fix = 1;
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

					if (arrow_random_on == 0) {   //Check arrow while in audition mode
						if (arrow_random == 0) {
							arrow_random = 4;
							arrow_stop = 1;
							frameTime_2 = 0;
							score += 1;
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}
						else {
							fail += 1;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
						}
					}
					break;
				case SDLK_DOWN:  //Check button arrow down
					keyboard_bug_fix = 1;
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

					if (arrow_random_on == 0) {   //Check arrow while in audition mode
						if (arrow_random == 1) {
							arrow_stop = 1;
							frameTime_2 = 0;
							arrow_random_on = 1;
							score += 1;
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}
						else {
							fail += 1;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
						}
					}
					break;
				case SDLK_LEFT:
					keyboard_bug_fix = 1;
					if (arrow_random_on == 0 && (easy || medium || hard)) {   //Check arrow while in audition mode
						if (arrow_random == 2) {
							arrow_random = 4;
							arrow_stop = 1;
							frameTime_2 = 0;
							arrow_random_on = 1;
							score += 1;
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}
						else {
							fail += 1;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
						}
					}
					else if (menu_how_2) {
						menu_how_1 = 1;
						menu_how_2 = 0;
					}
					
					break;
				case SDLK_RIGHT:
					keyboard_bug_fix = 1;
					if (arrow_random_on == 0 && (easy || medium || hard)) {   //Check arrow while in audition mode
						if (arrow_random == 3) {
							arrow_random = 4;
							arrow_stop = 1;
							frameTime_2 = 0;
							arrow_random_on = 1;
							score += 1;
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}
						else {
							fail += 1;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
						}
					}
					else if (menu_how_1){
						menu_how_1 = 0;
						menu_how_2 = 1;
					}
					
					break;
				case SDLK_RETURN:   //Check button ENTER
					keyboard_bug_fix = 1;

					if (fail_scene == 1) {
						fail_scene = 0;
						menu_bg = 1;
						menu_main_on = 1;
						death_on = 0;
						easy = 0;
						medium = 0;
						hard = 0;
					}

					else if (menu_main_on == 1) {    //Check where selector in main menu is
						switch (selector_main)
						{
							case 1:
								menu_diffi = 1;
								menu_main_on = 0;
								selector_diff = 1;
								break;
							case 2:
								menu_how_1 = 1;
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

					else if (menu_how_1 == 1 || menu_how_2 == 1) {   //For return to main menu in how to play screen
						menu_how_1 = 0;
						menu_how_2 = 0;
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
							bg_count = 0;
							start_attack_on = 1;
							break;
						case 2:
							menu_diffi = 0;
							menu_bg = 0;
							medium_1_mission = 1;
							medium = 1;
							bg_count = 0;
							start_attack_on = 1;
							break;
						case 3:
							menu_diffi = 0;
							menu_bg = 0;
							hard_1_mission = 1;
							hard = 1;
							bg_count = 0;
							start_attack_on = 1;
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

						if (easy_1_mission == 1) {   //Check Enter while in easy mission 1 scene 
							easy_1_mission = 0;
							easy_1 = 1;
							easy_1_idle = 1;
							monster_idle = 1;
							cha_idle_on = 1;
							monster_position = 830;
							max_monster_health = 20;
							monster_health = 20;
							healthbar_position_x = 865; 
							healthbar_position_y = 490;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (easy_1_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							easy_1_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (easy_1_pass == 1) {
							easy_1_pass = 0;
							easy_2_mission = 1;
							death_on = 0;
						}

						else if (easy_2_mission == 1) {
							easy_2_mission = 0;
							easy_2 = 1;
							easy_2_idle = 1;
							cha_idle_on = 1;
							monster_position = 800;
							max_monster_health = 30;
							monster_health = 30;
							healthbar_position_x = 855;
							healthbar_position_y = 475;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (easy_2_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							easy_2_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (easy_2_pass == 1) {
							easy_2_pass = 0;
							easy_3_mission = 1;
							death_on = 0;
						}

						else if (easy_3_mission == 1) {
							easy_3_mission = 0;
							easy_3 = 1;
							easy_3_idle = 1;
							cha_idle_on = 1;
							monster_position = 600;
							max_monster_health = 40;
							monster_health = 40;
							healthbar_position_x = 830;
							healthbar_position_y = 415;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (easy_3_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							easy_3_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (easy_3_pass == 1) {
							easy_3_pass = 0;
							menu_bg = 1;
							menu_main_on = 1;
							easy = 0;
						}
					}

					else if (medium == 1) {

						if (medium_1_mission == 1) {   //Check Enter while in easy mission 1 scene 
							medium_1_mission = 0;
							medium_1 = 1;
							medium_1_idle = 1;
							monster_idle = 1;
							cha_idle_on = 1;
							monster_position = 620;
							max_monster_health = 30;
							monster_health = 30; //30
							healthbar_position_x = 805;
							healthbar_position_y = 420;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (medium_1_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							medium_1_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (medium_1_pass == 1) {
							medium_1_pass = 0;
							medium_2_mission = 1;
							death_on = 0;
						}

						else if (medium_2_mission == 1) {
							medium_2_mission = 0;
							medium_2 = 1;
							medium_2_idle = 1;
							cha_idle_on = 1;
							monster_position = 650;
							max_monster_health = 40; 
							monster_health = 40; //40
							healthbar_position_x = 855;
							healthbar_position_y = 420;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (medium_2_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							medium_2_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (medium_2_pass == 1) {
							medium_2_pass = 0;
							medium_3_mission = 1;
							death_on = 0;
						}

						else if (medium_3_mission == 1) {
							medium_3_mission = 0;
							medium_3 = 1;
							medium_3_idle = 1;
							cha_idle_on = 1;
							monster_position = 600;
							max_monster_health = 55;
							monster_health = 55;
							healthbar_position_x = 830;
							healthbar_position_y = 415;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (medium_3_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							medium_3_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (medium_3_pass == 1) {
							medium_3_pass = 0;
							menu_bg = 1;
							menu_main_on = 1;
							medium = 0;
						}
					}

					else if (hard == 1) {

						if (hard_1_mission == 1) {   //Check Enter while in easy mission 1 scene 
							hard_1_mission = 0;
							hard_1 = 1;
							hard_1_idle = 1;
							monster_idle = 1;
							cha_idle_on = 1;
							monster_position = 620;
							max_monster_health = 45;
							monster_health = 45;
							healthbar_position_x = 805;
							healthbar_position_y = 420;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (hard_1_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							hard_1_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (hard_1_pass == 1) {
							hard_1_pass = 0;
							hard_2_mission = 1;
							death_on = 0;
						}

						else if (hard_2_mission == 1) {
							hard_2_mission = 0;
							hard_2 = 1;
							hard_2_idle = 1;
							cha_idle_on = 1;
							monster_position = 650;
							max_monster_health = 55;
							monster_health = 55;
							healthbar_position_x = 855;
							healthbar_position_y = 420;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (hard_2_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							hard_2_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (hard_2_pass == 1) {
							hard_2_pass = 0;
							hard_3_mission = 1;
							death_on = 0;
						}

						else if (hard_3_mission == 1) {
							hard_3_mission = 0;
							hard_3 = 1;
							hard_3_idle = 1;
							cha_idle_on = 1;
							monster_position = 600;
							max_monster_health = 60;
							monster_health = 60;
							healthbar_position_x = 800;
							healthbar_position_y = 400;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (hard_3_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							hard_3_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (hard_3_pass == 1) {
							hard_3_pass = 0;
							hard_4_mission = 1;
							death_on = 0;
						}

						else if (hard_4_mission == 1) {
							hard_4_mission = 0;
							hard_4 = 1;
							hard_4_idle = 1;
							cha_idle_on = 1;
							monster_position = 550;
							max_monster_health = 70;
							monster_health = 70;
							healthbar_position_x = 850;
							healthbar_position_y = 410;
							sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
							message_surface_health = TTF_RenderText_Solid(sans, health, white);
							message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

							turn_left = 3;
							sprintf(turn, "Turns Left : %01d/3", turn_left);
							message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
							message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
						}

						else if (hard_4_idle == 1 && turn_left > 0) {   //Check to enter audition mode in easy mission 1
							hard_4_idle = 0;
							cha_idle_on = 0;
							arrow_random_on = 1;
							arrow_on = 1;
							time_bar = 1100;
							pos_attack = 250;
							character_count = 0;
							pos_x_cha_attack = 250;
							score = 0;
							fail = 0;
							sprintf(fail_text, "Fail : %01d/3", fail);
							message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
							message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
							sprintf(score_text, "Score : %01d", score);
							message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
							message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
						}

						else if (hard_4_pass == 1) {
							hard_4_pass = 0;
							menu_bg = 1;
							menu_main_on = 1;
							hard = 0;
						}
					}

					break;
				
				case SDLK_SPACE:
					if (menu_how_language == 1) {
						menu_how_language = 2;
					}
					else if (menu_how_language == 2) {
						menu_how_language = 1;
					}
					break;
				default:
					break;
				}
			}

			else if (event.type == SDL_KEYUP) {
				keyboard_bug_fix = 0;
			}
		}

		frameTime++;

		if (frameTime_2  == 5 && arrow_stop == 1 && easy == 1) {
			arrow_stop = 0;
			arrow_random_on = 1;
		}

		if (frameTime_2 == 4 && arrow_stop == 1 && medium == 1) {
			arrow_stop = 0;
			arrow_random_on = 1;
		}

		if (frameTime_2 == 3 && arrow_stop == 1 && hard == 1) {
			arrow_stop = 0;
			arrow_random_on = 1;
		}
		
		if (menu_bg == 1) {  //render background and function in main menu
			SDL_RenderClear(renderer);  //clear renderer
			if (menu_bg_count > 7) {   //check for loop background
				menu_bg_count = 0;
			}
			render_animation(menu_bg_texture, menu_bg_count, 560, 272, 0, 0, 1200, 720);

			if (menu_main_on == 1) {  //render button in mainmenu
				menu_button_render(menu_main_button_texture, selector_main, arrow_cool_right_texture);
			}
			if (menu_how_1 == 1 && menu_how_language == 1) {   //render how to play menu
				render_something(menu_howtoplay_1_eng_texture, 0, 0, 1200, 720);
			}
			if (menu_how_2 == 1 && menu_how_language == 1) {   //render how to play menu
				render_something(menu_howtoplay_2_eng_texture, 0, 0, 1200, 720);
			}
			if (menu_how_1 == 1 && menu_how_language == 2) {   //render how to play menu
				render_something(menu_howtoplay_1_thai_texture, 0, 0, 1200, 720);
			}
			if (menu_how_2 == 1 && menu_how_language == 2) {   //render how to play menu
				render_something(menu_howtoplay_2_thai_texture, 0, 0, 1200, 720);
			}
			if (menu_diffi == 1) {  //render difficulty select menu
				menu_difficulty_render(menu_difficulty_texture, selector_diff, arrow_cool_right_texture);
			}
			if (menu_info_on == 1) {  //render info menu
				render_something(menu_info_texture, 0, 0, 1200, 720);
			}
			menu_bg_count++;  //move background
			SDL_RenderPresent(renderer);  //render
			delay_function(5000);
		}

		if (easy == 1) {
			SDL_RenderClear(renderer);
			if (bg_count == 17) {  //Background easy loop
				bg_count = 0;
			}
			render_animation(easy_background_texture, bg_count, 672, 378, 0, 0, 1200, 720);

			if (cha_idle_on == 1 && monster_health > 0) {
				if (character_count == 11) {   //character loop
					character_count = 0;
				}
				render_animation(character_texture, character_count, 91, 113, 250, 440, 158, 187);
				character_count++;
			}

			if (easy_1 == 1) {

				if (monster_health <= 0) {   //if health reach enter pass scene
					easy_1_idle = 0;
					cha_idle_on = 0;
					easy_1 = 0;
					easy_1_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						easy_1_idle = 1;
					}
					start_attack_on = 0;
				}
				
				if (death_on == 1) {
					if (monster_position != 280) {
						monster_position -= 10;
					}
					if (monster_position == 280) {
						monster_idle = 0;
					}
					if (monster_idle == 0) {
						if (monster_count >= 18) {  //monster idle loop
							easy_1_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(easy_background_texture, bg_count, 672, 378, 0, 0, 1200, 720);
							easy_1 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(slime_attack_texture, monster_count, 80, 100, monster_position, 470, 140, 140);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 9) {  //monster idle loop
						monster_count = 0;
					}
					render_animation(slime_texture, monster_count, 80, 80, monster_position, 490, 140 ,140);
					monster_count++;
				}

				if (easy_1_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (easy_2 == 1) {
				if (monster_health <= 0) {   //if health reach enter pass scene
					easy_2 = 0;
					easy_2_idle = 0;
					cha_idle_on = 0;
					easy_2_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					monster_move = 1;
					monster_idle = 0;
					if (fail_scene == 0) {
						easy_2_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 280) {
						monster_position -= 10;
					}
					if (monster_position == 280) {
						monster_move = 0;
					}
					if (monster_move == 0) {
						if (monster_count == 17) {  //monster idle loop
							easy_2_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(easy_background_texture, bg_count, 672, 378, 0, 0, 1200, 720);
							easy_2 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(eye_attack_texture, monster_count, 176, 176, monster_position, 440, 200, 200);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 7) {   //character loop
						monster_count = 0;
					}
					render_animation(eye_texture, monster_count, 176, 176, monster_position, 440, 200, 200);
					monster_count++;
				}

				if (monster_move == 1) {
					if (monster_count >= 3) {   //character loop
						monster_count = 0;
					}
					render_animation(eye_moving_texture, monster_count, 176, 176, monster_position, 440, 200, 200);
					monster_count++;
				}

				if (easy_2_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (easy_3 == 1) {
				if (monster_health <= 0) {   //if health reach enter pass scene
					easy_3 = 0;
					easy_3_idle = 0;
					cha_idle_on = 0;
					easy_3_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					monster_move = 1;
					monster_idle = 0;
					if (fail_scene == 0) {
						easy_3_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 280) {
						monster_position -= 10;
					}
					if (monster_position == 280) {
						monster_move = 0;
					}
					if (monster_move == 0) {
						if (monster_count == 10) {  //monster idle loop
							easy_3_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(easy_background_texture, bg_count, 672, 378, 0, 0, 1200, 720);
							easy_3 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(fire_tiger_attack_texture, monster_count, 560, 560, monster_position, 160, 560, 560);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 11) {   //character loop
						monster_count = 0;
					}
					render_animation(fire_tiger_texture, monster_count, 560, 560, monster_position, 160, 560, 560);
					monster_count++;
				}

				if (monster_move == 1) {
					if (monster_count >= 11) {   //character loop
						monster_count = 0;
					}
					render_animation(fire_tiger_texture, monster_count, 560, 560, monster_position, 160, 560, 560);
					monster_count++;
				}

				if (easy_3_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (arrow_on == 1) {    //Check arrow mode

				if (fail == 3) {  //check if fail = 3 enter attack scene
					arrow_on = 0;
					character_count = 0;
					attack_on = 1;
				}

				if (time_bar <= 0) {    //check if run out of time enter attack scene
					arrow_on = 0;
					attack_on = 1;
					character_count = 0;
					arrow_random = 5;
				}

				if (arrow_random_on == 1) {   //random arrow
					srand(time(0));
					arrow_random = rand() % 4;
					arrow_random_on = 0;
				}

				if (arrow_random_on == 0) {

					if (arrow_stop == 0) {
						time_bar -= 10;    // Render time bar
					}
					render_something(health_bar_bg_texture, 50, 50, 1100, 50);
					render_something(health_bar_texture, 50, 50, time_bar, 50);

					if (arrow_stop == 0) {
						switch (arrow_random)   //Render arrow
						{
						case 0: SDL_RenderCopy(renderer, arrow_up_texture, NULL, &arrow); break;
						case 1: SDL_RenderCopy(renderer, arrow_down_texture, NULL, &arrow); break;
						case 2: SDL_RenderCopy(renderer, arrow_left_texture, NULL, &arrow); break;
						case 3: SDL_RenderCopy(renderer, arrow_right_texture, NULL, &arrow); break;
						default:
							break;
						}
					}
					SDL_RenderCopy(renderer, message_texture_score, NULL, &message_score_ingame_rect);   //Render text in audition mode
					SDL_RenderCopy(renderer, message_texture_fail, NULL, &message_fail_ingame_rect);
				}

				if (character_count == 11) {   //character loop
					character_count = 0;
				}
				pos_x_cha_attack = find_position(250, 500, time_bar);
				render_animation(character_texture, character_count, 91, 113, pos_x_cha_attack, 440, 158, 187);
				character_count++;

				health_bar = health_bar_width(monster_health, max_monster_health, 80); //render monster health in audition mode
				render_something(health_bar_bg_texture, healthbar_position_x, healthbar_position_y, 80, 15);
				render_something(health_bar_texture, healthbar_position_x, healthbar_position_y, health_bar, 15);
			}

			if (easy_1_mission == 1) {  // Render easy mission 1
				render_something(easy_1_mission_texture, 0, 0, 1200, 720);
			}

			if (easy_2_mission == 1) {  // Render easy mission 1
				render_something(easy_2_mission_texture, 0, 0, 1200, 720);
			}

			if (easy_3_mission == 1) {  // Render easy mission 1
				render_something(easy_3_mission_texture, 0, 0, 1200, 720);
			}

			if (easy_1_pass == 1) {   // Render easy 1 pass
				render_something(easy_1_pass_texture, 0, 0, 1200, 720);
			}

			if (easy_2_pass == 1) {   // Render easy 1 pass
				render_something(easy_2_pass_texture, 0, 0, 1200, 720);
			}

			if (easy_3_pass == 1) {   // Render easy 1 pass
				render_something(easy_3_pass_texture, 0, 0, 1200, 720);
			}

			if (fail_scene == 1) {   //Render Fail Scene
				render_something(fail_texture, 0, 0, 1200, 720);
			}

			if (attack_on == 1) {   //Render attack scene
				death_on = 0;
				if (character_count == 15) {
					character_count = 0;
					attack_on = 0;
					if (easy_1 == 1) {
						easy_1_idle = 1;
					}
					else if (easy_2 == 1) {
						easy_2_idle = 1;
					}
					else if (easy_3 == 1) {
						easy_3_idle = 1;
					}
					cha_idle_on = 1;
						
					monster_health -= score;
					sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
					message_surface_health = TTF_RenderText_Solid(sans, health, white);
					message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

					turn_left -= 1;
					sprintf(turn, "Turns Left : %01d/3", turn_left);
					message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
					message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
				}
				render_animation(attack_2_texture, character_count, 154, 181, 720, 360, 248, 297);
				character_count++;
			}
			bg_count++;
			frameTime_2++;
			SDL_RenderPresent(renderer);
			delay_function(6000);
		}

		if (medium == 1) {
			SDL_RenderClear(renderer);
			if (bg_count == 7) {  //Background easy loop
				bg_count = 0;
			}
			render_animation(medium_background_texture, bg_count, 504, 336, 0, 0, 1200, 720);

			if (cha_idle_on == 1 && monster_health > 0) {
				if (character_count == 11) {   //character loop
					character_count = 0;
				}
				render_animation(character_texture, character_count, 91, 113, 250, 490, 158, 187);
				character_count++;
			}

			if (medium_1 == 1) {

				if (monster_health <= 0) {   //if health reach enter pass scene
					medium_1_idle = 0;
					cha_idle_on = 0;
					medium_1 = 0;
					medium_1_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						medium_1_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {
						if (monster_count >= 23) {  //monster idle loop
							medium_1_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(medium_background_texture, bg_count, 504, 336, 0, 0, 1200, 720);
							medium_1 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(fire_knight_attack_texture, monster_count, 240, 240, monster_position, 220, 500, 500);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {  //monster idle loop
						monster_count = 0;
					}
					render_animation(fire_knight_texture, monster_count, 240, 240, monster_position, 220, 500, 500);
					monster_count++;
				}

				if (medium_1_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (medium_2 == 1) {
				if (monster_health <= 0) {   //if health reach enter pass scene
					medium_2 = 0;
					medium_2_idle = 0;
					cha_idle_on = 0;
					medium_2_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						medium_2_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {
						if (monster_count >= 22) {  //monster idle loop
							medium_2_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(medium_background_texture, bg_count, 504, 336, 0, 0, 1200, 720);
							medium_2 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(fire_golem_attack_texture, monster_count, 600, 600, monster_position, 260, 480, 480);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 12) {   //character loop
						monster_count = 0;
					}
					render_animation(fire_golem_texture, monster_count, 600, 600, monster_position, 260, 480, 480);
					monster_count++;
				}


				if (medium_2_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (medium_3 == 1) {
				if (monster_health <= 0) {   //if health reach enter pass scene
					medium_3 = 0;
					medium_3_idle = 0;
					cha_idle_on = 0;
					medium_3_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						medium_3_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 220) {
						monster_position -= 10;
					}
					if (monster_position == 220 && monster_idle == 1) {
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {
						if (monster_count == 20) {  //monster idle loop
							medium_3_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(medium_background_texture, bg_count, 504, 336, 0, 0, 1200, 720);
							medium_3 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(fire_dragon_attack_texture, monster_count, 720, 720, monster_position, 160, 560, 560);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {   //character loop
						monster_count = 0;
					}
					render_animation(fire_dragon_texture, monster_count, 720, 720, monster_position, 160, 560, 560);
					monster_count++;
				}

				if (medium_3_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (arrow_on == 1) {    //Check arrow mode

				if (fail == 3) {  //check if fail = 3 enter attack scene
					arrow_on = 0;
					character_count = 0;
					attack_on = 1;
				}

				if (time_bar <= 0) {    //check if run out of time enter attack scene
					arrow_on = 0;
					attack_on = 1;
					character_count = 0;
					arrow_random = 5;
				}

				if (arrow_random_on == 1) {   //random arrow
					srand(time(0));
					arrow_random = rand() % 4;
					arrow_random_on = 0;
				}

				if (arrow_random_on == 0) {

					if (arrow_stop == 0) {
						time_bar -= 11;    // Render time bar
					}
					render_something(health_bar_bg_texture, 50, 50, 1100, 50);
					render_something(health_bar_texture, 50, 50, time_bar, 50);

					if (arrow_stop == 0) {
						switch (arrow_random)   //Render arrow
						{
						case 0: SDL_RenderCopy(renderer, arrow_up_texture, NULL, &arrow); break;
						case 1: SDL_RenderCopy(renderer, arrow_down_texture, NULL, &arrow); break;
						case 2: SDL_RenderCopy(renderer, arrow_left_texture, NULL, &arrow); break;
						case 3: SDL_RenderCopy(renderer, arrow_right_texture, NULL, &arrow); break;
						default:
							break;
						}
					}
					SDL_RenderCopy(renderer, message_texture_score, NULL, &message_score_ingame_rect);   //Render text in audition mode
					SDL_RenderCopy(renderer, message_texture_fail, NULL, &message_fail_ingame_rect);
				}

				if (character_count == 11) {   //character loop
					character_count = 0;
				}
				pos_x_cha_attack = find_position(250, 500, time_bar);
				render_animation(character_texture, character_count, 91, 113, pos_x_cha_attack, 490, 158, 187);
				character_count++;

				health_bar = health_bar_width(monster_health, max_monster_health, 80); //render monster health in audition mode
				render_something(health_bar_bg_texture, healthbar_position_x, healthbar_position_y, 80, 15);
				render_something(health_bar_texture, healthbar_position_x, healthbar_position_y, health_bar, 15);
			}

			if (medium_1_mission == 1) {  // Render easy mission 1
				render_something(medium_1_mission_texture, 0, 0, 1200, 720);
			}

			if (medium_2_mission == 1) {  // Render easy mission 1
				render_something(medium_2_mission_texture, 0, 0, 1200, 720);
			}

			if (medium_3_mission == 1) {  // Render easy mission 1
				render_something(medium_3_mission_texture, 0, 0, 1200, 720);
			}

			if (medium_1_pass == 1) {   // Render easy 1 pass
				render_something(medium_1_pass_texture, 0, 0, 1200, 720);
			}

			if (medium_2_pass == 1) {   // Render easy 1 pass
				render_something(medium_2_pass_texture, 0, 0, 1200, 720);
			}

			if (medium_3_pass == 1) {   // Render easy 1 pass
				render_something(medium_3_pass_texture, 0, 0, 1200, 720);
			}

			if (fail_scene == 1) {   //Render Fail Scene
				render_something(fail_texture, 0, 0, 1200, 720);
			}

			if (attack_on == 1) {   //Render attack scene
				death_on = 0;
				if (character_count == 15) {
					character_count = 0;
					attack_on = 0;
					if (medium_1 == 1) {
						medium_1_idle = 1;
					}
					else if (medium_2 == 1) {
						medium_2_idle = 1;
					}
					else if (medium_3 == 1) {
						medium_3_idle = 1;
					}
					cha_idle_on = 1;

					monster_health -= score;
					sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
					message_surface_health = TTF_RenderText_Solid(sans, health, white);
					message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

					turn_left -= 1;
					sprintf(turn, "Turns Left : %01d/3", turn_left);
					message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
					message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
				}
				render_animation(attack_2_texture, character_count, 154, 181, 680, 400, 248, 297);
				character_count++;
			}
			bg_count++;
			frameTime_2++;
			SDL_RenderPresent(renderer);
			delay_function(6000);
		}

		if (hard == 1) {
			SDL_RenderClear(renderer);
			if (bg_count == 16) {  //Background easy loop
				bg_count = 0;
			}
			render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);

			if (cha_idle_on == 1 && monster_health > 0) {
				if (character_count == 11) {   //character loop
					character_count = 0;
				}
				render_animation(character_texture, character_count, 91, 113, 250, 490, 158, 187);
				character_count++;
			}

			if (hard_1 == 1) {

				if (monster_health <= 0) {   //if health reach enter pass scene
					hard_1_idle = 0;
					cha_idle_on = 0;
					hard_1 = 0;
					hard_1_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						hard_1_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {
						if (monster_count >= 21) {  //monster idle loop
							hard_1_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);
							hard_1 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(dark_hammer_attack_texture, monster_count, 220, 220, monster_position, 220, 500, 500);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {  //monster idle loop
						monster_count = 0;
					}
					render_animation(dark_hammer_texture, monster_count, 220, 220, monster_position, 220, 500, 500);
					monster_count++;
				}

				if (hard_1_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (hard_2 == 1) {
				if (monster_health <= 0) {   //if health reach enter pass scene
					hard_2 = 0;
					hard_2_idle = 0;
					cha_idle_on = 0;
					hard_2_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						hard_2_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {
						if (monster_count >= 25) {  //monster idle loop
							hard_2_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);
							hard_2 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						else {
							render_animation(dark_mage_attack_texture, monster_count, 480, 480, monster_position, 240, 480, 480);
							monster_count++;
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 11) {   //character loop
						monster_count = 0;
					}
					render_animation(dark_mage_texture, monster_count, 480, 480, monster_position, 240, 480, 480);
					monster_count++;
				}


				if (hard_2_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (hard_3 == 1) {
				if (monster_health <= 0) {   //if health reach enter pass scene
					hard_3 = 0;
					hard_3_idle = 0;
					cha_idle_on = 0;
					hard_3_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						hard_3_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 220) {
						monster_position -= 10;
					}
					if (monster_position == 220 && monster_idle == 1) {
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {
						if (monster_count == 20) {  //monster idle loop
							hard_3_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);
							hard_3 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						render_animation(dark_lord_attack_texture, monster_count, 200, 200, monster_position, 240, 480, 480);
						monster_count++;
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {   //character loop
						monster_count = 0;
					}
					render_animation(dark_lord_texture, monster_count, 200, 200, monster_position, 240, 480, 480);
					monster_count++;
				}

				if (hard_3_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (hard_4 == 1) {
				if (monster_health <= 0) {   //if health reach enter pass scene
					hard_4 = 0;
					hard_4_idle = 0;
					cha_idle_on = 0;
					hard_4_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  //if run out of turn enter fail scene
					death_on = 1;
					if (fail_scene == 0) {
						hard_4_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 220) {
						monster_position -= 10;
					}
					if (monster_position == 220 && monster_idle == 1) {
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {
						if (monster_count == 27) {  //monster idle loop
							hard_4_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);
							hard_4 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						render_animation(dark_knight_attack_texture, monster_count, 506, 420, monster_position, 150, 656, 570);
						monster_count++;
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 16) {   //character loop
						monster_count = 0;
					}
					render_animation(dark_knight_texture, monster_count, 506, 420, monster_position, 150, 656, 570);
					monster_count++;
				}

				if (hard_4_idle == 1) {   // Chack easy 1 idle mode
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text in idle mode
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (arrow_on == 1) {    //Check arrow mode

				if (fail == 3) {  //check if fail = 3 enter attack scene
					arrow_on = 0;
					character_count = 0;
					attack_on = 1;
				}

				if (time_bar <= 0) {    //check if run out of time enter attack scene
					arrow_on = 0;
					attack_on = 1;
					character_count = 0;
					arrow_random = 5;
				}

				if (arrow_random_on == 1) {   //random arrow
					srand(time(0));
					arrow_random = rand() % 4;
					arrow_random_on = 0;
				}

				if (arrow_random_on == 0) {

					if (arrow_stop == 0) {
						time_bar -= 11;    // Render time bar
					}
					render_something(health_bar_bg_texture, 50, 50, 1100, 50);
					render_something(health_bar_texture, 50, 50, time_bar, 50);

					if (arrow_stop == 0) {
						switch (arrow_random)   //Render arrow
						{
						case 0: SDL_RenderCopy(renderer, arrow_up_texture, NULL, &arrow); break;
						case 1: SDL_RenderCopy(renderer, arrow_down_texture, NULL, &arrow); break;
						case 2: SDL_RenderCopy(renderer, arrow_left_texture, NULL, &arrow); break;
						case 3: SDL_RenderCopy(renderer, arrow_right_texture, NULL, &arrow); break;
						default:
							break;
						}
					}
					SDL_RenderCopy(renderer, message_texture_score, NULL, &message_score_ingame_rect);   //Render text in audition mode
					SDL_RenderCopy(renderer, message_texture_fail, NULL, &message_fail_ingame_rect);
				}

				if (character_count == 11) {   //character loop
					character_count = 0;
				}
				pos_x_cha_attack = find_position(250, 500, time_bar);
				render_animation(character_texture, character_count, 91, 113, pos_x_cha_attack, 490, 158, 187);
				character_count++;

				health_bar = health_bar_width(monster_health, max_monster_health, 80); //render monster health in audition mode
				render_something(health_bar_bg_texture, healthbar_position_x, healthbar_position_y, 80, 15);
				render_something(health_bar_texture, healthbar_position_x, healthbar_position_y, health_bar, 15);
			}

			if (hard_1_mission == 1) {  // Render easy mission 1
				render_something(hard_1_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_2_mission == 1) {  // Render easy mission 1
				render_something(hard_2_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_3_mission == 1) {  // Render easy mission 1
				render_something(hard_3_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_4_mission == 1) {  // Render easy mission 1
				render_something(hard_4_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_1_pass == 1) {   // Render easy 1 pass
				render_something(hard_1_pass_texture, 0, 0, 1200, 720);
			}

			if (hard_2_pass == 1) {   // Render easy 1 pass
				render_something(hard_2_pass_texture, 0, 0, 1200, 720);
			}

			if (hard_3_pass == 1) {   // Render easy 1 pass
				render_something(hard_3_pass_texture, 0, 0, 1200, 720);
			}

			if (hard_4_pass == 1) {   // Render easy 1 pass
				render_something(hard_4_pass_texture, 0, 0, 1200, 720);
			}

			if (fail_scene == 1) {   //Render Fail Scene
				render_something(fail_texture, 0, 0, 1200, 720);
			}

			if (attack_on == 1) {   //Render attack scene
				death_on = 0;
				if (character_count == 15) {
					character_count = 0;
					attack_on = 0;
					if (hard_1 == 1) {
						hard_1_idle = 1;
					}
					else if (hard_2 == 1) {
						hard_2_idle = 1;
					}
					else if (hard_3 == 1) {
						hard_3_idle = 1;
					}
					else if (hard_4 == 1) {
						hard_4_idle = 1;
					}
					cha_idle_on = 1;

					monster_health -= score;
					sprintf(health, "Monster HP : %01d/%d", monster_health, max_monster_health);
					message_surface_health = TTF_RenderText_Solid(sans, health, white);
					message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);

					turn_left -= 1;
					sprintf(turn, "Turns Left : %01d/3", turn_left);
					message_surface_turn = TTF_RenderText_Solid(sans, turn, white);
					message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
				}
				render_animation(attack_2_texture, character_count, 154, 181, 680, 400, 248, 297);
				character_count++;
			}
			bg_count++;
			frameTime_2++;
			SDL_RenderPresent(renderer);
			delay_function(6000);
		}
	}
	SDL_DestroyRenderer(renderer); // ทําลายตัว renderer
	SDL_DestroyWindow(window); // ทําลายหน้าต่างโปรแกรม
	TTF_Quit();
	SDL_Quit(); // ออกจากโปรแกรม
	return 0;
}

int render_animation(texture, count, srcrect_x, srcrect_y, pos_rect_x, pos_rect_y, rect_x, rect_y) {
	pos_x = count * srcrect_x;
	SDL_Rect animation_rect = { pos_rect_x, pos_rect_y, rect_x, rect_y };
	SDL_Rect animation_srcrect = { pos_x , 0, srcrect_x, srcrect_y };
	SDL_RenderCopy(renderer, texture, &animation_srcrect, &animation_rect);  //background render function
}

int render_something(texture, pos_rect_x, pos_rect_y, rect_x, rect_y) {
	SDL_Rect something_rect = { pos_rect_x, pos_rect_y, rect_x, rect_y };
	SDL_RenderCopy(renderer, texture, NULL, &something_rect);
}

int menu_button_render(button_texture, selector, arrow_texture) {
	int y = 0;
	switch (selector){
	case 1: y = 280; break;
	case 2: y = 390; break;
	case 3: y = 490; break;
	case 4: y = 600; break;
	default: break;
	}
	SDL_Rect menu_selector_rect = { 340, y, 80, 80 };
	SDL_Rect menu_bg_rect = { 0, 0, 1200, 720 };
	SDL_RenderCopy(renderer, button_texture, NULL, &menu_bg_rect);
	SDL_RenderCopy(renderer, arrow_texture, NULL, &menu_selector_rect);
}

int menu_difficulty_render(diff_texture, selector) {
	int y = 0;
	switch (selector) { //Check where selector is
	case 1: y = 90; break;
	case 2: y = 250; break;
	case 3: y = 410; break;
	case 4: y = 570; break;
	default: break;
	}
	SDL_Rect menu_rect = { 0, 0, 1200, 720 };
	SDL_RenderCopy(renderer, diff_texture, NULL, &menu_rect);
	if (selector != 4) {
		SDL_Rect selector_rect = { 260, y, 100, 100 };
		SDL_RenderCopy(renderer, arrow_cool_right_texture, NULL, &selector_rect);
	}
	else {
		SDL_Rect selector_rect = { 300, y, 100, 100 };
		SDL_RenderCopy(renderer, arrow_cool_right_texture, NULL, &selector_rect);
	}
}

int delay_function(delay_diff) {
	int delay = delay_diff / 60 - SDL_GetTicks() + SDL_GetTicks();
	SDL_Delay(delay);
	return 0;
}

int find_position(start, stop, time) {
	return (double)start + (double)stop * (1 - ((double)time / (double)1100));
}

int health_bar_width(monster_health, max_health, size) {
	return ((double)monster_health / max_health) * size;
}
