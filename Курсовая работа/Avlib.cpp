#pragma comment(lib, "SDL2_mixer.lib")
#include <SDL.h>
#include "Avlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <SDL_image.h>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

void loadmusic(Mix_Music* fon)
{
	fon = Mix_LoadMUS("1.wav");
	Mix_PlayMusic(fon, -1);
}
void loadmusic2(Mix_Music* fon)
{
	fon = Mix_LoadMUS("3.wav");
	Mix_PlayMusic(fon, -1);
}
void Sound(Mix_Chunk* sound)
{
	sound = Mix_LoadWAV("knopka.wav");
	Mix_PlayChannel(-1, sound, 0);
}
void draw(SDL_Rect r1, SDL_Renderer* ren, SDL_Rect r2, int mas[][40], int mas2[][40], int mas3[][40], int mode, SDL_Rect r3, int game, SDL_Texture* right,
	SDL_Texture* right2, SDL_Texture* right3, SDL_Texture* right4, SDL_Texture* left, SDL_Texture* left2, SDL_Texture* left3, SDL_Texture* left4, int pov, int sp1,
	SDL_Texture* right_2, SDL_Texture* right2_2, SDL_Texture* right3_2, SDL_Texture* right4_2, SDL_Texture* left_2, SDL_Texture* left2_2, SDL_Texture* left3_2, 
	SDL_Texture* left4_2, int ps1, int pov2, SDL_Texture *stenatex, SDL_Texture *poltex)
{
	//SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);
	//SDL_RenderClear(ren);
	//SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_Rect rpol = { 0,0,800,700 };
	SDL_RenderCopy(ren, poltex, NULL, &rpol);
	switch (mode)
	{
	case 1:
	{
		for (int i = 0; i < 35; i++)
			for (int j = 0; j < 40; j++)
			{
				if (mas[i][j] == 1)
				{
					r2.x = j * 20;
					r2.y = i * 20;
					//SDL_RenderFillRect(ren, &r2);
					SDL_RenderCopy(ren, stenatex, NULL, &r2);
				}
			}
		break;
	}
	case 2:
	{
		for (int i = 0; i < 35; i++)
			for (int j = 0; j < 40; j++)
			{
				if (mas2[i][j] == 1)
				{
					r2.x = j * 20;
					r2.y = i * 20;
					SDL_RenderCopy(ren, stenatex, NULL, &r2);
				}
			}
		break;
	}
	case 3:
	{
		for (int i = 0; i < 35; i++)
			for (int j = 0; j < 40; j++)
			{
				if (mas3[i][j] == 1)
				{
					r2.x = j * 20;
					r2.y = i * 20;
					SDL_RenderCopy(ren, stenatex, NULL, &r2);
				}
			}
		break;
	}
	}
	
	switch (game)
	{
		case 1:
		{
			//SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
			//SDL_RenderFillRect(ren, &r1);
			switch (pov)
			{
			case 1:
			{
				if (sp1 == 1)
					SDL_RenderCopy(ren, right, NULL, &r1);
				else
					SDL_RenderCopy(ren, left, NULL, &r1);
				break;
			}
			case 2:
			{
				if (sp1 == 1)
					SDL_RenderCopy(ren, left4, NULL, &r1);
				else
					SDL_RenderCopy(ren, right4, NULL, &r1);
				break;
			}
			case 3:
			{
				if (sp1 == 1)
					SDL_RenderCopy(ren, right2, NULL, &r1);
				else
					SDL_RenderCopy(ren, left2, NULL, &r1);
				break;
			}
			case 4: 
			{
				if (sp1 == 1)
					SDL_RenderCopy(ren, left3, NULL, &r1);
				else
					SDL_RenderCopy(ren, right3, NULL, &r1);
				break;
			}
			}
			break;
		}
		case 2:
		{
			/*SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
			SDL_RenderFillRect(ren, &r1);
			SDL_SetRenderDrawColor(ren, 0, 255, 0, 0);
			SDL_RenderFillRect(ren, &r3);*/
			switch (pov)
			{
			case 1:
			{
				if (sp1 == 1)
				{
					SDL_RenderCopy(ren, right, NULL, &r1);
				}
				else
				{
					SDL_RenderCopy(ren, left, NULL, &r1);
				}
				break;
			}
			case 2:
			{
				if (sp1 == 1)
				{
					SDL_RenderCopy(ren, left4, NULL, &r1);
				}
				else
				{
					SDL_RenderCopy(ren, right4, NULL, &r1);
				}

				break;
			}
			case 3:
			{
				if (sp1 == 1)
				{
					SDL_RenderCopy(ren, right2, NULL, &r1);
				}

				else
				{
					SDL_RenderCopy(ren, left2, NULL, &r1);

				}
				break;
			}
			case 4:
			{
				if (sp1 == 1)
				{
					SDL_RenderCopy(ren, left3, NULL, &r1);
				}

				else
				{
					SDL_RenderCopy(ren, right3, NULL, &r1);
				}

				break;
			}
			}
			switch (pov2)
			{
			case 1:
			{
				if (ps1 == 1)
					SDL_RenderCopy(ren, right3_2, NULL, &r3);
				else
					SDL_RenderCopy(ren, left3_2, NULL, &r3);
				break;
			}
			case 2:
			{
				if (ps1 == 1)
					SDL_RenderCopy(ren, left_2, NULL, &r3);
				else
					SDL_RenderCopy(ren, right2_2, NULL, &r3);
				break;
			}
			case 3:
			{
				if (ps1 == 1)
					SDL_RenderCopy(ren, right4_2, NULL, &r3);
				else
					SDL_RenderCopy(ren, left4_2, NULL, &r3);
				break;
			}
			case 4:
			{
				if (ps1 == 1)
					SDL_RenderCopy(ren, left2_2, NULL, &r3);
				else
					SDL_RenderCopy(ren, right_2, NULL, &r3);
				break;
			}
			}
			break;
		}
		case 3:
		{
			SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
			SDL_RenderFillRect(ren, &r1);
			SDL_SetRenderDrawColor(ren, 0, 255, 0, 0);
			SDL_RenderFillRect(ren, &r3);
			break;
		}
		case 0:
			break;
	}
	SDL_RenderPresent(ren);

}
void timer()
{
	for (int i = 1; i < 11; i++)
	{
		cout << i << endl;
		SDL_Delay(1000);
	}
}
void mode_move()
{
	
}
void check(SDL_Rect r, SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
	SDL_RenderDrawRect(ren, & r);
	SDL_RenderPresent(ren);
}
void menushka(SDL_Renderer*&ren,SDL_Texture *menutex)
{
	SDL_Rect r = { 0,0,800,700 };
	SDL_RenderCopy(ren, menutex, NULL, &r);
	SDL_RenderPresent(ren);
}
void pauses (SDL_Renderer*& ren,SDL_Texture* pausetex)
{
	SDL_Rect r = { 0,0,800,700 };
	
	SDL_RenderCopy(ren, pausetex, NULL, &r);
	SDL_RenderPresent(ren);
}
void gamemode(SDL_Renderer *&ren,SDL_Texture*menu_vtex)
{
	SDL_Rect r = { 0,0,800,700 };

	SDL_RenderCopy(ren, menu_vtex, NULL, &r);
	SDL_RenderPresent(ren);
}

