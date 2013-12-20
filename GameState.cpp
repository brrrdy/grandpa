/*
 *	Author: 	Cody Zornes
 *	Date: 		12/15/2013
 *	Version: 	2
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
	// input file stream
	std::ifstream gfxFiles(filenames.c_str());
	
	if (gfxFiles.is_open())
	{
		std::cout << "File opened for reading: " << filenames << std::endl;
		
		// read until EOF
		while (!gfxFiles.eof())
		{
			// get filename
			std::string tname, fname;
			if (gfxFiles >> tname >> fname >> std::ws)
			{
			
				std::cout << "Loading file: " << fname << std::endl;
				
				// attempt to create texture
				sf::Texture newTexture;
				if (!newTexture.loadFromFile(fname))
				{
					// err: file not found: fname!
				}
				else 
				{
					// add new texture to texture list
					_textures.insert( std::pair<std::string, sf::Texture&>(tname, newTexture) );
				}
			}
			else
			{ 
				// somethin f'd up
				std::cout << "Cannot read: " << filenames << std::endl;
			}
			
		}
	}
	else
		std::cout << "Cannot open file: "<< filenames << std::endl;
	
	// close file stream
	gfxFiles.close();
 }
 
 void GameState::drawScreen(sf::RenderWindow* window)
 {
	std::map<std::string, sf::Sprite&>::iterator it;
	
	for (it = _sprites.begin(); it != _sprites.end(); ++it)
	{
		window->draw(it->second);
	}
 }
 
 std::string GameState::GetName()
 {
	return _name;
 }