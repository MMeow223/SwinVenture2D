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
using namespace std;
int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D");
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);

	//Weapon weapon = Weapon(window);
	float move_distance = 0;
	Game game = Game(window);
	

	//Enemy* enemy = new Enemy(window, sf::Vector2f(1080 - 93, 567 - 183));
	//cout << 1080 - enemy.getSprite().getLocalBounds().width << endl;
	//enemy.setPosition(sf::Vector2f(1080 - enemy.getSprite().getLocalBounds().width, 567 - enemy.getSprite().getLocalBounds().height));
	while (window->isOpen())
	{

		// on key press
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		//	if (enemy != nullptr) {
		//		delete enemy;
		//		enemy = nullptr;
		//	}
		//}

		game.getBackground()->setAutoLoop(true);
		game.handle_event();
		game.update();
		window->clear();
		game.render();
		//if (enemy != nullptr) {
		//	enemy->render();
		//}
		//weapon.render();
		window->display();
	}
	// clean up game
	game.clean();
	
	return 0;
}
