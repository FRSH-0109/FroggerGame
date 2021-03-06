/**
 * @file engine.h
 *
 * @brief class for main game engine
 * @authors Kamil Kośnik, Adam Moszczyński
 * @contact: kamilkosnik@gmail.com, adm.moszczynski@gmail.com
 *
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "player.h"
#include "enemy.h"
#include "menu.h"

enum ScreenToDisplay
{
	menu,
	game,
	scoreSave
};

class Engine
{
	private:
	// A regular RenderWindow
	sf::RenderWindow mWindow;

	// Time handling variables
	const sf::Time frameDelay_ms = sf::milliseconds(1);
	sf::Time timeElapsedFromLastFrame_ms = sf::milliseconds(0);

	// Resolution display values
	const sf::Vector2f resolution = {1100, 800};

	// Declare a sprite and a Texture for the background
	sf::Sprite mGrassStartSprite;
	sf::Texture mGrassStartTexture;
	sf::Sprite mGrassMetaSprite[5]; // when using std::vector, segmentation fault occurs
	std::vector<sf::FloatRect> mGrassMetaHitbox;
	sf::Texture mGrassMetaTexture;
	sf::Sprite mGrassMidSprite;
	sf::Texture mGrassMetaTextureAchieved;
	sf::Texture mGrassMidTexture;
	sf::Sprite mGrassEndSprite;
	sf::Texture mGrassEndTexture;
	sf::Sprite mRoadSprite;
	sf::Texture mRoadTexture;
	sf::Sprite mWaterSprite;
	sf::Texture mWaterTexture;
	sf::FloatRect mWaterHitbox;
	sf::Text playingTimeDisplay;
	sf::Font font;
	sf::Text playerScore;

	// An instances of Player and other enemies
	Player mPlayer;

	Enemies mEnemies;

	Menu mMenu;

	bool safetyZone[5] = {false, false, false, false, false};

	float playingTime = 0;
	float playingTimeFinal = 0;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
	void createCarEnemies(unsigned int linesToCreate);
	void createLogEnemies(unsigned int linesToCreate);

	public:
	// The Engine constructor
	Engine();

	// start will call all the private functions
	void start();

	bool checkCollision();
	void checkPlayerBoundCollision();
	bool checkPlayerCarEnemyCollision();
	bool checkPlayerWaterCollision();
	void checkPlayerLogEnemyCollision();
	void checkPlayerMetaCollision();
	void loadBackgroundTexturesAndSprites();
	void resetGame();
	void wonGame();

	ScreenToDisplay screenToDisplay;
};

#endif