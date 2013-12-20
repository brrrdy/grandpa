/*
 *	Author: 	Cody Zornes
 *	Date: 		12/19/2013
 *	Version: 	3
 *	Desc:		Game object class implementation file
 */
 
 #include <iostream>
 
 #include "Game.hpp"
 #include "Uninitialized.hpp"

 Game::Game()
 {
	_exiting = false;
	_currentState = NULL;
 }
 
 Game::~Game()
 {
	ClearStates();
 }
 
/*  // rendering function to pass to other thread
 void renderingThread(sf::RenderWindow* window)
 {
	while(window->isOpen())
	{
		//draw stuff!
		state->drawScreen(window);
		//end of frame
		window->display();
	}
 } */
 
 // Start - Initialize gameWindow and start the main game loop
 void Game::Start()
 {
	
	// Start some stuff...
	_screenRect = sf::IntRect(0,0,1024,768);
	
	// Set first game state...
	Uninitialized* unitState = new Uninitialized();
	_gameStates.push_back(unitState);
	ChangeState(_gameStates[0]);
	
	window.create(sf::VideoMode(_screenRect.width, _screenRect.height), "Game");
	
	// launch a rendering thread
	/* window.setActive(false); // deactivate openGL context for multithreading
	sf::Thread thread(&renderingThread, &window);
	thread.launch(); */
	
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
		
		// event handling logic
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Game::_exiting = true;
			}
		}
		
		_currentState->drawScreen(window);
	}
 }
 
 int Game::BuildStates()
 {
	// read data files to just like make game here
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
 