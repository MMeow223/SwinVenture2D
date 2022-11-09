#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include <stack>
#include "Star.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <random>
using namespace std;
class StarContainer : public Object
{
private:
	DoublyLinkedList<Star*> star_list;
	sf::RectangleShape star_container_background;
	
	
public:
	StarContainer();
	StarContainer(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, float rarity, string filepath, Star* star);
	~StarContainer();

	//getter
	DoublyLinkedList<Star*> getStarList() { return star_list; }
	sf::RectangleShape getStarContainerBackground() { return star_container_background; }
	
	//setter
	void setStarList(DoublyLinkedList<Star*> new_star_list) { this->star_list= new_star_list; }
	void setStarContainerBackground(sf::RectangleShape star_container_background) { this->star_container_background = star_container_background; }
	
	void insertStar(Star* star);
	// dropStar, when the player get damaged, the star will drop, the star selected is random.
	void dropStar();
	Star* getStar();
	
	void update();
	void render();
};

