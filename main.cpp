//Two classes, one for the Pokemon, one for the attacks of each Pokemon. Each pokemon will have four attacks, HP, and a name
//Each attack will have a name, power, accuracy, and PP
//Pokemon will be assigned four attacks to use
//Open a menu to choose a Pokemon, this should be a function
//Then go through attack sequence, choosing which attack, accuracy, etc. This should also be a function.

#include "Class.h"
#include "Functions.h"

int main()
{
	Attack Ember("Ember", 40, 100, 25);
	Attack WaterGun("Water Gun", 40, 100, 25);
	Attack Scratch("Scratch", 40, 100, 30);
	Attack Tackle("Tackle", 40, 100, 35);
	Attack Bite("Bite", 60, 100, 20);
	Attack Flamethrower("Flamethrower", 90, 100, 15);
	Attack RazorLeaf("Razor Leaf", 55, 95, 20);

	Pokemon Charmander("Charmander", 100, 65, Ember, Scratch, Bite, Flamethrower);
	Pokemon Squirtle("Squirtle", 100, 43, WaterGun, Scratch, Tackle, Bite);
	Pokemon Bulbasaur("Bulbasaur", 100, 45, Scratch, Tackle, Bite, RazorLeaf);

	menuScreen(Charmander, Squirtle, Bulbasaur);

}