#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
	// Declare the SFML window, called gameWindow
	sf::RenderWindow gameWindow;

	// Set up the SFML window, pass in its dimensions and name
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Grenade Battle", sf::Style::Titlebar | sf::Style::Close);


	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// G A M E   S E T U P
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


	// Player Sprite
	// Declare an image, called playerTexture
	sf::Texture playerTexture;

	// Assign the player_1.png from the file to playerTexture
	playerTexture.loadFromFile("Assets/Graphics/player_1.png");

	// Declare a player object
	Player playerObject(playerTexture, gameWindow.getSize());

	// Game Font
	// Declare a Font variable, called gameFont
	sf::Font gameFont;

	// Load the dogica.ttf from the file
	gameFont.loadFromFile("Assets/Fonts/dogica.ttf");

	// Title text
	// Declare a text variable, called titleText
	sf::Text titleText;

	// Set titleText's font to gameFont
	titleText.setFont(gameFont);

	// Set the string that will display for tittleText
	titleText.setString("Grenade Battle 2000");

	// Set the different parameters of tittleText
	titleText.setCharacterSize(24);
	titleText.setFillColor(sf::Color::White);
	titleText.setStyle(sf::Text::Bold);
	titleText.setPosition(
		gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);

	// Game Clock
	// Declare a clock variable, called gameClock
	sf::Clock gameClock;

	// Game over variable to track if the game is done
	bool gameOver = false;

	// Game Loop
	// Repeat as long as the game window is open
	while (gameWindow.isOpen())
	{
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		// I N P U T   S E C T I O N
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		

		// Declare a variable to hold an event, called gameEvent
		sf::Event gameEvent;

		// Loop through all events and poll them, putting each one into our gameEvent variable
		while (gameWindow.pollEvent(gameEvent))
		{
			// Did the player try to close the window?
			if (gameEvent.type == sf::Event::Closed)
			{
				// If so, call the function to close the window
				gameWindow.close();
			}
		}
		
		// Player keybind input
		playerObject.Input();


		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		// U P D A T E   S E C T I O N
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


		// Get the time passed since the last frame and restart the game clock
		sf::Time frameTime = gameClock.restart();

		// Only perform this update logic if the game is still running
		if (!gameOver)
		{
			// Move the player
			playerObject.Update(frameTime);

			// Check for collisions
			// INSERT CODE HERE
		}

		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		// D R A W   S E C T I O N
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw everything to the window
		gameWindow.draw(titleText);

		// Only draw these items if the game has not ended
		if (!gameOver)
		{
			// Draw the player
			gameWindow.draw(playerObject.sprite);
		}

		// Display the window contents on the screen
		gameWindow.display();
	}
	return 0;
}