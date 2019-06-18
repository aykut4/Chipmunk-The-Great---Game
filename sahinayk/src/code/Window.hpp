#ifndef _Window.hpp_
#define _Window.hpp
//=========================================================================
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
//=========================================================================
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
//=========================================================================
class CWindow {
	private:
	SDL_Renderer * m_renderer;
	SDL_Window * m_window;
	SDL_Surface * m_screenSurface;
//----------------------------------------------
	public:
	CWindow ();
//----------------------------------------------
	~CWindow ();
//----------------------------------------------
	bool InitializeWindow ( const char * title = "default",
				const int & xpos = SDL_WINDOWPOS_CENTERED,
				const int & ypos = SDL_WINDOWPOS_CENTERED,
				const int & width = SCREEN_WIDTH,
				const int & height = SCREEN_HEIGHT,
				const int & fullscreen = SDL_WINDOW_SHOWN );
//----------------------------------------------
	bool CreateRenderer ( const int & num = -1,
			      const int & renderopt = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
//----------------------------------------------
	bool LoadImage ( void );
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
	void DestroyWindow ( void );
	void DestroyRenderer ( void );
//----------------------------------------------
	SDL_Window* GetWindow ( void );
	SDL_Renderer * GetRenderer ( void );
};
//=========================================================================
#endif /*_Window.hpp_*/
