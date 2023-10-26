#include "levelManager.h"
#include <fstream>

 LevelManager::LevelManager()
{
	numCurrentLevel = 1;
}

 std::string LevelManager::nextLevel(std::string scriptFile)
{


	std::ifstream in(scriptFile.c_str());
	std::string level;
	for (int i = 0; !in.eof() && i<numCurrentLevel; i++)
	{
		in >> level;
		currentLevel = level;
	}
	//	if (in.bad()) // АААА!!! случилось что-то плохое ...

	numCurrentLevel++;
	return level;


}

 std::string LevelManager::getCurrentLevel()
{

	return currentLevel;

}
