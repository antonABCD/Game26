#include "Player.h"

#include <iostream>

Player::Player(){

	//default constructor
}

Player::Player(std::string PDirectory){
	//setting a texture
	if (!texSpace.loadFromFile(PDirectory)) {
		std::cout << "failed to load the texture!!";
		return;
	}
	//removing an unwanted colour,which is sort of a background,where the player is displayed  of  out of a texture

	if (texSpace.loadFromFile(PDirectory)) {

		sf::Image im = texSpace.copyToImage();
		sf::Color wh = sf::Color::White;
		im.createMaskFromColor(wh);
		texSpace.loadFromImage(im);
	}
	sprSpace.setTexture(texSpace);
	texSpace.setSmooth(true);
}

void Player::setPlayerSpeed(float SpeeDofPlayer)
{
	playerSpeed = SpeeDofPlayer;
}

void Player::setPlayerPosition(float Px, float Py){
	sprSpace.setPosition(Px,Py);

}

float Player::getPlayerSpeed()
{
	return playerSpeed;
}

sf::Vector2f Player::getPlayerPosition(){

	return sprSpace.getPosition();
}



void Player::ControlPlayer(Player Ppl) {
	Ppl.setPlayerSpeed(2.36f);
	float moveSpeed = Ppl.getPlayerSpeed();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprSpace.move(-moveSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprSpace.move(moveSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprSpace.move(0, -moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprSpace.move(0, moveSpeed);
	}



}

void Player::SetingTexture(std::string Directory)
{

	//setting a texture
	if (!texSpace.loadFromFile(Directory)) {
		std::cout << "failed to load the texture!!";
		return;
	}
	//removing an unwanted colour,which is sort of a background,where the player is displayed  of  out of a texture
	
	if (texSpace.loadFromFile(Directory)) {
		 
		sf::Image im = texSpace.copyToImage();
		sf::Color wh = sf::Color::White;
		im.createMaskFromColor(wh);
		texSpace.loadFromImage(im);
	}
	sprSpace.setTexture(texSpace);
	texSpace.setSmooth(true);
}



void Player::DrawPlayer(sf::RenderWindow& Pwindow)
{

	Pwindow.draw(sprSpace);
}

Player::~Player()
{

}
