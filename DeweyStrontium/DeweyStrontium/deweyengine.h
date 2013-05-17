#ifndef _deweyengine
#define _deweyengine

#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

class deweyengine
{


	public:
		deweyengine();
		~deweyengine(void);
	
		bool getUSER_OPTION_FOR_EXIT();
		void setUSER_OPTION_FOR_EXIT(bool);
		void drawUpdate(sf::RenderWindow *renderWin);
		void checkKeyPress(sf::Event *eventpointer);
		void checkKeyRelease(sf::Event *eventpointer);

	private:
		bool USER_OPTION_FOR_EXIT;
		


};

#endif

