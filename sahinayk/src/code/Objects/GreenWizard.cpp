#include "GreenWizard.hpp"

CGreenWizard::CGreenWizard () : CMovingObject(){

	m_currentAnim = 2;

	m_health = 10;
	m_armor = 5;
	m_attackPower = 2;
	m_money = 5;
	m_wizardType = 4;
	m_currentLevel = 1;

	m_gravity = 0.1;
	m_speed = 5;
	m_velocityX = 0;
	m_velocityY = 0;

	m_indexIdle = 0;
	m_indexWalking = 0;
	m_indexJumping = 0;
	m_indexAttacking = 0;
	m_indexAttributes = 0;

	m_src.x = 0, m_src.y = 0;
	m_dest.x = 750, m_dest.y = 560;
	m_src.w = m_dest.w = 32;
	m_src.h = m_dest.h = 32;

	srcAtt.x = srcAtt.y = 0;
	destAtt.x = 50, destAtt.y = 50;
	srcAtt.w = destAtt.w = 16;
	srcAtt.h = destAtt.h = 16;

	m_isLanded = true;
	m_isFlip = false;
	m_isAttacking = false;
	m_flip = SDL_FLIP_HORIZONTAL;


	for (int i = 0; i < WALKINGFRAMES; i++) {
		m_greenWizardWalking[i] = NULL;
	}
	for (int i = 0; i < JUMPINGFRAMES; i++) {
		m_greenWizardJumping[i] = NULL;
	}
	for (int i = 0; i < IDLEFRAMES; i++) {
		m_greenWizardIdle[i] = NULL;
	}
	for (int i = 0; i < ATTACKFRAMES; i++) {
		m_greenWizardAttacking[i] = NULL;
	}
	for (int i = 0; i < ATTRIBUTEFRAMES; i++) {
		m_attributes[i] = NULL;
	}
}

CGreenWizard::CGreenWizard (int health, int armor, int attack, int money, int level, int rectwizx, int rectwizy ): CMovingObject(){

	m_currentAnim = 2;

	m_health = health;
	m_armor = armor;
	m_attackPower = attack;
	m_money = money;
	m_wizardType = 4;
	m_currentLevel = level;

	m_gravity = 0.1;
	m_speed = 5;
	m_velocityX = 0;
	m_velocityY = 0;

	m_indexIdle = 0;
	m_indexWalking = 0;
	m_indexJumping = 0;
	m_indexAttacking = 0;
	m_indexAttributes = 0;

	m_src.x = 0, m_src.y = 0;
	m_dest.x = rectwizx, m_dest.y = rectwizy;
	m_src.w = m_dest.w = 32;
	m_src.h = m_dest.h = 32;

	srcAtt.x = srcAtt.y = 0;
	destAtt.x = 50, destAtt.y = 50;
	srcAtt.w = destAtt.w = 16;
	srcAtt.h = destAtt.h = 16;

	m_isLanded = true;
	m_isFlip = false;
	m_isAttacking = false;
	m_flip = SDL_FLIP_HORIZONTAL;


	for (int i = 0; i < WALKINGFRAMES; i++) {
		m_greenWizardWalking[i] = NULL;
	}
	for (int i = 0; i < JUMPINGFRAMES; i++) {
		m_greenWizardJumping[i] = NULL;
	}
	for (int i = 0; i < IDLEFRAMES; i++) {
		m_greenWizardIdle[i] = NULL;
	}
	for (int i = 0; i < ATTACKFRAMES; i++) {
		m_greenWizardAttacking[i] = NULL;
	}
	for (int i = 0; i < ATTRIBUTEFRAMES; i++) {
		m_attributes[i] = NULL;
	}
}

CGreenWizard::~CGreenWizard () {
	for (int i = 0; i < WALKINGFRAMES; i++) {
		if (m_greenWizardWalking[i]) SDL_DestroyTexture (m_greenWizardWalking[i]);
	}
	for (int i = 0; i < JUMPINGFRAMES; i++) {
		if (m_greenWizardJumping[i]) SDL_DestroyTexture (m_greenWizardJumping[i]);
	}
	for (int i = 0; i < IDLEFRAMES; i++) {
		if (m_greenWizardIdle[i]) SDL_DestroyTexture (m_greenWizardIdle[i]);
	}
	for (int i = 0; i < ATTACKFRAMES; i++) {
		if (m_greenWizardAttacking[i]) SDL_DestroyTexture (m_greenWizardAttacking[i]);
	}
	for (int i = 0; i < ATTRIBUTEFRAMES; i++) {
		if (m_attributes[i]) SDL_DestroyTexture (m_attributes[i]);
	}
}

