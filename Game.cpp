/*
 *	Author: 	Cody Zornes
 *	Date: 		12/17/2013
 *	Version: 	3
 *	Desc:		Game object class implementation file
 */
 
 #include <iostream>
 
 #include "Game.hpp"
 #include "Uninitialized.hpp"

 Game::Game()
 {
 }
 
 Game::~Game()
 {
	ClearStates();
 }
 
 
 // Start - Initialize gameWindow and start the main game loop
 void Game::Start()
 {
 
	// Start some stuff...
	vidW = 1024;
	vidH = 768;
	
	// Set first game state...
	Uninitialized* unitState = new Uninitialized();
	_gameStates.push_back(unitState);
	_currentState = unitState;
	
	window.create(sf::VideoMode(vidW, vidH), "Game");
	
	Game::Loop();
	
	// Clean up after yourself...
	window.close();
 }
   
 

 // Loop - Run the main game loop while _exiting is false
 void Game::Loop()
 {
	while (!Game::_exiting)
	{
		// do stuff, yeah?
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Game::_exiting = true;
			}
		}
	}
 }
 
 int Game::BuildStates()
 {
	// call script to just like make game here
	return 0;
 }
 
 void Game::ChangeState(GameState* newGameState)
 {
 
	// Check if current game state ptr is null (uninitialized)
	if (_currentState != NULL) {
		// Call Exit 
		_currentState->Exit();
	}
	_currentState = newGameState;
	
	_currentState->Enter();
 }
 
 void Game::ClearStates()
 {
	 for (std::vector<GameState*>::const_iterator it = _gameStates.begin(); it != _gameStates.end(); it++)
		{
			std::cout << "Deleting gamestate \"" << (*it)->GetName() << "\"..." << std::endl;
			delete *it;
		}
		_gameStates.clear();
		
		std::cout << std::endl << "Gamestates cleared" << std::endl;
 }