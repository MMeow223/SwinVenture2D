#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <time.h>
#include <locale.h>
#include "Scene.h"
#include "Book.h"
#include "Achievement.h"
#include "Iterator.h"
using namespace std;

// struct of Achievement details
struct AchievementDetail
{
	string unlock_date;
	bool unlock_status;
};
class AchievementScene : public Scene
{

private:
	// achievement arrays
	Achievement* achievement_list[5];
	AchievementDetail achievement_status[5];
	
	// iterator
	Achievement** ptr;
	Iterator<Achievement*>* iter;
	
	// sprite and texture
	sf::Sprite sprite;
	sf::Texture texture;
	
public:
	AchievementScene();
	AchievementScene(sf::RenderWindow* window);
	~AchievementScene();

	// getter 
	Achievement** getAchievementList() { return achievement_list; }
	AchievementDetail* getAchievementStatus() { return achievement_status; }
	bool getAchievementUnlockStatus(int index) { return achievement_status[index].unlock_status; }
	
	// functions
	void loadAchievementFromFile();
	void updateAchievementStatus();

	void update();
	void render();
	void recordAchievement(string achievement_name);
	void recordToFile();
};

