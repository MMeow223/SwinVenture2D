#pragma once
#include "Scene.h"
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <string>
class MainMenu : public Scene
{
private:
	// text and font
	sf::Font font;
	sf::Text* text;
	sf::Text mainMenuQuoteText;
	
	// state for text blinking
	int textBlink = 255;
	int blinkspeed = 5;
	bool textBlinkUp = true;

	// shapes
	float sizex = 700;
	float sizey = 300;
	sf::RectangleShape rectangle;
	
	// sprite and texture
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture gameLogoTexture;
	sf::Sprite gameLogoSprite;
public:
	MainMenu();
	MainMenu(sf::RenderWindow* window);
	~MainMenu();
	
	// getter
	sf::RenderWindow* getWindow() { return window; }
	
	// functions
	void reset();
	void update() override;
	void clean();
	void render() override;

};


