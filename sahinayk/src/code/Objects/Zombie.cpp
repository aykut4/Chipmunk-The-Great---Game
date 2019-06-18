#include "Zombie.hpp"

CZombie::CZombie () {

	srand(time(NULL));

	m_zombieType = rand() % 3 + 1;

	if (m_zombieType == 1) {
		m_speed = 3;
		m_health = 200;
		m_attackPower = 2;
	}
	else if (m_zombieType == 2) {
		m_speed = 3;
		m_health = 300;
		m_attackPower = 3;
	}
	else {
		m_speed = 4;
		m_health = 50;
		m_attackPower = 4;
	}

	srand(time(NULL));
	m_src.x = 0, m_src.y = 0;
	m_dest.x = rand() % 1260 + 20, m_dest.y = 555;
	m_src.w = m_dest.w = 32;
	m_src.h = m_dest.h = 32;


	m_gravity = 0;
	m_velocityX = 0;
	m_velocityY = 0;
	m_isFlip = false;
	m_isLanded = true;
	m_currentLevel = 1;
}

CZombie::CZombie (int health, int type, int level, int rectzomx, int rectzomy) {

	m_zombieType = type;
	m_health = health;

	if (m_zombieType == 1) {
		m_speed = 3;
		m_attackPower = 2;
	}
	else if (m_zombieType == 2) {
		m_speed = 3;
		m_attackPower = 3;
	}
	else {
		m_speed = 4;
		m_attackPower = 4;
	}

	m_src.x = 0, m_src.y = 0;
	m_dest.x = rectzomx, m_dest.y = rectzomy;
	m_src.w = m_dest.w = 32;
	m_src.h = m_dest.h = 32;


	m_gravity = 0;
	m_velocityX = 0;
	m_velocityY = 0;
	m_isFlip = false;
	m_isLanded = true;
	m_currentLevel = level;
}


CZombie::~CZombie () {
	for (int i = 0; i < ZOMBIEFRAMES; i++) {
		if(m_zombie[i]) SDL_DestroyTexture (m_zombie[i]);
	}
}

bool CZombie::LoadMedia (SDL_Renderer * renderer) {
	uint32_t keyColor;
	for (int i = 0; i < ZOMBIEFRAMES; i++) {
		SDL_Surface * tempSurface = SDL_LoadBMP (m_pathsZombie[i]);
		keyColor = SDL_MapRGB (tempSurface->format, 0, 0, 0);
		SDL_SetColorKey (tempSurface, SDL_TRUE, keyColor);
		printf("%s\n", m_pathsZombie[i]);
		if (!tempSurface) {
			printf("loading surface failed54!\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		m_zombie[i] = SDL_CreateTextureFromSurface ( renderer, tempSurface );
		if (!m_zombie[i]) {
			printf("loading texture failed\n");
			printf("SDL Error: %s\n", SDL_GetError());
			return false;
		}
		SDL_FreeSurface (tempSurface);
	}
	return true;
}

int CZombie::HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer, bool & isRunning) {
	return 2;
}

void CZombie::Update (void) {
	printf("zombiehealth%d\n", m_health);
	if (m_dest.y >= 555) { m_dest.y = 555; m_isLanded = true;}
	else m_isLanded = false;
	m_dest.x += m_speed * m_velocityX;
}

void CZombie::Render (SDL_Renderer * renderer) {
	SDL_RenderCopy (renderer, m_zombie[m_zombieType-1], &m_src, &m_dest);
}

bool CZombie::Collision (CGameObject * obj) {
	if ( m_dest.x <= 0 ) { m_dest.x = 0; return true;}
	else if (m_dest.x >= 1248) {m_dest.x = 1248; return true;}
	else return false;
} 

void CZombie::SetCurrentLevel (const int & currentLevel) {
	m_currentLevel = currentLevel;
}
void CZombie::SetVelocity (SDL_Rect rect) {

	if ( rect.x >= m_dest.x) m_velocityX = 1;
	else m_velocityX = -1;
}

SDL_Rect CZombie::GetRect (void) {
	return m_dest;
}
int CZombie::GetAttackPower (void) {
	return m_attackPower;
}
void CZombie::SetHealth ( const int & health ) {
	m_health -= health;
}
void CZombie::SetAttackPower (const int & attack) {
	m_attackPower = attack;
}
int CZombie::GetHealth(void) {
	return m_health;
}
void CZombie::SetMoney (const int & money) {
	
}
int CZombie::GetTypeZombie (void) {
	return m_zombieType;
}
int CZombie::GetTypeLevel (void) {
	return m_currentLevel;
}
int CZombie::GetArmor (void) {}
int CZombie::GetMoney (void) {}
int CZombie::GetRectX (void) {
	return m_dest.x;
}
int CZombie::GetRectY (void) {
	return m_dest.y;
}
