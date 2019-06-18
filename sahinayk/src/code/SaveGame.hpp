#ifndef _SaveGame.hpp_
#define _SaveGame.hpp_

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include "Objects/GameObject.hpp"

using namespace std;

class CSaveGame {
	private:
	//
	public:
	CSaveGame ();
	~CSaveGame ();
	void SaveGame (const char * destPath, CGameObject * wizard, CGameObject * zombie);
	void LoadSavedGame (const char * destPath,  int & healthwiz, int & armorwiz, int & attackwiz, int & moneywiz, int & rectwizx, int & rectwizy, int & healthzom, int & typezom, int & rectzomx, int & rectzomy, int & typelevel);
};

#endif /*_SaveGame.hpp*/
