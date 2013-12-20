#ifndef PLAYER_HPP
#define PLAYER_HPP
/*
 *	Author: 	Cody Zornes
 *	Date: 		12/20/2013
 *	Version: 	1
 *	Desc:		The player object represents the player character controlled by the human.
 */
 
 #include <SFML/Graphics.hpp>
 #include <SFML/Window.hpp>
 
class Player {
public:
	Player();
	Player(sf::Sprite& player);
	~Player();
	
	void update(sf::RenderWindow& window);

private:
	sf::Sprite _playerSprite;
};

#endif