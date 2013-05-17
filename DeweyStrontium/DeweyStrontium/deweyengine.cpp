#include "deweyengine.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;

deweyengine::deweyengine()
{
	
}


deweyengine::~deweyengine(void)
{

}


bool deweyengine::getUSER_OPTION_FOR_EXIT(){

	return USER_OPTION_FOR_EXIT;

}

void deweyengine::setUSER_OPTION_FOR_EXIT(bool status){
	USER_OPTION_FOR_EXIT = status;
}

void deweyengine::drawUpdate(sf::RenderWindow *renderWin){
	
	// Draw the update
	
	renderWin -> clear();

	if(DATA_BASE.wKey == true){
			
						//create a font
				sf::Font font;

				// Load it from a file
				if (!font.loadFromFile("sansation.ttf"))
					//find this file in the "pong" example in the SFML examples folder
				{
					std::cout << "Error loading font\n" ;
				}
			
				sf::Text atext;
				atext.setFont(font);
				atext.setCharacterSize(20);
				atext.setStyle(sf::Text::Bold);
				atext.setColor(sf::Color::White);
				atext.setPosition(0,0);

				atext.setString("KEY A PRESSED!"); //ss.str() converts the string buffer into a regular string 

				//draw the string
				renderWin->draw(atext);
		}
	

	renderWin -> display();

}

void deweyengine::checkKeyPress(sf::Event *eventpointer){

	std::cout << "The key pressed is " << eventpointer -> key.code << " \n";
	
	switch(eventpointer -> key.code){
			
		case sf::Keyboard::W : DATA_BASE.wKey = true;
		case sf::Keyboard::A : DATA_BASE.aKey = true;
		case sf::Keyboard::S : DATA_BASE.sKey = true;
		case sf::Keyboard::D : DATA_BASE.dKey = true;
		

	}

}

void deweyengine::checkKeyRelease(sf::Event *eventpointer){

	std::cout << "The key released is " << eventpointer -> key.code << " \n";
	
	switch(eventpointer -> key.code){
			
		case sf::Keyboard::W : DATA_BASE.wKey = false;
		case sf::Keyboard::A : DATA_BASE.aKey = false;
		case sf::Keyboard::S : DATA_BASE.sKey = false;
		case sf::Keyboard::D : DATA_BASE.dKey = false;
	}

}

