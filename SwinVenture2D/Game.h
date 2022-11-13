#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <random>
#include "Background.h"
#include "CircularDoublyLinkedList.h"
#include "Scene.h"
#include "MainMenu.h"
#include "Entity.h"
#include "Weapon.h"
#include "Enemy.h"
#include "DoublyLinkedList.h"
#include "Page.h"
#include "Book.h"
#include "GameIntroScene.h"
#include "GameBackgroundScene.h"
#include "Stack.h"
#include "Player.h"
#include "LoseGameScene.h"
#include "WinGameScene.h"
#include "AchievementScene.h"
#include "PopUp.h"
#include "SinglyLinkedList.h"
using namespace std;
class Game : public Scene
{
private:
	// scenes
	Stack<Scene*> sceneStack;
	MainMenu* mainMenu;
	GameBackgroundScene* gameBackgroundScene;
	GameIntroScene* gameIntroScene;
	LoseGameScene* loseGameScene;
	WinGameScene* winGameScene;
	AchievementScene* achievementScene;

	// background
	Queue<BackgroundLayer*> queue_list[4];
	Background* background;
	float init_move_distance = 1.5;
	float move_distance = init_move_distance;
	
	// sprites & textures
	sf::Sprite dangerSprite;
	sf::Texture dangerTexture;
	sf::Sprite keyReferenceSprite;
	sf::Texture keyReferenceTexture;

	// shapes
	sf::RectangleShape hpBar;
	sf::RectangleShape maxHpBar;
	
	// font and text
	sf::Font font;
	sf::Text clockText;
	
	// game objects
	Player* player;
	Enemy* enemy;
	Weapon* weapon;
	//Book* gameIntroBook;
	
	// clock and time
	sf::Clock* clock;
	float accumulatedTime = 0;

	//SinglyLinkedList<PopUp*>* popUpList;
	SinglyLinkedList<PopUp*> popUpList;
	//Queue<PopUp*> popUpList;

	// game state
	bool showMainMenu = true;
	bool showBackground = true;
	bool backgroundLoop = true;
	bool enterPressed = false;
	bool gameStart = false;
	bool showKeyReference = true;
	bool showGameIntroBook = false;
	bool pause = true;
	
	// score and time to show after win game
	int ememies_killed = 0;
	string game_score[2] = { "", "" };
	int score = 0;
	int time_taken = 0;
	
	// achievement condition
	int use_weapon_attack_count = 0;
	int use_jump_attack_count = 0;
	int total_damage_deal = 0;
	sf::Clock* damage_deal_interval;
	float shortest_damage_per_second = 1000;
	bool enemy_first_attacked = false;
	
public:
	Game();
	Game(sf::RenderWindow* window);
	~Game();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	Background* getBackground() { return background; }

	// functions 
	void checkAchievementMaster();
	void checkAchievementHopper();
	void checkAchievementPitcher();
	void checkAchievementLegend();
	void checkAchievementFighter();
	void updateAchievement();
	void removeWeapon();
	Enemy* createEnemy();
	void recordScoreToFile();
	void reset();
	void handle_event();
	void updatePopUpList();
	void handleClock();
	void update();
	void updateWindowBorderColor();
	void checkSelectedOption();
	void checkWeaponEnemyCollide();
	void checkPlayerEnemyCollide();
	void checkStandOnEnemyHead();
	void checkJumpAttack();
	void checkLoseCondition();
	void checkWinCondition();
	void render();
	
};

