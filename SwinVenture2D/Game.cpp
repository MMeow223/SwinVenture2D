#include "Game.h"

Game::Game()
{
	cout << "Game init" << endl;
	
	sceneID = "scene_game";
	
	// init scenes
	mainMenu = new MainMenu(window);
	gameBackgroundScene = new GameBackgroundScene(window);
	gameIntroScene = new GameIntroScene(window);
	loseGameScene = new LoseGameScene(window);
	winGameScene = new WinGameScene(window);
	achievementScene = new AchievementScene(window);

	// init scene stack
	sceneStack = Stack<Scene*>(mainMenu);
	
	// init background
	background = new Background(window);
	player =  new Player(window);
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();

	// load text and font
	dangerTexture.loadFromFile("./res/images/danger.png");
	dangerSprite.setTexture(dangerTexture);
	dangerSprite.setPosition(sf::Vector2f(0, 0));
	dangerSprite.setColor(sf::Color(255, 255, 255, 100));

	// load texture
	keyReferenceTexture.loadFromFile("./res/images/key-reference.png");
	keyReferenceSprite.setTexture(keyReferenceTexture);
	keyReferenceSprite.setPosition(sf::Vector2f(0, 0));
	
	// load shape
	hpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(sf::Vector2f(10, 10));

	maxHpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	maxHpBar.setFillColor(sf::Color::White);
	maxHpBar.setPosition(sf::Vector2f(10, 10));
	
	// init weapon
	weapon = nullptr;

	// init enemy
	enemy = createEnemy();

	// stat clock
	clock = new sf::Clock();
	damage_deal_interval = new sf::Clock();
	
	// init pop up list
	popUpList = SinglyLinkedList<PopUp*>();
	
}

Game::Game(sf::RenderWindow* window)
{
	cout << "Game init" << endl;
	sceneID = "scene_game";
	
	// set window
	this->window = window;

	// init scenes
	mainMenu = new MainMenu(this->window);
	gameBackgroundScene = new GameBackgroundScene(window);
	gameIntroScene = new GameIntroScene(window);
	loseGameScene = new LoseGameScene(window);
	winGameScene = new WinGameScene(window);
	achievementScene = new AchievementScene(window);

	// init background
	background = new Background(window);
	player = new Player(window);
	queue_list[0] = background->getLayerOneQueue();
	queue_list[1] = background->getLayerTwoQueue();
	queue_list[2] = background->getLayerThreeQueue();
	queue_list[3] = background->getLayerFourQueue();

	// init texture
	dangerTexture.loadFromFile("./res/images/danger.png");
	dangerSprite.setTexture(dangerTexture);
	dangerSprite.setPosition(sf::Vector2f(0, 0));
	dangerSprite.setColor(sf::Color(255, 255, 255, 100));
	
	keyReferenceTexture.loadFromFile("./res/images/key-reference.png");
	keyReferenceSprite.setTexture(keyReferenceTexture);
	keyReferenceSprite.setPosition(sf::Vector2f(0, 0));

	// init shapes
	hpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(sf::Vector2f(10, 10));

	maxHpBar = sf::RectangleShape(sf::Vector2f(300, 40));
	maxHpBar.setFillColor(sf::Color::White);
	maxHpBar.setPosition(sf::Vector2f(10, 10));
	
	// inti weapon
	weapon = nullptr;

	// init enemy
	enemy = createEnemy();

	// init scene stack
	sceneStack = Stack<Scene*>(mainMenu);
	
	// start clock
	clock = new sf::Clock();
	damage_deal_interval = new sf::Clock();
	
	// init text and font
	font.loadFromFile("./res/font/Symtext.ttf");
	clockText.setFont(font);
	clockText.setCharacterSize(24);
	clockText.setFillColor(sf::Color::White);
	clockText.setString(to_string((int)accumulatedTime));

	// init pop up list
	popUpList = SinglyLinkedList<PopUp*>();
	popUpList.remove();

}

Game::~Game()
{
	delete window;
	delete mainMenu;
	delete gameBackgroundScene;
	delete gameIntroScene;
	delete loseGameScene;
	delete winGameScene;
	delete achievementScene;
	delete background;
	delete player;
	delete enemy;
	delete weapon;
	delete clock;
}

