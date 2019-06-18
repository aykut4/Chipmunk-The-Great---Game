#ifndef _States/State.hpp_
#define _States/State.hpp_
//=========================================================================
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
//=========================================================================
class CState {
	private:
	//
//----------------------------------------------
	public:
	CState ();
//----------------------------------------------
	~CState ();
//----------------------------------------------
	virtual bool LoadMedia ( SDL_Renderer * renderer ) = 0;
//----------------------------------------------
	virtual int HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer , bool & isRunning ) = 0;
//----------------------------------------------
	virtual void Update ( void ) = 0;
//----------------------------------------------
	virtual void Render ( SDL_Renderer * renderer ) = 0;
};
//=========================================================================
#endif /*_State.hpp_*/
