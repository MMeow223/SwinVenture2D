#include "Game.h"

Game::Game()
{
	cout << "Game init" << endl;
	//window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D - Game");
	//window->setFramerateLimit(60);
	//window->setKeyRepeatEnabled(false);
	mainMenu = new MainMenu(window);
	background = new Background();
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();
	//move_distance = background->getMoveDistance();
	//list = new CircularDoublyLinkedList<Content>("->Start Game\nQuick Introduction\nAbout this game\nExit", 1);
	//list->append("Start Game\nQuick Introduction\nAbout this game\n->Exit", 4);
	//list->append("Start Game\nQuick Introduction\n->About this game\nExit", 3);
	//list->append("Start Game\n->Quick Introduction\nAbout this game\nExit", 2);


	//font.loadFromFile("./res/font/Symtext.ttf");

	//text.setFont(font);
	//text.setString("Start Game\nQuick Introduction\nAbout this game\nExit");
	//text.setCharacterSize(24);
	//text.setFillColor(sf::Color::White);
	//text.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 20);

	//// create a rectangle in the middle of the screen with 50% opacity (alpha)
	//float sizex = 700;
	//float sizey = 300;
	//rectangle = sf::RectangleShape(sf::Vector2f(sizex, sizey));
	//rectangle.setFillColor(sf::Color(0, 0, 0, 200));
	//rectangle.setPosition(540 - sizex / 2, 360 - sizey / 2);

}

Game::Game(sf::RenderWindow* window)
{
	cout << "Game init" << endl;
	this->window = window;
	this->window->setFramerateLimit(60);
	this->window->setKeyRepeatEnabled(false);
	mainMenu = new MainMenu(this->window);
	background = new Background();
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();
	//move_distance = background->getMoveDistance();
	//list = new CircularDoublyLinkedList<Content>("->Start Game\nQuick Introduction\nAbout this game\nExit", 1);
	//list->append("Start Game\nQuick Introduction\nAbout this game\n->Exit", 4);
	//list->append("Start Game\nQuick Introduction\n->About this game\nExit", 3);
	//list->append("Start Game\n->Quick Introduction\nAbout this game\nExit", 2);


	//font.loadFromFile("./res/font/Symtext.ttf");

	//text.setFont(font);
	//text.setString("Start Game\nQuick Introduction\nAbout this game\nExit");
	//text.setCharacterSize(24);
	//text.setFillColor(sf::Color::White);
	//text.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 20);

	// create a rectangle in the middle of the screen with 50% opacity (alpha)
	//float sizex = 700;
	//float sizey = 300;
	//rectangle = sf::RectangleShape(sf::Vector2f(sizex, sizey));
	//rectangle.setFillColor(sf::Color(0, 0, 0, 200));
	//rectangle.setPosition(540 - sizex / 2, 360 - sizey / 2);
}

Game::~Game()
{
	delete window;
	delete background;
}

