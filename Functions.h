#pragma once
#include "Class.h"

void menuScreen(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3);
void pokeInfoSelect(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3);
void printPokeInfo(Pokemon &poke);
void attackScreen(Pokemon &player, Pokemon &opponent, Pokemon &unused);
void battleGame(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3);
int randNum(int min, int max);
void playerAttack(Pokemon &player, Pokemon &opponent, Pokemon &unused);
void opponentAttack(Pokemon &opponent, Pokemon &player, Pokemon &unused);
int endGame(Pokemon &player, Pokemon &opponent, Pokemon &unused);
Pokemon speedCompare(Pokemon &poke1, Pokemon &poke2);
//Create a function for the battle game that is separate from printing the attack screen, that way the attack screen can be called whenever without recursively calling to battle the Pokemon. 
//Take out calls to attack screen in battle game. Instead have battle game call a function to battle, and have that function be able to call attack screen. 

