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

void AchievementScene::recordAchievement(string achievement_name)
{
	// get today date
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int Date = newtime.tm_mday;
	int Month = 1 + newtime.tm_mon;
	int Year = 1900 + newtime.tm_year;

	string date = to_string(Date) + "-" + to_string(Month) + "-" + to_string(Year);
	
	
	if (achievement_name == "master") {
		achievement_status[0].unlock_date = date;
		achievement_status[0].unlock_status = true;
	}
	else if (achievement_name == "hopper") {
		achievement_status[1].unlock_date = date;
		achievement_status[1].unlock_status = true;
	}
	else if (achievement_name == "pitcher") {
		achievement_status[2].unlock_date = date;
		achievement_status[2].unlock_status = true;
	}
	else if (achievement_name == "legend") {
		achievement_status[3].unlock_date = date;
		achievement_status[3].unlock_status = true;
	}
	else if (achievement_name == "fighter") {
		achievement_status[4].unlock_date = date;
		achievement_status[4].unlock_status = true;
	}
	recordToFile();
	updateAchievementStatus();

}

void AchievementScene::recordToFile() {
	// write to file
	ofstream file;
	file.open("./data/achievement.txt");
	for (int i = 0; i < 5; i++) {
		file << achievement_status[i].unlock_date << "," << achievement_status[i].unlock_status << endl;
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
