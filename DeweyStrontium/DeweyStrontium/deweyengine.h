#ifndef _deweyengine
#define _deweyengine

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

class deweyengine
{


	public:
		
		/* CONSTRUCTORS */
		
		deweyengine();
		~deweyengine(void);

		/* GAME OJBJECTS AND ENTITIES */

		sf::RectangleShape rectPlayer;
		sf::CircleShape pongBall;
	
		/* MEMBER FUNCTIONS*/

		bool getUSER_OPTION_FOR_EXIT();
		void setUSER_OPTION_FOR_EXIT(bool);
		void drawUpdate(sf::RenderWindow *renderWin);
		void checkKeyPress(sf::Event *eventpointer);
		void checkKeyRelease(sf::Event *eventpointer);
		void checkMousePress(sf::Event *eventpointer);
		void checkMouseRelease(sf::Event *eventpointer);
		void checkMouseMove(sf::Event *eventpointer);

		/* USER INTERACTIVITY DATABASE */
		
		typedef struct{

			// Key booleans

			bool wKey;
			bool aKey;
			bool sKey;
			bool dKey;

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
			int ballVelX;
			int ballVelY;
			

        } databank;

		databank DATA_BASE;

	private:
		bool USER_OPTION_FOR_EXIT;
		


};

#endif

