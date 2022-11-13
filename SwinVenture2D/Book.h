#pragma once
#include "Object.h"
#include "Page.h"
#include "DoublyLinkedList.h"
class Book: public Object
{
private:
	// doubly linked list that store pages
	DoublyLinkedList<Page*> gameIntroPages;
	DoublyLinkedList<Page*>* currentPage;
	
	// texture and sprite
	sf::Texture bookRingTexture;
	sf::Sprite bookRingSprite;

public:
	Book();
	Book(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath);
	~Book();
	
	//getter
	DoublyLinkedList<Page*>* getCurrentPage() { return currentPage; }
	
	//setter
	void setCurrentPage(DoublyLinkedList<Page*>* currentPage) { this->currentPage = currentPage; }
	
	//function
	void previousPage();
	void nextPage();
	void addPageAtBack(Page* page);
	void resetToFirstPage();
	void render();
};

