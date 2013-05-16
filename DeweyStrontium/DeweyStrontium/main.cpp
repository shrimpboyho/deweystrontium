// Include headers

#include <SFML\Graphics.hpp>
#include <iostream>
#include "deweyengine.h"

// Main function

int main(){

	// INitialize engine

	deweyengine engine;
	
	engine.setUSER_OPTION_FOR_EXIT(true);

	// Create window

	sf::RenderWindow window(sf::VideoMode(800,600),"Dewey Strontium");
	window.setFramerateLimit(60);

	// Set up game loop

	while(engine.getUSER_OPTION_FOR_EXIT() == true && window.isOpen()){

		/* EVENTS */

		sf::Event event;

		while(window.pollEvent(event)){


			 // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();


		}
		
		
		/* LOGIC */


		/* RENDERING */
		
		window.clear();

		window.display();

	}

	// Clean up after the game is closed
	window.close();

	// Keep everyone happy
	return 0;
}


