#include "Class.h"

void Pokemon::printAtk1()
{
	cout << "Attack: " << atk1.getName() << "\n"
		<< "Power: " << atk1.getPower() << "\n"
		<< "Accuracy: " << atk1.getAccuracy() << "\n"
		<< "PP: " << atk1.getPP() << "\n" << endl;
}
void Pokemon::printAtk2()
{
	cout << "Attack: " << atk2.getName() << "\n"
		<< "Power: " << atk2.getPower() << "\n"
		<< "Accuracy: " << atk2.getAccuracy() << "\n"
		<< "PP: " << atk2.getPP() << "\n" << endl;
}
void Pokemon::printAtk3()
{
	cout << "Attack: " << atk3.getName() << "\n"
		<< "Power: " << atk3.getPower() << "\n"
		<< "Accuracy: " << atk3.getAccuracy() << "\n"
		<< "PP: " << atk3.getPP() << "\n" << endl;
}
void Pokemon::printAtk4()
{
	cout << "Attack: " << atk4.getName() << "\n"
		<< "Power: " << atk4.getPower() << "\n"
		<< "Accuracy: " << atk4.getAccuracy() << "\n"
		<< "PP: " << atk4.getPP() << "\n" << endl;
}
void Pokemon::printAtk1Name()
{
	cout << atk1.getName();
}
void Pokemon::printAtk2Name()
{
	cout << atk2.getName();
}
void Pokemon::printAtk3Name()
{
	cout << atk3.getName();
}
void Pokemon::printAtk4Name()
{
	cout << atk4.getName();
}
void Pokemon::pokeAttack(Pokemon attacker, Pokemon defender, Attack &atk, float modifier)
{
	int damage;
	if (atk.getDamageCategory() == damageCategory::Physical)
	{
		damage = (((((((2 * level) / 5) + 2)*atk.getPower()*(attacker.attack / defender.defense)) / 50) + 2))*modifier;
	}
	else if (atk.getDamageCategory() == damageCategory::Special)
	{
		damage = (((((((2 * level) / 5) + 2)*atk.getPower()*(attacker.specialAttack / defender.specialDefense)) / 50) + 2))*modifier;
	}
	HP = HP - damage;
}
void Pokemon::resetHP()
{
	HP = baseHP;
}


