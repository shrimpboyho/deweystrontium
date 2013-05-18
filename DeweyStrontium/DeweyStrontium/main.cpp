// Include headers

#include <SFML\Graphics.hpp>
#include <iostream>
#include "deweyengine.h"
#include <SFML/Audio.hpp>

// FUNCTION PROTOTYPES

void gameLogic();

// Initialize engine

deweyengine engine;

// Main function

int main(){

	// Start playing the music!

	sf::Music music;
	music.openFromFile("music.ogg");
	music.setLoop(true);
	music.play();
	
	engine.setUSER_OPTION_FOR_EXIT(true);

	// Create window

	sf::RenderWindow window(sf::VideoMode(800,600),"Dewey Strontium");
	window.setFramerateLimit(60);

	// Initialize event holding thingy

	sf::Event event;

	// Set up game loop

	while(engine.getUSER_OPTION_FOR_EXIT() == true && window.isOpen()){

		/* EVENTS */

		while(window.pollEvent(event)){

			 // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
			}

			// keyboard keypress event
			if (event.type == sf::Event::KeyPressed){
				engine.checkKeyPress(&event);
			}

			// keyboard release event
			if (event.type == sf::Event::KeyReleased){
				engine.checkKeyRelease(&event);
			}

			// mouse click event
			if(event.type == sf::Event::MouseButtonPressed){
				engine.checkMousePress(&event);
			}

			// mouse release event
			if(event.type == sf::Event::MouseButtonReleased){
				engine.checkMouseRelease(&event);
			}

			if(event.type == sf::Event::MouseMoved){
				engine.checkMouseMove(&event);
			}
		}
		
		
		/* LOGIC */

		gameLogic();

		/* RENDERING */

		engine.drawUpdate(&window);
		

	}

	// Clean up after the game is closed
	window.close();

	// Keep everyone happy
	return 0;
}

/* A Seperate function dealing mainly with the game's logic */

void gameLogic(){

	// Make sure the paddles don't go out of bounds and allow them to rise/fall based on wasd keys
	
	if(engine.DATA_BASE.wKey == true){
		if(engine.DATA_BASE.handleVar > engine.DATA_BASE.yBoundMin){
			engine.DATA_BASE.handleVar -= 20;
		}
	}

	if(engine.DATA_BASE.sKey == true){
		if(engine.DATA_BASE.handleVar < engine.DATA_BASE.yBoundMax - 100){
			engine.DATA_BASE.handleVar += 20;
		}
	}

}

