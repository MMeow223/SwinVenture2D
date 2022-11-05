#include "Background.h"

Background::Background()
{
	cout << "Background init" << endl;
	//layers[2] = new BackgroundLayer("./res/images/background-layer3.png", 2.5, sf::Vector2f(0.f,0.f));
	//layers[1] = new BackgroundLayer("./res/images/background-layer2.png", 2.0, sf::Vector2f(0.f, 0.f));
	//layers[0] = new BackgroundLayer("./res/images/background-layer1.png", 1.5, sf::Vector2f(0.f, 0.f));

	

	layer_one_queue.push(new BackgroundLayer("./res/images/background-layer1.png", 1, sf::Vector2f(0.0f, 0.f)));
	layer_one_queue.push(new BackgroundLayer("./res/images/background-layer1.png", 1, sf::Vector2f(2160, 0.f)));
	layer_two_queue.push(new BackgroundLayer("./res/images/background-layer2.png", 1.3, sf::Vector2f(0.f, 0.f)));
	layer_two_queue.push(new BackgroundLayer("./res/images/background-layer2.png", 1.3, sf::Vector2f(2160, 0.f)));
	layer_three_queue.push(new BackgroundLayer("./res/images/background-layer3.png", 1.7, sf::Vector2f(0.f, 0.f)));
	layer_three_queue.push(new BackgroundLayer("./res/images/background-layer3.png", 1.7, sf::Vector2f(2160, 0.f)));
	layer_four_queue.push(new BackgroundLayer("./res/images/background-layer4.png", 2.5, sf::Vector2f(0.f, 0.f)));
	layer_four_queue.push(new BackgroundLayer("./res/images/background-layer4.png", 2.5, sf::Vector2f(2160, 0.f)));

	//layer_one_queue.push(new BackgroundLayer("./res/images/background-layer1.png", 1, sf::Vector2f(-1080, 0.f)));
	//layer_one_queue.push(new BackgroundLayer("./res/images/background-layer1.png", 1, sf::Vector2f(-3240, 0.f)));
	//layer_two_queue.push(new BackgroundLayer("./res/images/background-layer2.png", 1.3, sf::Vector2f(-1080, 0.f)));
	//layer_two_queue.push(new BackgroundLayer("./res/images/background-layer2.png", 1.3, sf::Vector2f(-3240, 0.f)));
	//layer_three_queue.push(new BackgroundLayer("./res/images/background-layer3.png", 1.7, sf::Vector2f(-1080, 0.f)));
	//layer_three_queue.push(new BackgroundLayer("./res/images/background-layer3.png", 1.7, sf::Vector2f(-3240, 0.f)));
	//layer_four_queue.push(new BackgroundLayer("./res/images/background-layer4.png", 2.5, sf::Vector2f(-1080, 0.f)));
	//layer_four_queue.push(new BackgroundLayer("./res/images/background-layer4.png", 2.5, sf::Vector2f(-3240, 0.f)));
	//layer_one_queue.push(layers[0]);
	//layer_three_queue.push(layers[1]);
	//back_layer_queue.push(layers[2]);
}

Background::~Background()
{
}

void Background::AutoLoop()
{

	if (autoloop) {
		layer_four_queue.front()->setPosition(
			sf::Vector2f(
				layer_four_queue.front()->getPosition().x - move_distance * layer_four_queue.front()->getSpeed(),
				0
			)
		);
		layer_four_queue.back()->setPosition(
			sf::Vector2f(
				layer_four_queue.back()->getPosition().x - move_distance * layer_four_queue.back()->getSpeed(),
				0
			)
		);
		// middle
		layer_three_queue.front()->setPosition(
			sf::Vector2f(
				layer_three_queue.front()->getPosition().x - move_distance * layer_three_queue.front()->getSpeed(),
				0
			)
		);
		layer_three_queue.back()->setPosition(
			sf::Vector2f(
				layer_three_queue.back()->getPosition().x - move_distance * layer_three_queue.back()->getSpeed(),
				0
			)
		);
		layer_two_queue.front()->setPosition(
			sf::Vector2f(
				layer_two_queue.front()->getPosition().x - move_distance * layer_two_queue.front()->getSpeed(),
				0
			)
		);
		layer_two_queue.back()->setPosition(
			sf::Vector2f(
				layer_two_queue.back()->getPosition().x - move_distance * layer_two_queue.back()->getSpeed(),
				0
			)
		);
		// front
		layer_one_queue.front()->setPosition(
			sf::Vector2f(
				layer_one_queue.front()->getPosition().x - move_distance * layer_one_queue.front()->getSpeed(),
				0
			)
		);
		layer_one_queue.back()->setPosition(
			sf::Vector2f(
				layer_one_queue.back()->getPosition().x - move_distance * layer_one_queue.back()->getSpeed(),
				0
			)
		);
	}
}

