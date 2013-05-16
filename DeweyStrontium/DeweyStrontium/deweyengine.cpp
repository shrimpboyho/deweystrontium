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

