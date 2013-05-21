#ifndef _deweyengine
#define _deweyengine

#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace std;

class deweyengine
{


	public:
		
		/* CONSTRUCTORS */
		
		deweyengine();
		~deweyengine(void);

		/* GAME OJBJECTS AND ENTITIES */

		sf::RectangleShape rectPlayer;
		sf::RectangleShape rectOtherPlayer;
		sf::CircleShape pongBall;
		sf::Texture backgroundimagetexture;
		sf::RectangleShape backgroundshape;
	
		/* MEMBER FUNCTIONS*/

		bool getUSER_OPTION_FOR_EXIT();
		void setUSER_OPTION_FOR_EXIT(bool);
		void drawUpdate(sf::RenderWindow *renderWin);
		void drawMenuUpdate(sf::RenderWindow *renderWin);
		void checkKeyPress(sf::Event *eventpointer);
		void checkKeyRelease(sf::Event *eventpointer);
		void checkMousePress(sf::Event *eventpointer);
		void checkMouseRelease(sf::Event *eventpointer);
		void checkMouseMove(sf::Event *eventpointer);
		void resetGameState();
		string IntToString (int a);

		/* USER INTERACTIVITY DATABASE */
		
		typedef struct{

			// Developer booleans

			bool vertexShader;
			int centroidRect1;
			int centoidRect2;
			int centroidBall;
			
			// Key booleans

			bool wKey;
			bool aKey;
			bool sKey;
			bool dKey;

			bool upKey;
			bool downKey;
			bool leftKey;
			bool rightKey;

			bool escKey;

			// Mouse booleans

			bool leftMouseButton;
			bool rightMouseButton;
			int mousePosX;
			int mousePosY;

			// Window boundaries

			int xBoundMin;
			int yBoundMin;
			int xBoundMax;
			int yBoundMax;

			// Var that handles counting pixel position

			int handleVar;
			int handleVar2;
			int ballVelX;
			int ballVelY;

			// Variables that control the menu flow logic

			bool menuMode;
			bool gameMode;
			bool gameSingleMode;

			// Variables which control the point system

			int p1Score;
			int p2Score;
			

        } databank;

		databank DATA_BASE;

	private:
		bool USER_OPTION_FOR_EXIT;
		


};

#endif

