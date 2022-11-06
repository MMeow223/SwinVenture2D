#include "Game.h"

Game::Game()
{
	cout << "Game init" << endl;

	mainMenu = new MainMenu(window);
	background = new Background();
	player =  new Entity(window);
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();

	dangerTexture.loadFromFile("./res/images/danger.png");
	dangerSprite.setTexture(dangerTexture);
	dangerSprite.setPosition(sf::Vector2f(0, 0));
	dangerSprite.setColor(sf::Color(255, 255, 255, 100));

	keyReferenceTexture.loadFromFile("./res/images/key-reference.png");
	keyReferenceSprite.setTexture(keyReferenceTexture);
	keyReferenceSprite.setPosition(sf::Vector2f(0, 0));
	//keyReferenceSprite.setColor(sf::Color(255, 255, 255, 100));
	
	//sf::Sprite keyReferenceSprite;
	//sf::Texture keyReferenceTexture;
	
	hpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(sf::Vector2f(10, 10));

	maxHpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	maxHpBar.setFillColor(sf::Color::White);
	maxHpBar.setPosition(sf::Vector2f(10, 10));
	
	weapon = nullptr;
	//weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y));
	enemy = createEnemy();
	
}

Game::Game(sf::RenderWindow* window)
{
	cout << "Game init" << endl;
	this->window = window;
	this->window->setFramerateLimit(60);
	this->window->setKeyRepeatEnabled(false);
	mainMenu = new MainMenu(this->window);
	background = new Background();
	player = new Entity(window);
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();

	dangerTexture.loadFromFile("./res/images/danger.png");
	dangerSprite.setTexture(dangerTexture);
	dangerSprite.setPosition(sf::Vector2f(0, 0));
	dangerSprite.setColor(sf::Color(255, 255, 255, 100));
	
	keyReferenceTexture.loadFromFile("./res/images/key-reference.png");
	keyReferenceSprite.setTexture(keyReferenceTexture);
	keyReferenceSprite.setPosition(sf::Vector2f(0, 0));

	hpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(sf::Vector2f(10, 10));

	maxHpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	maxHpBar.setFillColor(sf::Color::White);
	maxHpBar.setPosition(sf::Vector2f(10, 10));
	
	weapon = nullptr;

	//weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y));
		enemy = createEnemy();

}

Game::~Game()
{
	delete window;
	delete background;
}

void Game::removeWeapon()
{
	if (weapon != nullptr) {
		if (weapon->getIsFinish()) {
			delete weapon;
			weapon = nullptr;
		}
	}
	/*if (!weaponQueue.empty()) {
		weaponQueue.front()->render();
		if (weaponQueue.front()->getIsFinish()) {
			weaponQueue.pop();
		}
	}*/
}
Enemy* Game::createEnemy()
{
	// randomly return one
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> randomNumber(1, 4); // distribution in range [1, 6]
	std::cout << randomNumber(rng) << std::endl;
	
	string temp;
	switch (randomNumber(rng))
	{
	case 1:
		temp = "Bro, can you let me peek ur assignment or not?";
		break;
	case 2:
		temp = "You team leader leh. You should help me or u also fail oh.";
		break;
	case 3:
		temp = "How to do this ah? Can you guide me?";
		break;
	case 4:
		temp = "What is this? I don't understand. Can you explain again?";
		break;
	default:
		break;
	}
	
	return new  Enemy(window, temp, sf::Vector2f(1080 - 93, 567 - 183));
	
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
				//move_distance = init_move_distance;
				mainMenu->reset();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (player->onGround() ||
					player->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
					player->getPosition().x  > enemy->getPosition().x
					)
				{
					player->setIsJump(true);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
				// show change this, not using queue
				if (weapon == nullptr) {
					weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 1);

				}
				/*if (weaponQueue.empty()) {
					weaponQueue.push(new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y),1));
				}*/
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
				if (weapon == nullptr) {
					weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 3);

				}
				/*if (weaponQueue.empty()) {
					weaponQueue.push(new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 3));
				}*/
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
				// show change this, not using queue
				if (weapon == nullptr) {
					weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 5);

				}
				/*if (weaponQueue.empty()) {
					weaponQueue.push(new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 5));
				}*/
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
				// show change this, not using queue
				showKeyReference = !showKeyReference;
			}
		}
	}

	// only keys that need continuous input here
	if (gameStart) {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			// move player until middle of screen
			if (player->getPosition().x < 520) {
				player->setPosition(sf::Vector2f(player->getPosition().x + player->getInitVelocity(), player->getPosition().y));
			}
			if (player->getPosition().x + player->getSize().x < enemy->getPosition().x + 10 &&
				player->getPosition().x + player->getSize().x > enemy->getPosition().x - 10 &&
				player->getPosition().y + player->getSize().y >= enemy->getPosition().y &&
				player->getPosition().y + player->getSize().y <= enemy->getPosition().y + enemy->getSize().y
				) 
			{
				// random
				
				enemy->setVelocity(enemy->getInitVelocity() * -1);
				move_distance = 0;
			}
			else 
			{
				enemy->setVelocity(enemy->getInitVelocity() * 2);
				move_distance = 2;
			}
			
		}
		else {
			enemy->setVelocity(enemy->getInitVelocity());
			//move_distance = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (player->getPosition().x > 0 - player->getSize().x) {
				player->setPosition(sf::Vector2f(player->getPosition().x - player->getInitVelocity(), player->getPosition().y));
			}
		}
		///
		///
		/// ///
		// for testing
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		//	if (player->getHp() - 1 != 0) {
		//		player->setHp(player->getHp()-1);
		//	}
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		//	//delete weapon;
		//	//weapon = new Weapon(window);
		//	weaponQueue.push(new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y)));
		//}
	}
}

