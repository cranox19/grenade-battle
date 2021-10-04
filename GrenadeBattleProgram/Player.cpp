#include "Player.h"

Player::Player(sf::Texture& playerTexture, sf::Vector2u screenSize)
{
	// Set the playerTexture to the sprite
	sprite.setTexture(playerTexture);

	// Set the scale of the player
	sprite.setScale(2.0f, 2.0f);

	// Position the player in the center of the screen
	sprite.setPosition(
		screenSize.x / 2 - playerTexture.getSize().x / 2,
		screenSize.y / 2 - playerTexture.getSize().y / 2);

	// Initialise the player's velocity values to zero
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	// Initialise the player's speed value
	speed = 300.0f;
}

void Player::Input()
{
	// Player keybind input
	// Start by initialising the player velocity to zero
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		// Move the player left
		velocity.x = -speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		// Move the player right
		velocity.x = speed;
	}
}

void Player::Update(sf::Time frameTime)
{
	// Move the player
	sprite.setPosition(sprite.getPosition() + velocity * frameTime.asSeconds());
}

void Player::Reset(sf::Vector2u screenSize)
{
	// Position the player in the center of the screen
	sprite.setPosition(
		screenSize.x / 2 - sprite.getTexture()->getSize().x / 2,
		screenSize.y / 2 - sprite.getTexture()->getSize().y / 2);
}



