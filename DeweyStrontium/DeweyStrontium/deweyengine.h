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
			bool mousePosX;
			bool mousePosY;

        } databank;

		databank DATA_BASE;

	private:
		bool USER_OPTION_FOR_EXIT;
		


};

#endif