void Game::checkAchievementMaster()
{
	// if the player win the game with full hp
	if (player->getHp() == player->getHpMax())
	{
		cout << "Unlock Master!" << endl;
		if (achievementScene->getAchievementUnlockStatus(0) == false) {
			popUpList.append(new PopUp(window, "./res/images/achievement-master.png"));
			achievementScene->recordAchievement("master");
		}
	}
}

// if the player win the game without using weapon
void Game::checkAchievementHopper()
{
	if (use_weapon_attack_count == 0) {
		cout << "Unlock Hopper!" << endl;
		if (achievementScene->getAchievementUnlockStatus(1) == false) {
			popUpList.append(new PopUp(window, "./res/images/achievement-hopper.png"));
			achievementScene->recordAchievement("hopper");
		}
	}
}

// if the player win the game without jump attack
void Game::checkAchievementPitcher()
{
	if (use_jump_attack_count == 0) {
		cout << "Unlock Pitcher!" << endl;
		if (achievementScene->getAchievementUnlockStatus(2) == false) {
			popUpList.append(new PopUp(window, "./res/images/achievement-pitcher.png"));
			achievementScene->recordAchievement("pitcher");
		}
	}
}

// if player lose the game without damaging enemy
void Game::checkAchievementLegend()
{
	if (player->getHp() <= 0 && total_damage_deal == 0) {
		cout << "Unlock Legend!" << endl;
		if (achievementScene->getAchievementUnlockStatus(3) == false) {
			popUpList.append(new PopUp(window, "./res/images/achievement-legend.png"));
			achievementScene->recordAchievement("legend");
		}
	}
}

// if the player defeat enemy in less than two second
void Game::checkAchievementFighter()
{
	if (shortest_damage_per_second <= 2) {
		cout << "Unlock Fighter!" << endl;

		if (achievementScene->getAchievementUnlockStatus(4) == false) {
			popUpList.append(new PopUp(window, "./res/images/achievement-fighter.png"));
			achievementScene->recordAchievement("fighter");
		}
	}
}

// update the achievement to text file once the player get the achievement
// also to prevent the achievement from showing again
// or renew the unlock date
void Game::updateAchievement()
{
	

}

// remove the weapon when its animation is finish
void Game::removeWeapon()
{

	if (weapon != nullptr) {
		if (weapon->getIsFinish()) {
			delete weapon;
			weapon = nullptr;
		}
	}
}

// creating enemy with random bubble text
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
		break;
	case 2:
		temp = "I am enemy 2";
		break;
	case 3:
		temp = "I am enemy 3";
		break;
	case 4:
		temp = "I am enemy 4";
		break;
	default:
		break;
	}
	enemy_first_attacked = false;
	return new Enemy(window, temp, sf::Vector2f(1080 - 93, 567 - 183));
}

