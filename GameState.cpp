/*
 *	Author: 	Cody Zornes
 *	Date: 		12/15/2013
 *	Version: 	2
 *	Desc:		GameState class implementation file
 */
 
 #include "GameState.hpp"
 
 GameState::GameState()
 {
	_name = "generic";
 }
 
 GameState::~GameState()
 {
 }
 
 std::string GameState::GetName()
 {
	return _name;
 }