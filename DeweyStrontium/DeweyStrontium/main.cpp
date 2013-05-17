// Include headers

#include <SFML\Graphics.hpp>
#include <iostream>
#include "deweyengine.h"
#include <SFML/Audio.hpp>

// Main function

int main(){

	// Start playing the music!

	sf::Music music;
	music.openFromFile("music.ogg");
	music.play();

	// Initialize engine

	deweyengine engine;
	
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


		}
		
		
		/* LOGIC */

		// Query the database and act accordingly

		

		/* RENDERING */

		engine.drawUpdate(&window);
		

	}

	// Clean up after the game is closed
	window.close();

	// Keep everyone happy
	return 0;
}


