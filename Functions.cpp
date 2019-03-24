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
		battleGame(poke1, poke2, poke3);
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
	cout << "Pokemon: " << poke.getName() << "\n"
		<< "HP: " << poke.getHP() << "\n" 
		<< "Speed: " << poke.getSpeed() << "\n" << endl;
	poke.printAtk1();
	poke.printAtk2();
	poke.printAtk3();
	poke.printAtk4();
}
void battleGame(Pokemon &poke1, Pokemon &poke2, Pokemon &poke3)
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
			attackScreen(playerPoke, opponentPoke, poke3);
		}
		else
		{
			Pokemon opponentPoke(poke3);
			attackScreen(playerPoke, opponentPoke, poke2);
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
			attackScreen(playerPoke, opponentPoke, poke3);
		}
		else
		{
			Pokemon opponentPoke(poke3);
			attackScreen(playerPoke, opponentPoke, poke1);
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
			attackScreen(playerPoke, opponentPoke, poke2);
		}
		else
		{
			Pokemon opponentPoke(poke2);
			attackScreen(playerPoke, opponentPoke, poke1);
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
	Pokemon first = speedCompare(player, opponent);
	if (first.getName() == player.getName())
	{
		playerAttack(player, opponent, unused);
		opponentAttack(opponent, player, unused);
		attackScreen(player, opponent, unused);
	}
	else if (first.getName() == opponent.getName());
	{
		opponentAttack(opponent, player, unused);
		playerAttack(player, opponent, unused);
		attackScreen(player, opponent, unused);
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
		opponent.pokeAttack(atk);
		cout << "\n"<<player.getName() << " used ";
		player.printAtk1Name();
		cout<<"! \n";
		if (opponent.getHP() <= 0)
		{
			cout << opponent.getName() << " has fainted. " << player.getName() << " wins!\n";
			endGame(player, opponent, unused);
		}
	}
	else if (input == 2)
	{
		auto atk = player.getAtk2();
		opponent.pokeAttack(atk);
		cout << "\n" << player.getName() << " used ";
		player.printAtk2Name();
		cout << "! \n";
		if (opponent.getHP() <= 0)
		{
			cout << opponent.getName() << " has fainted. " << player.getName() << " wins!\n";
			endGame(player, opponent, unused);
		}
	}
	else if (input == 3)
	{
		auto atk = player.getAtk3();
		opponent.pokeAttack(atk);
		cout << "\n" << player.getName() << " used ";
		player.printAtk3Name();
		cout << "! \n";
		if (opponent.getHP() <= 0)
		{
			cout << opponent.getName() << " has fainted. " << player.getName() << " wins!\n";
			endGame(player, opponent, unused);
		}
	}
	else if (input == 4)
	{
		auto atk = player.getAtk4();
		opponent.pokeAttack(atk);
		cout << "\n" << player.getName() << " used ";
		player.printAtk4Name();
		cout << "! \n";
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
		player.pokeAttack(atk2);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk1Name();
		cout << "! \n";
	}
	else if (x == 2)
	{
		auto atk2 = opponent.getAtk2();
		player.pokeAttack(atk2);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk2Name();
		cout << "! \n";
	}
	else if (x == 3)
	{
		auto atk2 = opponent.getAtk3();
		player.pokeAttack(atk2);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk3Name();
		cout << "! \n";
	}
	else if (x == 4)
	{
		auto atk2 = opponent.getAtk4();
		player.pokeAttack(atk2);
		cout << "\n" << opponent.getName() << " used ";
		opponent.printAtk4Name();
		cout << "! \n";
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