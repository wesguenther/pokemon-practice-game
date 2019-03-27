#include "Functions.h"

void menuScreen(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3) 
{
	cout << "\n1-Show Pokemon info" << endl;
	cout << "2-Battle Pokemon" << endl;
	cout << "3-Exit game" << endl;
	cout << "\nWhat would you like to do? Enter a number: ";
	int input;
	cin >> input;
	if (input == 1)
	{
		pokeInfoSelect(poke1, poke2, poke3);
	}
	else if (input == 2)
	{
		battlePokeSelect(poke1, poke2, poke3);
	}
	else if (input == 3)
	{
		exit(0);
	}
}
void pokeInfoSelect(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3)
{
	cout << "\n1- " << poke1.getName() << endl;
	cout << "2- " << poke2.getName() << endl;
	cout << "3- " << poke3.getName() << endl;
	cout << "\nWhich Pokemon would you like to see the information for? Enter a number: ";
	int input;
	cin >> input;
	if (input == 1)
	{
		printPokeInfo(poke1);
	}
	else if (input == 2)
	{
		printPokeInfo(poke2);
	}
	else if (input == 3)
	{
		printPokeInfo(poke3);
	}
}
void printPokeInfo(Pokemon &poke)
{
	cout << "\nPokemon: " << poke.getName() << "\n"
		<<"Level: "<<poke.getLevel()<<"\n"
		<< "HP: " << poke.getHP() << "\n" 
		<<"Attack: "<<poke.getAttack()<<"\n"
		<<"Defense: "<<poke.getDefense()<<"\n"
		<<"Special Attack: "<<poke.getSpecialAttack()<<"\n"
		<<"Special Defense: "<<poke.getSpecialDefense()<<"\n"
		<< "Speed: " << poke.getSpeed() << "\n" << endl;
	poke.printAtk1();
	poke.printAtk2();
	poke.printAtk3();
	poke.printAtk4();
}
void battlePokeSelect(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3)
{
	
	cout << "\n1- " << poke1.getName() << endl;
	cout << "2- " << poke2.getName() << endl;
	cout << "3- " << poke3.getName() << endl;
	cout << "\nWhich Pokemon would you like on your team? Enter a number: ";
	int input, random;
	cin >> input;
	if (input == 1)
	{
		Pokemon playerPoke(poke1);
		srand(time(NULL));
		random = (rand()%2==0 ? 1 : 2);
		if (random == 1)
		{
			Pokemon opponentPoke(poke2);
			Pokemon unused(poke3);
			attackScreen(playerPoke, opponentPoke, unused);
			attackCompare(playerPoke, opponentPoke, unused);
		}
		else
		{
			Pokemon opponentPoke(poke3);
			Pokemon unused(poke2);
			attackScreen(playerPoke, opponentPoke, unused);
			attackCompare(playerPoke, opponentPoke, unused);
		}
	}
	else if (input == 2)
	{
		Pokemon playerPoke(poke2);
		srand(time(NULL));
		random = (rand()%2==0 ? 1 : 2);
		if (random == 1)
		{
			Pokemon opponentPoke(poke1);
			Pokemon unused(poke3);
			attackScreen(playerPoke, opponentPoke, unused);
			attackCompare(playerPoke, opponentPoke, unused);
		}
		else
		{
			Pokemon opponentPoke(poke3);
			Pokemon unused(poke1);
			attackScreen(playerPoke, opponentPoke, unused);
			attackCompare(playerPoke, opponentPoke, unused);
		}
	}
	else if (input == 3)
	{
		Pokemon playerPoke(poke3);
		srand(time(NULL));
		random = (rand()%2==0 ? 1 : 2);
		if (random == 1)
		{
			Pokemon opponentPoke(poke1);
			Pokemon unused(poke2);
			attackScreen(playerPoke, opponentPoke, unused);
			attackCompare(playerPoke, opponentPoke, unused);
		}
		else
		{
			Pokemon opponentPoke(poke2);
			Pokemon unused(poke1);
			attackScreen(playerPoke, opponentPoke, unused);
			attackCompare(playerPoke, opponentPoke, unused);
		}
	}
}
int randNum(int min, int max)
{
	srand(time(NULL));
	int x = rand() % (max-min+1)+min;
	return x;
}
void attackScreen(Pokemon &player, Pokemon &opponent, Pokemon &unused)
{
	cout <<"\n\n"<< player.getName() << "\n\n\n";
	cout << "HP: "<< player.getHP()<<"\t";
	for (auto i = 0;i != player.getHP();++i)
	{
		cout << "-";
	}
	cout << endl;
	cout << "\n\n" << opponent.getName() << "\n\n\n";
	cout << "HP: " << opponent.getHP() << "\t";
	for (auto i = 0;i != opponent.getHP();++i)
	{
		cout << "-";
	}
	cout << endl;
}
void attackCompare(Pokemon &player, Pokemon &opponent, Pokemon &unused)
{
	Pokemon first = speedCompare(player, opponent);
	if (first.getName() == player.getName())
	{
		while (player.getHP() != 0 && opponent.getHP() != 0)
		{
			playerAttack(player, opponent, unused);
			attackScreen(player, opponent, unused);
			opponentAttack(opponent, player, unused);
			attackScreen(player, opponent, unused);
		}
	}
	else if (first.getName() == opponent.getName())
	{
		while (player.getHP() != 0 && opponent.getHP() != 0)
		{
			opponentAttack(opponent, player, unused);
			attackScreen(player, opponent, unused);
			playerAttack(player, opponent, unused);
			attackScreen(player, opponent, unused);
		}
	}
}
void playerAttack(Pokemon &player, Pokemon &opponent, Pokemon &unused)
{
	cout << "\n1-";
	player.printAtk1Name();
	cout << "\n";
	cout << "2-";
	player.printAtk2Name();
	cout << "\n";
	cout << "3-";
	player.printAtk3Name();
	cout << "\n";
	cout << "4-";
	player.printAtk4Name();
	cout << "\n";
	int input;
	cout << "\nWhich attack should " << player.getName() << " use? Enter a number: ";
	cin >> input;
	if (input == 1)
	{
		auto atk = player.getAtk1();
		float crit = critMod(opponent, atk);
		float overallModifier = overallMod(crit);
		opponent.pokeAttack(player, opponent, atk, overallModifier);
		cout << "\n"<<player.getName() << " used ";
		player.printAtk1Name();
		cout<<"! \n";
		
		critDialog(crit);
		if (opponent.getHP() <= 0)
		{
			cout << opponent.getName() << " has fainted. " << player.getName() << " wins!\n";
			endGame(player, opponent, unused);
		}
	}
	else if (input == 2)
	{
		auto atk = player.getAtk2();
		float crit = critMod(opponent, atk);
		float overallModifier = overallMod(crit);
		opponent.pokeAttack(player, opponent, atk, overallModifier);
		cout << "\n" << player.getName() << " used ";
		player.printAtk2Name();
		cout << "! \n";
		critDialog(crit);
		if (opponent.getHP() <= 0)
		{
			cout << opponent.getName() << " has fainted. " << player.getName() << " wins!\n";
			endGame(player, opponent, unused);
		}
	}
	else if (input == 3)
	{
		auto atk = player.getAtk3();
		float crit = critMod(opponent, atk);
		float overallModifier = overallMod(crit);
		opponent.pokeAttack(player, opponent, atk, overallModifier);
		cout << "\n" << player.getName() << " used ";
		player.printAtk3Name();
		cout << "! \n";
		critDialog(crit);
		if (opponent.getHP() <= 0)
		{
			cout << opponent.getName() << " has fainted. " << player.getName() << " wins!\n";
			endGame(player, opponent, unused);
		}
	}
	else if (input == 4)
	{
		auto atk = player.getAtk4();
		float crit = critMod(opponent, atk);
		float overallModifier = overallMod(crit);
		opponent.pokeAttack(player, opponent, atk, overallModifier);
		cout << "\n" << player.getName() << " used ";
		player.printAtk4Name();
		cout << "! \n";
		critDialog(crit);
		if (opponent.getHP() <= 0)
		{
			cout << opponent.getName() << " has fainted. " << player.getName() << " wins!\n";
			endGame(player, opponent, unused);
		}	
	}
}
void opponentAttack(Pokemon &opponent, Pokemon &player, Pokemon &unused)
{
	int x = randNum(1, 4);
	if (x == 1)
	{
		auto atk2 = opponent.getAtk1();
		float crit = critMod(player, atk2);
		float overallModifier = overallMod(crit);
		player.pokeAttack(opponent, player, atk2, overallModifier);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk1Name();
		cout << "! \n";
		critDialog(crit);
	}
	else if (x == 2)
	{
		auto atk2 = opponent.getAtk2();
		float crit = critMod(player, atk2);
		float overallModifier = overallMod(crit);
		player.pokeAttack(opponent, player, atk2, overallModifier);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk2Name();
		cout << "! \n";
		critDialog(crit);
	}
	else if (x == 3)
	{
		auto atk2 = opponent.getAtk3();
		float crit = critMod(player, atk2);
		float overallModifier = overallMod(crit);
		player.pokeAttack(opponent, player, atk2, overallModifier);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk3Name();
		cout << "! \n";
		critDialog(crit);
	}
	else if (x == 4)
	{
		auto atk2 = opponent.getAtk4();
		float crit = critMod(player, atk2);
		float overallModifier = overallMod(crit);
		player.pokeAttack(opponent, player, atk2, overallModifier);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk4Name();
		cout << "! \n";
		critDialog(crit);
	}
	if (player.getHP() <= 0)
	{
		cout << player.getName() << " has fainted. " << opponent.getName() << " wins!\n";
		endGame(player, opponent, unused);
	}
}
int endGame(Pokemon &player, Pokemon &opponent, Pokemon &unused) 
{
	cout << "\n1-Return to the menu" << endl;
	cout << "2-Exit game" << endl;
	int input;
	cout << "\nWhat would you like to do? Enter a number: ";
	cin >> input;
	if (input == 1)
	{
		player.resetHP();
		opponent.resetHP();
		unused.resetHP();
		menuScreen(player, opponent, unused);
	}
	else if (input == 2)
	{
		exit(0);
	}
}
Pokemon speedCompare(Pokemon &poke1, Pokemon &poke2)
{
	if (poke1.getSpeed() > poke2.getSpeed())
	{
		return poke1;
	}
	else
	{
		return poke2;
	}
}
float critMod(Pokemon &target, Attack &atk)
{
	if (target.getBaseType() == pokeType::Fire||target.getSubType()==pokeType::Fire)
	{
		if (atk.getAtkType() == attackType::Ground || atk.getAtkType() == attackType::Rock || atk.getAtkType() == attackType::Water)
		{
			return 2.0;
		}
		else if (atk.getAtkType() == attackType::Bug || atk.getAtkType() == attackType::Steel || atk.getAtkType() == attackType::Fire || atk.getAtkType() == attackType::Grass
			|| atk.getAtkType() == attackType::Ice || atk.getAtkType() == attackType::Fairy)
		{
			return 0.5;
		}
		else
		{
			return 1.0;
		}
	}
	if (target.getBaseType() == pokeType::Grass || target.getSubType() == pokeType::Grass)
	{
		if (atk.getAtkType() == attackType::Flying || atk.getAtkType() == attackType::Poison || atk.getAtkType() == attackType::Bug||atk.getAtkType()==attackType::Fire||atk.getAtkType()==attackType::Ice)
		{
			return 2.0;
		}
		else if (atk.getAtkType() == attackType::Ground || atk.getAtkType() == attackType::Water || atk.getAtkType() == attackType::Grass || atk.getAtkType() == attackType::Electric)
		{
			return 0.5;
		}
		else
		{
			return 1.0;
		}
	}
	if (target.getBaseType() == pokeType::Water || target.getSubType() == pokeType::Water)
	{
		if (atk.getAtkType() == attackType::Grass || atk.getAtkType() == attackType::Electric)
		{
			return 2.0;
		}
		else if (atk.getAtkType() == attackType::Steel || atk.getAtkType() == attackType::Fire || atk.getAtkType() == attackType::Water || atk.getAtkType() == attackType::Ice)
		{
			return 0.5;
		}
		else
		{
			return 1.0;
		}
	}
}
void critDialog(float x)
{
	if (x == 2.0)
	{
		cout << "\nIt's super effective!\n" << endl;
	}
	else if (x == 0.5)
	{
		cout << "\nIt's not very effective!\n" << endl;
	}
	else if (x == 0)
	{
		cout << "\nIt's not effecive.\n" << endl;
	}
}
float overallMod(float critMod)
{
	float overallMod = critMod;
	return overallMod;
}