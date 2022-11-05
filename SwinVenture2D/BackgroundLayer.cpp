#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer()
{
	cout << "Background layer init" << endl;
	
	this->image_path = "./res/images/background-layer1.png";
	this->speed = 1;

	if (this->texture.loadFromFile(this->image_path)) {
		cout << "load file success:" << this->image_path << endl;
	}
	else {
		cout << "load file failed:" << this->image_path << endl;

	}
	//this->texture.loadFromFile(this->image_path);
	this->sprite.setTexture(this->texture);
	this->position = sf::Vector2f(0, 0);
	this->sprite.setPosition(this->position);
}

BackgroundLayer::BackgroundLayer(string image_path, float speed, sf::Vector2f position)
{
	cout << "Background layer init" << endl;
	this->image_path = image_path;
	this->speed = speed;
	if (this->texture.loadFromFile(this->image_path)) {
		cout << "load file success:" << this->image_path << endl;
	}
	else {
		cout << "load file failed:" << this->image_path << endl;

	}
	this->sprite.setTexture(this->texture);
	this->position = position;
	this->sprite.setPosition(this->position);
	
}

BackgroundLayer::~BackgroundLayer()
{
}

void BackgroundLayer::update()
{
	//cout << "Position Changed" <<  position.x << endl;
	sprite.setPosition(position);
}

void BackgroundLayer::render(sf::RenderWindow* window)
{
	update();
	//sprite.setPosition(sf::Vector2f(40,0));
	window->draw(sprite);
}
