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
#include "SinglyLinkedList.h"
#include "Iterator.h"
#include "LoseGameScene.h"
#include "Achievement.h"
#include "Iterator.h"
#include "AchievementScene.h"
using namespace std;
int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D");
	window->setFramerateLimit(20);
	window->setKeyRepeatEnabled(false);

	float move_distance = 0;
	Game game = Game(window);
	SinglyLinkedList<int> list(1);
	//cout << list.getValue() << endl;
	list.pushBack(2);
	//cout << list.getValue() << endl;
	list.pushBack(3);
	//cout << list.getValue() << endl;

	//cout << list.front() << endl;
	cout << list.next()->getValue() << endl;
	cout << list.next()->getValue() << endl;
	//cout << list.back() << endl;
	//cout << list.back() << endl;

	//AchievementScene achievementScene = AchievementScene(window);

	while (window->isOpen())
	{
		game.getBackground()->setAutoLoop(true);
		game.handle_event();
		game.update();

		window->clear();
		game.render();
		
		//achievementScene.render();

		window->display();
	}
	game.clean();
	
	return 0;
}
