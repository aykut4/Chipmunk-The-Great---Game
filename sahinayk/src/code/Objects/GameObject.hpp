#ifndef _GameObject.hpp_
#define _GameObject.hpp_
//=========================================================================
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
//=========================================================================
class CGameObject {
	private:
	//
	public:
	CGameObject ();
//----------------------------------------------
	~CGameObject ();
//----------------------------------------------
	virtual bool LoadMedia (SDL_Renderer * renderer) = 0;
//----------------------------------------------
	virtual int HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer* renderer, bool & isRunning ) = 0;
//----------------------------------------------
	virtual void Update ( void ) = 0;
//----------------------------------------------
	virtual void Render ( SDL_Renderer * renderer ) = 0;
	virtual bool Collision ( CGameObject * obj = NULL ) = 0;
	virtual void SetCurrentLevel (const int & currentLevel) = 0;
	virtual void SetVelocity (SDL_Rect rect) =0;
	virtual SDL_Rect GetRect (void) = 0;
	virtual int GetAttackPower (void) = 0;
	virtual void SetHealth ( const int & health ) = 0;
	virtual void SetAttackPower (const int & attack) = 0;
	virtual int GetHealth (void) = 0;
	virtual void SetMoney (const int & money) = 0;
	virtual int GetTypeZombie (void) = 0;
	virtual int GetTypeLevel (void) = 0;
	virtual int GetArmor (void) = 0;
	virtual int GetMoney (void) = 0;
	virtual int GetRectX (void) = 0;
	virtual int GetRectY (void) = 0;
};
//=========================================================================
#endif /*_Objects/GameObject.hpp_*/
