#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Book.h"

using namespace std;
class GameBackgroundScene : public Scene
{
private:
	// sprite and textuer
	sf::Sprite sprite;
	sf::Texture texture;

public:
	GameBackgroundScene();
	GameBackgroundScene(sf::RenderWindow* window);
	~GameBackgroundScene();

	// functions
	void update();
	void render();

};

