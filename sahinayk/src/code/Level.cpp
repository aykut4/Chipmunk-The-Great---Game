#include "Level.hpp"
//=========================================================================
//=========================================================================
CLevel::CLevel () {

	m_indexBackground = 0;
	m_indexWater = 0;
	m_indexLava = 0;

	m_currentLevel = 1;

	m_src.x = m_src.y = 0;
	m_dest.x = m_dest.y = 0;
	m_src.w = m_dest.w = 16;
	m_src.h = m_dest.h = 16;

	m_grass = NULL;
	m_dirt = NULL;

	for (int i = 0; i < BACKGROUNDSFRAMES; i++) {
		m_background[i] = NULL;
	}
	for (int i = 0; i < WATERFRAMES; i++) {
		m_water[i] = NULL;
	}
	for (int i = 0; i < LAVAFRAMES; i++) {
		m_lava[i] = NULL;
	}
}
//=========================================================================
CLevel::~CLevel () {
	if (m_grass) SDL_DestroyTexture(m_grass);
	if (m_dirt) SDL_DestroyTexture (m_dirt);
	for (int i = 0; i < BACKGROUNDSFRAMES; i++) {
		if(m_background[i]) SDL_DestroyTexture (m_background[i]);
	}
	for (int i = 0; i < WATERFRAMES; i++) {
		if (m_water[i]) SDL_DestroyTexture (m_water[i]);
	}
	for (int i = 0; i < LAVAFRAMES; i++) {
		if (m_lava[i]) SDL_DestroyTexture (m_lava[i]);
	}
}
//=========================================================================
void CLevel::LevelManager (SDL_Renderer * renderer) {
	switch (m_currentLevel) {
		case 1:
			m_indexBackground = 0;
			DrawLevel (renderer, m_levelDesign1);
			break;
		case 2:
			m_indexBackground = 1;
			DrawLevel (renderer, m_levelDesign2);
			break;
		case 3:
			m_indexBackground = 2;
			DrawLevel (renderer, m_levelDesign3);
			break;
		default:	
			break;
	}
}
//=========================================================================
bool CLevel::LoadMedia (SDL_Renderer * renderer) {
	for (int i = 0; i < 3; i++) {
		SDL_Surface * tempSurface = SDL_LoadBMP (m_pathsBackground[i]);
		printf("%s\n", m_pathsBackground[i]);
		if (!tempSurface) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_background[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface );
		if (!m_background[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface);
	}
	for (int i = 0; i < 6; i++) {
		SDL_Surface * tempSurface1 = SDL_LoadBMP (m_pathsWater[i]);
		if (!tempSurface1) {
			printf("loading surface failed!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_water[i] = SDL_CreateTextureFromSurface (renderer, tempSurface1);
		if (!m_water[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface1);
	}
	for (int i = 0; i < 10; i++) {
		SDL_Surface * tempSurface2 = SDL_LoadBMP (m_pathsLava[i]);
		if (!tempSurface2) {
			printf("loading surface failed!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_lava[i] = SDL_CreateTextureFromSurface (renderer, tempSurface2);
		if (!m_lava[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface2);
	}
	SDL_Surface * tempSurface3 = SDL_LoadBMP (m_pathGrass);
	if (!tempSurface3) {
			printf("loading surface failed!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
	m_grass = SDL_CreateTextureFromSurface (renderer, tempSurface3);
	if (!m_grass) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
	SDL_FreeSurface (tempSurface3);
	SDL_Surface * tempSurface4 = SDL_LoadBMP (m_pathDirt);
	if (!tempSurface4) {
			printf("loading surface failed!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
	m_dirt = SDL_CreateTextureFromSurface (renderer, tempSurface4);
	if (!m_dirt) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
	SDL_FreeSurface (tempSurface4);
	return true;
}
//=========================================================================
//=========================================================================
void CLevel::DrawLevel (SDL_Renderer * renderer, int arr[45][80]) {
	
	SDL_RenderCopy (renderer, m_background[m_indexBackground], NULL, NULL);
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 80; j++) {
			m_dest.x = j * 16;
			m_dest.y = i * 16;
			if (arr[i][j] == 1) {SDL_RenderCopy (renderer, m_grass, &m_src, &m_dest);}
			else if (arr[i][j] == 2) {SDL_RenderCopy (renderer, m_dirt, &m_src, &m_dest);}
			else if (arr[i][j] == 3) {SDL_RenderCopy (renderer, m_water[m_indexWater], &m_src, &m_dest); m_indexWater = (SDL_GetTicks() / 100) % 6;}
			else if (arr[i][j] == 4) {SDL_RenderCopy (renderer, m_lava[m_indexLava], &m_src, &m_dest); m_indexLava = (SDL_GetTicks() / 100) % 10;}
			else {}
		}
	}
}

void CLevel::SetCurrentLevel (const int & currentLevel) {
	m_currentLevel = currentLevel;
}
