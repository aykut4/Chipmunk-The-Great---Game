#ifndef _Skill.hpp_
#define _Skill.hpp_

#include "MovingObject.hpp"

const int SKILLFRAMES = 4;

class CSkill : public CMovingObject {
	private:
	//
	int m_attackPower;
	int m_skillType; // 1=greenskill 2=waterskill 3=stoneskill 4=flameskill
	SDL_Texture * m_skills [ SKILLFRAMES ];
	const char * m_pathsSkills[ SKILLFRAMES ] = {"/root/Documents/sempro/sahinayk/src/graphics/skills/skillgreen.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/skills/skillwater.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/skills/skillstone.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/skills/skillflame.bmp"};

	public:
	CSkill (SDL_Rect rect, bool direction, int wizardType);
	~CSkill ();
	bool LoadMedia ( SDL_Renderer * renderer );
//----------------------------------------------
	int HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer , bool & isRunning);
//----------------------------------------------
	void Update ( void );
//----------------------------------------------
	void Render ( SDL_Renderer * renderer );
	bool Collision (CGameObject * obj = NULL);
	void SetCurrentLevel (const int & currentLevel);
	void SetVelocity (SDL_Rect rect);
	SDL_Rect GetRect (void);
	int GetAttackPower (void);
	void SetHealth ( const int & health );
	void SetAttackPower (const int & attack);
	int GetHealth (void);
	void SetMoney (const int & money);
	int GetArmor (void);
	int GetMoney (void);
	int GetTypeZombie (void);
	int GetTypeLevel (void);
	int GetRectX (void);
	int GetRectY (void);
};
#endif /*_Skill.hpp_*/
