#include <SDL.h>       // โหลด library SDL
#include <SDL_image.h> // โหลด library SDL_image
#include <SDL_ttf.h>   // โหลด library SDL_ttf
#include <stdio.h>     // โหลด library stdio
#include <string.h>    // โหลด library string.h
#include <stdlib.h>    // โหลด library stdlib.h
#include <ctype.h>     // โหลด library ctype
#include <stdbool.h>   // โหลด library stdbool
#include <time.h>      // โหลด library time
#include <conio.h>     // โหลด library conio
#include <string.h>    // โหลด library string
#include <math.h>      // โหลด library math

/*------------------------------------------------------ประกาศตัวแปร------------------------------------------------------*/
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

// สร้างตัวแปรไว้เก็บรูป Menu Background
SDL_Surface* menu_bg_surface = NULL;
SDL_Texture* menu_bg_texture = NULL;

// สร้างตัวแปรไว้เก็บรูป ปุ่มในหน้า menu
SDL_Surface* menu_main_button_surface = NULL;
SDL_Texture* menu_main_button_texture = NULL;

// สร้างตัวแปรไว้เก็บรูป How to play
SDL_Surface* menu_howtoplay_1_eng_surface = NULL;
SDL_Texture* menu_howtoplay_1_eng_texture = NULL;
SDL_Surface* menu_howtoplay_2_eng_surface = NULL;
SDL_Texture* menu_howtoplay_2_eng_texture = NULL;
SDL_Surface* menu_howtoplay_1_thai_surface = NULL;
SDL_Texture* menu_howtoplay_1_thai_texture = NULL;
SDL_Surface* menu_howtoplay_2_thai_surface = NULL;
SDL_Texture* menu_howtoplay_2_thai_texture = NULL;

// สร้างตัวแปรไว้เก็บรูป info
SDL_Surface* menu_info_surface = NULL;
SDL_Texture* menu_info_texture = NULL;

// สร้างตัวแปรไว้เก็บรูป Difficulty
SDL_Surface* menu_difficulty_surface = NULL;
SDL_Texture* menu_difficulty_texture = NULL;

// สร้างตัวแปรไว้เก็บรูปลูกศรในหน้า menu
SDL_Surface* arrow_cool_right_surface = NULL;
SDL_Texture* arrow_cool_right_texture = NULL;

// สร้างตัวแปรไว้เก็บรูปลูกศรในเกม
SDL_Surface* arrow_right_surface = NULL;
SDL_Texture* arrow_right_texture = NULL;
SDL_Surface* arrow_left_surface = NULL;
SDL_Texture* arrow_left_texture = NULL;
SDL_Surface* arrow_up_surface = NULL;
SDL_Texture* arrow_up_texture = NULL;
SDL_Surface* arrow_down_surface = NULL;
SDL_Texture* arrow_down_texture = NULL;

// สร้างตัวแปรไว้เก็บรูปตัวละคร
SDL_Surface* character_surface = NULL;
SDL_Texture* character_texture = NULL;
SDL_Surface* attack_2_surface = NULL;
SDL_Texture* attack_2_texture = NULL;

// สร้างตัวแปรไว้เก็บรูป Mission ของแต่ละเควส
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

// สร้างตัวแปรไว้เก็บรูปผ่าน Mission ของแต่ละเควส
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

// สร้างตัวแปรไว้เก็บรูป Fail
SDL_Surface* fail_surface = NULL;
SDL_Texture* fail_texture = NULL;

// สร้างตัวแปรไว้เก็บรูป Background ในด่าน
SDL_Surface* easy_background_surface = NULL;
SDL_Texture* easy_background_texture = NULL;
SDL_Surface* medium_background_surface = NULL;
SDL_Texture* medium_background_texture = NULL;
SDL_Surface* hard_background_surface = NULL;
SDL_Texture* hard_background_texture = NULL;

// สร้างตัวแปรไว้เก็บรูปหลอดเลือด
SDL_Surface* health_bar_surface = NULL;
SDL_Texture* health_bar_texture = NULL;
SDL_Surface* health_bar_bg_surface = NULL;
SDL_Texture* health_bar_bg_texture = NULL;

// สร้างตัวแปรไว้เก็บรูป Monster
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

// สร้างตัวแปรไว้เก็บรูป Text Start Attack
SDL_Surface* text_start_attack_surface = NULL;
SDL_Texture* text_start_attack_texture = NULL;

int running;
int width = 1200, height = 720; // ประกาศตัวแปร ความกว้างและสูงของโปรแกรม
long long frameTime = 0, keyboard_bug_fix = 0; // ประกาศตัวแปร frameTime และแก้บัค Keyboard

// ประกาศตัวแปรในหน้า menu
int menu_bg_count = 0 , menu_main_on = 1, menu_bg = 1, menu_how_1 = 0, menu_how_2 = 0, menu_how_language = 1, menu_diffi = 0, menu_info_on = 0;    //Create menu checker
int selector_main = 1, selector_diff = 1;

// ประกาศตัวแปรในด่าน easy
int easy_1_mission = 0, easy_2_mission = 0, easy_3_mission = 0;
int easy = 0, easy_1 = 0, easy_2 = 0, easy_3 = 0;
int easy_1_pass = 0, easy_2_pass = 0, easy_3_pass = 0;
int easy_1_idle = 0, easy_2_idle = 0, easy_3_idle = 0;

// ประกาศตัวแปรในด่าน medium
int medium_1_mission = 0, medium_2_mission = 0, medium_3_mission = 0;
int medium = 0, medium_1 = 0, medium_2 = 0, medium_3 = 0;
int medium_1_pass = 0, medium_2_pass = 0, medium_3_pass = 0;
int medium_1_idle = 0, medium_2_idle = 0, medium_3_idle = 0;

// ประกาศตัวแปรในด่าน Hard
int hard_1_mission = 0, hard_2_mission = 0, hard_3_mission = 0, hard_4_mission = 0;
int hard = 0, hard_1 = 0, hard_2 = 0, hard_3 = 0, hard_4 = 0;
int hard_1_pass = 0, hard_2_pass = 0, hard_3_pass = 0, hard_4_pass = 0;
int hard_1_idle = 0, hard_2_idle = 0, hard_3_idle = 0, hard_4_idle = 0;

// ประกาศตัวแปรนับตำแหน่งของภาพ Sprite
int bg_count = 0, character_count = 0, monster_count = 0;

