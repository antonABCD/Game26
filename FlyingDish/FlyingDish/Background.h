#pragma once

#include <SFML/Graphics.hpp>

class Background{
private:
	sf::Texture worldMapTex;
	sf::Sprite worldMapSpr;

public:
	Background();
	Background(std::string BDirectory);
	void SetingTextureForBackground(std::string Directory);
	void DrwawBackround(sf::RenderWindow& BPwindow);

	~Background();
};

