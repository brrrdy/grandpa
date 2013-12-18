#ifndef UNINITIALIZED_HPP
#define UNINITIALIZED_HPP

/*
 *	Author: 	Cody Zornes
 *	Date: 		12/16/2013
 *	Version: 	2
 *	Desc:		The uninitialized game state is the default game state 
 *				that is loaded when the engine starts
 */
 
 #include "GameState.hpp"
 
 class Uninitialized : public GameState {
 public:
 
	Uninitialized();
	~Uninitialized();
 
	void Enter();
	void Exit();
 
 };
 
 #endif