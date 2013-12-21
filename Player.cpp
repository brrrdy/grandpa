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
	const sf::FloatRect playerBounds = _playerSprite.getGlobalBounds();
	const sf::Vector2u screenBounds = window.getSize();
 
	// Update player position
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) && playerBounds.left > 0.0) {
		_playerSprite.move(-0.05,0.0);
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) && (playerBounds.left + playerBounds.width) < screenBounds.x) {
		_playerSprite.move(0.05,0.0);
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) && playerBounds.top > 0.0) {
		_playerSprite.move(0.0,-0.05);
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down) && (playerBounds.top + playerBounds.height) < screenBounds.y) {
		_playerSprite.move(0.0,0.05);
	}
	
	// Draw player to screen
	window.draw(_playerSprite);
 }