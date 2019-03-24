#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

enum class damageCategory { physical, special, status };

class Attack
{
private:
	const string name;
	const int power;
	const int accuracy;
	int PP;
	damageCategory type;
public:
	Attack(string nameIn, int powerIn, int accIn, int PPin) :
		name(nameIn), power(powerIn), accuracy(accIn), PP(PPin){}
	const string getName() { return name; };
	const int getPower() { return power; };
	const int getAccuracy() { return accuracy; };
	int getPP() { return PP; };
};
class Pokemon
{
private:
	friend class Attack;
	const string name;
	int HP, speed, level, attack, defense, specialAttack, specialDefense;
	Attack atk1, atk2, atk3, atk4;
public:
	Pokemon(string nameIn, int HPin, int speedIn, int levelIn, int attackIn, int defenseIn, int specialAttackIn, int specialDefenseIn, Attack attk1, Attack attk2, Attack attk3, Attack attk4) :
		name(nameIn), HP(HPin), speed(speedIn), level(levelIn), attack(attackIn), defense(defenseIn), specialAttack(specialAttackIn), specialDefense(specialDefenseIn), 
		atk1(attk1), atk2(attk2), atk3(attk3), atk4(attk4) {}
	const string getName() { return name; };
	int getHP() { return HP; };
	int getSpeed() { return speed; };
	int getLevel() { return level; };
	int getAttack() { return attack; };
	int getDefense() { return defense; };
	int getSpecialAttack() { return specialAttack; };
	int getSpecialDefense() { return specialDefense; };
	Attack getAtk1() { return atk1; };
	Attack getAtk2() { return atk2; };
	Attack getAtk3() { return atk3; };
	Attack getAtk4() { return atk4; };
	void printAtk1();
	void printAtk2();
	void printAtk3();
	void printAtk4();
	void printAtk1Name();
	void printAtk2Name();
	void printAtk3Name();
	void printAtk4Name();
	void pokeAttack(Attack &atk);
	void resetHP();
};


