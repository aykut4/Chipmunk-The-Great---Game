#ifndef _GreenWizard.hpp_
#define _GreenWizard.hpp_
//=========================================================================
#include "MovingObject.hpp"
#include "Skill.hpp"
//=========================================================================
const int WALKINGFRAMES = 9;
const int JUMPINGFRAMES = 3;
const int IDLEFRAMES = 2;
const int ATTACKFRAMES = 2;
const int ATTRIBUTEFRAMES = 7;
//=========================================================================
class CGreenWizard : public CMovingObject {
	private:
	//
	std::vector<CMovingObject*> m_skills;
	int m_health;
	int m_armor;
	int m_attackPower;
	int m_money;
	int m_wizardType; // 1=greenskill 2=waterskill 3=stoneskill 4=flameskill

	int m_currentLevel;
	int m_currentAnim; // 1 = idle, 2 = walking, 3 = jumping in the air, 4 = falling, 5 = attacking

	bool m_isAttacking;

	SDL_Rect srcAtt, destAtt;

	SDL_Texture * m_greenWizardWalking[WALKINGFRAMES];
	const char * m_pathsWalking [WALKINGFRAMES] = {"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking1.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking2.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking3.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking4.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking5.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking6.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking7.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking8.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardwalking/greenwizardwalking9.bmp"};
	int m_indexWalking;

	SDL_Texture * m_greenWizardJumping[JUMPINGFRAMES];
	const char * m_pathsJumping [JUMPINGFRAMES] = {"/root/Documents/sempro/sahinayk/src/graphics/greenwizardjumping/greenwizardjump1.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardjumping/greenwizardjump2.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardjumping/greenwizardjump3.bmp",};
	int m_indexJumping;

	SDL_Texture * m_greenWizardIdle[IDLEFRAMES];
	const char * m_pathsIdle [IDLEFRAMES] = {"/root/Documents/sempro/sahinayk/src/graphics/greenwizardidle/greenwizardidle1.bmp",
						"/root/Documents/sempro/sahinayk/src/graphics/greenwizardidle/greenwizardidle2.bmp"};
	int m_indexIdle;

	SDL_Texture * m_greenWizardAttacking[ATTACKFRAMES];
	const char * m_pathsAttacking [ATTACKFRAMES] = {"/root/Documents/sempro/sahinayk/src/graphics/greenwizardattacking/greenwizardattack1.bmp",
							"/root/Documents/sempro/sahinayk/src/graphics/greenwizardattacking/greenwizardattack2.bmp"};
	int m_indexAttacking;
	
	SDL_Texture * m_attributes [ ATTRIBUTEFRAMES ];
	const char * m_pathsAttributes[ ATTRIBUTEFRAMES ] = {"/root/Documents/sempro/sahinayk/src/graphics/attributes/gold.bmp",
								"/root/Documents/sempro/sahinayk/src/graphics/attributes/heart1.bmp",
								"/root/Documents/sempro/sahinayk/src/graphics/attributes/heart2.bmp",
								"/root/Documents/sempro/sahinayk/src/graphics/attributes/shield1.bmp",
								"/root/Documents/sempro/sahinayk/src/graphics/attributes/shield2.bmp",
								"/root/Documents/sempro/sahinayk/src/graphics/attributes/sword1.bmp",
								"/root/Documents/sempro/sahinayk/src/graphics/attributes/sword2.bmp"};
	int m_indexAttributes;

	public:
	CGreenWizard ();
	CGreenWizard (int health, int armor, int attack, int money, int level, int rectwizx, int rectwizy);
//----------------------------------------------
	~CGreenWizard ();
//----------------------------------------------
	bool LoadMedia ( SDL_Renderer * renderer );
//----------------------------------------------
	int HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer, bool & isRunning );
//----------------------------------------------
	void Update ( void );
//----------------------------------------------
	void Render ( SDL_Renderer * renderer );
	void Attack (SDL_Renderer * renderer );
	bool Collision ( CGameObject * obj = NULL );
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
//=========================================================================
#endif /*_Objects/GreenWizard.hpp_*/