void Game::handle_event()
{
	//CircularDoublyLinkedList<Content>* temp = list;
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		
		// only keys with single input here
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Down) {
				cout << mainMenu->getList()->getValue().number << endl;
				//cout << list->getValue().number << endl;
				mainMenu->setList(mainMenu->getList()->getNext());
			}
			if (event.key.code == sf::Keyboard::Up) {
				cout << mainMenu->getList()->getValue().number << endl;
				//cout << list->getValue().number << endl;
				mainMenu->setList(mainMenu->getList()->getPrevious());
			}
			if (event.key.code == sf::Keyboard::Enter) {
				cout << mainMenu->getList()->getValue().number << endl;
				enterPressed = true;
			}
		}
			//break;

			// we don't process other types of events
		//default:
			//break;
		//}
	}
	

	// only keys that need continuous input here

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move_distance = 2;
		//background->setMoveDistance(2);

		//for (int i = 0; i < 4; i++) {
		//	queue_list[i].front()->setPosition(
		//		sf::Vector2f(
		//			queue_list[i].front()->getPosition().x + move_distance * queue_list[i].front()->getSpeed(),
		//			0
		//		)
		//	);
		//	queue_list[i].back()->setPosition(
		//		sf::Vector2f(
		//			queue_list[i].back()->getPosition().x + move_distance *queue_list[i].front()->getSpeed(),
		//			0
		//		)
		//	);
		//}

		// back
		//background->getLayerFourQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerFourQueue().front()->getPosition().x - background->getMoveDistance() * background->getLayerFourQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerFourQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerFourQueue().back()->getPosition().x - background->getMoveDistance() * background->getLayerFourQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//// middle
		//background->getLayerThreeQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerThreeQueue().front()->getPosition().x - background->getMoveDistance() * background->getLayerThreeQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerThreeQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerThreeQueue().back()->getPosition().x - background->getMoveDistance() * background->getLayerThreeQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//// front
		//background->getLayerTwoQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerTwoQueue().front()->getPosition().x - background->getMoveDistance() * background->getLayerTwoQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerTwoQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerTwoQueue().back()->getPosition().x - background->getMoveDistance() * background->getLayerTwoQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//// front
		//background->getLayerOneQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerOneQueue().front()->getPosition().x - background->getMoveDistance() * background->getLayerOneQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerOneQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerOneQueue().back()->getPosition().x - background->getMoveDistance() * background->getLayerOneQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//pos_x+=0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		//for (int i = 0; i < 4; i++) {
		//	queue_list[i].front()->setPosition(
		//		sf::Vector2f(
		//			queue_list[i].front()->getPosition().x - move_distance * queue_list[i].front()->getSpeed(),
		//			0
		//		)
		//	);
		//	queue_list[i].back()->setPosition(
		//		sf::Vector2f(
		//			queue_list[i].back()->getPosition().x - move_distance * queue_list[i].back()->getSpeed(),
		//			0
		//		)
		//	);
		//}
		// back
		//background->getLayerFourQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerFourQueue().front()->getPosition().x + move_distance * background->getLayerFourQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerFourQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerFourQueue().back()->getPosition().x + move_distance * background->getLayerFourQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//// middle
		//background->getLayerThreeQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerThreeQueue().front()->getPosition().x + move_distance * background->getLayerThreeQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerThreeQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerThreeQueue().back()->getPosition().x + move_distance * background->getLayerThreeQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//// front
		//background->getLayerTwoQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerTwoQueue().front()->getPosition().x + move_distance * background->getLayerTwoQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerTwoQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerTwoQueue().back()->getPosition().x + move_distance * background->getLayerTwoQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//// front
		//background->getLayerOneQueue().front()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerOneQueue().front()->getPosition().x + move_distance * background->getLayerOneQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//background->getLayerOneQueue().back()->setPosition(
		//	sf::Vector2f(
		//		background->getLayerOneQueue().back()->getPosition().x + move_distance * background->getLayerOneQueue().front()->getSpeed(),
		//		0
		//	)
		//);
		//pos_x-=0.1;
	}
}

void Game::update()
{


	if (gameStart) {
		showMainMenu = false;
		//move_distance = 0;
	}
	/*else {
		move_distance = init_move_distance;
	}
	*/
	if (gameStart && background->getMoveDistance() <= 3) {
		//background->setMoveDistance(0);
		//background->setMoveDistance(background->getMoveDistance() + 0.1);
		//cout << background->getMoveDistance() << endl;
	}
	background->setMoveDistance(move_distance);
	
	mainMenu->update();
	
	if (enterPressed) {
		switch (mainMenu->getList()->getValue().number)
		{
		case 1: 
			gameStart = true;
			background->setMoveDistance(0);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			window->close();
			break;
		default:
			break;
		}
		enterPressed = false;
	}
	

	//text.setString(list->getValue().title);
}

void Game::clean()
{
}

void Game::render()
{
	
	if (showBackground) background->render(window);
	if (showMainMenu) mainMenu->render();



	//window->draw(rectangle);
	//window->draw(text);

}
