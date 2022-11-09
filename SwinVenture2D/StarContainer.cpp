#include "StarContainer.h"

StarContainer::StarContainer() : Object()
{
	cout << "Init StarContainer" << endl;
	//star_stack = stack<Star*>();
	star_list = DoublyLinkedList<Star*>();
	star_container_background = sf::RectangleShape(size);
}

StarContainer::StarContainer(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, float rarity, string filepath, Star* star)
	: Object(window, position, size, velocity, filepath)
{
	//star_stack = stack<Star*>();
	star_list = DoublyLinkedList<Star*>(star);
	star_container_background = sf::RectangleShape(size);
	star_container_background.setPosition(position);
}

StarContainer::~StarContainer()
{
}

void StarContainer::insertStar(Star* star)
{
	star_list.append(star);
}

void StarContainer::dropStar()
{


	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, star_list.getSize()-1); 
	//std::cout << randomNumber(rng) << std::endl;
	
	// generate random number between 0 and the size of the stack
	
	//int random_number = rand() % star_list.getSize();
	//cout << "Random number : " << randomNumber(rng) << endl;
	
	DoublyLinkedList<Star*>* temp = &star_list;
	for (int i = 0; i < randomNumber(rng); i++) {
		//if (temp->next() !=  &LinkedList<Star>::NIL) {
			
		//}
		temp = temp->next();
	}
	temp->remove();
}

Star* StarContainer::getStar()
{
	return star_list.getList()->getValue();
}

void StarContainer::update()
{
}

void StarContainer::render()
{
	window->draw(star_container_background);
	
}