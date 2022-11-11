#pragma once
#include "Scene.h"
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <string>
class LoseGameScene : public Scene
{
private:
	//CircularDoublyLinkedList<Content>* list;
	sf::Font font;
	sf::Text text;
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
	LoseGameScene();
	LoseGameScene(sf::RenderWindow* window);
	~LoseGameScene();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	//CircularDoublyLinkedList<Content>* getList() { return list; }

	//setter
	//void setList(CircularDoublyLinkedList<Content>* list) { this->list = list; }
	void reset();
	void update() override;
	void clean();
	void render() override;

};


