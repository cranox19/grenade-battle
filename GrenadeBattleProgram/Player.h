#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:

	// Constructor
	Player(sf::Texture& playerTexture, sf::Vector2u screenSize);

	// Functions to call player-specific code
	void Input();
	void Update(sf::Time frameTime);
	void Reset(sf::Vector2u screenSize);

	// Variables
	sf::Sprite sprite;
	sf::Vector2f velocity;
	float speed;
};

