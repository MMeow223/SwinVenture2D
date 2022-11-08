#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include <queue>
#include "CircularDoublyLinkedList.h"
#include "Scene.h"
#include "MainMenu.h"
#include "Entity.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Star.h"
#include <random>
#include <stack>
#include "DoublyLinkedList.h"
#include "Page.h"
#include "Book.h"
#include "GameIntroScene.h"
#include "GameBackgroundScene.h"
using namespace std;
class Game : public Scene
{
private:
	MainMenu* mainMenu;
	GameBackgroundScene* gameBackgroundScene;
	GameIntroScene* gameIntroScene;
	Background* background;
	float init_move_distance = 1.5;
	float move_distance = init_move_distance;
	queue<BackgroundLayer*> queue_list[4];
	Entity* player;
	sf::Sprite dangerSprite;
	sf::Texture dangerTexture;
	sf::Sprite keyReferenceSprite;
	sf::Texture keyReferenceTexture;

	sf::RectangleShape hpBar;
	sf::RectangleShape maxHpBar;
	
	sf::Font font;
	sf::Text clockText;
	
	//Weapon* weapon;
	queue<Weapon*> weaponQueue;
	Weapon* weapon;
	Enemy* enemy;
	stack<Star*> starStack;
	//DoublyLinkedList<Page*> gameIntroPages;
	//DoublyLinkedList<Page*>* currentPage;
	Book* gameIntroBook;
	stack<Scene*> sceneStack;
	
	sf::Clock* clock;
	float accumulatedTime;
	

	bool showMainMenu = true;
	bool showBackground = true;
	bool backgroundLoop = true;
	bool enterPressed = false;
	bool gameStart = false;
	bool showKeyReference = true;
	bool showGameIntroBook = false;
	bool pause = true;
public:
	Game();
	Game(sf::RenderWindow* window);
	~Game();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	Background* getBackground() { return background; }
	
	//setter
	//void setMoveDistance(float move_distance) { this->move_distance = move_distance; }

	void removeWeapon();
	//void gameOverCheck();
	Enemy* createEnemy();
	
	void handle_event();
	void update();
	void clean();
	void render();
	
};

