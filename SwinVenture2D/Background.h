#pragma once
#include <iostream>
#include <string>
//#include <queue>
#include "Queue.h"
#include "SFML/Graphics.hpp"
#include "BackgroundLayer.h"
using namespace std;

class Background
{
private:
	Queue<BackgroundLayer*> layer_one_queue;
	Queue<BackgroundLayer*> layer_two_queue;
	Queue<BackgroundLayer*> layer_three_queue;
	Queue<BackgroundLayer*> layer_four_queue;
	bool autoloop = false;
	float move_distance = 20;
public:
	Background();
	~Background();

	//getter
	Queue<BackgroundLayer*> getLayerOneQueue() { return this->layer_one_queue; }
	Queue<BackgroundLayer*> getLayerTwoQueue() { return this->layer_two_queue; }
	Queue<BackgroundLayer*> getLayerThreeQueue() { return this->layer_three_queue; }
	Queue<BackgroundLayer*> getLayerFourQueue() { return this->layer_four_queue; }
	bool getAutoloop() { return this->autoloop; }
	float getMoveDistance() { return this->move_distance; }

	//setter
	void setAutoLoop(bool autoloop) { this->autoloop = autoloop; }
	void setMoveDistance(float move_distance) { this->move_distance = move_distance; }
	
	void AutoLoop();
	void update();
	void render(sf::RenderWindow* window);
};

