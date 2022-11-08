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
using namespace std;
int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D");
	window->setFramerateLimit(20);
	window->setKeyRepeatEnabled(false);

	float move_distance = 0;
	Game game = Game(window);

	Queue<int> queue(new int(1));
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;
	queue.push(new int(2));
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;
	queue.push(new int(3));
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;
	queue.push(new int(4));
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;
	queue.pop();
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;
	queue.pop();
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;
	queue.pop();
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;
	queue.pop();
	cout << "Front: " << *queue.front() << "| Back: " << *queue.back() << "| Size: " << queue.getSize() << endl;

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
