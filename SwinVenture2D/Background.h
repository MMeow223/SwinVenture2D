#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Queue.h"
#include "BackgroundLayer.h"
using namespace std;

class Background
{
private:
	
	sf::RenderWindow* window;
	// background layers, there is four layer to create parallax effect when the background move.
	Queue<BackgroundLayer*> layer_one_queue;
	Queue<BackgroundLayer*> layer_two_queue;
	Queue<BackgroundLayer*> layer_three_queue;
	Queue<BackgroundLayer*> layer_four_queue;
	
	// background details
	float move_distance = 20;
	
	// state 
	bool autoloop = false;
public:
	Background(sf::RenderWindow* window);
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
	void render();
};

