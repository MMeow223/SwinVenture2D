#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include <queue>
#include "CircularDoublyLinkedList.h"
#include "Scene.h"
#include "MainMenu.h"
using namespace std;
class Game : public Scene
{
private:
	MainMenu* mainMenu;
	Background* background;
	float init_move_distance = 0.1;
	float move_distance = 0.1;
	queue<BackgroundLayer*> queue_list[4];
	
	
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

	void handle_event();
	void update();
	void clean();
	void render();
	
};

