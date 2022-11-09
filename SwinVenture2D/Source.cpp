#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Background.h"
#include "Game.h"
#include <list>
#include <iterator>
#include "CircularDoublyLinkedList.h"
#include "Entity.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Star.h"
#include "Page.h"
#include "GameIntroScene.h"
#include "Queue.h"
#include "Stack.h"
#include "StarContainer.h"
using namespace std;
int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D");
	window->setFramerateLimit(20);
	window->setKeyRepeatEnabled(false);

	float move_distance = 0;
	Game game = Game(window);

	/*StarContainer* starContainer = new StarContainer(
		window,
		sf::Vector2f(0, 0),
		sf::Vector2f(1080, 720),
		0,
		0,
		"star.png",
		new Star(window, sf::Vector2f(1, 1), sf::Vector2f(10, 10), 1, 2, "star.png"));*/
	
	/*starContainer->insertStar(new Star(window, sf::Vector2f(2, 1), sf::Vector2f(10, 10), 1, 2, "star.png"));
	starContainer->insertStar(new Star(window, sf::Vector2f(3, 1), sf::Vector2f(10, 10), 1, 2, "star.png"));
	starContainer->insertStar(new Star(window, sf::Vector2f(4, 1), sf::Vector2f(10, 10), 1, 2, "star.png"));
	cout << starContainer->getStar()->getPosition().x << endl;
	starContainer->dropStar();
	cout << starContainer->getStar()->getPosition().x << endl;
	starContainer->dropStar();
	cout << starContainer->getStar()->getPosition().x << endl;
	starContainer->dropStar();
	cout << starContainer->getStar()->getPosition().x << endl;*/



	while (window->isOpen())
	{
		game.getBackground()->setAutoLoop(true);
		game.handle_event();
		game.update();



		window->clear();
		game.render();
		window->display();
	}
	game.clean();
	
	return 0;
}