void Game::update()
{

	
	if (player->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
		player->getPosition().x  > enemy->getPosition().x
		&& player->getPosition().y + player->getSize().y > enemy->getPosition().y
		)
	{
		enemy->setHp(enemy->getHp() - player->getDamage());
	}
	
	// can stand on enemy head
	if (player->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
		player->getPosition().x  > enemy->getPosition().x
		) 
	{
		//enemy->setHp(enemy->getHp()-2);
		player->setStandOnEnemyHead(true);
		cout << "stand on enemy head" << endl;
	}
	else {
		player->setStandOnEnemyHead(false);

	}
	
	// enemy can block and push player
	if (player->getPosition().x + player->getSize().x < enemy->getPosition().x + 10 &&
		player->getPosition().x + player->getSize().x > enemy->getPosition().x - 10 && 
		player->getPosition().y + player->getSize().y >= enemy->getPosition().y &&
		player->getPosition().y + player->getSize().y <= enemy->getPosition().y + enemy->getSize().y
		) {
		player->setPosition(sf::Vector2f(enemy->getPosition().x - player->getSize().x, player->getPosition().y));
	}

	
	
	if (enemy->getPosition().x < 0 - enemy->getSize().x) {
		enemy = createEnemy();
		player->setHp(player->getHp() - 10);
	}
	
	if (enemy->getHp() <= 0) {
		enemy = createEnemy();

	}
	//removeWeapon();
	// check collision of weapon and enemy
	if (weapon != nullptr) {
		if (weapon->getPosition().x > enemy->getPosition().x &&
			weapon->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
			weapon->getPosition().y + weapon->getSize().y > enemy->getPosition().y &&
			weapon->getPosition().y + weapon->getSize().y > enemy->getPosition().y + enemy->getSize().y

			)
		{
			weapon->setIsFinish(true);
			enemy->setHp(enemy->getHp() - weapon->getDamage());
			cout << "Hit==================================================================" << endl;

		}
	}
	//if (!weaponQueue.empty()) {
	////cout << "enemy->getPosition().x: " << enemy->getPosition().x << "weaponQueue.front()->getPosition().x: " << weaponQueue.front()->getPosition().x << endl;
	//	if (weaponQueue.front()->getPosition().x > enemy->getPosition().x &&
	//		weaponQueue.front()->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
	//		weaponQueue.front()->getPosition().y + weaponQueue.front()->getSize().y > enemy->getPosition().y &&
	//		weaponQueue.front()->getPosition().y + weaponQueue.front()->getSize().y > enemy->getPosition().y + enemy->getSize().y

	//		) 
	//	{
	//		weaponQueue.front()->setIsFinish(true);
	//		enemy->setHp(enemy->getHp() - weaponQueue.front()->getDamage());
	//		cout << "Hit==================================================================" << endl;
	//		
	//	}
	//	
	//}
	
	//if (weaponQueue.front()->getPosition().x > ) {
		
	//}
	
	hpBar.setSize(sf::Vector2f(player->getHp()/ player->getHpMax()*300, 40));
	if (player->getPosition().x < 0 - player->getSize().x) {
		cout << "Game Over" << endl;
	}
	
	if (gameStart) player->update();

	showMainMenu = !gameStart;
	if (gameStart && move_distance > 0) {
		move_distance -= 0.1;
		if (move_distance <0) move_distance = 0;
		//cout << move_distance <<endl;
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
	removeWeapon();

	float danger_opacity = (enemy->getPosition().x / (enemy->getPosition().x + enemy->getSize().x)) * 255;
	if (enemy->getPosition().x < 0) {
		danger_opacity = 0;
	}
	dangerSprite.setColor(sf::Color(255, 255, 255, 255 - danger_opacity));
}

void Game::clean()
{
}

void Game::render()
{
	// need to extract this to somewhere

	
	
	if (showBackground) background->render(window);
	if (showMainMenu) mainMenu->render();
	if (gameStart) player->render();
	if (showKeyReference) window->draw(keyReferenceSprite);

	window->draw(maxHpBar);
	window->draw(hpBar);
	enemy->render();
	window->draw(dangerSprite);
	if (weapon != nullptr) weapon->render();

}
