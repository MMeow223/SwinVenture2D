#include "AchievementScene.h"


AchievementScene::AchievementScene() : Scene()
{
	cout << "AchievementScene init" << endl;
	sceneID = "scene_achievement";
	window = nullptr;
	book = nullptr;
	texture.loadFromFile("./res/images/bookcover-achievement.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(1080 / 2 - sprite.getLocalBounds().width / 2, 720 / 2 - sprite.getLocalBounds().height / 2));
}

AchievementScene::AchievementScene(sf::RenderWindow* window) : Scene(window)
{
	cout << "AchievementScene init" << endl;
	sceneID = "scene_achievement";

	// nullptr because doesnt need it
	book = nullptr;

	// load background texture
	texture.loadFromFile("./res/images/bookcover-achievement.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(1080 / 2 - sprite.getLocalBounds().width / 2, 720 / 2 - sprite.getLocalBounds().height / 2));

	// initialise achievement list
	achievement_list[0] = new Achievement(
		window,
		sf::Vector2f(150, 150),
		"./res/images/achievement-master.png",
		"Master",
		"Win the game without taking any damage.");
		
	achievement_list[1] = new Achievement(
		window,
		sf::Vector2f(150, 250),
		"./res/images/achievement-hopper.png",
		"Master",
		"Kill enemy with jump only");
	achievement_list[2] = new Achievement(
		window,
		sf::Vector2f(150, 350),
		"./res/images/achievement-pitcher.png",
		"Pitcher",
		"Win by using range weapon only");
	
	achievement_list[3] = new Achievement(
		window,
		sf::Vector2f(150, 450),
		"./res/images/achievement-legend.png",
		"Legend",
		"Lose without damaging any enemy.");
	
	achievement_list[4] = new Achievement(
		window,
		sf::Vector2f(600, 150),
		"./res/images/achievement-fighter.png",
		"Fighter",
		"Kill enemy in less than one second.");

	// initialise iterator
	ptr = achievement_list;
	iter = new Iterator<Achievement*>(ptr, 5);

	// update achievment details by loading them from file
	loadAchievementFromFile();
	updateAchievementStatus();
}

AchievementScene::~AchievementScene()
{
}

void AchievementScene::update()
{
}

void AchievementScene::render()
{
	// render the background
	window->draw(sprite);
	
	// render each of the achievement
	for (Iterator<Achievement*> i = *iter; i != i.end(); i++) {
		(**i)->render();
	}
}

void AchievementScene::loadAchievementFromFile()
{
	// read the achievement details from file and store them in the achievement_status array
	ifstream fr("./data/achievement.txt", std::ifstream::in);
	if (fr.is_open()) {
		string line;
		for (int i = 0; i < 5; i++) {
			getline(fr, line);
			string date = line.substr(0, line.find(","));
			string status = line.substr(line.find(",")+1, line.find(",") + 2);
			achievement_status[i].unlock_date = date;
			achievement_status[i].unlock_status = status == "1";
		}
		fr.close();
	}
	else {
		cout << "Unable to open achievement.txt file";
	}
}

void AchievementScene::updateAchievementStatus()
{
	// update the achievement status by comparing the achievement_status array with the achievement_list array
	for (int i = 0; i < 5; i++) {
		if (achievement_status[i].unlock_status) {
			achievement_list[i]->setIsUnlocked(true);
			achievement_list[i]->setDescription(
				achievement_list[i]->getDescription() 
				+ "\nUnlocked on " 
				+ achievement_status[i].unlock_date
				);
		}
		else {
			achievement_list[i]->setIsUnlocked(false);
		}
	}
}
