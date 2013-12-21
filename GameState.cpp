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
	_playerMovement = sf::Vector2f(0.0,0.0);
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

	// draw player
	window.draw(_player.sprite);
	
	window.display();
 }
 
 void GameState::update(sf::Event)
 {
	//const sf::FloatRect playerBounds = _player.sprite.getGlobalBounds();
 
	// Update player position
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) && _playerMovement.x > -.05 ){
		_playerMovement.x -= .0001;
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) && _playerMovement.x < .05 ) {
		_playerMovement.x += .0001;
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) && _playerMovement.y > -.05) {
		_playerMovement.y -= .0001;
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down) && _playerMovement.y < .05) {
		_playerMovement.y += .0001;
	}
	
	_player.sprite.move(_playerMovement.x, _playerMovement.y);
 }
 
 
 std::string GameState::GetName()
 {
	return _name;
 }