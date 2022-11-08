//#include "StarContainer.h"
//
//StarContainer::StarContainer() : Object()
//{
//	cout << "Init StarContainer" << endl;
//	star_stack = stack<Star*>();
//	star_container_background = sf::RectangleShape(size);
//}
//
//StarContainer::StarContainer(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, float rarity, string filepath)
//	: Object(window, position, size, velocity, rarity, filepath)
//{
//	star_stack = stack<Star*>();
//	star_container_background = sf::RectangleShape(size);
//	star_container_background.setPosition(position);
//}
//
//StarContainer::~StarContainer()
//{
//}
//
//void StarContainer::popStar()
//{
//	if (!star_stack.empty())
//	{
//		delete star_stack.top();
//		star_stack.pop();
//	}
//}
//
//void StarContainer::pushStar()
//{
//	sf::Vector2f star_position = sf::Vector2f(position.x + (star_stack.size() * 10), position.y);
//	star_stack.push(new Star(window, star_position, size, velocity, 1, imageFilePath));
//}
//
//void StarContainer::update()
//{
//}
//
//void StarContainer::render()
//{
//	window->draw(star_container_background);
//	
//}