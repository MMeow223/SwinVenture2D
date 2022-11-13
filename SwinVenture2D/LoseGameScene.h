#pragma once
#include "Scene.h"
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <string>
class LoseGameScene : public Scene
{
private:

	// text and font
	sf::Font font;
	sf::Text text;
	sf::Text mainMenuQuoteText;
	
	// sprite and texture
	sf::Texture texture;
	sf::Sprite sprite;
	
	// state for text blinking
	int textBlink = 255;
	int blinkspeed = 5;
	bool textBlinkUp = true;
	
public:
	LoseGameScene();
	LoseGameScene(sf::RenderWindow* window);
	~LoseGameScene();

	//getter
	sf::RenderWindow* getWindow() { return window; }

	// functions
	void reset();
	void update() override;
	void clean();
	void render() override;

};


