#include "Game.h"

Game::Game()
{
	cout << "Game init" << endl;
	sceneID = "scene_game";

	mainMenu = new MainMenu(window);
	gameBackgroundScene = new GameBackgroundScene(window);
	gameIntroScene = new GameIntroScene(window);
	loseGameScene = new LoseGameScene(window);
	winGameScene = new WinGameScene(window);
	achievementScene = new AchievementScene(window);

	background = new Background();
	player =  new Player(window);
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
	

	gameIntroBook = new Book(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/bookcover.png");
	sceneStack = Stack<Scene*>(mainMenu);
	//sceneStack.push(mainMenu);

	clock = new sf::Clock();
	damage_deal_interval = new sf::Clock();

	
}

Game::Game(sf::RenderWindow* window)
{
	cout << "Game init" << endl;
	sceneID = "scene_game";
	this->window = window;
	this->window->setFramerateLimit(60);
	this->window->setKeyRepeatEnabled(false);

	// scenes
	mainMenu = new MainMenu(this->window);
	gameBackgroundScene = new GameBackgroundScene(window);
	gameIntroScene = new GameIntroScene(window);
	loseGameScene = new LoseGameScene(window);
	winGameScene = new WinGameScene(window);
	achievementScene = new AchievementScene(window);

	background = new Background();
	player = new Player(window);
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

	gameIntroBook = new Book(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/bookcover.png");
	//sceneStack.push(mainMenu);
	sceneStack = Stack<Scene*>(mainMenu);
	clock = new sf::Clock();
	damage_deal_interval = new sf::Clock();
	accumulatedTime = 0;

	font.loadFromFile("./res/font/Symtext.ttf");
	clockText.setFont(font);
	clockText.setCharacterSize(24);
	clockText.setFillColor(sf::Color::White);
	clockText.setString(to_string((int)accumulatedTime));

	

}

Game::~Game()
{
	delete window;
	delete background;
}

void Game::checkAchievementMaster()
{
	if (player->getHp() == player->getHpMax()) 
	{
		cout << "Unlock Master!" << endl;
		// achievement unlock
	}
}

void Game::checkAchievementHopper()
{
	if (use_weapon_attack_count == 0){
		cout << "Unlock Hopper!" << endl;
		// achievement unlock
	}
}

void Game::checkAchievementPitcher()
{
	if (use_jump_attack_count == 0) {
		// achievement unlock
		cout << "Unlock Pitcher!" << endl;
	}
}

void Game::checkAchievementLegend()
{
	if (player->getHp() <= 0 && total_damage_deal == 0) {
		// achievement unlock
		cout << "Unlock Legend!" << endl;
	}
}

void Game::checkAchievementFighter()
{
	if (shortest_damage_per_second <= 1) {
		// achievement unlock
		cout << "Unlock Fighter!" << endl;

	}
}

void Game::updateAchievement()
{

}

void Game::removeWeapon()
{
	if (weapon != nullptr) {
		if (weapon->getIsFinish()) {
			delete weapon;
			weapon = nullptr;
		}
	}
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
		temp = "I am enemy 1";
		//temp = "Bro, can you let me peek ur assignment or not?";
		break;
	case 2:
		temp = "I am enemy 2";
		//temp = "You team leader leh. You should help me or u also fail oh.";
		break;
	case 3:
		temp = "I am enemy 3";
		//temp = "How to do this ah? Can you guide me?";
		break;
	case 4:
		temp = "I am enemy 4";
		//temp = "What is this? I don't understand. Can you explain again?";
		break;
	default:
		break;
	}
	
	return new Enemy(window, temp, sf::Vector2f(1080 - 93, 567 - 183));
	
}

void Game::recordScoreToFile()
{

	// read from file
	ifstream fr("./data/score.txt", std::ifstream::in);
	if (fr.is_open()) {
		string line;
		for (int i = 0; i < 2; i++) {
			getline(fr, line);
			game_score[i] = line;
		}
		fr.close();
	}
	else {
		cout << "Unable to open score.txt file";
	}

	// if new score bigger than the old score, write to file
	if (score > stoi(game_score[0])) {
		// write to file
		ofstream fw("./data/score.txt", std::ofstream::out);
		if (fw.is_open()) {
			fw << score << endl;
			fw << time_taken;
			fw.close();
		}
		else {
			cout << "Unable to open score.txt file";
		}
		winGameScene->setQuoteText("New Record!");
	}
	else {
		winGameScene->setQuoteText("Congratulation!!");
	}
}

void Game::handle_event()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		// only input from menu
		else if (event.type == sf::Event::KeyPressed && pause) {
			if (event.key.code == sf::Keyboard::Down) {
				if (sceneStack.top()->getSceneID() == "scene_main_menu"
					|| sceneStack.top()->getSceneID() == "scene_lose_game"
					|| sceneStack.top()->getSceneID() == "scene_win_game"
					) 
				{
					sceneStack.top()->setList(sceneStack.top()->getList()->getNext());
				}
				/*if (sceneStack.top()->getSceneID() == "scene_main_menu") {
					mainMenu->setList(mainMenu->getList()->getNext());
				}
				else if (sceneStack.top()->getSceneID() == "scene_lose_game") {

				}*/
			}
			if (event.key.code == sf::Keyboard::Up) {
				if (sceneStack.top()->getSceneID() == "scene_main_menu"
					|| sceneStack.top()->getSceneID() == "scene_lose_game"
					|| sceneStack.top()->getSceneID() == "scene_win_game"
					)
				{
					sceneStack.top()->setList(sceneStack.top()->getList()->getPrevious());
				}
				
				//mainMenu->setList(mainMenu->getList()->getPrevious());
			}
			if (event.key.code == sf::Keyboard::Enter) {
				enterPressed = true;
				pause = true;
				
			}
			if (event.key.code == sf::Keyboard::Left) {
				if (sceneStack.top()->getSceneID() != "scene_main_menu") {
					sceneStack.top()->getBook()->previousPage();
				}

			}
			if (event.key.code == sf::Keyboard::Right) {
				if (sceneStack.top()->getSceneID() != "scene_main_menu") {
					sceneStack.top()->getBook()->nextPage();
				}
			}
			if (event.key.code == sf::Keyboard::Escape) {
				if (!sceneStack.empty()) {
					sceneStack.pop();
					pause = false;
				}
				else {
					//if (sceneStack.top()->getSceneID() != "scene_main_menu") {
					sceneStack.push(mainMenu);
					pause = true;
					//}
				}
				//mainMenu->reset();
			}

		}
		// input from any screen
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				if (!sceneStack.empty()) {
					sceneStack.pop();
					pause = false;
				}
				else {
					//if (sceneStack.top()->getSceneID() != "scene_main_menu") {
					sceneStack.push(mainMenu);
					pause = true;
					//}
				}
				//stack.pop();
				//cout << "Exist";
				//gameStart = false;
				//showMainMenu = true;
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
	//if (gameStart) {
	if (!pause) {
		
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
	}
}
void Game::reset() {
	player = new Player(window);
	//enemy = createEnemy();
	clock->restart();
	ememies_killed = 0;
	time_taken = 0;
	score = 0;

	use_weapon_attack_count = 0;
	use_jump_attack_count = 0;
	total_damage_deal = 0;
	damage_deal_interval->restart();
	shortest_damage_per_second = 0;
	
}

