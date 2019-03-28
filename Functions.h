#pragma once
#include "Class.h"

void menuScreen(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3);
void pokeInfoSelect(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3);
void printPokeInfo(Pokemon &poke);
void attackScreen(Pokemon &player, Pokemon &opponent, Pokemon &unused);
void battlePokeSelect(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3);
int randNum(int min, int max);
void playerAttackChoice(Pokemon &player, Pokemon &opponent, Pokemon &unused);
void playerAttack(Pokemon &player, Pokemon &opponent, Pokemon &unused, Attack &atk);
void opponentAttack(Pokemon &opponent, Pokemon &player, Pokemon &unused);
int endGame(Pokemon &player, Pokemon &opponent, Pokemon &unused);
Pokemon speedCompare(Pokemon &poke1, Pokemon &poke2);
void attackCompare(Pokemon &player, Pokemon &opponent, Pokemon &unused);
float critMod(Pokemon &target, Attack &atk);
void critDialog(float x);
float overallMod(float critMod);
//Find a way to print the damage category and type of pokemon. Might have to convert them to strings. 
//Condense the attack functions with parameters of the specified attack type.


