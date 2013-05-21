// Include headers

#include <SFML\Graphics.hpp>
#include <iostream>
#include "deweyengine.h"
#include <SFML/Audio.hpp>
#include <sstream>

// Initialize engine

deweyengine engine;

// Main function

int main(){

	// Set up the game mode booleans

	engine.DATA_BASE.menuMode = true;
	engine.DATA_BASE.gameMode = false;

	// Start playing the music!

	sf::Music music;
	music.openFromFile("music.ogg");
	music.setLoop(true);
	music.play();
	
	engine.setUSER_OPTION_FOR_EXIT(true);

	// Create window

	sf::RenderWindow window(sf::VideoMode(800,600),"Dewey Strontium");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	//window.setIcon(gimp_image.width,  gimp_image.height, gimp_image.pixel_data);

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
		
		

		/* LOGIC and RENDERING */
		
		// Check to see if in game mode
		
		if(engine.DATA_BASE.gameMode == true){
			engine.drawUpdate(&window);
		}

		// Check to see if in menu mode

		if(engine.DATA_BASE.menuMode == true){
			engine.drawMenuUpdate(&window);
		}
		

	}

	// Clean up after the game is closed
	window.close();

	// Keep everyone happy
	return 0;
}

