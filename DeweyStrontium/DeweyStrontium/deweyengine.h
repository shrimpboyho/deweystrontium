#ifndef _deweyengine
#define _deweyengine

#include <iostream>
using namespace std;

class deweyengine
{


	public:
		deweyengine();
		~deweyengine(void);
	
		bool getUSER_OPTION_FOR_EXIT();
		void setUSER_OPTION_FOR_EXIT(bool);
		

	private:
		bool USER_OPTION_FOR_EXIT;
		


};

#endif

