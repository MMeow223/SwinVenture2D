#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Book.h"

using namespace std;
class GameIntroScene : public Scene
{

private:
	// sprite and texture
	sf::Sprite sprite;
	sf::Texture texture;

public:
	GameIntroScene();
	GameIntroScene(sf::RenderWindow* window);
	~GameIntroScene();

	// functions
	void update();
	void render();
};

