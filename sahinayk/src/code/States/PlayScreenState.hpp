#ifndef _PlayScreenState.hpp_
#define _PlayScreenState.hpp_
//=========================================================================
#include <bits/stdc++.h>
#include "State.hpp"
#include "../Objects/GameObject.hpp"
#include "../Objects/MovingObject.hpp"
#include "../Objects/GreenWizard.hpp"
#include "../Objects/Zombie.hpp"
#include "../Level.hpp"
#include "../SaveGame.hpp"
//=========================================================================
const int OBJECTCOUNT = 2;
//=========================================================================
class CPlayScreenState : public CState {
	private:
	//
	CGameObject * m_gameObject[OBJECTCOUNT];
	CLevel * m_level;
	int m_currentLevel;
	int m_counterLevel;
	
//----------------------------------------------
	public:
	CPlayScreenState ();
	CPlayScreenState (int healthwiz, int armorwiz, int attackwiz, int moneywiz, int rectwizx, int rectwizy, int healthzom, int typezom, int rectzomx, int rectzomy, int typelevel );
//----------------------------------------------
	~CPlayScreenState ();
//----------------------------------------------
	bool LoadMedia ( SDL_Renderer * renderer );
//----------------------------------------------
	int HandleEvents ( bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer , bool & isRunning );
//----------------------------------------------
	void Update ( void );
//----------------------------------------------
	void Render ( SDL_Renderer * renderer );
	//bool Collision (void);
};
//=========================================================================
#endif /*_PlayScreenState.hpp*/

/*
Add the class moving object and derive another class for the wizard from it and load its textures there then render it in its own class method
*/
