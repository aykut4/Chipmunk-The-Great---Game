#include "DeathScreenState.hpp"
CDeathScreenState::CDeathScreenState () : CState () {

}

CDeathScreenState::~CDeathScreenState () {

}

bool CDeathScreenState::LoadMedia ( SDL_Renderer * renderer ) {
	SDL_Surface * tempSurface = SDL_LoadBMP (m_pathWin);
	if (!tempSurface) {
		printf("loading surface failed54!\n");
		printf("SDL Error: %s\n", SDL_GetError());
		return false;
	}
	m_winningScreen = SDL_CreateTextureFromSurface ( renderer, tempSurface );
	if (!m_winningScreen) {
		printf("loading texture failed\n");
		printf("SDL Error: %s\n", SDL_GetError());
		return false;
	}
	SDL_FreeSurface (tempSurface);
	return true;
}

int CDeathScreenState::HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer , bool & isRunning) {
	this->Render(renderer);
	SDL_Delay(5000);
	return 1;
}

void CDeathScreenState::Update (void) {

}

void CDeathScreenState::Render (SDL_Renderer * renderer) {
	SDL_RenderClear ( renderer );
	SDL_RenderCopy (renderer, m_winningScreen, NULL, NULL);
	SDL_RenderPresent (renderer);
}

