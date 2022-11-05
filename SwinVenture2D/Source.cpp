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
using namespace std;
int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D");
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);

	//Entity entity1(window,"./res/images/player.png",sf::Vector2f(520,-300));
	
	float move_distance = 0;
	Game game = Game(window);
	
	CircularDoublyLinkedList<Content>* list = new CircularDoublyLinkedList<Content>("->Start Game\nQuick Introduction\nAbout this game\nExit", 1);
	list->append("Start Game\nQuick Introduction\nAbout this game\n->Exit", 4);
	list->append("Start Game\nQuick Introduction\n->About this game\nExit", 3);
	list->append("Start Game\n->Quick Introduction\nAbout this game\nExit", 2);
	CircularDoublyLinkedList<Content>* temp = list;
	//sf::Event event;
	while (window->isOpen())
	{
	
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		//	if (entity1.onGround()) {
		//		entity1.setIsJump(true);
		//	}
		//}

		//move_distance += 0.1;
		game.getBackground()->setAutoLoop(true);
		//cout << move_distance << endl;
		//game.setMoveDistance(move_distance);
		// handle game events
		game.handle_event();
		// handle game updates
		game.update();
		
		// render game
		window->clear();
		//game.setMoveDistance(0.02);
		game.render();
	/*	entity1.update();
		entity1.render();*/
		//window->draw(rectangle);
		//window->draw(text);
		//window->draw(sprite);
		window->display();
	}
	// clean up game
	game.clean();
	
	return 0;
}
