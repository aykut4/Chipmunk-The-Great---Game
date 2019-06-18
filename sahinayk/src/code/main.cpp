#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include "Window.hpp"
#include "Init.hpp"
#include "Terminate.hpp"
#include "StateMachine.hpp"
#include "Level.hpp"
#include "States/State.hpp"
#include "States/TitleScreenState.hpp"
#include "States/PlayScreenState.hpp"
#include "States/DeathScreenState.hpp"
#include "Objects/GameObject.hpp"
#include "Objects/MovingObject.hpp"
#include "Objects/GreenWizard.hpp"

int main ( int argc, char* args[] ) {

	CInit init;
	CWindow window;
	CTerminate program;
	CStateMachine gStateMachine;

	if (! init.InitializeSDL() ) 			return program.Terminate (1); // exit code 1
	if (! window.InitializeWindow() ) 		return program.Terminate (2); // exit code 2
	if (! window.CreateRenderer() ) 		return program.Terminate (3); // exit code 3
	gStateMachine.SetWindow (window.GetWindow());
	gStateMachine.SetRenderer (window.GetRenderer());
	if (! gStateMachine.ChangeState (1) ) 		return program.Terminate (4, &window); // exit code 4

	while ( gStateMachine.GetBool() ) {

		gStateMachine.HandleEvents();
		gStateMachine.Update();
		gStateMachine.Render();
	}

	return program.Terminate (5, &window); // exit code 4
}
