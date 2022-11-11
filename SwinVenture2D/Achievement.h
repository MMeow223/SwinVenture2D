#pragma once
#include "Object.h"
class Achievement : public Object
{
private:
	string name;
	string description;
	bool isUnlocked;
	bool isHover;
	
	sf::Text achievementDescriptionText;
	sf::Font font;

	sf::RectangleShape achievementDescriptionBackground;

	sf::Texture lockTexture;
	sf::Sprite lockSprite;
	
public:
	Achievement();
	Achievement(sf::RenderWindow* window,
		sf::Vector2f position,
		string filename,
		string name,
		string description
	);
	
	//Object(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath);

	
	~Achievement();
	
	// getter
	string getName() { return this->name; }
	string getDescription() { return this->description; }
	bool getIsUnlocked() { return this->isUnlocked; }
	bool getIsHover() { return this->isHover; }

	// setter
	void setName(string name) { this->name = name; }
	void setDescription(string description) { this->description = description; }
	void setIsUnlocked(bool isUnlocked) { this->isUnlocked = isUnlocked; }
	void setIsHover(bool isHover) { this->isHover = isHover; }
	
	// functions
	void update();
	void render();
	
	
};

