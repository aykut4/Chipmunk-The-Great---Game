# Commands

## Run main program
.PHONY: main
main: 	build/main
	./build/main

## Removing generated directory
.PHONY: clean
clean:
	rm -r ./build

# Programs

## Program "main"
build/main: build/main.o build/Window.o build/Init.o build/Terminate.o build/StateMachine.o build/State.o build/TitleScreenState.o build/PlayScreenState.o build/DeathScreenState.o build/Level.o build/GameObject.o build/MovingObject.o build/GreenWizard.o build/Skill.o build/Zombie.o build/SaveGame.o
	mkdir -p build
	g++ -g -lSDL2 build/main.o build/Window.o build/Init.o build/Terminate.o build/StateMachine.o build/State.o build/TitleScreenState.o build/PlayScreenState.o build/DeathScreenState.o build/Level.o build/GameObject.o build/MovingObject.o build/GreenWizard.o build/Skill.o build/Zombie.o build/SaveGame.o -o build/main

# Moduls

## Modul "main.cpp"
build/main.o: src/code/main.cpp src/code/Window.hpp src/code/Init.hpp src/code/Terminate.hpp src/code/StateMachine.hpp src/code/States/State.hpp src/code/States/TitleScreenState.hpp src/code/States/PlayScreenState.hpp src/code/States/DeathScreenState.hpp src/code/Level.hpp src/code/Objects/GameObject.hpp src/code/Objects/MovingObject.hpp src/code/Objects/GreenWizard.hpp src/code/Objects/Skill.hpp src/code/Objects/Zombie.hpp src/code/SaveGame.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/main.cpp -o build/main.o

# Classes

## class "Window"
build/Window.o: src/code/Window.cpp src/code/Window.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Window.cpp -o build/Window.o

##class "Init"
build/Init.o: src/code/Init.cpp src/code/Init.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Init.cpp -o build/Init.o

##class "Terminate"
build/Terminate.o: src/code/Terminate.cpp src/code/Terminate.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Terminate.cpp -o build/Terminate.o
#class "StateMachine"
build/StateMachine.o: src/code/StateMachine.cpp src/code/StateMachine.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/StateMachine.cpp -o build/StateMachine.o

#class "State"
build/State.o: src/code/States/State.cpp src/code/States/State.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/States/State.cpp -o build/State.o

#class "TitleScreenState"
build/TitleScreenState.o: src/code/States/TitleScreenState.cpp src/code/States/TitleScreenState.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/States/TitleScreenState.cpp -o build/TitleScreenState.o

#class "PlayScreenState"
build/PlayScreenState.o: src/code/States/PlayScreenState.cpp src/code/States/PlayScreenState.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/States/PlayScreenState.cpp -o build/PlayScreenState.o

#class "DeathScreenState"
build/DeathScreenState.o: src/code/States/DeathScreenState.cpp src/code/States/DeathScreenState.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/States/DeathScreenState.cpp -o build/DeathScreenState.o
#class "Level"
build/Level.o: src/code/Level.cpp src/code/Level.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Level.cpp -o build/Level.o
#class "GameObject"
build/GameObject.o: src/code/Objects/GameObject.cpp src/code/Objects/GameObject.hpp 
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Objects/GameObject.cpp -o build/GameObject.o
#class "MovingObject"
build/MovingObject.o: src/code/Objects/MovingObject.cpp src/code/Objects/MovingObject.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Objects/MovingObject.cpp -o build/MovingObject.o
#class "GreenWizard"
build/GreenWizard.o: src/code/Objects/GreenWizard.cpp src/code/Objects/GreenWizard.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Objects/GreenWizard.cpp -o build/GreenWizard.o 
#class "Skill"
build/Skill.o: src/code/Objects/Skill.cpp src/code/Objects/Skill.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Objects/Skill.cpp -o build/Skill.o
#class "Zombie"
build/Zombie.o: src/code/Objects/Zombie.cpp src/code/Objects/Zombie.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/Objects/Zombie.cpp -o build/Zombie.o
#class "SaveGame"
build/SaveGame.o: src/code/SaveGame.cpp src/code/SaveGame.hpp
	mkdir -p build
	g++ -Wall -pedantic -Wextra -g -w -c src/code/SaveGame.cpp -o build/SaveGame.o
