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

int main(int argc, char** argv)
{
	const int w = 800;
	const int h = 700;
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	SDL_Window* okno = SDL_CreateWindow("Averchenkov_TW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	SDL_Renderer* ren = SDL_CreateRenderer(okno, -1, 0);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Ошибка запуска!" << endl;
		SDL_GetError();
	}
	else
	{
		if (okno == NULL)
		{
			cout << "Окно не открыто!" << endl;
			SDL_GetError();
		}
		else
		{
			mein(okno, ren, w, h);  //основная функция
			SDL_DestroyRenderer(ren);
			SDL_DestroyWindow(okno);
			SDL_Quit();
		}
	}
	return 0;
}