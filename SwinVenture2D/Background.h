#pragma once
#include <iostream>
#include <string>
#include <queue>
#include "SFML/Graphics.hpp"
#include "BackgroundLayer.h"
using namespace std;

class Background
{
private:
	queue<BackgroundLayer*> layer_one_queue;
	queue<BackgroundLayer*> layer_two_queue;
	queue<BackgroundLayer*> layer_three_queue;
	queue<BackgroundLayer*> layer_four_queue;
	bool autoloop = false;
	float move_distance = 0.1;
public:
	Background();
	~Background();

	//getter
	//BackgroundLayer* getLayer(int i) { return this->layers[i]; }
	queue<BackgroundLayer*> getLayerOneQueue() { return this->layer_one_queue; }
	queue<BackgroundLayer*> getLayerTwoQueue() { return this->layer_two_queue; }
	queue<BackgroundLayer*> getLayerThreeQueue() { return this->layer_three_queue; }
	queue<BackgroundLayer*> getLayerFourQueue() { return this->layer_four_queue; }
	bool getAutoloop() { return this->autoloop; }
	float getMoveDistance() { return this->move_distance; }

	//setter
	void setAutoLoop(bool autoloop) { this->autoloop = autoloop; }
	void setMoveDistance(float move_distance) { this->move_distance = move_distance; }
	
	void AutoLoop();
	void update();
	void render(sf::RenderWindow* window);
};

