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
 Player::Player(sf::Sprite& spriteIn)
 {
	sprite = spriteIn;
 }
 
 Player::~Player()
 {
	// desctruct
 }
 