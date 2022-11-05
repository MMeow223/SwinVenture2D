#include "Game.h"

Game::Game()
{
	cout << "Game init" << endl;

	mainMenu = new MainMenu(window);
	background = new Background();
	player =  new Entity(window, "./res/images/player.png", sf::Vector2f(520, -300));
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();

	dangerTexture.loadFromFile("./res/images/danger.png");
	dangerSprite.setTexture(dangerTexture);
	dangerSprite.setPosition(sf::Vector2f(0, 0));
	dangerSprite.setColor(sf::Color(255, 255, 255, 100));

}

Game::Game(sf::RenderWindow* window)
{
	cout << "Game init" << endl;
	this->window = window;
	this->window->setFramerateLimit(60);
	this->window->setKeyRepeatEnabled(false);
	mainMenu = new MainMenu(this->window);
	background = new Background();
	player = new Entity(window, "./res/images/player.png", sf::Vector2f(520, -300));
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();

	dangerTexture.loadFromFile("./res/images/danger.png");
	dangerSprite.setTexture(dangerTexture);
	dangerSprite.setPosition(sf::Vector2f(0, 0));
	dangerSprite.setColor(sf::Color(255, 255, 255, 100));
}

Game::~Game()
{
	delete window;
	delete background;
}

void Game::handle_event()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		// only input from menu
		else if (event.type == sf::Event::KeyPressed && showMainMenu) {
			if (event.key.code == sf::Keyboard::Down) {
				mainMenu->setList(mainMenu->getList()->getNext());
			}
			if (event.key.code == sf::Keyboard::Up) {
				mainMenu->setList(mainMenu->getList()->getPrevious());
			}
			if (event.key.code == sf::Keyboard::Enter) {
				enterPressed = true;
			}
		}
		// input from any screen
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				cout << "Exist";
				gameStart = false;
				showMainMenu = true;
				move_distance = init_move_distance;
				mainMenu->reset();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (player->onGround()) {
					player->setIsJump(true);
				}
			}
		}
	}

	// only keys that need continuous input here
	if (gameStart) {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			// move player until middle of screen
			if (player->getPosition().x < 520) {
				player->setPosition(sf::Vector2f(player->getPosition().x + 2, player->getPosition().y));
			}
			move_distance = 2;
		}
		else {
			move_distance = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (player->getPosition().x > 0 - player->getSize().x) {
				player->setPosition(sf::Vector2f(player->getPosition().x - 2, player->getPosition().y));
			}
		}
	}
}

void Game::update()
{
	
	if (player->getPosition().x < 0 - player->getSize().x) {
		cout << "Game Over" << endl;
	}
	
	if (gameStart) player->update();

	showMainMenu = !gameStart;
	if (gameStart && background->getMoveDistance() > 0) {
		background->setMoveDistance(background->getMoveDistance() - 0.1);
	}
	background->setMoveDistance(move_distance);
	
	mainMenu->update();
	
	if (enterPressed && showMainMenu) {
		switch (mainMenu->getList()->getValue().number)
		{
		case 1: 
			gameStart = true;
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
}

void Game::clean()
{
}

void Game::render()
{
	// need to extract this to somewhere
	float danger_opacity = (player->getPosition().x / (player->getPosition().x + player->getSize().x)) * 255;
	if (player->getPosition().x < 0) {
		danger_opacity = 0;
	}
	dangerSprite.setColor(sf::Color(255, 255, 255, 255- danger_opacity));
	//
	

	
	if (showBackground) background->render(window);
	if (showMainMenu) mainMenu->render();
	if (gameStart) player->render();

	window->draw(dangerSprite);

}
