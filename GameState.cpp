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
	_playerV = sf::Vector2f(0.0,0.0);
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
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) && _playerV.x > - 2.0 ){
		_playerV.x -= .01;
	}
	else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) && _playerV.x < 2.0 ) {
		_playerV.x += .01;
	}
	else if (_playerV.x > 0) {
		_playerV.x -= .005;
	}
	else if (_playerV.x < 0) {
		_playerV.x += .005;
	}
	
	
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) && _playerV.y > -2.0) {
		_playerV.y -= .01;
	}
	else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down) && _playerV.y < 2.0) {
		_playerV.y += .01;
	}
	else if (_playerV.y > 0) {
		_playerV.y -= .005;
	}
	else if (_playerV.y < 0) {
		_playerV.y += .005;
	}
	
	if (_playerV.x < .005 && _playerV.x > -.005) {
		_playerV.x = 0.0;
	}
	if (_playerV.y < .005 && _playerV.y > -.005) {
		_playerV.y = 0.0;
	}

	_player.sprite.move(_playerV.x, _playerV.y);
	
	if (colliding(_player.sprite)) {
		
	}
 }
 
 bool GameState::colliding(sf::Sprite & sprite)
 {
	std::vector<sf::Sprite>::iterator spriteIt;
	for (spriteIt = _sprites.begin(); spriteIt != _sprites.end(); ++spriteIt) {
		if (sprite.getGlobalBounds().intersects(spriteIt->getGlobalBounds())) {
			return true;
		}
	}
	return false;
 }
 
 
 
 std::string GameState::GetName()
 {
	return _name;
 }