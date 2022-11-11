#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Book.h"
//#include "Background.h"
//#include <queue>
#include "CircularDoublyLinkedList.h"
using namespace std;
class Scene
{

protected:
	sf::RenderWindow* window;
	Book* book;
	string sceneID;
	CircularDoublyLinkedList<Content>* list;
	

public:
	Scene();
	Scene(sf::RenderWindow* window);
	~Scene();

	//getter
	sf::RenderWindow* getWindow() { return window; }
	string getSceneID() { return sceneID; }
	Book* getBook() { return book; }
	CircularDoublyLinkedList<Content>* getList() { return list; }

	//setter
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void setSceneID(string sceneID) { this->sceneID = sceneID; }
	void setBook(Book* book) { this->book = book; }
	void setList(CircularDoublyLinkedList<Content>* list) { this->list = list; }

	virtual void update() = 0;
	virtual void render() = 0;

};

