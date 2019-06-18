#ifndef _Zombie.hpp_
#define _Zombie.hpp_
//=========================================================================
#include "MovingObject.hpp"
//=========================================================================
const int ZOMBIEFRAMES = 3;
//=========================================================================
class CZombie : public CMovingObject {
	private:
	//
	int m_health;
	int m_attackPower;
	int m_zombieType; // 1=greenskill 2=waterskill 3=stoneskill
	int m_currentLevel;


	SDL_Texture * m_zombie [ZOMBIEFRAMES];
	const char * m_pathsZombie [ZOMBIEFRAMES] = {"/root/Documents/sempro/sahinayk/src/graphics/enemies/zombie1.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/enemies/zombie2.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/enemies/zombie3.bmp"};


	public:
	CZombie ();
	CZombie (int health, int type, int level, int rectzomx, int rectzomy);
//----------------------------------------------
	~CZombie();
//----------------------------------------------
	bool LoadMedia ( SDL_Renderer * renderer );
//----------------------------------------------
	int HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer, bool & isRunning );
//----------------------------------------------
	void Update ( void );
//----------------------------------------------
	void Render ( SDL_Renderer * renderer );
//----------------------------------------------
	bool Collision ( CGameObject * obj = NULL );
//----------------------------------------------
	void SetCurrentLevel (const int & currentLevel);
//----------------------------------------------
	void SetVelocity (SDL_Rect rect);
//----------------------------------------------
	SDL_Rect GetRect (void);
//----------------------------------------------
	int GetAttackPower (void);
//----------------------------------------------
	void SetHealth ( const int & health );
//----------------------------------------------
	int GetHealth (void);
//----------------------------------------------
	void SetAttackPower (const int & attack);
//----------------------------------------------
	void SetMoney (const int & money);
	int GetTypeZombie (void);
	int GetTypeLevel (void);
	int GetArmor (void);
	int GetMoney (void);
	int GetRectX (void);
	int GetRectY (void);
	
//----------------------------------------------
};
//=========================================================================
#endif /*_Zombie.hpp_*/
