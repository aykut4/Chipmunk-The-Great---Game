#include "Skill.hpp"

CSkill::CSkill ( SDL_Rect rect, bool direction, int wizardType) : CMovingObject () {

	m_skillType = wizardType;

	m_attackPower = 1;

	m_src.x = 0, m_src.y = 0;
	m_dest.x = rect.x, m_dest.y = rect.y;
	m_src.w = m_dest.w = 32;
	m_src.h = m_dest.h = 32;

	m_gravity = 0;
	m_speed = 10;
	m_velocityX = 3;
	m_velocityY = 0;

	m_isFlip = direction;

	for (int i = 0; i < SKILLFRAMES; i++) {
		m_skills[i] = NULL;
	}
}

CSkill::~CSkill () {
	for (int i = 0; i < SKILLFRAMES; i++) {
		if (m_skills[i]) SDL_DestroyTexture (m_skills[i]);
	}
}


bool CSkill::LoadMedia ( SDL_Renderer * renderer ) {
	uint32_t keyColor;
	for (int i = 0; i < SKILLFRAMES; i++) {
		SDL_Surface * tempSurface4 = SDL_LoadBMP (m_pathsSkills[i]);
		keyColor = SDL_MapRGB (tempSurface4->format, 0, 0, 0);
		SDL_SetColorKey (tempSurface4, SDL_TRUE, keyColor);
		printf("%s\n", m_pathsSkills[i]);
		if (!tempSurface4) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_skills[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface4 );
		if (!m_skills[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface4);
	}
	return true;
}

int CSkill::HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer, bool & isRunning) {
	return 2;
}

void CSkill::Update () {

	if (m_isFlip) m_dest.x -= m_speed * m_velocityX;
	else m_dest.x += m_speed * m_velocityX;

}
void CSkill::Render ( SDL_Renderer * renderer ) {
	printf("%d, %d, %d, %d\n", m_dest.x, m_dest.y, m_src.x, m_src.y);
	int indexSkill;
	if (m_attackPower < 5) indexSkill = 0;
	else if (m_attackPower >= 5 && m_attackPower < 10) indexSkill = 1;
	else if (m_attackPower >= 10 && m_attackPower < 15) indexSkill = 2;
	else indexSkill = 3;
	SDL_RenderCopy (renderer, m_skills[indexSkill], &m_src, &m_dest);
}

bool CSkill::Collision ( CGameObject * obj ) {
	if ( m_dest.x <= obj->GetRect().x + obj->GetRect().w && m_dest.x + m_dest.w >= obj->GetRect().x && m_dest.y + m_dest.h >= obj->GetRect().y) {
		obj->SetHealth(m_attackPower);
		return true;
	}
	if ( m_dest.x <= 0 || m_dest.x >= 1280 ) return true;
	else return false;
}
void CSkill::SetCurrentLevel (const int & currentLevel) {

}
void CSkill::SetVelocity (SDL_Rect rect) {

}
SDL_Rect CSkill::GetRect (void) {
	return m_dest;
}
int CSkill::GetAttackPower (void) {
	return m_attackPower;
}

void CSkill::SetHealth (const int & health) {

}
void CSkill::SetAttackPower (const int & attack) {
	m_attackPower = attack;
}
int CSkill::GetHealth (void) {
}
void CSkill::SetMoney (const int & money) {

}
int CSkill::GetArmor (void) {

}
int CSkill::GetMoney (void) {

}
int CSkill::GetTypeZombie (void) {

}
int CSkill::GetTypeLevel (void) {

}
int CSkill::GetRectX (void) {
	return m_dest.x;
}
int CSkill::GetRectY (void) {
	return m_dest.y;
}
