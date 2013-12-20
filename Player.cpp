#include "Player.hpp"
/*
 *	Author: 	Cody Zornes
 *	Date: 		12/20/2013
 *	Version: 	1
 *	Desc:		Player object class implementation
 */
 
 // empty constructor
 Player::Player()
 {
 }
 
 // construct player object from sf::Sprite
 Player::Player(sf::Sprite& sprite)
 {
	_playerSprite = sprite;
 }
 
 Player::~Player()
 {
	// desctruct
 }
 
 void Player::update(sf::RenderWindow& window)
 {
	// Update player position
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left)) {
		_playerSprite.move(-0.01,0.0);
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right)) {
		_playerSprite.move(0.01,0.0);
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up)) {
		_playerSprite.move(0.0,-0.01);
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down)) {
		_playerSprite.move(0.0,0.01);
	}
	
	// Draw player to screen
	window.draw(_playerSprite);
 }