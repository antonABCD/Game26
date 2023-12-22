#pragma once
#include <SFML/Graphics.hpp>

class Player{
private:
	float playerSpeed;
	sf::Texture texSpace;
	sf::Sprite sprSpace;

public:
	Player();
	Player(std::string PDirectory);

	void setPlayerSpeed(float SpeeDofPlayer);
	void setPlayerPosition(float Px, float Py);
	

	void ControlPlayer(Player Ppl);
	void SetingTexture(std::string Directory);

	float getPlayerSpeed();
	sf::Vector2f getPlayerPosition();

	void DrawPlayer(sf::RenderWindow& Pwindow);
	~Player();
};

