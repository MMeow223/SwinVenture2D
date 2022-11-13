#pragma once
#include "Object.h"
class PopUp : public Object
{
private:
	// shapes
	sf::RectangleShape popUpBackground;
	
	// text and font
	sf::Text popUpText;
	sf::Font font;
	string text;
	
	// state for pop up to slide in
	sf::Clock clock;
	bool turnDirection = false;
	bool isFinish = false;
	bool startClock = false;
	bool startShow = false;
	float count = 1;
	
public:
	PopUp();
	PopUp(sf::RenderWindow* window, string filepath);
	~PopUp();

	// getter
	sf::Vector2f getPosition() { return this->position; }
	sf::Vector2f getSize() { return this->size; }
	string getText() { return this->text; }
	bool getIsFinish() { return this->isFinish; }
	bool getStartClock() { return this->startClock; }
	

	// setter
	void setPosition(sf::Vector2f position) { this->position = position; }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setText(string text) { this->text = text; }
	void setIsFinish(bool isFinish) { this->isFinish = isFinish; }
	void setStartClock(bool startClock) { this->startClock = startClock; }
	
	// functions
	void update();
	void render();
	
};

