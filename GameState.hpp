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
 
 class GameState {
 
 public:
	GameState();
	virtual ~GameState();
 
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	std::string GetName();
	
protected:
	std::string _name;
	
 private:
	// private stuff
 };
 
 #endif