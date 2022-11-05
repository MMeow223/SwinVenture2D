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
using namespace std;
class Game : public Scene
{
private:
	MainMenu* mainMenu;
	Background* background;
	float init_move_distance = 3;
	float move_distance = init_move_distance;
	queue<BackgroundLayer*> queue_list[4];
	Entity* player;
	sf::Sprite dangerSprite;
	sf::Texture dangerTexture;
	

	bool showMainMenu = true;
	bool showBackground = true;
	bool backgroundLoop = true;
	bool enterPressed = false;
	bool gameStart = false;
public:
	Game();
	Game(sf::RenderWindow* window);
	~Game();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	Background* getBackground() { return background; }
	
	//setter
	//void setMoveDistance(float move_distance) { this->move_distance = move_distance; }

	void gameOverCheck();
	void handle_event();
	void update();
	void clean();
	void render();
	
};