// record the score to file
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

	// if new score higher than the old score, write to file
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
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		// only input from main menu, lose scene and win scene
		else if (event.type == sf::Event::KeyPressed && pause) {
			if (event.key.code == sf::Keyboard::Down) {
				if (sceneStack.top()->getSceneID() == "scene_main_menu"
					|| sceneStack.top()->getSceneID() == "scene_lose_game"
					|| sceneStack.top()->getSceneID() == "scene_win_game"
					) 
				{
					sceneStack.top()->setList(sceneStack.top()->getList()->getNext());
				}
			}
			if (event.key.code == sf::Keyboard::Up) {
				if (sceneStack.top()->getSceneID() == "scene_main_menu"
					|| sceneStack.top()->getSceneID() == "scene_lose_game"
					|| sceneStack.top()->getSceneID() == "scene_win_game"
					)
				{
					sceneStack.top()->setList(sceneStack.top()->getList()->getPrevious());
				}
			}
			
			// press enter key to select the option
			if (event.key.code == sf::Keyboard::Enter) {
				enterPressed = true;
				pause = true;
				
			}
			
			// press left to go previous page for game intro scene and game background scene
			if (event.key.code == sf::Keyboard::Left) {
				if (sceneStack.top()->getSceneID() == "scene_game_intro"
					|| sceneStack.top()->getSceneID() == "scene_game_background"
					)
				{
					sceneStack.top()->getBook()->previousPage();
				}
			}
			
			// press right to go next page for game intro scene and game background scene 
			if (event.key.code == sf::Keyboard::Right) {
				if (sceneStack.top()->getSceneID() == "scene_game_intro"
					|| sceneStack.top()->getSceneID() == "scene_game_background"
					)
				{
					sceneStack.top()->getBook()->nextPage();
				}
			}
			
			// press escape to go back to main menu or remove the main menu
			if (event.key.code == sf::Keyboard::Escape) {
				if (!sceneStack.empty()) {
					sceneStack.pop();
					pause = false;
				}
				else {
					sceneStack.push(mainMenu);
					pause = true;
				}
			}
		}
		// input from any game scene
		else if (event.type == sf::Event::KeyPressed) {
			
			// press escape to go back to main menu or remove the main menu
			if (event.key.code == sf::Keyboard::Escape) {
				if (!sceneStack.empty()) {
					sceneStack.pop();
					pause = false;
				}
				else {
					sceneStack.push(mainMenu);
					pause = true;
				}
				mainMenu->reset();
			}
			
			// press space to jump
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (player->onGround() ||
					player->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
					player->getPosition().x  > enemy->getPosition().x
					)
				{
					player->setIsJump(true);
				}
			}
			
			// press J for short range attack
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
				// show change this, not using queue
				if (weapon == nullptr) {
					weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 1);
				}
			}
			
			// press K for mid range attack
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
				if (weapon == nullptr) {
					weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 3);
				}
			}

			// press L for long range attack
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
				// show change this, not using queue
				if (weapon == nullptr) {
					weapon = new Weapon(window, sf::Vector2f(player->getPosition().x, player->getPosition().y), 5);
				}
			}
			
			// press X to toggle the key reference
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
				showKeyReference = !showKeyReference;
			}
		}
	}

	// only keys that need continuous input here
	if (!pause) {
		
		// press d to move right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			// limit player to move to until middle of screen if not pushing anything
			if (player->getPosition().x < 520) {
				player->setPosition(sf::Vector2f(player->getPosition().x + player->getInitVelocity(), player->getPosition().y));
			}

			// when the player collide with enemy, enemy stop moving, enemy ready for pushed by player
			if (player->getPosition().x + player->getSize().x < enemy->getPosition().x + 10 &&
				player->getPosition().x + player->getSize().x > enemy->getPosition().x - 10 &&
				player->getPosition().y + player->getSize().y >= enemy->getPosition().y &&
				player->getPosition().y + player->getSize().y <= enemy->getPosition().y + enemy->getSize().y
				) 
			{
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
		}

		// press a to move left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (player->getPosition().x > 0 - player->getSize().x) {
				player->setPosition(sf::Vector2f(player->getPosition().x - player->getInitVelocity(), player->getPosition().y));
			}
		}
	}
}
void Game::reset() {
	player = new Player(window);
	clock->restart();
	ememies_killed = 0;
	time_taken = 0;
	score = 0;
	use_weapon_attack_count = 0;
	use_jump_attack_count = 0;
	total_damage_deal = 0;
	damage_deal_interval->restart();
	shortest_damage_per_second = 1000;
	
}

// if the pop up is finish, remove it
void Game::updatePopUpList()
{
	if (popUpList.getSize() > 0) {
		if (popUpList.getList()->getValue()->getIsFinish()) {
			popUpList.remove();
		}
	}
}

void Game::handleClock()
{
	if (pause) {
		accumulatedTime += (int)clock->getElapsedTime().asSeconds();
		clock->restart();
		clockText.setString("Time [pause]: " + to_string((int)(accumulatedTime + (int)clock->getElapsedTime().asSeconds())));
	}
	else {
		clockText.setString("Time: " + to_string((int)(accumulatedTime + (int)clock->getElapsedTime().asSeconds())));
	}
}

