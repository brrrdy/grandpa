#ifndef GAME_HPP
#define GAME_HPP

/*
 *	Author: 	Cody Zornes
 *	Date: 		12/17/2013
 *	Version: 	3
 *	Desc:		The Game object is the highest level object in the system, it handles entry, main loop and exiting the game.
 */

 #include <vector>
 #include <iostream>
 
 #include "GameState.hpp"
 
  #include <SFML/Window.hpp>
 
class Game {

public:
	Game();
	~Game();
	void Start();
	
private:
	void Loop();
	int BuildStates();
	void ChangeState(GameState* newGameState);
	void ClearStates();
	
	unsigned int vidW;
	unsigned int vidH;
	std::vector<GameState*> _gameStates;
	GameState* _currentState;
	bool _exiting;
	// TODO gameWorld/gameWindow objects
	sf::Window window;

	
};

#endif