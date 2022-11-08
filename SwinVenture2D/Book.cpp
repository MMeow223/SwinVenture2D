#include "Book.h"

Book::Book() : Object()
{


	Page* blankpagefront = new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/blankpagefront.png");
	Page* blankpageend = new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/blankpageend.png");
	blankpagefront->setPosition(sf::Vector2f(1080 / 2 - (blankpagefront->getSprite().getLocalBounds().width), 720 / 2 - blankpagefront->getSprite().getLocalBounds().height / 2));
	blankpageend->setPosition(sf::Vector2f(1080 / 2 - (blankpageend->getSprite().getLocalBounds().width), 720 / 2 - blankpageend->getSprite().getLocalBounds().height / 2));

	gameIntroPages = DoublyLinkedList<Page*>(blankpagefront);
	addPageAtBack(blankpageend);


	currentPage = &gameIntroPages;

	bookRingTexture.loadFromFile("./res/images/book-ring.png");
	bookRingSprite.setTexture(bookRingTexture);
	bookRingSprite.setPosition(sf::Vector2f(1080 / 2 - bookRingSprite.getLocalBounds().width / 2, 720 / 2 - bookRingSprite.getLocalBounds().height / 2));
}

Book::Book(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath)
	: Object(window, position, size, velocity, filepath)
{

	Page* blankpagefront = new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/blankpagefront.png");
	Page* blankpageend = new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/blankpageend.png");
	blankpagefront->setPosition(sf::Vector2f(1080 / 2 - (blankpagefront->getSprite().getLocalBounds().width), 720 / 2 - blankpagefront->getSprite().getLocalBounds().height / 2));
	blankpageend->setPosition(sf::Vector2f(1080 / 2 - (blankpageend->getSprite().getLocalBounds().width), 720 / 2 - blankpageend->getSprite().getLocalBounds().height / 2));

	gameIntroPages = DoublyLinkedList<Page*>(blankpagefront);
	addPageAtBack(blankpageend);


	currentPage = &gameIntroPages;
	bookRingTexture.loadFromFile("./res/images/book-ring.png");
	bookRingSprite.setTexture(bookRingTexture);
	bookRingSprite.setPosition(sf::Vector2f(1080 / 2 - bookRingSprite.getLocalBounds().width / 2, 720 / 2 - bookRingSprite.getLocalBounds().height / 2));
}

Book::~Book()
{
}

void Book::previousPage()
{
	
	if (currentPage->getList()->getPrevious()->getPrevious() != &LinkedList<Page*>::NIL) {
		if (currentPage->getList()->getPrevious()->getPrevious() != &LinkedList<Page*>::NIL) {
			currentPage->setList(currentPage->getList()->getPrevious()->getPrevious());
			cout << "Left" << endl;
		}
	}
}

void Book::nextPage()
{
	if (currentPage->getList()->getNext()->getNext()->getNext() != &LinkedList<Page*>::NIL) {
		currentPage->setList(currentPage->getList()->getNext()->getNext());
		cout << "Right" << endl;
	}
}

void Book::addPageAtBack(Page* page)
{
	//DoublyLinkedList<Page*>* temp = &gameIntroPages;
	//
	//while (temp->getList()->getNext()->getNext() != &LinkedList<Page*>::NIL) {
	//	
	//	temp->setList(temp->getList()->getNext());
	//}
	//if (gameIntroPages.getSize() % 2 == 0) {
	//	page->setPosition(sf::Vector2f(1080 / 2 - (page->getSprite().getLocalBounds().width), 720 / 2 - page->getSprite().getLocalBounds().height / 2));
	//}
	//else {
	//	page->setPosition(sf::Vector2f(temp->getList()->getValue()->getPosition().x + temp->getList()->getValue()->getSize().x, temp->getList()->getValue()->getPosition().y));
	//}
	////temp->append(page);
	//temp->append(page);
	//DoublyLinkedList<Page*>* temp = &gameIntroPages;

	while (gameIntroPages.getList()->getNext()->getNext() != &LinkedList<Page*>::NIL) {

		gameIntroPages.setList(gameIntroPages.getList()->getNext());
	}
	if (gameIntroPages.getSize() % 2 == 0) {
		page->setPosition(sf::Vector2f(1080 / 2 - (page->getSprite().getLocalBounds().width), 720 / 2 - page->getSprite().getLocalBounds().height / 2));
	}
	else {
		page->setPosition(sf::Vector2f(gameIntroPages.getList()->getValue()->getPosition().x + gameIntroPages.getList()->getValue()->getSize().x, gameIntroPages.getList()->getValue()->getPosition().y));
	}
	//temp->append(page);
	gameIntroPages.append(page);
}

void Book::resetToFirstPage()
{
	while (gameIntroPages.getList()->getPrevious()->getPrevious() != &LinkedList<Page*>::NIL) {
		gameIntroPages.setList(gameIntroPages.getList()->getPrevious());
	}
}
void Book::render()
{
	//window->draw(sprite);
	currentPage->getList()->getValue()->render();
	currentPage->getList()->getNext()->getValue()->render();
	window->draw(bookRingSprite);
}
