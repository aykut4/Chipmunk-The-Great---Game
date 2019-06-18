#include "Terminate.hpp"
//=========================================================================
CTerminate::CTerminate () {

}
//=========================================================================
CTerminate::~CTerminate () {

}
//=========================================================================
int CTerminate::Terminate ( const int & exitcode, CWindow * window ) {
	switch (exitcode) {
		case (1): return 0;
		case (2): SDL_Quit(); return 0;
		case (3): if(window) {window->DestroyWindow();} SDL_Quit(); return 0;
		case (4): if(window) {window->DestroyWindow(); window->DestroyRenderer();} SDL_Quit(); return 0;
		case (5): if(window) {window->DestroyWindow(); window->DestroyRenderer();} SDL_Quit(); return 0; // exit on success so might have to add more destroy functions in here later on
	}
}
//=========================================================================
