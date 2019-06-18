#include "StateMachine.hpp"
//=========================================================================
CStateMachine::CStateMachine () {
	m_windowSM = NULL;
	m_rendererSM = NULL;
	m_currentState = NULL;
	m_running = true;
	m_isGameSaved = false;
	m_currentStateNumber = 1;
	ispread = false;
}
//=========================================================================
CStateMachine::~CStateMachine () {
	if ( m_currentState ) delete m_currentState;
	if ( m_rendererSM ) SDL_DestroyRenderer (m_rendererSM);
	if ( m_windowSM ) SDL_DestroyWindow ( m_windowSM );
}
//=========================================================================
void CStateMachine::SetWindow ( SDL_Window * window ) {
	if (window) m_windowSM = window;
}
//=========================================================================
void CStateMachine::SetRenderer ( SDL_Renderer * renderer ) {
	if (renderer) m_rendererSM = renderer;
}
//=========================================================================
bool CStateMachine::GetBool (void) {
	return m_running;
}
//=========================================================================
bool CStateMachine::ChangeState ( const int & stateCode ) {
	if ( m_currentState ) delete m_currentState;
	switch (stateCode) {
		case (1): m_currentState = new CTitleScreenState(); m_currentStateNumber = 1; break;
		case (2): if (m_isGameSaved) {
						int healthwiz, armorwiz, attackwiz, moneywiz, rectwizx, rectwizy, healthzom, typezom, rectzomx, rectzomy, typelevel;
						CSaveGame saveGame;
						const char * path = "/root/Documents/sempro/sahinayk/src/code/savedgame";
						saveGame.LoadSavedGame (path, healthwiz, armorwiz, attackwiz, moneywiz, rectwizx, rectwizy, healthzom, typezom, rectzomx, rectzomy, typelevel);
						m_currentState = new CPlayScreenState (healthwiz, armorwiz, attackwiz, moneywiz, rectwizx, rectwizy, healthzom, typezom, rectzomx, rectzomy, typelevel);
						m_currentStateNumber = 2;
						break;
					   }
					   else {
						m_currentState = new CPlayScreenState();
						m_currentStateNumber = 2;
						break;
					   }
		case (3): m_currentState = new CDeathScreenState(); m_currentStateNumber = 3; break;
		default: printf ("No such game state!\n"); return false;
	}
	if (!m_currentState->LoadMedia (m_rendererSM)) {
		printf("loading media failed!\n");
		return false;
	}
	return true;
}
//=========================================================================
void CStateMachine::HandleEvents () {
	int nextState = m_currentState->HandleEvents(ispread, m_event, m_isGameSaved, m_rendererSM, m_running);
	if ( nextState != m_currentStateNumber ) ChangeState (nextState);
}
//=========================================================================
void CStateMachine::Update () {
	m_currentState->Update();
}
//=========================================================================
void CStateMachine::Render () {
	m_currentState->Render(m_rendererSM);	
}
//=========================================================================



