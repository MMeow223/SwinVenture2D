#pragma once
#include "Scene.h"
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <string>
class MainMenu : public Scene
{
private:
	CircularDoublyLinkedList<Content>* list;
	sf::Font font;
	sf::Text* text;
	float sizex = 700;
	float sizey = 300;
	
	sf::RectangleShape rectangle;
	sf::Texture texture;
	sf::Sprite sprite;
	// sprite and texture
	sf::Texture gameLogoTexture;
	sf::Sprite gameLogoSprite;
public:
	MainMenu();
	MainMenu(sf::RenderWindow* window);
	~MainMenu();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	CircularDoublyLinkedList<Content>* getList() { return list; }
	
	//setter
	void setList(CircularDoublyLinkedList<Content>* list) { this->list = list; }
	void reset();
	void update();
	void clean();
	void render();

};


