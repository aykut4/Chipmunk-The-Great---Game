#ifndef _StateMachine.hpp_
#define _StateMachine.hpp_
//=========================================================================
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include "States/State.hpp"
#include "States/TitleScreenState.hpp"
#include "States/PlayScreenState.hpp"
#include "States/DeathScreenState.hpp"
#include "SaveGame.hpp"

//=========================================================================
class CStateMachine {
	private:
	SDL_Event m_event;
	SDL_Window * m_windowSM;
	SDL_Renderer * m_rendererSM;
	CState * m_currentState;
	int m_currentStateNumber; // 1 titlescreen, 2 playscreen, 3 deathscreen
	bool m_running;
	bool m_isGameSaved;
	bool ispread;
//----------------------------------------------
	public:
	CStateMachine ();
//----------------------------------------------
	~CStateMachine ();
//----------------------------------------------
	void SetWindow ( SDL_Window * window );
//----------------------------------------------
	void SetRenderer ( SDL_Renderer * renderer );
//----------------------------------------------
	bool GetBool ( void );
//----------------------------------------------
	bool ChangeState ( const int & stateCode );
//----------------------------------------------
	void HandleEvents ( void );
//----------------------------------------------
	void Update ( void );
//----------------------------------------------
	void Render ( void );
	//bool Collision (void);
};
//=========================================================================
#endif /*_StateMachine.hpp */

//	State Codes for individual states are:
//		TitleScreenState = 1;
//		PlayScreenState = 2;
//		DeathScreenState = 3;
//
