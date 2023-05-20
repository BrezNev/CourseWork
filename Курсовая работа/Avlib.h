#pragma once
void draw(SDL_Rect r1, SDL_Renderer* ren, SDL_Rect r2, int mas[][40], int mas2[][40], int mas3[][40], int mode, SDL_Rect r3, int game, SDL_Texture* right,
	SDL_Texture* right2, SDL_Texture* right3, SDL_Texture* right4, SDL_Texture* left, SDL_Texture* left2, SDL_Texture* left3, SDL_Texture* left4, int pov, int sp1,
	SDL_Texture* right_2, SDL_Texture* right2_2, SDL_Texture* right3_2, SDL_Texture* right4_2, SDL_Texture* left_2, SDL_Texture* left2_2, SDL_Texture* left3_2,
	SDL_Texture* left4_2, int ps1, int pov2, SDL_Texture* stenatex, SDL_Texture *poltex);
void menushka(SDL_Renderer*& ren, SDL_Texture* menutex);
bool is_but_on(SDL_Rect but, int x, int y);
void pauses(SDL_Renderer*& ren, SDL_Texture* pausetex);
void check(SDL_Rect r, SDL_Renderer* ren);
void timer();
void gamemode(SDL_Renderer*& ren, SDL_Texture* menu_vtex);
void mein(SDL_Window* okno, SDL_Renderer* ren, int w, int h);
void ii(SDL_Rect& r, int mas[][40], int move, int h, int w, int i, int j);
void drawvopros(SDL_Renderer* ren, SDL_Texture* tex);
void drawfinal(SDL_Renderer* ren, SDL_Texture* tex);
void drawtext(SDL_Renderer* ren, SDL_Texture* texttex);
void drawrecord(SDL_Renderer* ren, SDL_Texture* tex);

/*void loadmusic(Mix_Music* fon);
void loadmusic2(Mix_Music* fon);
void Sound(Mix_Chunk* sound);*/