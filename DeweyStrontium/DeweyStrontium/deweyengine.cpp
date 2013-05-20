#include "deweyengine.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <sstream>

using namespace std;

// Constructor

deweyengine::deweyengine()
{
	DATA_BASE.handleVar = 250;
	DATA_BASE.handleVar2 = 250;
	DATA_BASE.yBoundMin = 0;
	DATA_BASE.yBoundMax = 600;
	DATA_BASE.xBoundMin = 0;
	DATA_BASE.xBoundMax = 800;
	DATA_BASE.ballVelX = 8;
	DATA_BASE.ballVelY = 6;

	// Set up the player scores

	DATA_BASE.p1Score = 0;
	DATA_BASE.p2Score = 0;

	// Set up the pong ball

	pongBall.setRadius(19);
	pongBall.setFillColor(sf::Color::Red);
	pongBall.setPosition(200,300);

	// Set up textures

	backgroundimagetexture.loadFromFile("background.jpg");
	backgroundshape.setTexture(&backgroundimagetexture);
	backgroundshape.setSize(sf::Vector2f(800,600));
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

	// Check to see if the user wants to go back to the menu

	if(DATA_BASE.escKey == true){
		DATA_BASE.gameMode = false;
		DATA_BASE.gameSingleMode = false;
		DATA_BASE.menuMode = true;
		resetGameState();
	}
	
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

	if(DATA_BASE.upKey == true){
		if(DATA_BASE.handleVar2 > DATA_BASE.yBoundMin){
			DATA_BASE.handleVar2 -= 20;
		}
	}

	if(DATA_BASE.downKey == true){
		if(DATA_BASE.handleVar2 < DATA_BASE.yBoundMax - 100){
			DATA_BASE.handleVar2 += 20;
		}
	}
	
	// Move the pong ball

	pongBall.move(DATA_BASE.ballVelX, DATA_BASE.ballVelY);

	// Make sure the ball doesn't go out of bounds

	if(pongBall.getPosition().y < 0 || pongBall.getPosition().y > 560){
		DATA_BASE.ballVelY = -1 * DATA_BASE.ballVelY;
	}

	if(pongBall.getPosition().x < 0){
		
		// POINT SCORED
		DATA_BASE.p2Score++;

		// Move the ball back to the center

		pongBall.setPosition(200,300);


	}

	 if(pongBall.getPosition().x > 760){

		 // POINT SCORED
		 DATA_BASE.p1Score++;

		 // Move the ball back to the center

		 pongBall.setPosition(200,300);
	 }

	// Check for ball collisions with paddles

	if (pongBall.getGlobalBounds().intersects(rectPlayer.getGlobalBounds()) || pongBall.getGlobalBounds().intersects(rectOtherPlayer.getGlobalBounds()))
	{
		//incrementspeed

		if(DATA_BASE.ballVelX > 0){
			DATA_BASE.ballVelX += 2;
		}
		if(DATA_BASE.ballVelX < 0){
			DATA_BASE.ballVelX -= 2;
		}
		
		if(DATA_BASE.ballVelY > 0){
			DATA_BASE.ballVelY += 2;
		}
		if(DATA_BASE.ballVelY < 0){
			DATA_BASE.ballVelY -= 2;
		}

		// collision! flip velocity
		DATA_BASE.ballVelX = -1 * (DATA_BASE.ballVelX);
		DATA_BASE.ballVelY = -1 * (DATA_BASE.ballVelY);
	}
	/*====================Draw the update=========================*/
	
	renderWin -> clear();

	// Set up the backgroudn

	renderWin ->draw(backgroundshape);
			
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

	atext.setString("PONG"); 

	sf::Text player1ScoreText;
	player1ScoreText.setFont(font);
	player1ScoreText.setCharacterSize(40);
	player1ScoreText.setStyle(sf::Text::Bold);
	player1ScoreText.setColor(sf::Color::Green);
	player1ScoreText.setPosition(100,20);
	player1ScoreText.setString(IntToString(DATA_BASE.p1Score));

	sf::Text player2ScoreText;
	player2ScoreText.setFont(font);
	player2ScoreText.setCharacterSize(40);
	player2ScoreText.setStyle(sf::Text::Bold);
	player2ScoreText.setColor(sf::Color::Green);
	player2ScoreText.setPosition(680,20);
	player2ScoreText.setString(IntToString(DATA_BASE.p2Score));

	renderWin->draw(player1ScoreText);
	renderWin->draw(player2ScoreText);

	//draw the string
	
	renderWin->draw(atext);
				
	// Set up shapes

	rectPlayer.setSize(sf::Vector2f(20,100));
	rectPlayer.setPosition(70,DATA_BASE.handleVar);
	renderWin -> draw(rectPlayer);

	rectOtherPlayer.setSize(sf::Vector2f(20,100));
	rectOtherPlayer.setPosition(730,DATA_BASE.handleVar2);
	renderWin -> draw(rectOtherPlayer);

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
		case sf::Keyboard::Escape : DATA_BASE.escKey = true;
								cout << "Esc key pressed\n";
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
		case sf::Keyboard::Up : DATA_BASE.upKey = true;
								cout << "Up key pressed\n";
								break;
		case sf::Keyboard::Down : DATA_BASE.downKey = true;
								cout << "Down key pressed\n";
								break;
		case sf::Keyboard::Left : DATA_BASE.leftKey = true;
								cout << "Left key pressed\n";
								break;
		case sf::Keyboard::Right : DATA_BASE.rightKey = true;
								cout << "Right key pressed\n";
								break;

	}

}

