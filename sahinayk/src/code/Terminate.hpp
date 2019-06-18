#ifndef _Terminate.hpp_
#define _Terminate.hpp_
//=========================================================================
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include "Window.hpp"
//=========================================================================
class CTerminate {
	private:
	//
//----------------------------------------------
	public:
	CTerminate ();
//----------------------------------------------
	~CTerminate ();
//----------------------------------------------
	int Terminate (const int & exitcode, CWindow * window = NULL);
};
//=========================================================================
#endif /*_Terminate.hpp_*/
