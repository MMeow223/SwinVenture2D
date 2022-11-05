#include "Scene.h"

Scene::Scene()
{
	//cout << "Scene init" << endl;
	//window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D - Base Scene");
}

Scene::Scene(sf::RenderWindow* window)
{
	cout << "Game init" << endl;
	this->window = window;
}

Scene::~Scene()
{
}

void Scene::update()
{
}

void Scene::render()
{
}
