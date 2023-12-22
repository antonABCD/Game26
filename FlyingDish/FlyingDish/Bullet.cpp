#include "Bullet.h"


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <iostream>
#include "Player.h"

Bullet::Bullet(){

	//default constructor
}

Bullet::Bullet(std::string BuDirectory){
	
	

	

	if (!texBu.loadFromFile(BuDirectory)) {
		std::cout << "failed to load the texture!!";
		return;
	}
	//removing an unwanted colour,which is sort of a background,where the player is displayed  of  out of a texture

	if (texBu.loadFromFile(BuDirectory)) {

		sf::Image ima = texBu.copyToImage();
		sf::Color whi = sf::Color::White;
		ima.createMaskFromColor(whi);
		texBu.loadFromImage(ima);
	}
	sprBu.setTexture(texBu);
	texBu.setSmooth(true);

	bulletCooldown = sf::seconds(0.15f);

}


void Bullet::FireBullet(Player& rplayer){
	//when F is pressed. A Flying dish shoots :)

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && bulletClock.getElapsedTime() >= bulletCooldown) {
		

		

		sf::Vector2f bulletOffSet(153, 136); // Adjust the offset as needed
		
		sf::Vector2f bulletPos = rplayer.getPlayerPosition() + bulletOffSet;

		

		bullets.push_back(*this);
		//bullets.back().setFillColor(sf::Color::White);
		//bullets.back().setRadius(5);
		bullets.back().getSprite().setOrigin(5, 5); //setOrigin(5, 5);
		bullets.back().getSprite().setPosition(bulletPos);


		bulletClock.restart();

		
	}
}

void Bullet::DrawBullet(sf::RenderWindow& bwindow){
	

	for (auto& bullet : bullets) {
		bwindow.draw(bullet.sprBu);
		bullet.sprBu.move(0, -5);//the direction bullet goes in 
		
		
		if (bullet.sprBu.getPosition().y > bwindow.getSize().y) {
			//make sure to delete the bullets that go off the screen
		//	bullets.erase(bullets.begin());
			//i--;// Decrement the counter to properly iterate over the modified vector

			std::cout << "Bullets are removed!\n";
		}
		
	}
}

sf::Sprite& Bullet::getSprite(){

	return sprBu;
	
}
