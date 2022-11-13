#include "Scene.h"

Scene::Scene()
{
	cout << "Scene init" << endl;
	
	// nullptr because not use
	window = nullptr;
	sceneID = "scene_base";
	
}

Scene::Scene(sf::RenderWindow* window)
{
	cout << "Scene init" << endl;
	
	// set window
	this->window = window;
	sceneID = "scene_base";
}

Scene::~Scene()
{
}


