#pragma once
#include "Scene.h"
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <string>
class WinGameScene : public Scene
{
private:
	//CircularDoublyLinkedList<Content>* list;
	sf::Font font;
	sf::Text text;
	sf::Text scoreText;
	sf::Text timeText;
	sf::Text mainMenuQuoteText;
	int textBlink = 255;
	int blinkspeed = 5;
	bool textBlinkUp = true;

	//float sizex = 700;
	//float sizey = 300;



	//sf::RectangleShape rectangle;
	sf::Texture texture;
	sf::Sprite sprite;
	// sprite and texture
	//sf::Texture gameLogoTexture;
	//sf::Sprite gameLogoSprite;
public:
	WinGameScene();
	WinGameScene(sf::RenderWindow* window);
	~WinGameScene();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	
	//CircularDoublyLinkedList<Content>* getList() { return list; }

	//setter
	void setQuoteText(string quoteText) { mainMenuQuoteText.setString(quoteText); }
	void setTimeText(string newtext) { timeText.setString("Time Taken : " + newtext + " (sec)"); }
	void setScoreText(string newtext) { scoreText.setString("Score : " + newtext ); }
	
	
	//void setList(CircularDoublyLinkedList<Content>* list) { this->list = list; }
	void reset();
	void update() override;
	void clean();
	void render() override;

};


