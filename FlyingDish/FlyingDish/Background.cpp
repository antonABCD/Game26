#include "Background.h"


#include <iostream>
// simple class for drawing the background
Background::Background() {

}

Background::Background(std::string BDirectory){
	if (!worldMapTex.loadFromFile(BDirectory)) {
		std::cout << "Failed to load a texture!";
	}
	worldMapSpr.setTexture(worldMapTex);
	worldMapTex.setSmooth(true);

}


void Background::SetingTextureForBackground(std::string Directory) {	
	if (!worldMapTex.loadFromFile(Directory)) {
		std::cout << "Failed to load a texture!";
	}
	worldMapSpr.setTexture(worldMapTex);
	worldMapTex.setSmooth(true);




}

void Background::DrwawBackround(sf::RenderWindow& BPwindow) {
	BPwindow.draw(worldMapSpr);
}

Background::~Background() {


}
