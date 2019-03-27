#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <type_traits>

using namespace std;

enum class damageCategory { Physical, Special, Status };
enum class pokeType {Water, Fire, Grass, Electric, Normal, Fighting, Flying, Poison, Bug, Psychic, Ground, Rock, Fairy, Dragon, Steel, Ghost, Dark, Ice, None};
enum class attackType {Water, Fire, Grass, Electric, Normal, Fighting, Flying, Poison, Bug, Psychic, Ground, Rock, Fairy, Dragon, Steel, Ghost, Dark, Ice};

class Attack
{
private:
	const string name;
	const int power;
	const int accuracy;
	int PP;
	damageCategory moveType;
	attackType atkType;
public:
	Attack(string nameIn, int powerIn, int accIn, int PPin, damageCategory moveTypeIn, attackType attackTypeIn) :
		name(nameIn), power(powerIn), accuracy(accIn), PP(PPin), moveType(moveTypeIn), atkType(attackTypeIn){}
	const string getName() { return name; }
	const int getPower() { return power; }
	const int getAccuracy() { return accuracy; }
	damageCategory getDamageCategory() { return moveType; }
	attackType getAtkType() { return atkType; }
	int getPP() { return PP; }
};
class Pokemon
{
private:
	friend class Attack;
	const string name;
	const int baseHP;
	int HP, speed, level, attack, defense, specialAttack, specialDefense;
	pokeType baseType, subType;
	Attack atk1, atk2, atk3, atk4;
public:
	Pokemon(string nameIn, const int baseHPIn, int HPin, int speedIn, int levelIn, int attackIn, int defenseIn, int specialAttackIn, int specialDefenseIn, pokeType baseTypeIn, pokeType subTypeIn,
		Attack attk1, Attack attk2, Attack attk3, Attack attk4) :
		name(nameIn), baseHP(baseHPIn), HP(HPin), speed(speedIn), level(levelIn), attack(attackIn), defense(defenseIn), specialAttack(specialAttackIn), specialDefense(specialDefenseIn), baseType(baseTypeIn), subType(subTypeIn),
		atk1(attk1), atk2(attk2), atk3(attk3), atk4(attk4) {}
	const string getName() { return name; };
	int getHP() { return HP; };
	int getSpeed() { return speed; };
	int getLevel() { return level; };
	int getAttack() { return attack; };
	int getDefense() { return defense; };
	int getSpecialAttack() { return specialAttack; };
	int getSpecialDefense() { return specialDefense; };
	pokeType getBaseType() { return baseType; }
	pokeType getSubType() { return subType; }
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
	void pokeAttack(Pokemon attacker, Pokemon defender, Attack &atk, float modifier);
	void resetHP();
};