void Game::update()
{
	
	updatePopUpList();
	
	// if the scene stack is empty, means that the game is not pause
	pause = !sceneStack.empty();

	// handle clock
	handleClock();
	
	// check if player have win
	checkWinCondition();

	// when player die (lose)
	checkLoseCondition();

	// update the clock text position based on the text length
	clockText.setPosition(1080 - clockText.getLocalBounds().width - 10, 10);

	// jump attack
	checkJumpAttack();
	
	// can stand on enemy head
	checkStandOnEnemyHead();
	
	// enemy can block and push player
	checkPlayerEnemyCollide();

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
	
	checkWeaponEnemyCollide();
	
	hpBar.setSize(sf::Vector2f(player->getHp()/ player->getHpMax()*300, 40));
	
	if (!pause) player->update();

	if (!pause && move_distance > 0) {
		move_distance -= 0.1;
		if (move_distance <0) move_distance = 0;
	}

	background->setMoveDistance(move_distance);
	
	// after press the enter, check which optin is choosen
	checkSelectedOption();
	
	// remove weapon when the animation is finish
	removeWeapon();

	// update the border color
	updateWindowBorderColor();

}

void Game::updateWindowBorderColor()
{
	float danger_opacity = (enemy->getPosition().x / (enemy->getPosition().x + enemy->getSize().x)) * 255;
	if (enemy->getPosition().x < 0) {
		danger_opacity = 0;
	}
	dangerSprite.setColor(sf::Color(255, 255, 255, 255 - danger_opacity));
}

void Game::checkSelectedOption()
{
	if (enterPressed) {
		if (sceneStack.top()->getSceneID() == "scene_main_menu"
			|| sceneStack.top()->getSceneID() == "scene_win_game"
			|| sceneStack.top()->getSceneID() == "scene_lose_game"
			) {

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
		}
		enterPressed = false;
	}
}

void Game::checkWeaponEnemyCollide()
{
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
		}
	}
}

void Game::checkPlayerEnemyCollide()
{
	if (player->getPosition().x + player->getSize().x < enemy->getPosition().x + 10 &&
		player->getPosition().x + player->getSize().x > enemy->getPosition().x - 10 &&
		player->getPosition().y + player->getSize().y >= enemy->getPosition().y &&
		player->getPosition().y + player->getSize().y <= enemy->getPosition().y + enemy->getSize().y
		) {
		player->setPosition(sf::Vector2f(enemy->getPosition().x - player->getSize().x, player->getPosition().y));
	}
}

void Game::checkStandOnEnemyHead()
{
	if (player->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
		player->getPosition().x  > enemy->getPosition().x
		)
	{
		player->setStandOnEnemyHead(true);
	}
	else {
		player->setStandOnEnemyHead(false);
	}
}

void Game::checkJumpAttack()
{
	if (player->getPosition().x < enemy->getPosition().x + enemy->getSize().x &&
		player->getPosition().x  > enemy->getPosition().x
		&& player->getPosition().y + player->getSize().y > enemy->getPosition().y
		)
	{
		enemy->setHp(enemy->getHp() - player->getDamage());
		use_jump_attack_count++;
		total_damage_deal += player->getDamage();
	}
}

void Game::checkLoseCondition()
{
	if (player->getHp() <= 0) {
		checkAchievementLegend();
		sceneStack.push(loseGameScene);
		reset();
	}
}

void Game::checkWinCondition()
{
	if (ememies_killed > 1) {
		checkAchievementPitcher();
		checkAchievementMaster();
		checkAchievementHopper();

		score = (int)((500 - (int)accumulatedTime - (int)clock->getElapsedTime().asSeconds()) * 51);
		time_taken = (int)accumulatedTime + (int)clock->getElapsedTime().asSeconds();
		winGameScene->setScoreText(to_string(score));
		winGameScene->setTimeText(to_string(time_taken));
		sceneStack.push(winGameScene);
		recordScoreToFile();
		reset();

	}
}

void Game::render()
{

	// show game background
	background->render();

	// things to render when game start
	if (!pause)
	{
		player->render();
		enemy->render();
		window->draw(dangerSprite);
		window->draw(maxHpBar);
		window->draw(hpBar);
	}

	// show key reference if it is set to shown
	if (showKeyReference) window->draw(keyReferenceSprite);

	// show weapon if it is there is one
	if (weapon != nullptr) weapon->render();

	// show the scene if there is one in the stack
	if (!sceneStack.empty()) sceneStack.top()->render();
	
	// show the timer
	window->draw(clockText);

	// show the pop ups if there is one
	if (popUpList.getSize() > 0) popUpList.getList()->getValue()->render();
	
}

