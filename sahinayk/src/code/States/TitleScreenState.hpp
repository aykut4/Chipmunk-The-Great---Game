#ifndef _TitleScreenState.hpp_
#define _TitleScreenState.hpp_
//=========================================================================
#include "State.hpp"
//=========================================================================
const int TITLESCREENFRAMES = 3;
//=========================================================================
enum KEYPRESS {
	KEY_UP = -1,
	KEY_DEFAULT = 0,
	KEY_DOWN = 1
};
//=========================================================================
class CTitleScreenState : public CState {
	private:
	KEYPRESS pressedKey;
	int indexTexture;
	SDL_Texture * titleScreens [ TITLESCREENFRAMES ];
	const char * paths[ TITLESCREENFRAMES ] = {"/root/Documents/sempro/sahinayk/src/graphics/titlescreen/titlescreen1.bmp",
						   "/root/Documents/sempro/sahinayk/src/graphics/titlescreen/titlescreen2.bmp",
						   "/root/Documents/sempro/sahinayk/src/graphics/titlescreen/titlescreen3.bmp"};
//----------------------------------------------
	public:
	CTitleScreenState ();
//----------------------------------------------
	~CTitleScreenState ();
	bool LoadMedia ( SDL_Renderer * renderer );
//----------------------------------------------
	int HandleEvents (bool & ispread, SDL_Event & m_event, bool & isGameSaved, SDL_Renderer * renderer , bool & isRunning );
//----------------------------------------------
	void Update ( void );
//----------------------------------------------
	void Render ( SDL_Renderer * renderer );
};
//=========================================================================
#endif /*_TitleScreenState.hpp*/
