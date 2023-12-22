#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include <iostream>

#include "Player.h"
#include "Background.h"

int main() {

		unsigned int width = 1260;
		unsigned int height = 700;


		sf::RenderWindow window(sf::VideoMode(width, height), "Spaceship");
		
		tgui::Gui gui(window);
		

		sf::SoundBuffer sound1;
		if (!sound1.loadFromFile("C:\\Users\\User\\Desktop\\SGuns\\blasterSound.ogg")) {
			std::cout << "Failed to load a sound!";
		}
		
		//--------------------------------------------
		Player player1("C:\\Users\\User\\Desktop\\Myfonts\\Spaceship.png");//Player
		player1.setPlayerPosition(300,340);

		//--------------------------------------------
		Background backround1("C:\\Users\\User\\Desktop\\Myfonts\\StarsBackround2.png");//Backround
	
		//Bulets

		std::vector<sf::CircleShape> bullets;

	
	

		// Timer for bullet firing
		sf::Clock bulletClock;
		sf::Time bulletCooldown = sf::seconds(0.15f);

		
		sf::Sound so;
		so.setBuffer(sound1);
		
		
		
		tgui::Button::Ptr button = tgui::Button::create();
		button->setPosition(200, 200);
		button->setWidth(80);
		button->setHeight(50);
		button->setText("Button");

		button->getRenderer()->setBackgroundColor(sf::Color::Green);
		button->getRenderer()->setBorderColor(sf::Color::Magenta);
		button->getRenderer()->setBackgroundColorHover(sf::Color::Cyan);
		gui.add(button);

		
		button->onPress([] {
			std::cout << "Hello";
		});
		gui.remove(button);
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
					window.close();
				}

				gui.handleEvent(event);

			}

			//bulletsToKeep.clear();

			float sp = 2.36f;

			player1.ControlPlayer(player1);




			//press F to shoot
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && bulletClock.getElapsedTime() >= bulletCooldown) {
				so.stop();

				so.play();

				sf::Vector2f bulletOffSet(153, 136); // Adjust the offset as needed
				sf::Vector2f bulletPos = player1.getPlayerPosition() + bulletOffSet;


				bullets.push_back(sf::CircleShape());
				bullets.back().setFillColor(sf::Color::White);
				bullets.back().setRadius(5);
				bullets.back().setOrigin(5, 5);
				bullets.back().setPosition(bulletPos);


				bulletClock.restart();

			}
			window.clear();
			
			backround1.DrwawBackround(window);

			player1.DrawPlayer(window);

		
		
			
			for (int i = 0; i < bullets.size(); i++) {
				window.draw(bullets[i]);
				bullets[i].move(0, -5);
				
				


				if (bullets[i].getPosition().y > 0) {
					bullets.erase(bullets.begin() + i);
					i--;
					std::cout << "Bullets are removed!\n";

					
				}


			}

			
			

			gui.draw();
			
			window.display();

		}

	
	return 0;
}