bool is_but_on(SDL_Rect but,int x,int y)
{
	if ((x >= but.x) && (x <= (but.x + but.w)) && (y >= but.y) && (y <= (but.y + but.h)))
		return true;
	else
		return false;
}
void ii(SDL_Rect& r, int mas[][40], int move, int h, int w, int i, int j)
{
	//int i = 0, j = 8;
	int z = 0;
	z = rand() % 4 + 1;
	switch (z)
	{
	case 1:
	{
		if (r.y >= 0)
			if (mas[i - 1][j] == 1);
			else
			{
				i--;
				r.y -= move;
			}
		break;
	}
	case 2:
	{
		if (r.x >= 0)
			if (mas[i][j - 1] == 1);
			else
			{
				j--;
				r.x -= move;
			}
		break;
	}
	case 3:
	{
		if (r.y <= h - r.h)
		if (mas[i + 1][j] == 1);
		else
		{
			i++;
			r.y += move;
		}
		break;
	}
	case 4:
	{
		if (r.x <= w - r.w)
			if (mas[i][j + 1] == 1);
			else
			{
				j++;
				r.x += move;
			}
		break;
	}
	}
	
}
void options(SDL_Renderer*ren,SDL_Texture *optex)
{
	SDL_Rect r = { 0,0,800,700 };
	SDL_RenderCopy(ren, optex, NULL, &r);
	SDL_RenderPresent(ren);
}
void drawvopros(SDL_Renderer*ren,SDL_Texture *tex)
{
	SDL_Rect r = { 100,100,600,500 };
	SDL_RenderCopy(ren, tex, NULL, &r);
	SDL_RenderPresent(ren);
}
void drawfinal(SDL_Renderer* ren, SDL_Texture* tex)
{
	SDL_Rect r = { 0,0,800,700 };
	SDL_RenderCopy(ren, tex, NULL, &r);
	SDL_RenderPresent(ren);
}
struct RECORD_WRITE
{
	char level1[3];
	char level2[3];
	char level3[3];
};
void drawrecord(SDL_Renderer* ren, SDL_Texture* tex,SDL_Texture *tex2[],RECORD_WRITE level[])
{
	SDL_Rect r = { 0,0,800,700 };
	SDL_RenderCopy(ren, tex, NULL, &r);
	SDL_Rect rir = { 159,305,50,50 };
	SDL_Rect rir2 = { 373,305,50,50 };
	SDL_Rect rir3 = { 589,305,50,50 };

	for (int i = 0; i < 3; i++)
	{
		SDL_RenderCopy(ren, tex2[i], NULL, &rir);
		rir.y += 60;
	}
	for (int i = 3; i < 6; i++)
	{
		SDL_RenderCopy(ren, tex2[i], NULL, &rir2);
		rir2.y += 60;
	}
	for (int i = 6; i < 9; i++)
	{
		SDL_RenderCopy(ren, tex2[i], NULL, &rir3);
		rir3.y += 60;
	}
	SDL_RenderPresent(ren);
}
void drawcon()
{
	SDL_Rect r = { 100,100,600,500 };
	
}
SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font)
{
	SDL_Surface* textSurface = NULL;
	SDL_Color fore_color = { 170,35,35 };
	//SDL_Color back_color = { 0,0,0 };
	textSurface = TTF_RenderText_Solid(font, text, fore_color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return texture;
}
void drawtext(SDL_Renderer *ren,SDL_Texture *texttex)
{
	SDL_Rect r = { 368,360,30,30 };
	SDL_RenderCopy(ren, texttex, NULL, &r);
	SDL_RenderPresent(ren);
}
void mein(SDL_Window* okno, SDL_Renderer* ren, int w, int h)
{
	Mix_Chunk* sound = NULL;
	Mix_Music* fon = NULL;
	SDL_Surface* menu = IMG_Load("menu1.bmp");
	SDL_SetColorKey(menu, SDL_TRUE, SDL_MapRGB(menu->format, 255, 255, 255));
	SDL_Texture* menutex = SDL_CreateTextureFromSurface(ren, menu);
	SDL_FreeSurface(menu);
	SDL_Surface* pause = IMG_Load("menu2.bmp");
	SDL_SetColorKey(pause, SDL_TRUE, SDL_MapRGB(pause->format, 255, 255, 255));
	SDL_Texture* pausetex = SDL_CreateTextureFromSurface(ren, pause);
	SDL_FreeSurface(pause);
	SDL_Surface* pause2 = IMG_Load("menu22.bmp");
	SDL_SetColorKey(pause2, SDL_TRUE, SDL_MapRGB(pause2->format, 255, 255, 255));
	SDL_Texture* pause2tex = SDL_CreateTextureFromSurface(ren, pause2);
	SDL_FreeSurface(pause2);
	SDL_Surface* menu_v = IMG_Load("menu_v.bmp");
	SDL_SetColorKey(menu_v, SDL_TRUE, SDL_MapRGB(menu_v->format, 255, 255, 255));
	SDL_Texture* menu_vtex = SDL_CreateTextureFromSurface(ren, menu_v);
	SDL_FreeSurface(menu_v);
	SDL_Surface* p1e = IMG_Load("p1e.bmp");
	SDL_SetColorKey(p1e, SDL_TRUE, SDL_MapRGB(p1e->format, 255, 255, 255));
	SDL_Texture* p1etex = SDL_CreateTextureFromSurface(ren, p1e);
	SDL_FreeSurface(p1e);
	SDL_Surface* p2e = IMG_Load("p2e.bmp");
	SDL_SetColorKey(p2e, SDL_TRUE, SDL_MapRGB(p2e->format, 255, 255, 255));
	SDL_Texture* p2etex = SDL_CreateTextureFromSurface(ren, p2e);
	SDL_FreeSurface(p2e);
	SDL_Surface* p1g = IMG_Load("p1g.bmp");
	SDL_SetColorKey(p1g, SDL_TRUE, SDL_MapRGB(p1g->format, 255, 255, 255));
	SDL_Texture* p1gtex = SDL_CreateTextureFromSurface(ren, p1g);
	SDL_FreeSurface(p1g);
	SDL_Surface* p2g = IMG_Load("p2g.bmp");
	SDL_SetColorKey(p2g, SDL_TRUE, SDL_MapRGB(p2g->format, 255, 255, 255));
	SDL_Texture* p2gtex = SDL_CreateTextureFromSurface(ren, p2g);
	SDL_FreeSurface(p2g);
	SDL_Surface* p1b = IMG_Load("p1b.bmp");
	SDL_SetColorKey(p1b, SDL_TRUE, SDL_MapRGB(p1b->format, 255, 255, 255));
	SDL_Texture* p1btex = SDL_CreateTextureFromSurface(ren, p1b);
	SDL_FreeSurface(p1b);
	SDL_Surface* p2b = IMG_Load("p2b.bmp");
	SDL_SetColorKey(p2b, SDL_TRUE, SDL_MapRGB(p2b->format, 255, 255, 255));
	SDL_Texture* p2btex = SDL_CreateTextureFromSurface(ren, p2b);
	SDL_FreeSurface(p2b);
	SDL_Surface* right = IMG_Load("r.bmp");
	SDL_SetColorKey(right, SDL_TRUE, SDL_MapRGB(right->format, 255, 255, 255));
	SDL_Texture* righttex = SDL_CreateTextureFromSurface(ren, right);
	SDL_FreeSurface(right);
	SDL_Surface* right2 = IMG_Load("r2.bmp");
	SDL_SetColorKey(right2, SDL_TRUE, SDL_MapRGB(right2->format, 255, 255, 255));
	SDL_Texture* right2tex = SDL_CreateTextureFromSurface(ren, right2);
	SDL_FreeSurface(right2);
	SDL_Surface* right3 = IMG_Load("r3.bmp");
	SDL_SetColorKey(right3, SDL_TRUE, SDL_MapRGB(right3->format, 255, 255, 255));
	SDL_Texture* right3tex = SDL_CreateTextureFromSurface(ren, right3);
	SDL_FreeSurface(right3);
	SDL_Surface* right4 = IMG_Load("r4.bmp");
	SDL_SetColorKey(right4, SDL_TRUE, SDL_MapRGB(right4->format, 255, 255, 255));
	SDL_Texture* right4tex = SDL_CreateTextureFromSurface(ren, right4);
	SDL_FreeSurface(right4);
	SDL_Surface* left = IMG_Load("l.bmp");
	SDL_SetColorKey(left, SDL_TRUE, SDL_MapRGB(left->format, 255, 255, 255));
	SDL_Texture* lefttex = SDL_CreateTextureFromSurface(ren, left);
	SDL_FreeSurface(left);
	SDL_Surface* left2 = IMG_Load("l2.bmp");
	SDL_SetColorKey(left2, SDL_TRUE, SDL_MapRGB(left2->format, 255, 255, 255));
	SDL_Texture* left2tex = SDL_CreateTextureFromSurface(ren, left2);
	SDL_FreeSurface(left2);
	SDL_Surface* left3 = IMG_Load("l3.bmp");
	SDL_SetColorKey(left3, SDL_TRUE, SDL_MapRGB(left3->format, 255, 255, 255));
	SDL_Texture* left3tex = SDL_CreateTextureFromSurface(ren, left3);
	SDL_FreeSurface(left3);
	SDL_Surface* left4 = IMG_Load("l4.bmp");
	SDL_SetColorKey(left4, SDL_TRUE, SDL_MapRGB(left4->format, 255, 255, 255));
	SDL_Texture* left4tex = SDL_CreateTextureFromSurface(ren, left4);
	SDL_FreeSurface(left4);
	SDL_Surface* op1 = IMG_Load("op1.bmp");
	SDL_SetColorKey(op1, SDL_TRUE, SDL_MapRGB(op1->format, 255, 255, 255));
	SDL_Texture* op1tex = SDL_CreateTextureFromSurface(ren, op1);
	SDL_FreeSurface(op1);
	SDL_Surface* op2 = IMG_Load("op2.bmp");
	SDL_SetColorKey(op2, SDL_TRUE, SDL_MapRGB(op2->format, 255, 255, 255));
	SDL_Texture* op2tex = SDL_CreateTextureFromSurface(ren, op2);
	SDL_FreeSurface(op2);
	SDL_Surface* con = IMG_Load("continue.bmp");
	SDL_SetColorKey(con, SDL_TRUE, SDL_MapRGB(con->format, 255, 255, 255));
	SDL_Texture* contex = SDL_CreateTextureFromSurface(ren, con);
	SDL_FreeSurface(con);
	SDL_Surface* cowleft1 = IMG_Load("cowboyl1.bmp");
	SDL_SetColorKey(cowleft1, SDL_TRUE, SDL_MapRGB(cowleft1->format, 255, 255, 255));
	SDL_Texture* cowleft1tex = SDL_CreateTextureFromSurface(ren, cowleft1);
	SDL_FreeSurface(cowleft1);
	SDL_Surface* cowleft2 = IMG_Load("cowboyl2.bmp");
	SDL_SetColorKey(cowleft2, SDL_TRUE, SDL_MapRGB(cowleft2->format, 255, 255, 255));
	SDL_Texture* cowleft2tex = SDL_CreateTextureFromSurface(ren, cowleft2);
	SDL_FreeSurface(cowleft2);
	SDL_Surface* cowleft3 = IMG_Load("cowboyl3.bmp");
	SDL_SetColorKey(cowleft3, SDL_TRUE, SDL_MapRGB(cowleft3->format, 255, 255, 255));
	SDL_Texture* cowleft3tex = SDL_CreateTextureFromSurface(ren, cowleft3);
	SDL_FreeSurface(cowleft3);
	SDL_Surface* cowleft4 = IMG_Load("cowboyl4.bmp");
	SDL_SetColorKey(cowleft4, SDL_TRUE, SDL_MapRGB(cowleft4->format, 255, 255, 255));
	SDL_Texture* cowleft4tex = SDL_CreateTextureFromSurface(ren, cowleft4);
	SDL_FreeSurface(cowleft4);
	SDL_Surface* cowright1 = IMG_Load("cowboyr1.bmp");
	SDL_SetColorKey(cowright1, SDL_TRUE, SDL_MapRGB(cowright1->format, 255, 255, 255));
	SDL_Texture* cowright1tex = SDL_CreateTextureFromSurface(ren, cowright1);
	SDL_FreeSurface(cowright1);
	SDL_Surface* cowright2 = IMG_Load("cowboyr2.bmp");
	SDL_SetColorKey(cowright2, SDL_TRUE, SDL_MapRGB(cowright2->format, 255, 255, 255));
	SDL_Texture* cowright2tex = SDL_CreateTextureFromSurface(ren, cowright2);
	SDL_FreeSurface(cowright2);
	SDL_Surface* cowright3 = IMG_Load("cowboyr3.bmp");
	SDL_SetColorKey(cowright3, SDL_TRUE, SDL_MapRGB(cowright3->format, 255, 255, 255));
	SDL_Texture* cowright3tex = SDL_CreateTextureFromSurface(ren, cowright3);
	SDL_FreeSurface(cowright3);
	SDL_Surface* cowright4 = IMG_Load("cowboyr4.bmp");
	SDL_SetColorKey(cowright4, SDL_TRUE, SDL_MapRGB(cowright4->format, 255, 255, 255));
	SDL_Texture* cowright4tex = SDL_CreateTextureFromSurface(ren, cowright4);
	SDL_FreeSurface(cowright4);
	SDL_Surface* stena = IMG_Load("stena.bmp");
	SDL_SetColorKey(stena, SDL_TRUE, SDL_MapRGB(stena->format, 255, 255, 255));
	SDL_Texture* stenatex = SDL_CreateTextureFromSurface(ren, stena);
	SDL_FreeSurface(stena);
	SDL_Surface* pol = IMG_Load("pol.bmp");
	SDL_SetColorKey(pol, SDL_TRUE, SDL_MapRGB(pol->format, 255, 255, 255));
	SDL_Texture* poltex = SDL_CreateTextureFromSurface(ren, pol);
	SDL_FreeSurface(pol);
	SDL_Surface* rec = IMG_Load("record.bmp");
	SDL_SetColorKey(rec, SDL_TRUE, SDL_MapRGB(rec->format, 255, 255, 255));
	SDL_Texture* rectex = SDL_CreateTextureFromSurface(ren, rec);
	SDL_FreeSurface(rec);
	char text[10];
	RECORD_WRITE level[3];
	int vrema = 0;
	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("arial.ttf", 100);
	SDL_Texture* texttex;
	SDL_Texture* recotext[10];
	_itoa_s(vrema, text, 10);
	texttex = get_text_texture(ren, text, my_font);
	SDL_Event event;
	bool quit = false;
	int m = 1;
	int p = 0;
	int r = 0;
	int r_f = 1;
	int game = 0;
	int mute = 0;
	int f_mus1 = 0;
	int f_mus2 = 0;
	int op = 0;
	int pov = 0;
	int pov2 = 0;
	int cont = 0;
	int final = 0;
	int record = 0;
	SDL_Rect r1 = { 160,0,20,20 };
	SDL_Rect r2 = { 0,0,20,20 };
	SDL_Rect r3 = { 160,0,20,20 };
	SDL_Rect but_ex = { 290,584,223,50 };
	SDL_Rect but_main_menu = { 290,584,223,50 };
	SDL_Rect but_start = { 290,326,223,50 };
	SDL_Rect but_single = { 290,326,223,50 };
	SDL_Rect but_options = { 290,415,223,50 };
	SDL_Rect but_records = { 290,502,223,50 };
	SDL_Rect but_wf = { 290,415,223,50 };
	SDL_Rect but_wii = { 290,502,223,50 };
	SDL_Rect but_back_to_game = { 290,326,223,50 };
	SDL_Rect but_back_to_menu = { 290,584,223,50 };
	SDL_Rect but_mute = { 290,502,223,50 };
	SDL_Rect but_save = { 290,415,223,50 };
	SDL_Rect but_mode1 = { 297,502,50,50 };
	SDL_Rect but_mode2 = { 376,502,50,50 };
	SDL_Rect but_mode3 = { 458,502,50,50 };
	SDL_Rect but_yes = { 500,420,95,120 };
	SDL_Rect but_no = { 225, 420,95,120 };
	SDL_Rect but_end = { 535,200,25,30 };
	SDL_Rect but_exit_records = { 390,540,37,52 };
	int dmove = 20;

	//SDL_Delay(3000);
	int lab[35][40] = {
		{1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,1},
		{1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1},
		{1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,1},
		{1,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,0,1,0,1,1,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1},
		{1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1},
		{1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1},
		{1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,1},
		{1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
		{1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1},
	};
	int lab2[35][40] = {
		{1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,1},
		{1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1},
		{1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1},
		{1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1},
		{1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1},
		{1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,3},
		{1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1},
		{1,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
		{1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,1,0,1,0,1},
		{1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	int lab3[35][40] = {
		{1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1},
		{1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1},
		{1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1},
		{1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1},
		{1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1},
		{1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,1,0,1},
		{1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1},
		{1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1},
		{1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},
		{1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,1},
		{1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,3,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1},
		{1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
		{1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,0,1},
		{1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1},
		{1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,0,1,1,1},
		{1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,1,0,1},
		{1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,1},
		{1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1},
		{1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1},
		{1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	int sav = 5;
	double* save = new double[sav];
	int sav2 = 5;
	double* save2 = new double[sav2];
	int sav3 = 5;
	double* save3 = new double[sav3];
	int re = 3;
	int* Re = new int[re];
	int re2 = 3;
	int* Re2 = new int[re];
	int re3 = 3;
	int* Re3 = new int[re];
	ofstream fout;
	ifstream fin;
	ifstream f2in;
	ofstream f2out;
	int k = 0, t = 8;
	int l = 0, b = 8;
	int mode = 1;
	int sp1 = 1, sp2 = 2, st = 0;
	int ps1 = 1, ps2 = 2, ts = 0;
	double gh = 0;
	f2in.open("records.txt");
	for (int i = 0; i < 3; i++)
		f2in >> Re[i];
	f2in.close();
	f2in.open("records2.txt");
	for (int i = 0; i < 3; i++)
		f2in >> Re2[i];
	f2in.close();
	f2in.open("records3.txt");
	for (int i = 0; i < 3; i++)
		f2in >> Re3[i];
	f2in.close();
	for (int i = 0; i < 3; i++)
		_itoa_s(Re[i], level[i].level1, 10);
	for (int i = 0; i < 3; i++)
		_itoa_s(Re2[i], level[i].level2, 10);
	for (int i = 0; i < 3; i++)
		_itoa_s(Re3[i], level[i].level3, 10);
	for (int i = 0; i < 3; i++)
		recotext[i] = get_text_texture(ren, level[i].level1, my_font);
	for (int i = 3; i < 6; i++)
		recotext[i] = get_text_texture(ren, level[i-3].level2, my_font);
	for (int i = 6; i < 9; i++)
		recotext[i] = get_text_texture(ren, level[i-6].level3, my_font);

	while (!quit)
	{
		//timer();
		//cout << gh << "   " << vrema << endl;
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			quit = true;
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && m == 1)
		{
			if (is_but_on(but_ex, event.button.x, event.button.y))
			{
				quit = true;
				Sound(sound);
			}
		}
		/*if (m == 0 && r == 0)
		{
			r = 1;
			gamemode(ren, menu_vtex);
		}*/
		if (m == 1 && f_mus1 == 0 && mute == 0)
		{
			f_mus1 = 1;
			f_mus2 = 0;
			loadmusic(fon);
		}
		if (m == 0 && f_mus2 == 0 && mute == 0)
		{
			f_mus2 = 1;
			f_mus1 = 0;
			loadmusic2(fon);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && r == 1 && r_f == 1)
		{
			if (is_but_on(but_single, event.button.x, event.button.y))
			{
				drawvopros(ren, contex);
				cont = 1;
				Sound(sound);
				continue;
			}
			if (is_but_on(but_wf, event.button.x, event.button.y))
			{
				game = 2;
				r = 0;
				r_f = 0;
				Sound(sound);
				//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
				//cout << "dljnd" << endl;
				continue;
			}
			if (is_but_on(but_wii, event.button.x, event.button.y))
			{
				game = 3;
				r = 0;
				r_f = 0;
				Sound(sound);
				//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
				//cout << "dljnd" << endl;
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && cont == 1)
		{
			if (is_but_on(but_no, event.button.x, event.button.y))
			{
				game = 1;
				r = 0;
				r_f = 0;
				cont = 0;
				Sound(sound);
				//SDL_DestroyTexture(contex);
			}
			if (is_but_on(but_yes, event.button.x, event.button.y) && mode == 1)
			{
				game = 1;
				r = 0;
				r_f = 0;
				cont = 0;
				fin.open("1.txt");	
				for (int i = 0; i < 5; i++)
					fin >> save[i];
				r1.x = save[1];
				r1.y = save[2];
				k = save[3];
				t = save[4];
				gh = save[0];
				fin.close();
				Sound(sound);
				//SDL_DestroyTexture(contex);
			}
			if (is_but_on(but_yes, event.button.x, event.button.y) && mode == 2)
			{
				game = 1;
				r = 0;
				r_f = 0;
				cont = 0;
				fin.open("2.txt");
				for (int i = 0; i < 5; i++)
					fin >> save2[i];
				r1.x = save2[1];
				r1.y = save2[2];
				k = save2[3];
				t = save2[4];
				gh = save2[0];
				fin.close();
				Sound(sound);
				//SDL_DestroyTexture(contex);
			}
			if (is_but_on(but_yes, event.button.x, event.button.y) && mode == 3)
			{
				game = 1;
				r = 0;
				r_f = 0;
				cont = 0;
				fin.open("3.txt");
				for (int i = 0; i < 5; i++)
					fin >> save3[i];
				r1.x = save3[1];
				r1.y = save3[2];
				k = save3[3];
				t = save3[4];
				gh = save3[0];
				fin.close();
				Sound(sound);
				//SDL_DestroyTexture(contex);
			}
			continue;
		}
		//if (game == 3)
		//	ii(r3, lab, dmove, h, w, l, b);
		//cout << r3.x << "   " << r3.y << endl;
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && p == 1 && mode == 1)
		{
			if (is_but_on(but_save, event.button.x, event.button.y))
			{
				save[0] = gh;
				save[1] = r1.x;
				save[2] = r1.y;
				save[3] = k;
				save[4] = t;
				fout.open("1.txt");
				for (int i = 0; i < 5; i++)
					fout << save[i] << endl;
				fout.close();
				Sound(sound);
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && p == 1 && mode == 2)
		{
			if (is_but_on(but_save, event.button.x, event.button.y))
			{
				save2[0] = gh;
				save2[1] = r1.x;
				save2[2] = r1.y;
				save2[3] = k;
				save2[4] = t;
				fout.open("2.txt");
				for (int i = 0; i < 5; i++)
					fout << save2[i] << endl;
				for (int i = 0; i < 5; i++)
					cout << save2[i] << endl;
				fout.close();
				Sound(sound);
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && p == 1 && mode == 3)
		{
			if (is_but_on(but_save, event.button.x, event.button.y))
			{
				save3[0] = gh;
				save3[1] = r1.x;
				save3[2] = r1.y;
				save3[3] = k;
				save3[4] = t;
				fout.open("3.txt");
				for (int i = 0; i < 5; i++)
					fout << save3[i] << endl;
				for (int i = 0; i < 5; i++)
					cout << save3[i] << endl;
				fout.close();
				Sound(sound);
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && m == 1)
		{
			if (is_but_on(but_start, event.button.x, event.button.y))
			{
				m = 0;
				Sound(sound);
				//k = 0; t = 8; r1.x = 160; r1.y = 0;
				//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
				//loadmusic2(fon);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && m == 1)
		{
			if (is_but_on(but_options, event.button.x, event.button.y))
			{
				op = 1;
				m = 0;
				Sound(sound);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && op == 1)
		{
			if (is_but_on(but_back_to_menu, event.button.x, event.button.y))
			{
				op = 0;
				m = 1;
				Sound(sound);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && op == 1 && mute == 0)
		{
			if (is_but_on(but_options, event.button.x, event.button.y))
			{
				mute = 1;
				//cout << mute << endl;
				Sound(sound);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && op == 1 && mute == 1)
		{
			if (is_but_on(but_options, event.button.x, event.button.y))
			{
				mute = 0;
				//cout << mute << endl;
				Sound(sound);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && op == 1 && record == 0)
		{
			if (is_but_on(but_records, event.button.x, event.button.y))
			{
				op = 0;
				record = 1;
				for (int i = 0; i < 3; i++)
					_itoa_s(Re[i], level[i].level1, 10);
				for (int i = 0; i < 3; i++)
					_itoa_s(Re2[i], level[i].level2, 10);
				for (int i = 0; i < 3; i++)
					_itoa_s(Re3[i], level[i].level3, 10);
				for (int i = 0; i < 3; i++)
					recotext[i] = get_text_texture(ren, level[i].level1, my_font);
				for (int i = 3; i < 6; i++)
					recotext[i] = get_text_texture(ren, level[i - 3].level2, my_font);
				for (int i = 6; i < 9; i++)
					recotext[i] = get_text_texture(ren, level[i - 6].level3, my_font);
				drawrecord(ren, rectex, recotext, level);
				for (int i = 0; i < 3; i++)
					cout << Re[i] << "  " << Re2[i] << "  " << Re3[i] << endl;
				Sound(sound);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && record == 1)
		{
			if (is_but_on(but_exit_records, event.button.x, event.button.y))
			{
				record = 0;
				op = 1;
				Sound(sound);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && m == 1)
		{
			if (is_but_on(but_mode1, event.button.x, event.button.y))
			{
				mode = 1;
				Sound(sound);
			}
			if (is_but_on(but_mode2, event.button.x, event.button.y))
			{
				mode = 2;
				Sound(sound);
			}
			if (is_but_on(but_mode3, event.button.x, event.button.y))
			{
				mode = 3;
				Sound(sound);
			}
		}
		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) && p == 1)
		{
			p = 0;
			Sound(sound);
			//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
			continue;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		{
			if (is_but_on(but_back_to_game, event.button.x, event.button.y))
			{
				p = 0;
				Sound(sound);
				//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
				continue;
			}
		}
		
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && p == 1 && mute == 0)
		{
			if (is_but_on(but_mute, event.button.x, event.button.y))
			{
				mute = 1;
				Sound(sound);
				//Mix_PauseMusic();
				pauses(ren, pause2tex);
				continue;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && p == 1 && mute == 1)
		{
			if (is_but_on(but_mute, event.button.x, event.button.y))
			{
				mute = 0;
				Sound(sound);
				//Mix_ResumeMusic();
				pauses(ren, pausetex);
				continue;
			}
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE && p == 0 )
		{
			p = 1;
			Sound(sound);
			if (mute == 1)
				pauses(ren, pause2tex);
			if (mute == 0)
				pauses(ren, pausetex);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		{
			if (is_but_on(but_back_to_menu, event.button.x, event.button.y))
			{
				p = 0;
				m = 1;
				Sound(sound);
				continue;
			}
		}
		/*if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && p == 1)
		{
			if (is_but_on(but_mute, event.button.x, event.button.y))
			{
				SDL_RenderCopy(ren, mutetex, NULL, &but_mute);
				Mix_PauseMusic();
			}
		}*/
		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP) && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r3.y >= 0)
					if (lab[l - 1][b] == 1);
					else
					{
						l--;
						r3.y -= dmove;
						pov2 = 1;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);

					}
				break;
			}
			case 2:
			{
				if (r3.y >= 0)
					if (lab2[l - 1][b] == 1);
					else
					{
						l--;
						r3.y -= dmove;
						pov2= 1;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}

				break;
			}
			case 3:
			{
				if (r3.y >= 0)
					if (lab3[l - 1][b] == 1);
					else
					{
						l--;
						r3.y -= dmove;
						pov2 = 1;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			ts = ps1;
			ps1 = ps2;
			ps2 = ts;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r3.x >= 0)
					if (lab[l][b - 1] == 1);
					else
					{
						b--;
						r3.x -= dmove;
						pov2 = 2;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 2:
			{
				if (r3.x >= 0)
					if (lab2[l][b - 1] == 1);
					else
					{
						b--;
						r3.x -= dmove;
						pov2 = 2;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 3:
			{
				if (r3.x >= 0)
					if (lab3[l][b - 1] == 1);
					else
					{
						b--;
						r3.x -= dmove;
						pov2 = 2;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			ts = ps1;
			ps1 = ps2;
			ps2 = ts;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r3.y <= h - r3.h)
					if (lab[l + 1][b] == 1);
					else
					{
						l++;
						r3.y += dmove;
						pov2 = 3;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 2:
			{
				if (r3.y <= h - r3.h)
					if (lab2[l + 1][b] == 1);
					else
					{
						l++;
						r3.y += dmove;
						pov2 = 3;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 3:
			{
				if (r3.y <= h - r3.h)
					if (lab3[l + 1][b] == 1);
					else
					{
						l++;
						r3.y += dmove;
						pov2 = 3;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			ts = ps1;
			ps1 = ps2;
			ps2 = ts;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r3.x <= w - r3.w)
					if (lab[l][b + 1] == 1);
					else
					{
						b++;
						r3.x += dmove;
						pov2 = 4;

						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 2:
			{
				if (r3.x <= w - r3.w)
					if (lab2[l][b + 1] == 1);
					else
					{
						b++;
						r3.x += dmove;
						pov2 = 4;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 3:
			{
				if (r3.x <= w - r3.w)
					if (lab3[l][b + 1] == 1);
					else
					{
						b++;
						r3.x += dmove;
						pov2 = 4;

						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			ts = ps1;
			ps1 = ps2;
			ps2 = ts;
		}
		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w) && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r1.y >= 0)
					if (lab[k - 1][t] == 1);
					else
					{
						k--;
						r1.y -= dmove;
						pov = 1;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);

					}

				break;
			}
			case 2:
			{
				if (r1.y >= 0)
					if (lab2[k - 1][t] == 1);
					else
					{
						k--;
						r1.y -= dmove;
						pov = 1;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}

				break;
			}
			case 3:
			{
				if (r1.y >= 0)
					if (lab3[k - 1][t] == 1);
					else
					{
						k--;
						r1.y -= dmove;
						pov = 1;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			st = sp1;
			sp1 = sp2;
			sp2 = st;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r1.x >= 0)
					if (lab[k][t - 1] == 1);
					else
					{
						t--;
						r1.x -= dmove;
						pov = 2;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 2:
			{
				if (r1.x >= 0)
					if (lab2[k][t - 1] == 1);
					else
					{
						t--;
						r1.x -= dmove;
						pov = 2;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 3:
			{
				if (r1.x >= 0)
					if (lab3[k][t - 1] == 1);
					else
					{
						t--;
						r1.x -= dmove;
						pov = 2;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			st = sp1;
			sp1 = sp2;
			sp2 = st;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r1.y <= h - r1.h)
					if (lab[k + 1][t] == 1);
					else
					{
						k++;
						r1.y += dmove;
						pov = 3;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 2:
			{
				if (r1.y <= h - r1.h)
					if (lab2[k + 1][t] == 1);
					else
					{
						k++;
						r1.y += dmove;
						pov = 3;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 3:
			{
				if (r1.y <= h - r1.h)
					if (lab3[k + 1][t] == 1);
					else
					{
						k++;
						r1.y += dmove;
						pov = 3;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			st = sp1;
			sp1 = sp2;
			sp2 = st;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d && p == 0)
		{
			switch (mode)
			{
			case 1:
			{
				if (r1.x <= w - r1.w)
					if (lab[k][t + 1] == 1);
					else
					{
						t++;
						r1.x += dmove;
						pov = 4;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 2:
			{
				if (r1.x <= w - r1.w)
					if (lab2[k][t + 1] == 1);
					else
					{
						t++;
						r1.x += dmove;
						pov = 4;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			case 3:
			{
				if (r1.x <= w - r1.w)
					if (lab3[k][t + 1] == 1);
					else
					{
						t++;
						r1.x += dmove;
						pov = 4;
						//draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game);
					}
				break;
			}
			}
			st = sp1;
			sp1 = sp2;
			sp2 = st;
		}
		//cout << r1.x + r1.h << "   " << r1.y + r1.h << endl;
		if ((lab[k][t] == 3 && mode == 1) || (lab2[k][t] == 3 && mode == 2) || (lab3[k][t] == 3 && mode == 3))
		{		
			final = 1;
			p = 1;
		}
		if ((lab[l][b] == 3 && mode == 1) || (lab2[l][b] == 3 && mode == 2) || (lab3[l][b] == 3 && mode == 3))
		{
			final = 2;
			p = 1;
		}
		if (final == 1)
		{
			//SDL_DestroyTexture(texttex);
			_itoa_s(vrema, text, 10);
			texttex = get_text_texture(ren, text, my_font);
			if (game == 1 && mode == 1)
			{
				if (vrema > Re[0] && vrema > Re[1] && vrema < Re[2])
					Re[2] = vrema;
				if (vrema > Re[0] && vrema < Re[1])
					Re[1] = vrema;
				if (vrema < Re[0])
					Re[0] = vrema;
			}
			if (game == 1 && mode == 2)
			{
				if (vrema > Re2[0] && vrema > Re2[1] && vrema < Re2[2])
					Re2[2] = vrema;
				if (vrema > Re2[0] && vrema < Re2[1])
					Re2[1] = vrema;
				if (vrema < Re2[0])
					Re2[0] = vrema;
			}
			if (game == 1 && mode == 3)
			{
				if (vrema > Re3[0] && vrema > Re3[1] && vrema < Re3[2])
					Re3[2] = vrema;
				if (vrema > Re3[0] && vrema < Re3[1])
					Re3[1] = vrema;
				if (vrema < Re3[0])
					Re3[0] = vrema;
			}
			if (vrema <= 20 && mode == 1)
			{
				drawfinal(ren, p1etex);
				drawtext(ren, texttex);
			}
			if (vrema > 20 && vrema <= 30 && mode == 1)
			{
				drawfinal(ren, p1gtex);
				drawtext(ren, texttex);
			}
			if (vrema > 30 && mode == 1)
			{
				drawfinal(ren, p1btex);
				drawtext(ren, texttex);
			}
			if (vrema <= 30 && mode == 2)
			{
				drawfinal(ren, p1etex);
				drawtext(ren, texttex);
			}
			if (vrema > 30 && vrema <= 40 && mode == 2)
			{
				drawfinal(ren, p1gtex);
				drawtext(ren, texttex);
			}
			if (vrema > 40 && mode == 2)
			{
				drawfinal(ren, p1btex);
				drawtext(ren, texttex);
			}
			if (vrema <= 50 && mode == 3)
			{
				drawfinal(ren, p1etex);
				drawtext(ren, texttex);
			}
			if (vrema > 50 && vrema <= 60 && mode == 3)
			{
				drawfinal(ren, p1gtex);
				drawtext(ren, texttex);
			}
			if (vrema > 60 && mode == 3)
			{
				drawfinal(ren, p1btex);
				drawtext(ren, texttex);
			}
		}
		if (final == 2)
		{
			//SDL_DestroyTexture(texttex);
			_itoa_s(vrema, text, 10);
			texttex = get_text_texture(ren, text, my_font);
			if (vrema <= 20 && mode == 1)
			{
				drawfinal(ren, p2etex);
				drawtext(ren, texttex);
			}
			if (vrema > 20 && vrema <= 30 && mode == 1)
			{
				drawfinal(ren, p2gtex);
				drawtext(ren, texttex);
			}
			if (vrema > 30 && mode == 1)
			{
				drawfinal(ren, p2btex);
				drawtext(ren, texttex);
			}
			if (vrema <= 30 && mode == 2)
			{
				drawfinal(ren, p2etex);
				drawtext(ren, texttex);
			}
			if (vrema > 30 && vrema <= 40 && mode == 2)
			{
				drawfinal(ren, p2gtex);
				drawtext(ren, texttex);
			}
			if (vrema > 40 && mode == 2)
			{
				drawfinal(ren, p2btex);
				drawtext(ren, texttex);
			}
			if (vrema <= 50 && mode == 3)
			{
				drawfinal(ren, p2etex);
				drawtext(ren, texttex);
			}
			if (vrema > 50 && vrema <= 60 && mode == 3)
			{
				drawfinal(ren, p2gtex);
				drawtext(ren, texttex);
			}
			if (vrema > 60 && mode == 3)
			{
				drawfinal(ren, p2btex);
				drawtext(ren, texttex);
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && (final == 1 || final == 2))
		{
			if (is_but_on(but_end, event.button.x, event.button.y))
			{
				p = 0;
				Sound(sound);
				final = 0;
				m = 1;
			}
		}
		if (m == 1)
		{
			menushka(ren, menutex);
			k = 0;
			t = 8;
			l = 0;
			b = 8;
			r = 0;
			gh = 0;
			vrema = 0;
			r_f = 1;
			r3.x = 160;
			r3.y = 0;
			r1.x = 160;
			r1.y = 0;
			//mode = 1;
		}
		if (m == 0 && r == 0 && r_f == 1)
		{
			gamemode(ren, menu_vtex);
			r = 1;
		}
		if (mute == 1)
			Mix_PauseMusic();
		if (mute == 0)
			Mix_ResumeMusic();
		if (op == 1)
		{
			if (mute == 0)
				options(ren, op1tex);
			if (mute == 1)
				options(ren, op2tex);
		}
		if (m == 0 && p == 0 && r == 0 && r_f == 0 && op == 0 && record == 0)
		{
			gh += 0.00045;
			vrema = gh / 1;
			draw(r1, ren, r2, lab, lab2, lab3, mode, r3, game, righttex, right2tex, right3tex, right4tex, lefttex, left2tex, left3tex, left4tex,
				pov, sp1, cowright1tex, cowright2tex, cowright3tex, cowright4tex, cowleft1tex, cowleft2tex, cowleft3tex, cowleft4tex, ps1, pov2, stenatex, poltex);
		}
		   //cout << pov << "  " << sp1 << endl;
		    //loadmusic2();

			/*check(but_single, ren);
			check(but_wf, ren);
			check(but_wii, ren);*/
			
		
		//check(but_end, ren);
		//check(but_exit_records, ren);
	}
	f2out.open("records.txt");
	for (int i = 0; i < 3; i++)
		f2out << Re[i] << endl;
	f2out.close();
	f2out.open("records2.txt");
	for (int i = 0; i < 3; i++)
		f2out << Re2[i] << endl;
	f2out.close();
	f2out.open("records3.txt");
	for (int i = 0; i < 3; i++)
		f2out << Re3[i] << endl;
	f2out.close();
	delete[] save;
	delete[] save2;
	delete[] save3;
	delete[] Re;
	delete[] Re2;
	delete[] Re3;
	SDL_DestroyTexture(menutex);
	SDL_DestroyTexture(menu_vtex);
	SDL_DestroyTexture(pausetex);
	SDL_DestroyTexture(p1etex);
	SDL_DestroyTexture(p2etex);
	SDL_DestroyTexture(p1gtex);
	SDL_DestroyTexture(p2gtex);
	SDL_DestroyTexture(p1btex);
	SDL_DestroyTexture(p2btex);
	SDL_DestroyTexture(pause2tex);
	SDL_DestroyTexture(righttex);
	SDL_DestroyTexture(right2tex);
	SDL_DestroyTexture(right3tex);
	SDL_DestroyTexture(right4tex);
	SDL_DestroyTexture(lefttex);
	SDL_DestroyTexture(left2tex);
	SDL_DestroyTexture(left3tex);
	SDL_DestroyTexture(left4tex);
	SDL_DestroyTexture(op1tex);
	SDL_DestroyTexture(op2tex);
	SDL_DestroyTexture(contex);
	SDL_DestroyTexture(cowleft1tex);
	SDL_DestroyTexture(cowleft2tex);
	SDL_DestroyTexture(cowleft3tex);
	SDL_DestroyTexture(cowleft4tex);
	SDL_DestroyTexture(cowright1tex);
	SDL_DestroyTexture(cowright2tex);
	SDL_DestroyTexture(cowright3tex);
	SDL_DestroyTexture(cowright4tex);
	SDL_DestroyTexture(texttex);
	SDL_DestroyTexture(stenatex);
	SDL_DestroyTexture(poltex);
	SDL_DestroyTexture(rectex);
	TTF_CloseFont(my_font);
	TTF_Quit();
	Mix_FreeMusic(fon);
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
	
}
	

