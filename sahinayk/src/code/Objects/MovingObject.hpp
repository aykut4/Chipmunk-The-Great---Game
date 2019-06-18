#ifndef _MovingObject.hpp_
#define _MovingObject.hpp_
//=========================================================================
#include <bits/stdc++.h>
#include "GameObject.hpp"
//=========================================================================
class CMovingObject : public CGameObject {
	protected:
	//
	SDL_RendererFlip m_flip;
	//SDL_Event m_event;
	SDL_Rect m_src, m_dest;
	int m_speed;
	double m_gravity;
	double m_velocityX;
	double m_velocityY;
	bool m_isFlip;
	bool m_isLanded;

	public:
//----------------------------------------------
	CMovingObject ();
//----------------------------------------------
	~CMovingObject ();
//----------------------------------------------
	virtual bool LoadMedia (SDL_Renderer * renderer) = 0;
//----------------------------------------------
	virtual int HandleEvents (bool & ispread, SDL_Event & m_event,  bool & isGameSaved, SDL_Renderer * renderer , bool & isRunning ) = 0;
//----------------------------------------------
	virtual void Update ( void ) = 0;
//----------------------------------------------
	virtual void Render ( SDL_Renderer * renderer ) = 0;
//----------------------------------------------
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
#endif /*_Objects/MovingObject.hpp_*/
