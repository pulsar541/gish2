#ifndef _levelManager_h_
#define _levelManager_h_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LevelManager
{

public:
	int numCurrentLevel;
		std::string currentLevel;
	LevelManager()
	{
		numCurrentLevel = 1;
	}

	std::string nextLevel(std::string scriptFile)
	{
		

		std::ifstream in(scriptFile.c_str());
		std::string level;
		for (int i=0;!in.eof() && i<numCurrentLevel; i++)
		{
			in>>level;
			currentLevel = level;
		}
	//	if (in.bad()) // АААА!!! случилось что-то плохое ...

		numCurrentLevel ++;
		return level;
		
		
	}

	std::string getCurrentLevel()
	{

		return currentLevel;

	}

};
/*
class LevelManager
{

public:

//	int numCurrentLevel;

	std::string currentLevel;

	LevelManager()
	{
		currentLevel = "";
	//	numCurrentLevel = 1;
	}

	std::string nextLevel(std::string scriptFile)
	{
		

		std::ifstream in(scriptFile.c_str());
		std::string level;
		for (int i=0;!in.eof() ; i++)
		{
			in>>level;

			if(currentLevel == "")
			{ 
			  currentLevel = level;
			  return level;
			}

			if(currentLevel == level)
			{ 
			  in>>level;
			  currentLevel = level;
			  return level;
			}
		}
	//	if (in.bad()) // АААА!!! случилось что-то плохое ...

//		numCurrentLevel ++;
		return NULL;
		
		
	}

};
*/
#endif 