void Background::update()
{
	AutoLoop();
	
	// moving to right
	if (layer_one_queue.front()->getPosition().x < -2160) {
		float temp = layer_one_queue.front()->getPosition().x + 4320;
		delete layer_one_queue.front();
		layer_one_queue.pop();
		cout << "Remove Layer One" << endl;
		layer_one_queue.push(new BackgroundLayer("./res/images/background-layer1.png", 1, sf::Vector2f(temp, 0.f)));
		cout << "Create Layer One" << endl;
	}
	if (layer_two_queue.front()->getPosition().x < -2160) {
		float temp = layer_two_queue.front()->getPosition().x + 4320;
		delete layer_two_queue.front();
		layer_two_queue.pop();
		cout << "Remove Layer Two" << endl;
		layer_two_queue.push(new BackgroundLayer("./res/images/background-layer2.png", 1.3, sf::Vector2f(temp, 0.f)));
		cout << "Create Layer Two" << endl;
	}
	if (layer_three_queue.front()->getPosition().x < -2160) {
		float temp = layer_three_queue.front()->getPosition().x + 4320;
		delete layer_three_queue.front();
		layer_three_queue.pop();
		cout << "Remove Layer Three" << endl;
		layer_three_queue.push(new BackgroundLayer("./res/images/background-layer3.png", 1.7, sf::Vector2f(temp, 0.f)));
		cout << "Create Layer Three" << endl;
	}
	if (layer_four_queue.front()->getPosition().x < -2160) {
		float temp = layer_four_queue.front()->getPosition().x + 4320;
		delete layer_four_queue.front();
		layer_four_queue.pop();
		cout << "Remove Layer Four" << endl;
		layer_four_queue.push(new BackgroundLayer("./res/images/background-layer4.png", 2.5, sf::Vector2f(temp, 0.f)));
		cout << "Create Layer Four" << endl;
	}
		//moving to left
	//if (layer_one_queue.front()->getPosition().x > 1080) {
	//	float temp = layer_one_queue.front()->getPosition().x - 4320;
	//	delete layer_one_queue.front();
	//	layer_one_queue.pop();
	//	cout << "Remove Layer One" << endl;
	//	layer_one_queue.push(new BackgroundLayer("./res/images/background-layer1.png", 1, sf::Vector2f(temp, 0.f)));
	//	cout << "Create Layer One" << endl;
	//}
	//if (layer_two_queue.front()->getPosition().x > 1080) {
	//	float temp = layer_two_queue.front()->getPosition().x - 4320;
	//	delete layer_two_queue.front();
	//	layer_two_queue.pop();
	//	cout << "Remove Layer Two" << endl;
	//	layer_two_queue.push(new BackgroundLayer("./res/images/background-layer2.png", 1.3, sf::Vector2f(temp, 0.f)));
	//	cout << "Create Layer Two" << endl;
	//}
	//if (layer_three_queue.front()->getPosition().x > 1080) {
	//	float temp = layer_three_queue.front()->getPosition().x - 4320;
	//	delete layer_three_queue.front();
	//	layer_three_queue.pop();
	//	cout << "Remove Layer Three" << endl;
	//	layer_three_queue.push(new BackgroundLayer("./res/images/background-layer3.png", 1.7, sf::Vector2f(temp, 0.f)));
	//	cout << "Create Layer Three" << endl;
	//}
	//if (layer_four_queue.front()->getPosition().x > 1080) {
	//	float temp = layer_four_queue.front()->getPosition().x - 4320;
	//	delete layer_four_queue.front();
	//	layer_four_queue.pop();
	//	cout << "Remove Layer Four" << endl;
	//	layer_four_queue.push(new BackgroundLayer("./res/images/background-layer4.png", 2.5, sf::Vector2f(temp, 0.f)));
	//	cout << "Create Layer Four" << endl;
	//}
}

void Background::render(sf::RenderWindow* window)
{
	update();
	layer_one_queue.front()->render(window);
	layer_one_queue.back()->render(window);

	layer_two_queue.front()->render(window);
	layer_two_queue.back()->render(window);
	
	layer_three_queue.front()->render(window);
	layer_three_queue.back()->render(window);
	
	layer_four_queue.front()->render(window);
	layer_four_queue.back()->render(window);
	
}
