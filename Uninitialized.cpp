/*
 *	Author: 	Cody Zornes
 *	Date: 		12/16/2013
 *	Version: 	1
 *	Desc:		Uninitialized game state implementation
 */

 #include <iostream>
 
 #include "Uninitialized.hpp"

 
 Uninitialized::Uninitialized()
 {
	_name = "uninitialized";
	loadAssets("data/unit.txt");
 }
 
 Uninitialized::~Uninitialized()
 {
 }
 
 void Uninitialized::Enter()
 {
	// We haven't started yet!!
	std::cout << "Entered state uninitialized." << std::endl;
	
	// Test drawing to window
	// get texture of skullman
	std::map<std::string, sf::Texture>::iterator it = _textures.find("skullman");
	if (it == _textures.end())
		std::cout << "Texture not found.\n";
	else
		std::cout << "Texture loaded.\n";
	
	//set alpha channel for texture
	
	
	// make a test sprite from "skullman"
	sf::Sprite skull;
	skull.setTexture(it->second);
	skull.setPosition(100,100);
	_sprites.push_back(skull);
	
 }
 
 void Uninitialized::Exit()
 {
	// Ok, we're going to a new state!
	std::cout << "Exiting state uninitialized." << std::endl;
 }
 