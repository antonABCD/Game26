#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"

class Bullet{
private:
	sf::Texture texBu;
	sf::Sprite sprBu;

	sf::Clock bulletClock;
	sf::Time bulletCooldown;

	

	std::vector<Bullet> bullets;


public:
	Bullet();
	Bullet(std::string BuDirectory);

	void FireBullet(Player& rplayer);
	void DrawBullet(sf::RenderWindow& bwindow);

	sf::Sprite& getSprite();

};

