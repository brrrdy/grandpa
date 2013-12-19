#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

/*
 *	Author: 	Cody Zornes
 *	Date: 		12/16/2013
 *	Version: 	2
 *	Desc:		The GameState object handles the entry and exit to/from
 *				the different modes of the game
 */
 
 #include <string>
 #include <vector>
 #include <memory>
 
 #include <SFML/Graphics.hpp>
 
 class GameState {
 
 public:
	GameState();
	virtual ~GameState();
 
	void loadAssets(std::string filenames);
	
	
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	std::string GetName();
	
protected:
	std::string _name;
	std::unique_ptr<sf::Texture> _textures;
	
 private:
	// private stuff
 };
 
 #endif