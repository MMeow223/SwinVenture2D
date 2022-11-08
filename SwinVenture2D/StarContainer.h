//#pragma once
//#include <iostream>
//#include <string>
//#include <SFML/Graphics.hpp>
//#include "Object.h"
//#include <stack>
//#include "Star.h"
//using namespace std;
//class StarContainer : public Object
//{
//private:
//	stack<Star*> star_stack;
//	sf::RectangleShape star_container_background;
//	
//public:
//	StarContainer();
//	StarContainer(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, float rarity, string filepath);
//	~StarContainer();
//
//	//getter
//	stack<Star*> getStarStack() { return star_stack; }
//	sf::RectangleShape getStarContainerBackground() { return star_container_background; }
//	
//	//setter
//	void setStarStack(stack<Star*> star_stack) { this->star_stack = star_stack; }
//	void setStarContainerBackground(sf::RectangleShape star_container_background) { this->star_container_background = star_container_background; }
//	
//	void popStar();
//	void pushStar();
//	
//	void update();
//	void render();
//};
//
