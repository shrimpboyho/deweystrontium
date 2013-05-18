#include "deweyengine.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;

// Constructor

deweyengine::deweyengine()
{
	DATA_BASE.handleVar = 250;
	DATA_BASE.yBoundMin = 0;
	DATA_BASE.yBoundMax = 600;
	DATA_BASE.xBoundMin = 0;
	DATA_BASE.xBoundMax = 800;
	DATA_BASE.ballVelX = 5;
	DATA_BASE.ballVelY = 3;

	// Set up the pong ball

	pongBall.setRadius(19);
	pongBall.setFillColor(sf::Color::Red);
	pongBall.setPosition(200,300);
}

// Deconstructor

deweyengine::~deweyengine(void)
{

}

// Exit option settings (getter and setter)

bool deweyengine::getUSER_OPTION_FOR_EXIT(){

	return USER_OPTION_FOR_EXIT;

}

void deweyengine::setUSER_OPTION_FOR_EXIT(bool status){
	USER_OPTION_FOR_EXIT = status;
}

// Drawing stuff

void deweyengine::drawUpdate(sf::RenderWindow *renderWin){
	
	/* LOGICAL STUFF!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
	
	// Make sure the paddles don't go out of bounds and allow them to rise/fall based on wasd keys
	
	if(DATA_BASE.wKey == true){
		if(DATA_BASE.handleVar > DATA_BASE.yBoundMin){
			DATA_BASE.handleVar -= 20;
		}
	}

	if(DATA_BASE.sKey == true){
		if(DATA_BASE.handleVar < DATA_BASE.yBoundMax - 100){
			DATA_BASE.handleVar += 20;
		}
	}
	
	// Move the pong ball

	pongBall.move(DATA_BASE.ballVelX, DATA_BASE.ballVelY);

	// Make sure the ball doesn't go out of bounds

	if(pongBall.getPosition().y < 0 || pongBall.getPosition().y > 560){
		DATA_BASE.ballVelY = -1 * DATA_BASE.ballVelY;
	}

	if(pongBall.getPosition().x < 0 || pongBall.getPosition().x > 760){
		DATA_BASE.ballVelX = -1 * DATA_BASE.ballVelX;
	}
	/*====================Draw the update=========================*/
	
	renderWin -> clear();
			
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
	atext.setCharacterSize(40);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::Green);
	atext.setPosition(325,250);

	atext.setString("PONG"); //ss.str() converts the string buffer into a regular string 

	//draw the string
	
	renderWin->draw(atext);
				
	// Set up shapes

	rectPlayer.setSize(sf::Vector2f(20,100));
	rectPlayer.setPosition(70,DATA_BASE.handleVar);
	renderWin -> draw(rectPlayer);

	renderWin -> draw(pongBall);


	/*======================Finish drawing update======================*/

	renderWin -> display();

}

/* KEYBOARD EVENTS */

void deweyengine::checkKeyPress(sf::Event *eventpointer){

	std::cout << "The key pressed is " << eventpointer -> key.code << " \n";
	
	switch(eventpointer -> key.code){
			
		case sf::Keyboard::W : DATA_BASE.wKey = true;
								cout << "W key pressed\n";
								break;
		case sf::Keyboard::A : DATA_BASE.aKey = true;
								cout << "A key pressed\n";
								break;
		case sf::Keyboard::S : DATA_BASE.sKey = true;
								cout << "S key pressed\n";
								break;
		case sf::Keyboard::D : DATA_BASE.dKey = true;
								cout << "D key pressed\n";
								break;
		

	}

}

void deweyengine::checkKeyRelease(sf::Event *eventpointer){

	std::cout << "The key released is " << eventpointer -> key.code << " \n";
	
	switch(eventpointer -> key.code){
			
		case sf::Keyboard::W : DATA_BASE.wKey = false; 
								cout << "W key released\n";
								break;
		case sf::Keyboard::A : DATA_BASE.aKey = false; 
								cout << "A key released\n";
								break;
		case sf::Keyboard::S : DATA_BASE.sKey = false; 
								cout << "S key released\n";
								break;
		case sf::Keyboard::D : DATA_BASE.dKey = false; 
								cout << "D key released\n";
								break;
	}

}

/* MOUSE EVENTS DATABASE */

void deweyengine::checkMousePress(sf::Event *eventpointer){

	switch(eventpointer -> mouseButton.button){
			
		case sf::Mouse::Button::Left : DATA_BASE.leftMouseButton = true;
									    std::cout << "Left mouse button pressed\n";
										break;
		case sf::Mouse::Button::Right : DATA_BASE.rightMouseButton = true;
										std::cout << "Right mouse button pressed\n";
										break;
		
	}

}
void deweyengine::checkMouseRelease(sf::Event *eventpointer){

	switch(eventpointer -> mouseButton.button){
			
		case sf::Mouse::Button::Left : DATA_BASE.leftMouseButton = false;
										std::cout << "Left mouse button released\n";
										break;
		case sf::Mouse::Button::Right : DATA_BASE.rightMouseButton = false;
										std::cout << "Right mouse button released\n";
										break;
		
	}

}
void deweyengine::checkMouseMove(sf::Event *eventpointer){
	
	DATA_BASE.mousePosX =  eventpointer -> mouseMove.x;
	DATA_BASE.mousePosY =  eventpointer -> mouseMove.y;

	cout << "Mouse moved to " << DATA_BASE.mousePosX << "," << DATA_BASE.mousePosY << "\n";
}
