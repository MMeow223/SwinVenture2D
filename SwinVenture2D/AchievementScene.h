#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Scene.h"
#include "Book.h"
#include "Achievement.h"
#include "Iterator.h"
using namespace std;

struct AchievementDetail
{
	string unlock_date;
	bool unlock_status;
};
class AchievementScene : public Scene
{

private:
	sf::Sprite sprite;
	sf::Texture texture;
	Achievement* achievement_list[5];
	AchievementDetail achievement_status[5];
	Achievement** ptr;
	Achievement* temp;

	// creating the both iterator
	Iterator<Achievement*>* iter;
public:
	AchievementScene();
	AchievementScene(sf::RenderWindow* window);
	~AchievementScene();

	void loadAchievementFromFile();
	void updateAchievementStatus();

	void update();
	void render();

};

