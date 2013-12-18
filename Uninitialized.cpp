/*
 *	Author: 	Cody Zornes
 *	Date: 		12/16/2013
 *	Version: 	1
 *	Desc:		Uninitialized game state implementation
 */

 #include <iostream>
 
 #include "Uninitialized.hpp"

 
 Uninitialized::Uninitialized()
 {
	_name = "uninitialized";
 }
 
 Uninitialized::~Uninitialized()
 {
 }
 
 void Uninitialized::Enter()
 {
	// We haven't started yet!!
	std::cout << "Entered state uninitialized." << std::endl;
 }
 
 void Uninitialized::Exit()
 {
	// Ok, we're going to a new state!
	std::cout << "Exiting state uninitialized." << std::endl;
 }
 