void deweyengine::checkKeyRelease(sf::Event *eventpointer){

	std::cout << "The key released is " << eventpointer -> key.code << " \n";
	
	switch(eventpointer -> key.code){

		case sf::Keyboard::Escape : DATA_BASE.escKey = false;
								cout << "Esc key released\n";
								break;	
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
		case sf::Keyboard::Up : DATA_BASE.upKey = false;
								cout << "Up key released\n";
								break;
		case sf::Keyboard::Down : DATA_BASE.downKey = false;
								cout << "Down key released\n";
								break;
		case sf::Keyboard::Left : DATA_BASE.leftKey = false;
								cout << "Left key released\n";
								break;
		case sf::Keyboard::Right : DATA_BASE.rightKey = false;
								cout << "Right key released\n";
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


/*  LOGIC AND RENDERING FOR THE MENU  */

void deweyengine::drawMenuUpdate(sf::RenderWindow *renderWin){

	// Logic

	if(DATA_BASE.leftMouseButton == true){
		
		// Enter game mode
		DATA_BASE.menuMode = false;
		DATA_BASE.gameSingleMode = false;
		DATA_BASE.gameMode = true;

	}
	
	
	// Rendering 
	
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

	atext.setString("CLICK TO PLAY");

	renderWin -> draw(atext);



	renderWin -> display();

}

/* RESETS THE GAME STATE */

void deweyengine::resetGameState(){

	DATA_BASE.handleVar = 250;
	DATA_BASE.handleVar2 = 250;
	DATA_BASE.yBoundMin = 0;
	DATA_BASE.yBoundMax = 600;
	DATA_BASE.xBoundMin = 0;
	DATA_BASE.xBoundMax = 800;
	DATA_BASE.ballVelX = 8;
	DATA_BASE.ballVelY = 6;

	// Set up the pong ball

	pongBall.setRadius(19);
	pongBall.setFillColor(sf::Color::Red);
	pongBall.setPosition(200,300);

	// Set up textures

	backgroundimagetexture.loadFromFile("background.jpg");
	backgroundshape.setTexture(&backgroundimagetexture);
	backgroundshape.setSize(sf::Vector2f(800,600));

}

string deweyengine::IntToString (int a)
{
    string str;
    ostringstream temp;
    temp<<a;
    return temp.str();
}