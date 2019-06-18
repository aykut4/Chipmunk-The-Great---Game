#include "SaveGame.hpp"

CSaveGame::CSaveGame () {

}

CSaveGame::~CSaveGame () {

}

void CSaveGame::SaveGame ( const char * destPath , CGameObject * wizard, CGameObject * zombie) {
	ofstream myfile;
	myfile.open (destPath, ios::out | ios::binary | ios::trunc );
	if (!myfile.is_open()) { printf("The game could not be saved!\n"); return; }
	
	myfile << wizard->GetHealth() << '\n';
	myfile << wizard->GetArmor() << '\n';
	myfile << wizard->GetAttackPower() << '\n';
	myfile << wizard->GetMoney () << '\n';
	myfile << wizard->GetRectX () << '\n';
	myfile << wizard->GetRectY () << '\n';
	myfile << zombie->GetHealth() << '\n';
	myfile << zombie->GetTypeZombie() << '\n';
	myfile << zombie->GetRectX() << '\n';
	myfile << zombie->GetRectY() << '\n';
	myfile << wizard->GetTypeLevel();

	myfile.close();
}

void CSaveGame::LoadSavedGame (const char * destPath, int & healthwiz, int & armorwiz, int & attackwiz, int & moneywiz, int & rectwizx, int & rectwizy, int & healthzom, int & typezom, int & rectzomx, int & rectzomy, int & typelevel) {

	int tmp;
	// assign all parameters
	ifstream myfile;
	myfile.open (destPath, ios::in | ios::binary);
	if (!myfile.is_open()) { printf("The game could not be saved!\n"); return; }

	myfile >> healthwiz >> armorwiz >> attackwiz >> moneywiz >> rectwizx >> rectwizy >> healthzom >> typezom >> rectzomx >> rectzomy >> typelevel;

	myfile.close();
}
