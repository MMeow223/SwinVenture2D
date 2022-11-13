#pragma once
#include "Scene.h"
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <string>
class WinGameScene : public Scene
{
private:
	// text and font
	sf::Font font;
	sf::Text text;
	sf::Text scoreText;
	sf::Text timeText;
	sf::Text mainMenuQuoteText;

	// state for text blinking
	int textBlink = 255;
	int blinkspeed = 5;
	bool textBlinkUp = true;

	// sprite and texture
	sf::Texture texture;
	sf::Sprite sprite;
public:
	WinGameScene();
	WinGameScene(sf::RenderWindow* window);
	~WinGameScene();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	
	//setter
	void setQuoteText(string quoteText) { mainMenuQuoteText.setString(quoteText); }
	void setTimeText(string newtext) { timeText.setString("Time Taken : " + newtext + " (sec)"); }
	void setScoreText(string newtext) { scoreText.setString("Score : " + newtext ); }
	
	// functions
	void reset();
	void update() override;
	void clean();
	void render() override;

};


