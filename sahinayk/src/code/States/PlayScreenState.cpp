#include "PlayScreenState.hpp"
CPlayScreenState::CPlayScreenState () : CState() {
	m_counterLevel = 0;
	m_currentLevel = 1;
	for (int i = 0; i < OBJECTCOUNT; i++) {
		m_gameObject[i]= NULL;
	}
	m_level = NULL;
	m_level = new CLevel ();
	m_gameObject[0] = new CGreenWizard ();
	for (int i = 1; i < OBJECTCOUNT; i++) {
		m_gameObject[i] = new CZombie ();
	}
}

CPlayScreenState::CPlayScreenState (int healthwiz, int armorwiz, int attackwiz, int moneywiz, int rectwizx, int rectwizy, int healthzom, int typezom, int rectzomx, int rectzomy, int typelevel) : CState() {

	m_counterLevel = 0;
	m_currentLevel = typelevel;
	for (int i = 0; i < OBJECTCOUNT; i++) {
		m_gameObject[i]= NULL;
	}
	m_level = NULL;
	m_level = new CLevel ();
	m_gameObject[0] = new CGreenWizard (healthwiz, armorwiz, attackwiz, moneywiz, typelevel, rectwizx, rectwizy);
	m_gameObject[1] = new CZombie (healthzom, typezom, typelevel, rectzomx, rectzomy);
	
}

CPlayScreenState::~CPlayScreenState () {
	for (int i = 0; i < OBJECTCOUNT; i++) {
		if (m_gameObject[i]) delete m_gameObject[i];
	}
	if (m_level) delete m_level;
}

bool CPlayScreenState::LoadMedia ( SDL_Renderer * renderer) {
	bool isOk =  m_level->LoadMedia(renderer);
	bool isOk2;
	bool isOk3;

	if (m_gameObject[0]) isOk2 = m_gameObject[0]->LoadMedia (renderer);
	if (m_gameObject[1]) isOk3 = m_gameObject[1]->LoadMedia (renderer); 

	return isOk == false || isOk2 == false || isOk3 == false ? false : true;
}

int CPlayScreenState::HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer, bool & isRunning ) {

	if (ispread) {
		const char * stairwayToHeaven = "/root/Documents/sempro/sahinayk/src/code/savedgame";
		CSaveGame saveGame;
		saveGame.SaveGame (stairwayToHeaven, m_gameObject[0], m_gameObject[1]);
		ispread = false;
	}

	if (m_counterLevel == 20) {
		m_counterLevel = 0;
		return 3;
	}

	if (m_gameObject[1] && m_gameObject[0]) {
		if (m_gameObject[0]->GetHealth() <= 0) {
			return 1;
		}
		if (m_gameObject[1]->GetHealth() <= 0) {
			m_counterLevel++;
			m_gameObject[0]->SetMoney(10);
			delete m_gameObject[1];
			m_gameObject[1] = new CZombie();
			m_gameObject[1]->LoadMedia(renderer);
			srand(time(NULL));
			m_currentLevel = rand() % 3 + 1;
		}
	}

	return m_gameObject[0]->HandleEvents (ispread, m_event, isGameSaved, renderer, isRunning);
}

void CPlayScreenState::Update ( void ) {

	

	m_level->SetCurrentLevel (m_currentLevel);
	if (m_gameObject[1] && m_gameObject[0]) {
		m_gameObject[1]->SetVelocity (m_gameObject[0]->GetRect());
		m_gameObject[1]->Collision (m_gameObject[0]);
		m_gameObject[0]->Collision(m_gameObject[1]);
	}
	if (m_gameObject[0]) m_gameObject[0]->Update();
	if (m_gameObject[1]) m_gameObject[1]->Update();
	if (m_gameObject[0]) m_gameObject[0]->SetCurrentLevel (m_currentLevel);
	if (m_gameObject[1]) m_gameObject[1]->SetCurrentLevel (m_currentLevel);
}

void CPlayScreenState::Render ( SDL_Renderer * renderer ) {
	SDL_RenderClear ( renderer );
	m_level->LevelManager(renderer);
	if (m_gameObject[0]) m_gameObject[0]->Render(renderer);
	if (m_gameObject[1]) m_gameObject[1]->Render(renderer);
	SDL_RenderPresent (renderer);
}

