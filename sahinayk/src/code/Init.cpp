#include "Init.hpp"
//=========================================================================
CInit::CInit () {

}
//=========================================================================
CInit::~CInit () {

}
//=========================================================================
bool CInit::InitializeSDL ( void ) {
	if ( SDL_Init ( SDL_INIT_EVERYTHING ) == 0 ) {
		printf ("SDL Initialization is successful!\n");
		return true;
	}
	else {
		printf ("SDL Initialization was not successful!\n");
		return false;
	}
}
//=========================================================================
