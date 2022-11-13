#pragma once
#include "Object.h"
class Achievement : public Object
{
private:
	// achievement detail
	string name;
	string description;
	
	// text and font
	sf::Text achievementDescriptionText;
	sf::Font font;

	// shape
	sf::RectangleShape achievementDescriptionBackground;

	// texture and sprite
	sf::Texture lockTexture;
	sf::Sprite lockSprite;
	
	// state
	bool isUnlocked;
	bool isHover;
public:
	Achievement();
	Achievement(sf::RenderWindow* window,sf::Vector2f position,string filename,string name,string description);
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
	
	void checkIsHover(sf::Vector2i& mousePosition);

	// functions
	void update();
	void render();
};

