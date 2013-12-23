#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

/*
 *	Author: 	Cody Zornes
 *	Date: 		12/19/2013
 *	Version: 	2
 *	Desc:		The GameState object handles the entry and exit to/from
 *				the different modes of the game
 */
 
 #include <string>
 #include <vector>
 #include <memory>
 
 #include <SFML/Graphics.hpp>
 
 #include "Player.hpp"
 
 class GameState {
 
 public:
	GameState();
	virtual ~GameState();
 
	void loadAssets(std::string filenames);
	void drawScreen(sf::RenderWindow & window);
	void update(sf::Event);
	
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	std::string GetName();
	
protected:
	std::string _name;
	std::map<std::string, sf::Texture> _textures;
	std::vector<sf::Sprite> _sprites;
	Player _player;
	
	sf::Vector2f _playerV;
	void checkPlayerInput();
	
	bool colliding(sf::Sprite & sprite, sf::Sprite & collided, sf::FloatRect & overlap);
	
 private:
	// private stuff
 };
 
 #endif