#ifndef _levelManager_h_
#define _levelManager_h_


#include <string>

using namespace std;

class LevelManager
{

public:
	int numCurrentLevel;
		std::string currentLevel;
	LevelManager();

	std::string nextLevel(std::string scriptFile);

	std::string getCurrentLevel();

};

#endif 