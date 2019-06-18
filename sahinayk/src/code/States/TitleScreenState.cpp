#include "TitleScreenState.hpp"
//=========================================================================
CTitleScreenState::CTitleScreenState () : CState() {
	indexTexture = 0;
	pressedKey = KEY_DEFAULT;
	for (int i = 0; i < TITLESCREENFRAMES; i++) {
		titleScreens[i] = NULL;
	}
}
//=========================================================================
CTitleScreenState::~CTitleScreenState () {
	for (int i = 0; i < TITLESCREENFRAMES; i++) {
		if (titleScreens[i]) SDL_DestroyTexture ( titleScreens[i] );
	}
}
//=========================================================================
bool CTitleScreenState::LoadMedia ( SDL_Renderer * renderer) {
	for (int i = 0; i < TITLESCREENFRAMES; i++) {
		SDL_Surface * tempSurface = NULL;
		printf("%s\n", paths[i]);
		tempSurface = SDL_LoadBMP (paths[i]);
		if (!tempSurface) {
			printf("loading surface failed!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		titleScreens[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface );
		if (!titleScreens[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface ( tempSurface );
	}
	return true;
}
//=========================================================================
int CTitleScreenState::HandleEvents (bool & ispread, SDL_Event & m_event,  bool & isGameSaved, SDL_Renderer * renderer, bool & isRunning ) {
	SDL_Event e;
	while (SDL_PollEvent (&e) != 0) {
		if ( e.type == SDL_QUIT ) {isRunning = false; break;}


		if ( e.type == SDL_KEYDOWN ) {
			switch ( e.key.keysym.sym ) {
				case SDLK_UP  	: pressedKey = KEY_UP;    return 1;
				case SDLK_DOWN	: pressedKey = KEY_DOWN;  return 1;
				case SDLK_RETURN: if ( indexTexture == 1 ) isGameSaved = false;
						  else if (indexTexture == 2) {
							isGameSaved = true;
						  }
						  return 2;
				default	      	: return 1;
			}
		}
	}
	return 1;
}
//=========================================================================
void CTitleScreenState::Update ( void ) {
	indexTexture += pressedKey;
	pressedKey = KEY_DEFAULT;
	if (indexTexture < 0) indexTexture = 0;
	if (indexTexture > 2) indexTexture = 2;
}
//=========================================================================
void CTitleScreenState::Render ( SDL_Renderer * renderer ) {
	SDL_RenderClear ( renderer );
	SDL_RenderCopy (renderer, titleScreens[indexTexture], NULL, NULL);
	SDL_RenderPresent (renderer);
}
//=========================================================================

