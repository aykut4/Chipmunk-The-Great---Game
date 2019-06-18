#ifndef _DeathScreenState.hpp_
#define _DeathScreenState.hpp_
//=========================================================================
#include "State.hpp"
//=========================================================================
class CDeathScreenState : public CState {
	private:
	//
	SDL_Texture * m_winningScreen;
	const char * m_pathWin = "/root/Documents/sempro/sahinayk/src/graphics/background/winning.bmp";
//----------------------------------------------
	public:
	CDeathScreenState ();
//----------------------------------------------
	~CDeathScreenState ();
//----------------------------------------------
	bool LoadMedia ( SDL_Renderer * renderer );
//----------------------------------------------
	int HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer , bool & isRunning );
//----------------------------------------------
	void Update ( void );
//----------------------------------------------
	void Render ( SDL_Renderer * renderer );
};
//=========================================================================
#endif /*_DeathScreenState.hpp*/
