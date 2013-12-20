/*
 *	Author: 	Cody Zornes
 *	Date: 		12/19/2013
 *	Version: 	3
 *	Desc:		GameState class implementation file
 */
 
 #include <fstream>
 #include <iostream>
 
 #include "GameState.hpp"
 
 GameState::GameState()
 {
	_name = "generic";
 }
 
 GameState::~GameState()
 {
 }
 
 void GameState::loadAssets(std::string filenames)
 {
	// input file stream, open filenames file
	std::ifstream gfxFiles(filenames.c_str());
	
	if (gfxFiles.is_open()) {
		std::cout << "File opened for reading: " << filenames << std::endl;
		
		std::string tname, fname;
		
		// read until EOF
		while (gfxFiles >> tname >> fname) {

			std::cout << "Loading file: " << fname << std::endl;
				
			// attempt to create texture
			sf::Texture newTexture;
			
			if (!newTexture.loadFromFile(fname)) {
				// err: file not found: fname!
			}
			else {
				// add new texture to texture list
				_textures.insert( std::pair<std::string, sf::Texture&>(tname, newTexture) );
			}
		}

	}
	else
		std::cout << "Cannot open file: "<< filenames << std::endl;
	
	// close file stream
	gfxFiles.close();
 }
 
 void GameState::drawScreen(sf::RenderWindow & window)
 {
	window.clear();
 
	// iterator for traversing sprites
	std::vector<sf::Sprite>::iterator spriteIt = _sprites.begin();
	
	// draw all sprites to window
	while ( spriteIt != _sprites.end() )
	{
		window.draw(*spriteIt);
		spriteIt++;
	}
	
	window.display();
 }
 
 std::string GameState::GetName()
 {
	return _name;
 }