// ประกาศตัวแปรอื่นๆ
int health_bar = 0, time_bar = 800, monster_health = 0, max_monster_health = 0, turn_left = 0;
char health[100], turn[100], score_text[100], fail_text[100];
int attack_on = 0, cha_idle_on = 0;
int arrow_on = 0, arrow_random_on = 0, arrow_random = 5, arrow_stop = 0;
int score = 0, fail = 0;
int death_on = 0, start_attack_on = 1, fail_scene = 0;
int monster_position = 830, monster_idle = 1, monster_move = 0;
int pos_x = 0, pos_x_cha = 0, pos_x_mon = 0, pos_attack = 250, pos_x_cha_attack = 0, pos_selector_y = 0;
int healthbar_position_x = 0, healthbar_position_y = 0;

/*------------------------------------------------------ภายในเกม------------------------------------------------------*/
int main(int argc, char* args[]) {
	TTF_Init();                              //SDL_ttf init
	SDL_Init(SDL_INIT_EVERYTHING);           //SDL init
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Audition Quest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = 1;   // ให้เกมเปิด

	TTF_Font* sans = TTF_OpenFont("font/MesseDuesseldorf-O1d3.ttf", 100);   // ใส่ Font
	SDL_Color black = { 0, 0, 0 };                                          // สร้างตัวแปรสีดำ
	SDL_Color white = { 255, 255, 255 };                                    // สร้างตัวแปรสีขาว

	/*------------------------------------------------------ใส่รูป------------------------------------------------------*/
	menu_bg_surface = IMG_Load("background/menu_bg.png");
	menu_bg_texture = SDL_CreateTextureFromSurface(renderer, menu_bg_surface);

	menu_main_button_surface = IMG_Load("image/menu/main_menu.png");
	menu_main_button_texture = SDL_CreateTextureFromSurface(renderer, menu_main_button_surface);

	SDL_Rect arrow = { 470, 120, 250, 250 };
	arrow_cool_right_surface = IMG_Load("image/arrow/arrow_wood.png");
	arrow_cool_right_texture = SDL_CreateTextureFromSurface(renderer, arrow_cool_right_surface);

	arrow_right_surface = IMG_Load("image/arrow/yellow/arrow_right.png");
	arrow_right_texture = SDL_CreateTextureFromSurface(renderer, arrow_right_surface);

	arrow_left_surface = IMG_Load("image/arrow/yellow/arrow_left.png");
	arrow_left_texture = SDL_CreateTextureFromSurface(renderer, arrow_left_surface);

	arrow_up_surface = IMG_Load("image/arrow/yellow/arrow_up.png");
	arrow_up_texture = SDL_CreateTextureFromSurface(renderer, arrow_up_surface);

	arrow_down_surface = IMG_Load("image/arrow/yellow/arrow_down.png");
	arrow_down_texture = SDL_CreateTextureFromSurface(renderer, arrow_down_surface);

	menu_howtoplay_1_eng_surface = IMG_Load("image/menu/menu_howtoplay_1_eng.png");
	menu_howtoplay_1_eng_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_1_eng_surface);

	menu_howtoplay_2_eng_surface = IMG_Load("image/menu/menu_howtoplay_2_eng.png");
	menu_howtoplay_2_eng_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_2_eng_surface);

	menu_howtoplay_1_thai_surface = IMG_Load("image/menu/menu_howtoplay_1_thai.png");
	menu_howtoplay_1_thai_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_1_thai_surface);

	menu_howtoplay_2_thai_surface = IMG_Load("image/menu/menu_howtoplay_2_thai.png");
	menu_howtoplay_2_thai_texture = SDL_CreateTextureFromSurface(renderer, menu_howtoplay_2_thai_surface);

	menu_info_surface = IMG_Load("image/menu/menu_info.png");
	menu_info_texture = SDL_CreateTextureFromSurface(renderer, menu_info_surface);

	menu_difficulty_surface = IMG_Load("image/menu/menu_difficulty.png");
	menu_difficulty_texture = SDL_CreateTextureFromSurface(renderer, menu_difficulty_surface);

	easy_1_mission_surface = IMG_Load("image/mission/easy_1.png");
	easy_1_mission_texture = SDL_CreateTextureFromSurface(renderer, easy_1_mission_surface);
	easy_2_mission_surface = IMG_Load("image/mission/easy_2.png");
	easy_2_mission_texture = SDL_CreateTextureFromSurface(renderer, easy_2_mission_surface);
	easy_3_mission_surface = IMG_Load("image/mission/easy_3.png");
	easy_3_mission_texture = SDL_CreateTextureFromSurface(renderer, easy_3_mission_surface);

	medium_1_mission_surface = IMG_Load("image/mission/medium_1.png");
	medium_1_mission_texture = SDL_CreateTextureFromSurface(renderer, medium_1_mission_surface);
	medium_2_mission_surface = IMG_Load("image/mission/medium_2.png");
	medium_2_mission_texture = SDL_CreateTextureFromSurface(renderer, medium_2_mission_surface);
	medium_3_mission_surface = IMG_Load("image/mission/medium_3.png");
	medium_3_mission_texture = SDL_CreateTextureFromSurface(renderer, medium_3_mission_surface);

	hard_1_mission_surface = IMG_Load("image/mission/hard_1.png");
	hard_1_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_1_mission_surface);
	hard_2_mission_surface = IMG_Load("image/mission/hard_2.png");
	hard_2_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_2_mission_surface);
	hard_3_mission_surface = IMG_Load("image/mission/hard_3.png");
	hard_3_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_3_mission_surface);
	hard_4_mission_surface = IMG_Load("image/mission/hard_4.png");
	hard_4_mission_texture = SDL_CreateTextureFromSurface(renderer, hard_4_mission_surface);

	easy_1_pass_surface = IMG_Load("image/mission/easy_1_pass.png");
	easy_1_pass_texture = SDL_CreateTextureFromSurface(renderer, easy_1_pass_surface);
	easy_2_pass_surface = IMG_Load("image/mission/easy_2_pass.png");
	easy_2_pass_texture = SDL_CreateTextureFromSurface(renderer, easy_2_pass_surface);
	easy_3_pass_surface = IMG_Load("image/mission/easy_3_pass.png");
	easy_3_pass_texture = SDL_CreateTextureFromSurface(renderer, easy_3_pass_surface);

	medium_1_pass_surface = IMG_Load("image/mission/medium_1_pass.png");
	medium_1_pass_texture = SDL_CreateTextureFromSurface(renderer, medium_1_pass_surface);
	medium_2_pass_surface = IMG_Load("image/mission/medium_2_pass.png");
	medium_2_pass_texture = SDL_CreateTextureFromSurface(renderer, medium_2_pass_surface);
	medium_3_pass_surface = IMG_Load("image/mission/medium_3_pass.png");
	medium_3_pass_texture = SDL_CreateTextureFromSurface(renderer, medium_3_pass_surface);

	hard_1_pass_surface = IMG_Load("image/mission/hard_1_pass.png");
	hard_1_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_1_pass_surface);
	hard_2_pass_surface = IMG_Load("image/mission/hard_2_pass.png");
	hard_2_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_2_pass_surface);
	hard_3_pass_surface = IMG_Load("image/mission/hard_3_pass.png");
	hard_3_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_3_pass_surface);
	hard_4_pass_surface = IMG_Load("image/mission/hard_4_pass.png");
	hard_4_pass_texture = SDL_CreateTextureFromSurface(renderer, hard_4_pass_surface);

	fail_surface = IMG_Load("image/mission/fail.png");
	fail_texture = SDL_CreateTextureFromSurface(renderer, fail_surface);

	easy_background_surface = IMG_Load("background/easy_bg.png");
	easy_background_texture = SDL_CreateTextureFromSurface(renderer, easy_background_surface);

	medium_background_surface = IMG_Load("background/medium_bg.png");
	medium_background_texture = SDL_CreateTextureFromSurface(renderer, medium_background_surface);

	hard_background_surface = IMG_Load("background/hard_bg.png");
	hard_background_texture = SDL_CreateTextureFromSurface(renderer, hard_background_surface);

	character_surface = IMG_Load("image/human_1/human_idle.png");
	character_texture = SDL_CreateTextureFromSurface(renderer, character_surface);

	slime_surface = IMG_Load("image/slime/slime_idle_sprite.png");
	slime_texture = SDL_CreateTextureFromSurface(renderer, slime_surface);
	slime_attack_surface = IMG_Load("image/slime/slime_attack_sprite.png");
	slime_attack_texture = SDL_CreateTextureFromSurface(renderer, slime_attack_surface);

	eye_surface = IMG_Load("image/monster_eye/eye_idle_sprite.png");
	eye_texture = SDL_CreateTextureFromSurface(renderer, eye_surface);
	eye_attack_surface = IMG_Load("image/monster_eye/eye_attack_sprite.png");
	eye_attack_texture = SDL_CreateTextureFromSurface(renderer, eye_attack_surface);
	eye_moving_surface = IMG_Load("image/monster_eye/eye_walk_sprite.png");
	eye_moving_texture = SDL_CreateTextureFromSurface(renderer, eye_moving_surface);

	fire_tiger_surface = IMG_Load("image/monster_fire_tiger/fire_tiger_idle_sprite.png");
	fire_tiger_texture = SDL_CreateTextureFromSurface(renderer, fire_tiger_surface);
	fire_tiger_attack_surface = IMG_Load("image/monster_fire_tiger/fire_tiger_attack_sprite.png");
	fire_tiger_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_tiger_attack_surface);

	fire_knight_surface = IMG_Load("image/monster_fire_knight/fire_knight_idle_sprite.png");
	fire_knight_texture = SDL_CreateTextureFromSurface(renderer, fire_knight_surface);
	fire_knight_attack_surface = IMG_Load("image/monster_fire_knight/fire_knight_attack_sprite.png");
	fire_knight_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_knight_attack_surface);

	fire_golem_surface = IMG_Load("image/monster_fire_golem/fire_golem_idle_sprite.png");
	fire_golem_texture = SDL_CreateTextureFromSurface(renderer, fire_golem_surface);
	fire_golem_attack_surface = IMG_Load("image/monster_fire_golem/fire_golem_attack_sprite.png");
	fire_golem_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_golem_attack_surface);

	fire_dragon_surface = IMG_Load("image/monster_fire_dragon/fire_dragon_idle_sprite.png");
	fire_dragon_texture = SDL_CreateTextureFromSurface(renderer, fire_dragon_surface);
	fire_dragon_attack_surface = IMG_Load("image/monster_fire_dragon/fire_dragon_attack_sprite.png");
	fire_dragon_attack_texture = SDL_CreateTextureFromSurface(renderer, fire_dragon_attack_surface);

	dark_hammer_surface = IMG_Load("image/monster_dark_hammer/dark_hammer_idle_sprite.png");
	dark_hammer_texture = SDL_CreateTextureFromSurface(renderer, dark_hammer_surface);
	dark_hammer_attack_surface = IMG_Load("image/monster_dark_hammer/dark_hammer_attack_sprite.png");
	dark_hammer_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_hammer_attack_surface);

	dark_mage_surface = IMG_Load("image/monster_dark_mage/dark_mage_idle_sprite.png");
	dark_mage_texture = SDL_CreateTextureFromSurface(renderer, dark_mage_surface);
	dark_mage_attack_surface = IMG_Load("image/monster_dark_mage/dark_mage_attack_sprite.png");
	dark_mage_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_mage_attack_surface);

	dark_lord_surface = IMG_Load("image/monster_dark_lord/dark_lord_idle_sprite.png");
	dark_lord_texture = SDL_CreateTextureFromSurface(renderer, dark_lord_surface);
	dark_lord_attack_surface = IMG_Load("image/monster_dark_lord/dark_lord_attack_sprite.png");
	dark_lord_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_lord_attack_surface);

	dark_knight_surface = IMG_Load("image/monster_dark_knight/dark_knight_idle_sprite.png");
	dark_knight_texture = SDL_CreateTextureFromSurface(renderer, dark_knight_surface);
	dark_knight_attack_surface = IMG_Load("image/monster_dark_knight/dark_knight_attack_sprite.png");
	dark_knight_attack_texture = SDL_CreateTextureFromSurface(renderer, dark_knight_attack_surface);

	health_bar_surface = IMG_Load("image/yellow.png");
	health_bar_texture = SDL_CreateTextureFromSurface(renderer, health_bar_surface);

	health_bar_bg_surface = IMG_Load("image/black.png");
	health_bar_bg_texture = SDL_CreateTextureFromSurface(renderer, health_bar_bg_surface);

	attack_2_surface = IMG_Load("image/human_1/human_attack_sprite.png");   //Render Button
	attack_2_texture = SDL_CreateTextureFromSurface(renderer, attack_2_surface);

	/*------------------------------------------------------สร้างตัวแปร Text------------------------------------------------------*/
	SDL_Surface* message_surface_health = TTF_RenderText_Solid(sans, "xxxxxx", black);
	SDL_Texture* message_texture_health = SDL_CreateTextureFromSurface(renderer, message_surface_health);
	SDL_Rect message_health_ingame_rect = { 720, 110, 280, 40 };

	SDL_Surface* message_surface_turn = TTF_RenderText_Solid(sans, "xxxxxx", black);
	SDL_Texture* message_texture_turn = SDL_CreateTextureFromSurface(renderer, message_surface_turn);
	SDL_Rect message_turn_ingame_rect = { 200, 110, 220, 40 };

	sprintf(score_text, "Score : %01d", score);   //turn int to string
	SDL_Surface* message_surface_score = TTF_RenderText_Solid(sans, score_text, white);
	SDL_Texture* message_texture_score = SDL_CreateTextureFromSurface(renderer, message_surface_score);
	SDL_Rect message_score_ingame_rect = { 850, 200, 210, 60 };

	sprintf(fail_text, "Fail : %01d/3", fail);   //turn int to string
	SDL_Surface* message_surface_fail = TTF_RenderText_Solid(sans, fail_text, white);
	SDL_Texture* message_texture_fail = SDL_CreateTextureFromSurface(renderer, message_surface_fail);
	SDL_Rect message_fail_ingame_rect = { 850, 260, 180, 60 };

	text_start_attack_surface = IMG_Load("image/text/attack_easy.png");
	text_start_attack_texture = SDL_CreateTextureFromSurface(renderer, text_start_attack_surface);
	SDL_Rect start_attack_rect = { 0, 0, 1200, 720 };

	while (running) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {   // ถ้ากดปุ่ม close จะปิดโปรแกรม
				running = 0;
			}
			/*------------------------------------------------------เช็คการกด Keyboard------------------------------------------------------*/
			else if (event.type == SDL_KEYDOWN && keyboard_bug_fix == 0) {
				switch (event.key.keysym.sym){
				case SDLK_UP:    // เช็คปุ่ม ลูกศรขึ้น
					keyboard_bug_fix = 1;
					if (menu_main_on == 1) {   // ขยับลูกศรในหน้า menu
						if (selector_main == 2 || selector_main == 3 || selector_main == 4) {
							selector_main--;
						}
					}

					else if (menu_diffi == 1) {   // ขยับลูกศรในหน้า Difficulty
						if (selector_diff == 2 || selector_diff == 3 || selector_diff == 4) {
							selector_diff--;
						}
					}

					if (arrow_random_on == 0) {   // เช็คว่ากดลูกศรถูกหรือผิดในโหมดโจมตี
						if (arrow_random == 0) {
							arrow_random = 4;
							arrow_stop = 1;
							frameTime = 0;
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
				case SDLK_DOWN:    // เช็คปุ่ม ลูกศรลง
					keyboard_bug_fix = 1;
					if (menu_main_on == 1) {   // ขยับลูกศรในหน้า menu
						if (selector_main == 1 || selector_main == 2 || selector_main == 3) {
							selector_main++;
						}
					}

					else if (menu_diffi == 1) {  // ขยับลูกศรในหน้า Difficulty
						if (selector_diff == 1 || selector_diff == 2 || selector_diff == 3) {
							selector_diff++;
						}
					}

					if (arrow_random_on == 0) {   // เช็คว่ากดลูกศรถูกหรือผิดในโหมดโจมตี
						if (arrow_random == 1) {
							arrow_stop = 1;
							frameTime = 0;
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
					if (arrow_random_on == 0 && (easy || medium || hard)) {   // เช็คว่ากดลูกศรถูกหรือผิดในโหมดโจมตี
						if (arrow_random == 2) {
							arrow_random = 4;
							arrow_stop = 1;
							frameTime = 0;
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

					else if (menu_how_2) {  // ขยับหน้าใน How To play
						menu_how_1 = 1;
						menu_how_2 = 0;
					}

					break;
				case SDLK_RIGHT:
					keyboard_bug_fix = 1;
					if (arrow_random_on == 0 && (easy || medium || hard)) {   // เช็คว่ากดลูกศรถูกหรือผิดในโหมดโจมตี
						if (arrow_random == 3) {
							arrow_random = 4;
							arrow_stop = 1;
							frameTime = 0;
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

					else if (menu_how_1){ // ขยับหน้าใน How To play
						menu_how_1 = 0;
						menu_how_2 = 1;
					}

					break;
				case SDLK_RETURN:   // เช็คปุ่ม Enter
					keyboard_bug_fix = 1;

					if (fail_scene == 1) {  // กดกลับสู่เมนูในหน้า Fail
						fail_scene = 0;
						menu_bg = 1;
						menu_main_on = 1;
						death_on = 0;
						easy = 0;
						medium = 0;
						hard = 0;
					}

					else if (menu_main_on == 1) {    // กดเลือกในหน้า Main Menu
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

					else if (menu_how_1 == 1 || menu_how_2 == 1) {   //  กลับสู่ Main Menu ในหน้า How to play
						menu_how_1 = 0;
						menu_how_2 = 0;
						menu_main_on = 1;
					}

					else if (menu_info_on == 1) {   //  กลับสู่หน้า Main Menu ในหน้า Info
						menu_info_on = 0;
						menu_main_on = 1;
					}

					else if (menu_diffi == 1) {    // กดเลือกในหน้า Difficulty
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

					else if (easy == 1) {  // เช็คการกดในโหมด Easy

						if (easy_1_mission == 1) {   // เข้าสู่ด่าน Easy 1
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

						else if (easy_1_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน easy 1
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

						else if (easy_1_pass == 1) {  // เข้าสู่ Quest ของ Easy 2
							easy_1_pass = 0;
							easy_2_mission = 1;
							death_on = 0;
						}

						else if (easy_2_mission == 1) {  // เข้าสู่ด่าน Easy 2
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

						else if (easy_2_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Easy 2
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

						else if (easy_2_pass == 1) {  // เข้าสู่ Quest ของ Easy 2
							easy_2_pass = 0;
							easy_3_mission = 1;
							death_on = 0;
						}

						else if (easy_3_mission == 1) {  // เข้าสู่ด่าน Easy 3
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

						else if (easy_3_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Easy 3
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

						else if (easy_3_pass == 1) {  // กลับสู่ Main Menu หลังจากจบด่าน Easy
							easy_3_pass = 0;
							menu_bg = 1;
							menu_main_on = 1;
							easy = 0;
						}
					}

					else if (medium == 1) {  // เช็คการกดในโหมด Medium

						if (medium_1_mission == 1) {   // เข้าสู่ด่าน Medium 1
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

						else if (medium_1_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Medium 1
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

						else if (medium_1_pass == 1) { // เข้าสู่ Quest ของ Medium 2
							medium_1_pass = 0;
							medium_2_mission = 1;
							death_on = 0;
						}

						else if (medium_2_mission == 1) {   // เข้าสู่ด่าน Medium 2
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

						else if (medium_2_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Medium 2
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

						else if (medium_2_pass == 1) { // เข้าสู่ Quest ของ Medium 3
							medium_2_pass = 0;
							medium_3_mission = 1;
							death_on = 0;
						}

						else if (medium_3_mission == 1) {   // เข้าสู่ด่าน Medium 3
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

						else if (medium_3_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Medium 3
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

						else if (medium_3_pass == 1) {  // กลับสู่ Main Menu หลังจากจบด่าน Medium
							medium_3_pass = 0;
							menu_bg = 1;
							menu_main_on = 1;
							medium = 0;
						}
					}

					else if (hard == 1) {  // เช็คการกดในโหมด Hard

						if (hard_1_mission == 1) {   // เข้าสู่ด่าน Hard 1
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

						else if (hard_1_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Hard 1
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

						else if (hard_1_pass == 1) {  // เข้าสู่ Quest ของ Hard 1
							hard_1_pass = 0;
							hard_2_mission = 1;
							death_on = 0;
						}

						else if (hard_2_mission == 1) {   // เข้าสู่ด่าน Hard 2
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

						else if (hard_2_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Hard 2
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

						else if (hard_2_pass == 1) {  // เข้าสู่ Quest ของ Hard 2
							hard_2_pass = 0;
							hard_3_mission = 1;
							death_on = 0;
						}

						else if (hard_3_mission == 1) {   // เข้าสู่ด่าน Hard 3
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

						else if (hard_3_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Hard 3
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

						else if (hard_3_pass == 1) {  // เข้าสู่ Quest ของ Hard 3
							hard_3_pass = 0;
							hard_4_mission = 1;
							death_on = 0;
						}

						else if (hard_4_mission == 1) {   // เข้าสู่ด่าน Hard 4
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

						else if (hard_4_idle == 1 && turn_left > 0) {   //  เข้าสู่โหมดโจมตีในด่าน Hard 4
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

						else if (hard_4_pass == 1) {  // กลับสู่ Main Menu หลังจากจบด่าน Hard
							hard_4_pass = 0;
							menu_bg = 1;
							menu_main_on = 1;
							hard = 0;
						}
					}

					break;

				case SDLK_SPACE:  // เช็คปุ่ม Space Bar (เปลี่ยนภาษาในหน้า How to play)
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

			else if (event.type == SDL_KEYUP) {  //  แก้บัค Keyboard
				keyboard_bug_fix = 0;
			}
		}

		/*------------------------------------------------ตั้ง Delay ลูกศรของแต่ละความยาก------------------------------------------------*/
		if (frameTime  == 5 && arrow_stop == 1 && easy == 1) {
			arrow_stop = 0;
			arrow_random_on = 1;
		}

		if (frameTime == 4 && arrow_stop == 1 && medium == 1) {
			arrow_stop = 0;
			arrow_random_on = 1;
		}

		if (frameTime == 3 && arrow_stop == 1 && hard == 1) {
			arrow_stop = 0;
			arrow_random_on = 1;
		}

		/*------------------------------------------------------Render หน้า Menu------------------------------------------------------*/
		if (menu_bg == 1) {
			SDL_RenderClear(renderer);  //  ล้างตัวแปร Renderer
			if (menu_bg_count > 7) {   //  หาตำแหน่งในภาพ Sprite
				menu_bg_count = 0;
			}
			render_animation(menu_bg_texture, menu_bg_count, 560, 272, 0, 0, 1200, 720);  //  Render Background

			if (menu_main_on == 1) {  //  Render ปุ่มใน Main Menu
				menu_button_render(menu_main_button_texture, selector_main, arrow_cool_right_texture);
			}
			if (menu_how_1 == 1 && menu_how_language == 1) {  //  Render ภาพ How to play 1 ภาษา eng
				render_something(menu_howtoplay_1_eng_texture, 0, 0, 1200, 720);
			}
			if (menu_how_2 == 1 && menu_how_language == 1) {  //  Render ภาพ How to play 2 ภาษา eng
				render_something(menu_howtoplay_2_eng_texture, 0, 0, 1200, 720);
			}
			if (menu_how_1 == 1 && menu_how_language == 2) {  //  Render ภาพ How to play 1 ภาษาไทย
				render_something(menu_howtoplay_1_thai_texture, 0, 0, 1200, 720);
			}
			if (menu_how_2 == 1 && menu_how_language == 2) {  //  Render ภาพ How to play 2 ภาษาไทย
				render_something(menu_howtoplay_2_thai_texture, 0, 0, 1200, 720);
			}
			if (menu_diffi == 1) {  //  Render ปุ่มในหน้า Difficulty
				menu_difficulty_render(menu_difficulty_texture, selector_diff, arrow_cool_right_texture);
			}
			if (menu_info_on == 1) {  //  Render ภาพ Info
				render_something(menu_info_texture, 0, 0, 1200, 720);
			}
			menu_bg_count++;  //  ขยับ Background
			SDL_RenderPresent(renderer);  //  Render ภาพ
			delay_function(5000);  //  ตั้งดีเลระหว่างภาพ เพื่อลดการทำงานของโปรแกรม
		}

		/*------------------------------------------------------Render ด่าน Easy------------------------------------------------------*/
		if (easy == 1) {
			SDL_RenderClear(renderer);  // เคลีย Renderer
			if (bg_count == 17) {  //  หาตำแหน่งในภาพ Sprite
				bg_count = 0;
			}
			render_animation(easy_background_texture, bg_count, 672, 378, 0, 0, 1200, 720);  //  Render Background

			if (cha_idle_on == 1 && monster_health > 0) {
				if (character_count == 11) {   //  หาตำแหน่งในภาพ Sprite
					character_count = 0;
				}
				render_animation(character_texture, character_count, 91, 113, 250, 440, 158, 187);  //  Render ตัวละคร
				character_count++;
			}

			if (easy_1 == 1) {

				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					easy_1_idle = 0;
					cha_idle_on = 0;
					easy_1 = 0;
					easy_1_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						easy_1_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 280) {  //  ขยับ Monster
						monster_position -= 10;
					}
					if (monster_position == 280) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count >= 18) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {  //  Loop ขยับตัว
					if (monster_count >= 9) {
						monster_count = 0;
					}
					render_animation(slime_texture, monster_count, 80, 80, monster_position, 490, 140 ,140);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (easy_1_idle == 1) {   //  Render หน้าจอตอนโหมด Idle
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (easy_2 == 1) {
				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					easy_2 = 0;
					easy_2_idle = 0;
					cha_idle_on = 0;
					easy_2_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					monster_move = 1;
					monster_idle = 0;
					if (fail_scene == 0) {
						easy_2_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 280) {  //  ขยับ Monster
						monster_position -= 10;
					}
					if (monster_position == 280) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_move = 0;
					}
					if (monster_move == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count == 17) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {  //  Loop ขยับตัว
					if (monster_count >= 7) {
						monster_count = 0;
					}
					render_animation(eye_texture, monster_count, 176, 176, monster_position, 440, 200, 200);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (monster_move == 1) {  //  Loop ตอนเคลื่อนที่
					if (monster_count >= 3) {
						monster_count = 0;
					}
					render_animation(eye_moving_texture, monster_count, 176, 176, monster_position, 440, 200, 200);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (easy_2_idle == 1) {   //  Render หน้าจอตอนโหมด Idle
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);  // Render health in idle mode
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (easy_3 == 1) {
				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					easy_3 = 0;
					easy_3_idle = 0;
					cha_idle_on = 0;
					easy_3_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					monster_move = 1;
					monster_idle = 0;
					if (fail_scene == 0) {
						easy_3_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 280) {  //  ขยับ Monster
						monster_position -= 10;
					}
					if (monster_position == 280) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_move = 0;
					}
					if (monster_move == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count == 10) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {  //  Loop ขยับตัว
					if (monster_count >= 11) {
						monster_count = 0;
					}
					render_animation(fire_tiger_texture, monster_count, 560, 560, monster_position, 160, 560, 560);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (monster_move == 1) {  //  Loop ขยับตัว
					if (monster_count >= 11) {
						monster_count = 0;
					}
					render_animation(fire_tiger_texture, monster_count, 560, 560, monster_position, 160, 560, 560);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (easy_3_idle == 1) {   //  Render หน้าจอตอนโหมด Idle
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);
					render_something(health_bar_bg_texture, 200, 150, 800, 80);
					render_something(health_bar_texture, 200, 150, health_bar, 80);

					// Render text
					SDL_RenderCopy(renderer, message_texture_health, NULL, &message_health_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_turn, NULL, &message_turn_ingame_rect);
					if (start_attack_on == 1) {
						SDL_RenderCopy(renderer, text_start_attack_texture, NULL, &start_attack_rect);
					}
				}
			}

			if (arrow_on == 1) {    //  เช็คว่าอยู่ในโหมดโจมตีไหม

				if (fail == 3) {  //  เช็คถ้าพลาดครบ 3 รอบ จะโจมตีทันที
					arrow_on = 0;
					character_count = 0;
					attack_on = 1;
				}

				if (time_bar <= 0) {  //  เช็คถ้าเวลาหมดจะโจมตีทันที
					arrow_on = 0;
					attack_on = 1;
					character_count = 0;
					arrow_random = 5;
				}

				if (arrow_random_on == 1) {   //  สุ่มลูกศร
					srand(time(0));
					arrow_random = rand() % 4;
					arrow_random_on = 0;
				}

				if (arrow_random_on == 0) {

					if (arrow_stop == 0) {
						time_bar -= 10;    // ลดหลอดเวลา
					}
					render_something(health_bar_bg_texture, 50, 50, 1100, 50);
					render_something(health_bar_texture, 50, 50, time_bar, 50);

					if (arrow_stop == 0) {
						switch (arrow_random)   // Render ลูกศร
						{
						case 0: SDL_RenderCopy(renderer, arrow_up_texture, NULL, &arrow); break;
						case 1: SDL_RenderCopy(renderer, arrow_down_texture, NULL, &arrow); break;
						case 2: SDL_RenderCopy(renderer, arrow_left_texture, NULL, &arrow); break;
						case 3: SDL_RenderCopy(renderer, arrow_right_texture, NULL, &arrow); break;
						default:
							break;
						}
					}
					//Render text in audition mode
					SDL_RenderCopy(renderer, message_texture_score, NULL, &message_score_ingame_rect);
					SDL_RenderCopy(renderer, message_texture_fail, NULL, &message_fail_ingame_rect);
				}

				if (character_count == 11) {  //  Loop ขยับตัว
					character_count = 0;
				}
				pos_x_cha_attack = find_position(250, 500, time_bar);
				render_animation(character_texture, character_count, 91, 113, pos_x_cha_attack, 440, 158, 187);
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite

				health_bar = health_bar_width(monster_health, max_monster_health, 80); //render monster health in audition mode
				render_something(health_bar_bg_texture, healthbar_position_x, healthbar_position_y, 80, 15);
				render_something(health_bar_texture, healthbar_position_x, healthbar_position_y, health_bar, 15);
			}

			if (easy_1_mission == 1) {  // Render easy mission 1
				render_something(easy_1_mission_texture, 0, 0, 1200, 720);
			}

			if (easy_2_mission == 1) {  // Render easy mission 2
				render_something(easy_2_mission_texture, 0, 0, 1200, 720);
			}

			if (easy_3_mission == 1) {  // Render easy mission 2
				render_something(easy_3_mission_texture, 0, 0, 1200, 720);
			}

			if (easy_1_pass == 1) {   // Render easy 1 pass
				render_something(easy_1_pass_texture, 0, 0, 1200, 720);
			}

			if (easy_2_pass == 1) {   // Render easy 2 pass
				render_something(easy_2_pass_texture, 0, 0, 1200, 720);
			}

			if (easy_3_pass == 1) {   // Render easy 2 pass
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
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			}
			bg_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			frameTime++;
			SDL_RenderPresent(renderer); // Render ภาพทั้งหมด
			delay_function(6000);  //  ตั้งดีเล
		}

		/*------------------------------------------------------Render ด่าน Medium------------------------------------------------------*/
		if (medium == 1) {
			SDL_RenderClear(renderer);  //  เคลีย Renderer
			if (bg_count == 7) {  //  Loop ขยับภาพ
				bg_count = 0;
			}
			render_animation(medium_background_texture, bg_count, 504, 336, 0, 0, 1200, 720);

			if (cha_idle_on == 1 && monster_health > 0) {
				if (character_count == 11) {
					character_count = 0;
				}
				render_animation(character_texture, character_count, 91, 113, 250, 490, 158, 187);
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			}

			if (medium_1 == 1) {

				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					medium_1_idle = 0;
					cha_idle_on = 0;
					medium_1 = 0;
					medium_1_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						medium_1_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {  //  ขยับตำแหน่ง Monster
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count >= 23) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {
						monster_count = 0;
					}
					render_animation(fire_knight_texture, monster_count, 240, 240, monster_position, 220, 500, 500);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (medium_1_idle == 1) {
					arrow_random = 5;
					health_bar = health_bar_width(monster_health, max_monster_health, 800);
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
				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					medium_2 = 0;
					medium_2_idle = 0;
					cha_idle_on = 0;
					medium_2_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						medium_2_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {  //  ขยับตำแหน่ง Monster
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count >= 22) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 12) {   //character loop
						monster_count = 0;
					}
					render_animation(fire_golem_texture, monster_count, 600, 600, monster_position, 260, 480, 480);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}


				if (medium_2_idle == 1) {
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
				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					medium_3 = 0;
					medium_3_idle = 0;
					cha_idle_on = 0;
					medium_3_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						medium_3_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 220) {  //  ขยับตำแหน่ง Monster
						monster_position -= 10;
					}
					if (monster_position == 220 && monster_idle == 1) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count == 20) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {   //character loop
						monster_count = 0;
					}
					render_animation(fire_dragon_texture, monster_count, 720, 720, monster_position, 160, 560, 560);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (medium_3_idle == 1) {
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

			if (arrow_on == 1) {

				if (fail == 3) {  //  ถ้าพลาดครบ 3 ครั้งเข้าสู่การโจมตี
					arrow_on = 0;
					character_count = 0;
					attack_on = 1;
				}

				if (time_bar <= 0) {  //  ถ้าเวลาหมด เข้าสู่การโจมตี
					arrow_on = 0;
					attack_on = 1;
					character_count = 0;
					arrow_random = 5;
				}

				if (arrow_random_on == 1) {  //  สุ่มลูกศร
					srand(time(0));
					arrow_random = rand() % 4;
					arrow_random_on = 0;
				}

				if (arrow_random_on == 0) {

					if (arrow_stop == 0) { //  ลดหลอดเวลา
						time_bar -= 11;
					}
					render_something(health_bar_bg_texture, 50, 50, 1100, 50);
					render_something(health_bar_texture, 50, 50, time_bar, 50);

					if (arrow_stop == 0) {  //  Render ลูกศรตามที่สุ่ม
						switch (arrow_random)
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

				if (character_count == 11) {   //  เปลี่ยนตำแหน่งในภาพ Sprite
					character_count = 0;
				}
				pos_x_cha_attack = find_position(250, 500, time_bar);
				render_animation(character_texture, character_count, 91, 113, pos_x_cha_attack, 490, 158, 187);
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite

				health_bar = health_bar_width(monster_health, max_monster_health, 80); //render monster health in audition mode
				render_something(health_bar_bg_texture, healthbar_position_x, healthbar_position_y, 80, 15);
				render_something(health_bar_texture, healthbar_position_x, healthbar_position_y, health_bar, 15);
			}

			if (medium_1_mission == 1) {  // Render Medium mission 1
				render_something(medium_1_mission_texture, 0, 0, 1200, 720);
			}

			if (medium_2_mission == 1) {  // Render Medium mission 2
				render_something(medium_2_mission_texture, 0, 0, 1200, 720);
			}

			if (medium_3_mission == 1) {  // Render Medium mission 3
				render_something(medium_3_mission_texture, 0, 0, 1200, 720);
			}

			if (medium_1_pass == 1) {   // Render Medium 1 pass
				render_something(medium_1_pass_texture, 0, 0, 1200, 720);
			}

			if (medium_2_pass == 1) {   // Render Medium 2 pass
				render_something(medium_2_pass_texture, 0, 0, 1200, 720);
			}

			if (medium_3_pass == 1) {   // Render Medium 3 pass
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
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			}
			bg_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			frameTime++;
			SDL_RenderPresent(renderer);  // Render ภาพทั้งหมด
			delay_function(6000);  // ดีเล
		}

		/*------------------------------------------------------Render ด่าน Hard------------------------------------------------------*/
		if (hard == 1) {
			SDL_RenderClear(renderer);  //  เคลีย Renderer
			if (bg_count == 16) {  //  Loop Render Background
				bg_count = 0;
			}
			render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);

			if (cha_idle_on == 1 && monster_health > 0) {
				if (character_count == 11) {
					character_count = 0;
				}
				render_animation(character_texture, character_count, 91, 113, 250, 490, 158, 187);
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			}

			if (hard_1 == 1) {

				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					hard_1_idle = 0;
					cha_idle_on = 0;
					hard_1 = 0;
					hard_1_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						hard_1_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {  //  ขยับตำแหน่ง Monster
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count >= 21) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {
						monster_count = 0;
					}
					render_animation(dark_hammer_texture, monster_count, 220, 220, monster_position, 220, 500, 500);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (hard_1_idle == 1) {
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
				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					hard_2 = 0;
					hard_2_idle = 0;
					cha_idle_on = 0;
					hard_2_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						hard_2_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 230) {  //  ขยับตำแหน่ง Monster
						monster_position -= 10;
					}
					if (monster_position == 230 && monster_idle == 1) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count >= 25) {
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
							monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
						}
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 11) {
						monster_count = 0;
					}
					render_animation(dark_mage_texture, monster_count, 480, 480, monster_position, 240, 480, 480);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
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
				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					hard_3 = 0;
					hard_3_idle = 0;
					cha_idle_on = 0;
					hard_3_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						hard_3_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 220) {  //  ขยับตำแหน่ง Monster
						monster_position -= 10;
					}
					if (monster_position == 220 && monster_idle == 1) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count == 20) {
							hard_3_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);
							hard_3 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						render_animation(dark_lord_attack_texture, monster_count, 200, 200, monster_position, 240, 480, 480);
						monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 13) {   //character loop
						monster_count = 0;
					}
					render_animation(dark_lord_texture, monster_count, 200, 200, monster_position, 240, 480, 480);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (hard_3_idle == 1) {
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
				if (monster_health <= 0) {   //  เช็คถ้าเลือดหมดให้เข้าสู่ pass
					hard_4 = 0;
					hard_4_idle = 0;
					cha_idle_on = 0;
					hard_4_pass = 1;
				}

				if (turn_left == 0 && monster_health > 0) {  // เช็คถ้า Turn หมด แล้วเลือด Monster ยังเหลือให้เข้าสู่ฉากโดนโจมตี
					death_on = 1;
					if (fail_scene == 0) {
						hard_4_idle = 1;
					}
					start_attack_on = 0;
				}

				if (death_on == 1) {
					if (monster_position != 220) {  //  ขยับตำแหน่ง Monster
						monster_position -= 10;
					}
					if (monster_position == 220 && monster_idle == 1) {  //  เช็คว่า Monster อยู่ในตำแหน่งที่ต้องการหรือยัง
						monster_idle = 0;
						monster_count = 0;
					}
					if (monster_idle == 0) {  //  ถ้าอยู่ตำแหน่งที่ต้องการแล้ว ให้แสดงท่าโจมตี
						if (monster_count == 27) {
							hard_4_idle = 0;
							cha_idle_on = 0;
							SDL_RenderClear(renderer);
							render_animation(hard_background_texture, bg_count, 800, 336, 0, 0, 1200, 720);
							hard_4 = 0;
							death_on = 0;
							fail_scene = 1;
						}
						render_animation(dark_knight_attack_texture, monster_count, 506, 420, monster_position, 150, 656, 570);
						monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
					}
				}

				if (monster_idle == 1) {
					if (monster_count >= 16) {   //character loop
						monster_count = 0;
					}
					render_animation(dark_knight_texture, monster_count, 506, 420, monster_position, 150, 656, 570);
					monster_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
				}

				if (hard_4_idle == 1) {
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

			if (arrow_on == 1) {    //  โหมดโจมตี

				if (fail == 3) {  //  ถ้า Fail ครบ 3 รอบจะโจมตีทันที
					arrow_on = 0;
					character_count = 0;
					attack_on = 1;
				}

				if (time_bar <= 0) {    //  ถ้าเวลาหมด โจมตีทันที
					arrow_on = 0;
					attack_on = 1;
					character_count = 0;
					arrow_random = 5;
				}

				if (arrow_random_on == 1) {   //  สุ่มลูกศร
					srand(time(0));
					arrow_random = rand() % 4;
					arrow_random_on = 0;
				}

				if (arrow_random_on == 0) {

					if (arrow_stop == 0) {  //  ลดหลอดเวลา
						time_bar -= 11;
					}
					render_something(health_bar_bg_texture, 50, 50, 1100, 50);
					render_something(health_bar_texture, 50, 50, time_bar, 50);

					if (arrow_stop == 0) {
						switch (arrow_random)   //Render ลูกศร
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

				if (character_count == 11) {
					character_count = 0;
				}
				pos_x_cha_attack = find_position(250, 500, time_bar);
				render_animation(character_texture, character_count, 91, 113, pos_x_cha_attack, 490, 158, 187);
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite

				health_bar = health_bar_width(monster_health, max_monster_health, 80); //render monster health in audition mode
				render_something(health_bar_bg_texture, healthbar_position_x, healthbar_position_y, 80, 15);
				render_something(health_bar_texture, healthbar_position_x, healthbar_position_y, health_bar, 15);
			}

			if (hard_1_mission == 1) {  // Render Hard mission 1
				render_something(hard_1_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_2_mission == 1) {  // Render Hard mission 2
				render_something(hard_2_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_3_mission == 1) {  // Render Hard mission 3
				render_something(hard_3_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_4_mission == 1) {  // Render Hard mission 4
				render_something(hard_4_mission_texture, 0, 0, 1200, 720);
			}

			if (hard_1_pass == 1) {   // Render Hard 1 pass
				render_something(hard_1_pass_texture, 0, 0, 1200, 720);
			}

			if (hard_2_pass == 1) {   // Render Hard 2 pass
				render_something(hard_2_pass_texture, 0, 0, 1200, 720);
			}

			if (hard_3_pass == 1) {   // Render Hard 3 pass
				render_something(hard_3_pass_texture, 0, 0, 1200, 720);
			}

			if (hard_4_pass == 1) {   // Render Hard 4 pass
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
				character_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			}
			bg_count++;   //  เปลี่ยนตำแหน่งในภาพ Sprite
			frameTime++;
			SDL_RenderPresent(renderer); //  Render ภาพทั้งหมด
			delay_function(6000);  // ดีเล
		}
	}
	SDL_DestroyRenderer(renderer); // ทำลายตัว Renderer
	SDL_DestroyWindow(window); // ทำลาย Window
	TTF_Quit();
	SDL_Quit();
	return 0;
}

/*------------------------------------------------------ฟังก์ชั่นอื่นๆ------------------------------------------------------*/
int render_animation(texture, count, srcrect_x, srcrect_y, pos_rect_x, pos_rect_y, rect_x, rect_y) {  // ฟังก์ชั่นในการ Render Animation ใส่ตัวแปร (Texture, ตำแหน่ง, ความกว้างดั้งเดิม, ความสูงดั้งเดิม, ตำแหน่งแกน x, ตำแหน่งแกน y, ความกว้าง, ความสูง)
	pos_x = count * srcrect_x; // คำนวณหาตำแหน่งใน Sprite
	SDL_Rect animation_rect = { pos_rect_x, pos_rect_y, rect_x, rect_y };  //  สร้างกล่องใส่รูป
	SDL_Rect animation_srcrect = { pos_x , 0, srcrect_x, srcrect_y };  // สร้างกล่องในการเอาภาพออกมาจุดๆเดียว
	SDL_RenderCopy(renderer, texture, &animation_srcrect, &animation_rect);  // RenderCopy Animation
}

int render_something(texture, pos_rect_x, pos_rect_y, rect_x, rect_y) {  // Render ภาพนิ่ง ใส่ตัวแปร (Texture, ตำแหน่งแกน x, ตำแหน่งแกน y, ความกว้าง, ความสูง)
	SDL_Rect something_rect = { pos_rect_x, pos_rect_y, rect_x, rect_y };  // สร้างกล่องใส่รูป
	SDL_RenderCopy(renderer, texture, NULL, &something_rect);  //  RenderCopy ภาพนิ่ง
}

int menu_button_render(button_texture, selector, arrow_texture) {  //  Render ลูกศรในหน้า Main Menu
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

int menu_difficulty_render(diff_texture, selector) {  //  Render ลูกศรในหน้า Difficulty
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

int delay_function(delay_diff) {  //  ฟังก์ชั่นดีเล
	int delay = delay_diff / 60 - SDL_GetTicks() + SDL_GetTicks();
	SDL_Delay(delay);
	return 0;
}

int find_position(start, stop, time) {  // คำนวณตำแหน่งตัวละครตามเวลา
	return (double)start + (double)stop * (1 - ((double)time / (double)1100));
}

int health_bar_width(monster_health, max_health, size) {  //  คำนวณหาความกว้างหลอดเลือดมอนสเตอร์
	return ((double)monster_health / max_health) * size;
}
