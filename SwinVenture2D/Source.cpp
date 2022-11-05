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

	Entity entity1(window,"./res/images/player.png",sf::Vector2f(520,-300));
	
	
	// create a rectangle in the middle of the screen with 50% opacity (alpha)
	//float sizex = 700;
	//float sizey = 300;
	//sf::RectangleShape rectangle(sf::Vector2f(sizex, sizey));
	//rectangle.setFillColor(sf::Color(0, 0, 0, 200));
	//rectangle.setPosition(540- sizex/2, 360-sizey/2);

	// text
	/*sf::Font font;
	font.loadFromFile("./res/font/Symtext.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Start Game\nQuick Introduction\nAbout this game\nExit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2);*/
	
	// sprite and texture
	//sf::Texture texture;
	//texture.loadFromFile("./res/images/game-logo.png");
	//sf::Sprite sprite;
	//sprite.setTexture(texture);
	//sprite.setPosition(0, 0);
	
	
	float move_distance = 0;
	Game game = Game(window);
	//sf::RenderWindow* window= game.getWindow();
	
	CircularDoublyLinkedList<Content>* list = new CircularDoublyLinkedList<Content>("->Start Game\nQuick Introduction\nAbout this game\nExit", 1);
	list->append("Start Game\nQuick Introduction\nAbout this game\n->Exit", 4);
	list->append("Start Game\nQuick Introduction\n->About this game\nExit", 3);
	list->append("Start Game\n->Quick Introduction\nAbout this game\nExit", 2);
	CircularDoublyLinkedList<Content>* temp = list;
	//sf::Event event;
	while (window->isOpen())
	{
		//while (window->pollEvent(event))
		//{
		//	// check the type of the event...
		//	switch (event.type)
		//	{
		//	case sf::Event::KeyPressed:
		//		if (event.type == sf::Keyboard::Down) {
		//			temp = temp->getNext();
		//			cout << temp->getValue().number << endl;
		//		}
		//		break;

		//		// we don't process other types of events
		//	default:
		//		break;
		//	}
		//}
		//if (event.key.code == sf::Keyboard::Down) // event.key.CODE
		//{
		//	temp = temp->getNext();
		//	cout << temp->getValue().number << endl;
		//}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			temp = temp->getNext();
			cout << temp->getValue().number << endl;
		}*/
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		//	temp = temp->getPrevious();
		//	cout << temp->getValue().number << endl;
		//}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			entity1.setIsJump(true);
		}


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
		entity1.update();
		entity1.render();
		//window->draw(rectangle);
		//window->draw(text);
		//window->draw(sprite);
		window->display();
	}
	// clean up game
	game.clean();

	
	// example for circular doubly linked list
	//CircularDoublyLinkedList<Content>* list = new CircularDoublyLinkedList<Content>("->Start Game\nQuick Introduction\nAbout this game\nExit", 1);
	//list->append("Start Game\nQuick Introduction\nAbout this game\n->Exit", 4);
	//list->append("Start Game\nQuick Introduction\n->About this game\nExit", 3);
	//list->append("Start Game\n->Quick Introduction\nAbout this game\nExit", 2);
	////
	//for (CircularDoublyLinkedList<Content>* temp = list; temp != temp->getEnd(); temp = temp->getNext()) {
	//	cout << temp->getValue().title << endl;
	//}

	//CircularDoublyLinkedList<Content>* temp = list;
	//for (int i = 0; i < 20; i++) {
	//	cout << " Start:" << temp->getStart()->getValue().title << " | This:" << temp->getValue().title << " | End:"  << temp->getEnd()->getValue().title << endl;
	//	temp = temp->getNext();
	//}

	return 0;
}
