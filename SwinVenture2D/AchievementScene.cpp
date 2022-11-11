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

	book = nullptr;
	//book = new Book(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/bookcover-background.png");

	texture.loadFromFile("./res/images/bookcover-achievement.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(1080 / 2 - sprite.getLocalBounds().width / 2, 720 / 2 - sprite.getLocalBounds().height / 2));

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

	ptr = achievement_list;
	// creating the both iterator
	iter = new Iterator<Achievement*>(ptr, 5);


	temp = new Achievement(
		window,
		sf::Vector2f(0, 0),
		"./res/images/achievement-master.png",
		"Master",
		"Win the game without taking any damage.");

	loadAchievementFromFile();
	updateAchievementStatus();
}

AchievementScene::~AchievementScene()
{
}

void AchievementScene::update()
{
	//book->update();
}

void AchievementScene::render()
{
	// print the curren tmouse position
	//cout << "Mouse Position: " << sf::Mouse::getPosition(*window).x << ", " << sf::Mouse::getPosition(*window).y << endl;
	
	//temp->render();
	//oneDimensionArray[0]->render();
	//oneDimensionArray[1]->render();
	//oneDimensionArray[2]->render();
	
	//for (int i = 0; i < 5; i++)
	//{
	//	oneDimensionArray[i]->render();
	//}

	//(*(iter->begin()))->render();

	//iter->getItem(0)->render();
	window->draw(sprite);

	for (Iterator<Achievement*> i = *iter; i != i.end(); i++) {
		//cout << i.getIndex() << endl;
		//cout << (**i)->getDescription() << endl;
		(**i)->render();
	}

	//for (Iterator<Achievement*> i = (*iter).end(); i != i.begin(); i--) {
	//	cout << i.getIndex() << endl;
	//	//cout << (**i)->getDescription() << endl;
	//	(**i)->render();
	//}
	//window->draw(sprite);
	//book->render();
}

void AchievementScene::loadAchievementFromFile()
{
	// read from file
	ifstream fr("./data/achievement.txt", std::ifstream::in);
	if (fr.is_open()) {
		string line;
		for (int i = 0; i < 5; i++) {
			getline(fr, line);

			string date = line.substr(0, line.find(","));
			string status = line.substr(line.find(",")+1, line.find(",") + 2);
			cout << date << " | " << status << endl;
			
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