void Game::update()
{
	
	
	// record score to text file
	// text file
	

	pause = !sceneStack.empty();


	if (pause) {
		accumulatedTime += (int)clock->getElapsedTime().asSeconds();
		clock->restart();
		clockText.setString("Time [pause]: " + to_string((int)(accumulatedTime + (int)clock->getElapsedTime().asSeconds())));
	}
	else {
		clockText.setString("Time: " + to_string((int)(accumulatedTime + (int)clock->getElapsedTime().asSeconds())));
	}
	
	if (ememies_killed > 1) {
		checkAchievementMaster();
		checkAchievementHopper();
		checkAchievementPitcher();
		
		score = (int)((500 - (int)accumulatedTime - (int)clock->getElapsedTime().asSeconds()) * 51);
		time_taken = (int)accumulatedTime + (int)clock->getElapsedTime().asSeconds();
		winGameScene->setScoreText(to_string(score));
		winGameScene->setTimeText(to_string(time_taken));
		sceneStack.push(winGameScene);
		recordScoreToFile();
		reset();
		
	}

	// when player die (lose)
	if (player->getHp() <= 0) {
		checkAchievementLegend();
		sceneStack.push(loseGameScene);
		reset();
	}

	
	clockText.setPosition(1080 - clockText.getLocalBounds().width - 10, 10);

	// jump attack
	if (player->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
		player->getPosition().x  > enemy->getPosition().x
		&& player->getPosition().y + player->getSize().y > enemy->getPosition().y
		)
	{
		enemy->setHp(enemy->getHp() - player->getDamage());
		use_jump_attack_count++;
		total_damage_deal += player->getDamage();
		
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

	// when the enemy first taking damage
	if (enemy_first_attacked == false && enemy->getHp() < enemy->getHpMax()) {
		enemy_first_attacked = true;
		damage_deal_interval->restart();
	}

	// when enemy pass the left screen
	if (enemy->getPosition().x < 0 - enemy->getSize().x) {
		enemy = createEnemy();
		player->setHp(player->getHp() - 10);
	}
	
	// when player killed the enemy
	if (enemy->getHp() <= 0) {

		
		if (damage_deal_interval->getElapsedTime().asSeconds() < shortest_damage_per_second) {
			shortest_damage_per_second = damage_deal_interval->getElapsedTime().asSeconds();
		}
		cout << "Current Time taken to kill enemy: " << damage_deal_interval->getElapsedTime().asSeconds() << endl;
		cout << "Shortest Time taken to kill enemy: " << shortest_damage_per_second << endl;
		damage_deal_interval->restart();
		checkAchievementFighter();

		enemy = createEnemy();
		ememies_killed += 1;

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
		
			use_weapon_attack_count++;
			total_damage_deal += weapon->getDamage();
			//if (damage_deal_interval->getElapsedTime().asSeconds() < shortest_damage_per_second) {
			//	shortest_damage_per_second = damage_deal_interval->getElapsedTime().asSeconds();
			//}
			//damage_deal_interval->restart();
		}
	}
	
	hpBar.setSize(sf::Vector2f(player->getHp()/ player->getHpMax()*300, 40));
	
	if (!pause) player->update();
	//if (gameStart) player->update();

	//showMainMenu = !gameStart;
	if (!pause && move_distance > 0) {
	//if (gameStart && move_distance > 0) {
		move_distance -= 0.1;
		if (move_distance <0) move_distance = 0;
		//cout << move_distance <<endl;
	}

	background->setMoveDistance(move_distance);
	
	mainMenu->update();
	
	//pause = !sceneStack.empty();
		
	if (enterPressed) {

		switch (sceneStack.top()->getList()->getValue().number)
		{
		case 1:
			//gameStart = true;
			if (!sceneStack.empty()) {
				if (sceneStack.top()->getSceneID() == "scene_main_menu") {
					sceneStack.pop();
				}
				else {
					if (sceneStack.top()->getSceneID() == "scene_lose_game"
						|| sceneStack.top()->getSceneID() == "scene_win_game"
						) {
						while (!sceneStack.empty()) {
							sceneStack.pop();
						}
					}
					else {
						sceneStack.push(mainMenu);
					}
				}
			}
			break;
		case 2:
			if (sceneStack.top()->getSceneID() == "scene_main_menu") {
				sceneStack.push(gameIntroScene);
			}
			else if (sceneStack.top()->getSceneID() == "scene_lose_game"
				|| sceneStack.top()->getSceneID() == "scene_win_game"
				) {
				while (!sceneStack.empty()) {
					sceneStack.pop();
				}
				sceneStack.push(mainMenu);
			}
			//pause = true;
			//showGameIntroBook = true;
			break;
		case 3:
			if (sceneStack.top()->getSceneID() == "scene_main_menu") {
				sceneStack.push(gameBackgroundScene);
			}
			break;
		case 4:
			window->close();
			break;
		case 5:
			if (sceneStack.top()->getSceneID() == "scene_main_menu") {
				sceneStack.push(achievementScene);
			}
			break;
		default:
			break;
		}

		//switch (mainMenu->getList()->getValue().number)
		//{
		//case 1: 
		//	//gameStart = true;
		//	if (!sceneStack.empty()) {
		//		if (sceneStack.top()->getSceneID() == "scene_main_menu") {
		//			sceneStack.pop();
		//		}
		//		else {
		//			sceneStack.push(mainMenu);
		//		}
		//	}
		//	
		//	break;
		//case 2:
		//	if (sceneStack.top()->getSceneID() == "scene_main_menu") {
		//		sceneStack.push(gameIntroScene);
		//	}
		//	//pause = true;
		//	//showGameIntroBook = true;
		//	break;
		//case 3:
		//	if (sceneStack.top()->getSceneID() == "scene_main_menu") {
		//		sceneStack.push(gameBackgroundScene);
		//	}
		//	break;
		//case 4:
		//	window->close();
		//	break;
		//default:
		//	break;
		//}

		
		enterPressed = false;
	}
	removeWeapon();

	float danger_opacity = (enemy->getPosition().x / (enemy->getPosition().x + enemy->getSize().x)) * 255;
	if (enemy->getPosition().x < 0) {
		danger_opacity = 0;
	}
	dangerSprite.setColor(sf::Color(255, 255, 255, 255 - danger_opacity));


	//checkAchievementLegend();

}

void Game::clean()
{
}

void Game::render()
{
	// need to extract this to somewhere

	if (showBackground) background->render(window);
	//if (showMainMenu) mainMenu->render();
	//if (gameStart)
	if (!pause)
	{
		player->render();
		enemy->render();
		window->draw(dangerSprite);
		window->draw(maxHpBar);
		window->draw(hpBar);
	}

	if (showKeyReference) window->draw(keyReferenceSprite);
	if (weapon != nullptr) weapon->render();
	if (!sceneStack.empty())
	{
		sceneStack.top()->render();
	}
	window->draw(clockText);
	//if (showGameIntroBook) gameIntroBook->render();
	//currentPage->getValue()->render();
	//currentPage->getNext()->getValue()->render();
	
}

