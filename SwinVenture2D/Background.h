#pragma once
#include <iostream>
#include <string>
#include "Queue.h"
#include "SFML/Graphics.hpp"
#include "BackgroundLayer.h"
using namespace std;

class Background
{
private:
	// background layers, there is four layer to create parallax effect when 
	// the background move.
	Queue<BackgroundLayer*> layer_one_queue;
	Queue<BackgroundLayer*> layer_two_queue;
	Queue<BackgroundLayer*> layer_three_queue;
	Queue<BackgroundLayer*> layer_four_queue;
	
	// auto move only for the main menu background when this game is open
	bool autoloop = false;
	
	// distance represent how far the background move in one frame
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
	
	// functions
	void AutoLoop();
	void update();
	void render(sf::RenderWindow* window);
};