bool CGreenWizard::LoadMedia ( SDL_Renderer * renderer ) {
	uint32_t keyColor;
	for (int i = 0; i < WALKINGFRAMES; i++) {
		SDL_Surface * tempSurface = SDL_LoadBMP (m_pathsWalking[i]);
		keyColor = SDL_MapRGB (tempSurface->format, 0, 0, 0);
		SDL_SetColorKey (tempSurface, SDL_TRUE, keyColor);
		printf("%s\n", m_pathsWalking[i]);
		if (!tempSurface) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_greenWizardWalking[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface );
		if (!m_greenWizardWalking[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface);
	}

	for (int i = 0; i < JUMPINGFRAMES; i++) {
		SDL_Surface * tempSurface1 = SDL_LoadBMP (m_pathsJumping[i]);
		keyColor = SDL_MapRGB (tempSurface1->format, 0, 0, 0);
		SDL_SetColorKey (tempSurface1, SDL_TRUE, keyColor);
		printf("%s\n", m_pathsJumping[i]);
		if (!tempSurface1) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_greenWizardJumping[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface1 );
		if (!m_greenWizardJumping[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface1);
	}

	for (int i = 0; i < IDLEFRAMES; i++) {
		SDL_Surface * tempSurface2 = SDL_LoadBMP (m_pathsIdle[i]);
		keyColor = SDL_MapRGB (tempSurface2->format, 0, 0, 0);
		SDL_SetColorKey (tempSurface2, SDL_TRUE, keyColor);
		printf("%s\n", m_pathsIdle[i]);
		if (!tempSurface2) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_greenWizardIdle[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface2 );
		if (!m_greenWizardIdle[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface2);
	}

	for (int i = 0; i < ATTACKFRAMES; i++) {
		SDL_Surface * tempSurface3 = SDL_LoadBMP (m_pathsAttacking[i]);
		keyColor = SDL_MapRGB (tempSurface3->format, 0, 0, 0);
		SDL_SetColorKey (tempSurface3, SDL_TRUE, keyColor);
		printf("%s\n", m_pathsAttacking[i]);
		if (!tempSurface3) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_greenWizardAttacking[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface3 );
		if (!m_greenWizardAttacking[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface3);
	}
	for (int i = 0; i < ATTRIBUTEFRAMES; i++) {
		SDL_Surface * tempSurface5 = SDL_LoadBMP (m_pathsAttributes[i]);
		keyColor = SDL_MapRGB (tempSurface5->format, 0, 0, 0);
		SDL_SetColorKey (tempSurface5, SDL_TRUE, keyColor);
		printf("%s\n", m_pathsAttributes[i]);
		if (!tempSurface5) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_attributes[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface5 );
		if (!m_attributes[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface5);
	}	
	return true;
}

void CGreenWizard::Render ( SDL_Renderer * renderer ) {

	int cnt = 0;

	destAtt.x = 1180;
	destAtt.y = 50;

	SDL_RenderCopy (renderer, m_attributes[2], &srcAtt, &destAtt);
	destAtt.x = 1200;
	SDL_RenderCopy (renderer, m_attributes[4], &srcAtt, &destAtt);
	destAtt.x = 1220;
	SDL_RenderCopy (renderer, m_attributes[6], &srcAtt, &destAtt);

	destAtt.x = 50;
	destAtt.y = 50;

	for (int i = 0; i < m_health; i++) {
		SDL_RenderCopy (renderer, m_attributes[1], &srcAtt, &destAtt);
		destAtt.x += 20;
	}
	destAtt.x = 50;
	destAtt.y = 70;
	for (int i = 0; i < m_armor; i++) {
		SDL_RenderCopy (renderer, m_attributes[3], &srcAtt, &destAtt);
		destAtt.x += 20;
	}
	destAtt.x = 50;
	destAtt.y = 90;
	for (int i = 0; i < m_attackPower; i++) {
		SDL_RenderCopy (renderer, m_attributes[5], &srcAtt, &destAtt);
		destAtt.x += 20;
	}
	destAtt.x = 50;
	destAtt.y = 110;
	for (int i = 0; i < m_money; i++) {
		SDL_RenderCopy (renderer, m_attributes[0], &srcAtt, &destAtt);
		destAtt.x += 20;
		if (cnt > 50) { cnt = 0; destAtt.y += 20; destAtt.x = 50; }
		cnt++;
	}
	destAtt.x = 50;
	destAtt.y = 50;


	size_t size = m_skills.size();
	for (size_t i = 0; i < size; i++) {
		m_skills[i]->Render(renderer);
	}


	switch (m_currentAnim) {
		case 1:
			if (m_isFlip) SDL_RenderCopyEx (renderer, m_greenWizardIdle[m_indexIdle], &m_src, &m_dest, 0, NULL, m_flip);
			else SDL_RenderCopy (renderer, m_greenWizardIdle[m_indexIdle], &m_src, &m_dest);
			m_indexIdle = (SDL_GetTicks() / 150) % IDLEFRAMES;
			break;
		case 2:
			if (m_isFlip) SDL_RenderCopyEx (renderer, m_greenWizardWalking[m_indexWalking], &m_src, &m_dest, 0, NULL, m_flip);
			else SDL_RenderCopy (renderer, m_greenWizardWalking[m_indexWalking], &m_src, &m_dest);
			m_indexWalking = (SDL_GetTicks() / 100) % 6;
			break;
		case 3:
			if (m_isFlip) SDL_RenderCopyEx (renderer, m_greenWizardJumping[1], &m_src, &m_dest, 0, NULL, m_flip);
			else SDL_RenderCopy (renderer, m_greenWizardJumping[1], &m_src, &m_dest);
			break;
		case 4:
			if (m_isFlip) SDL_RenderCopyEx (renderer, m_greenWizardJumping[2], &m_src, &m_dest, 0, NULL, m_flip);
			else SDL_RenderCopy (renderer, m_greenWizardJumping[2], &m_src, &m_dest);
			break;
		case 5:
			if (m_isFlip) SDL_RenderCopyEx (renderer, m_greenWizardAttacking[1], &m_src, &m_dest, 0, NULL, m_flip);
			else SDL_RenderCopy (renderer, m_greenWizardAttacking[1], &m_src, &m_dest);
			break;
		default: break;
	}
}

int CGreenWizard::HandleEvents (bool & ispread, SDL_Event & m_event,  bool & isGameSaved, SDL_Renderer * renderer, bool & isRunning ) {
	while (SDL_PollEvent (&m_event) != 0) {
		if ( m_event.type == SDL_QUIT ) {isRunning = false; break;}
		if ( m_event.type == SDL_KEYDOWN ) {
			switch ( m_event.key.keysym.sym ) {
				case SDLK_KP_1:if (m_money >= 2) {m_money -= 2; m_health += 1;} return 2;
				case SDLK_KP_2:if (m_money >= 1) {m_money -= 1; m_armor += 1; }return 2;
				case SDLK_KP_3:if (m_money >= 5) {m_money -= 5; m_attackPower += 1;} return 2;
				case SDLK_w: if (m_isLanded) {m_currentAnim = 3;m_velocityY = -3;} return 2;
				case SDLK_a: m_velocityX = -1; m_isFlip = true; if (m_isLanded) { m_currentAnim = 2;}  return 2;
				case SDLK_d: m_velocityX =  1; m_isFlip = false; if (m_isLanded) { m_currentAnim = 2;} return 2;
				case SDLK_n: this->Attack(renderer); m_isAttacking = true; m_currentAnim = 5; return 2;
				case SDLK_p: ispread = true; return 2;
				default	   : return 2;
			}
		}
		if ( m_event.type == SDL_KEYUP ) {
			switch ( m_event.key.keysym.sym ) {
				case SDLK_w: m_currentAnim = 4; return 2;
				case SDLK_a: m_velocityX = 0;	m_currentAnim = 1; return 2;
				case SDLK_d: m_velocityX = 0; 	m_currentAnim = 1; return 2;
				case SDLK_n: m_currentAnim = 1; return 2;
				default    : return 2;
			}
		}
	}
	return 2;
}

void CGreenWizard::Update ( void ) {

	size_t size = m_skills.size();
	for (size_t i = 0; i < size; i++) {
		m_skills[i]->SetAttackPower(m_attackPower);
	}

	//this->Collision();
	m_dest.x += m_speed * m_velocityX;
	m_dest.y += m_speed * m_velocityY;

	if (m_dest.y >= 555) { m_dest.y = 555; m_isLanded = true;}
	else m_isLanded = false;

	if (!m_isLanded) {m_velocityY += m_gravity;}

}

bool CGreenWizard::Collision ( CGameObject * obj ) {

	//skill collision
	size_t size = m_skills.size();
	for (size_t i = 0; i < size; i++ ) {
		m_skills[i]->Update();
		if (m_skills[i]->Collision(obj) ) {
			if (m_skills[i]) delete m_skills[i];
			m_skills.erase (m_skills.begin() + i);
			size--;
		}
	}

	// zombie collision
	if (obj) {
	if ( m_dest.x <= obj->GetRect().x + obj->GetRect().w && m_dest.x + m_dest.w >= obj->GetRect().x && m_dest.y + m_dest.h >= obj->GetRect().y) {

		if (m_dest.x < obj->GetRect().x) { m_dest.x -= 5; m_velocityX = -2; }
		else if (m_dest.x + m_dest.w > obj->GetRect().x + obj->GetRect().w) {m_dest.x += 5; m_velocityX = 2;}
		else m_dest.y -= 5;
		m_velocityY = -2;
		if (m_armor > 0) {
			m_armor -= obj->GetAttackPower();
		}
		else m_health -= obj->GetAttackPower();
	}
	}


	if (m_currentLevel == 1) {
		if (m_dest.x >= 192 && m_dest.x <= 336 && m_dest.y >= 555 ){ m_velocityY = -1; m_health -=1; }
		if (m_dest.x >= 576 && m_dest.x <= 752 && m_dest.y >= 555) {m_speed = 1;}
		else m_speed = 5;
	}
	else if (m_currentLevel == 2) {
		if (m_dest.x  >= 12*16 && m_dest.x <= 12*16 + 10*16 && m_dest.y >= 555) {m_velocityY = -1; m_health -= 1;}
		else if (m_dest.x >= 54*16 && m_dest.x <= 64 *16 && m_dest.y >= 555) {m_velocityY = -1; m_health -= 1;}
		else {}

		if (m_dest.x >= 25 *16 && m_dest.x <= 51*16 && m_dest.y >= 555) {m_speed = 1;}
		else m_speed = 5;
	}
	else if (m_currentLevel == 3) {

		if (m_dest.x >= 0 && m_dest.x <= 11*16 && m_dest.y >= 555) {m_velocityY = -1; m_health -= 1;}
		else if (m_dest.x >= 67*16 && m_dest.x <= 80*16 && m_dest.y >= 555) {m_velocityY = -1; m_health -= 1;}
		else if (m_dest.x >= 32*16 && m_dest.x <= 42*16 && m_dest.y >= 555) {m_velocityY = -1; m_health -= 1;}
		else {}


		if (m_dest.x >= 16 *16 && m_dest.x <= 24*16 && m_dest.y >= 555) {m_speed = 1;}
		else if (m_dest.x >= 50*16 && m_dest.x <= 58*16 && m_dest.y >= 555) {m_speed = 1;}
		else m_speed = 5;
		
	}
	else {}


	if (m_dest.x <= 0) { m_dest.x = 0; return true; }
	else if (m_dest.x >= 1248) { m_dest.x = 1248; return true; }
	else return false;
}

void CGreenWizard::Attack (SDL_Renderer * renderer) {
	CMovingObject * newSkill = new CSkill (m_dest, m_isFlip, m_wizardType);
	newSkill->LoadMedia (renderer);
	m_skills.push_back (newSkill);
	
}

void CGreenWizard::SetCurrentLevel (const int & currentLevel) {
	m_currentLevel = currentLevel;
}

void CGreenWizard::SetVelocity (SDL_Rect rect) {

}

SDL_Rect CGreenWizard::GetRect (void) {
	return m_dest;
}
int CGreenWizard::GetAttackPower (void) {
	return m_attackPower;
}
void CGreenWizard::SetHealth (const int & health) {
	m_health = health;
} 

void CGreenWizard::SetAttackPower (const int & attack) {
	m_attackPower = attack;
}
int CGreenWizard::GetHealth (void) {
	return m_health;
}
void CGreenWizard::SetMoney (const int & money) {
	m_money += money;
}
int CGreenWizard::GetArmor (void) {
	return m_armor;
}
int CGreenWizard::GetMoney (void) {
	return m_money;
}
int CGreenWizard::GetTypeZombie (void) {}
int CGreenWizard::GetTypeLevel (void) {
	return m_currentLevel;
}

int CGreenWizard::GetRectX (void) {
	return m_dest.x;
}
int CGreenWizard::GetRectY (void) {
	return m_dest.y;
}

