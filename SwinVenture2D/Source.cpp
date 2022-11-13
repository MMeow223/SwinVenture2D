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
#include "Page.h"
#include "GameIntroScene.h"
#include "Queue.h"
#include "Stack.h"
#include "SinglyLinkedList.h"
#include "Iterator.h"
#include "LoseGameScene.h"
#include "Achievement.h"
#include "Iterator.h"
#include "AchievementScene.h"
#include "PopUp.h"
using namespace std;
int main() {
	// init window
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D");
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);

	// init game and set the background to auto loop once it start
	Game game = Game(window);
	game.getBackground()->setAutoLoop(true);
	
	while (window->isOpen())
	{
			
		// handle inputs and events
		game.handle_event();
		
		// update game
		game.update();
		
		// render and display
		window->clear();
		game.render();
		window->display();
		
	}
	
	return 0;
}
