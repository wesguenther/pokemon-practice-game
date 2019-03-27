//Two classes, one for the Pokemon, one for the attacks of each Pokemon. Each pokemon will have four attacks, HP, and a name
//Each attack will have a name, power, accuracy, and PP
//Pokemon will be assigned four attacks to use
//Open a menu to choose a Pokemon, this should be a function
//Then go through attack sequence, choosing which attack, accuracy, etc. This should also be a function.

#include "Class.h"
#include "Functions.h"

int main()
{
	//Attack name(name, power, accuracy, damagecategory, attackType)
	Attack Ember("Ember", 40, 100, 25, damageCategory::Special, attackType::Fire);
	Attack WaterGun("Water Gun", 40, 100, 25, damageCategory::Special, attackType::Water);
	Attack Scratch("Scratch", 40, 100, 30, damageCategory::Physical, attackType::Normal);
	Attack Tackle("Tackle", 40, 100, 35, damageCategory::Physical, attackType::Normal);
	Attack Bite("Bite", 60, 100, 20, damageCategory::Physical, attackType::Dark);
	Attack Flamethrower("Flamethrower", 90, 100, 15, damageCategory::Special, attackType::Fire);
	Attack RazorLeaf("Razor Leaf", 55, 95, 20, damageCategory::Physical, attackType::Grass);

	//Pokemon name(name, HP, speed, level, attack, defense, specialattack, specialdefense, atk1, atk2, atk3, atk4)
	Pokemon Charmander("Charmander", 39, 39, 65, 5, 52, 43, 60, 50, pokeType::Fire, pokeType::None, Ember, Scratch, Bite, Flamethrower);
	Pokemon Squirtle("Squirtle", 44, 44, 43, 5, 48, 65, 50, 64, pokeType::Water, pokeType::None, WaterGun, Scratch, Tackle, Bite);
	Pokemon Bulbasaur("Bulbasaur", 45, 45, 45, 5, 49, 49, 65, 65, pokeType::Grass, pokeType::None, Scratch, Tackle, Bite, RazorLeaf);

	menuScreen(Charmander, Squirtle, Bulbasaur);

}