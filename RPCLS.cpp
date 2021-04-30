#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<math.h>

using namespace std;
// Sheldon would be proud of the game idea.
int userChoice=0;

const int ROCK=1;
const int PAPER=2;
const int SCISSORS=3;
const int LIZARD=4;
const int SPOCK=5;


int getComputerChoice()
{
	srand(time(NULL));
	int compChoice=rand()%5+1;
	return compChoice;
}

void determineWinnner(int userChoice,int compChoice)
{
	if(userChoice==compChoice)
	{
		cout<<"Nobody wins, try again :)";
		return;
	}

	if(userChoice==SCISSORS && compChoice==PAPER)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==PAPER && compChoice==ROCK)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==ROCK && compChoice==LIZARD)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==LIZARD && compChoice==SPOCK)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==SPOCK && compChoice==SCISSORS)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==SCISSORS && compChoice==LIZARD)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==LIZARD && compChoice==PAPER)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==PAPER && compChoice==SPOCK)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==SPOCK && compChoice==ROCK)
	{
		cout<<"user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}

	if(userChoice==ROCK && compChoice==SCISSORS)
	{

		cout<<" And as it always has : user wins";
		return;
	}
	else
	{
		cout<<"computer wins";
		return;
	}
}


void displayChoice(int choice)
{

	string result;

	if(choice==ROCK)
	{
		result="rock";
	}
	if(choice==PAPER)
	{
		result="paper";
	}
	if(choice==SCISSORS)
	{
		result="scissors";
	}
	if(choice==LIZARD)
	{
		result="lizard";
	}
	if(choice==SPOCK)
	{
		result="spock";
	}
	cout<<result<<endl;

}


int main()
{
	cin>>userChoice;

	displayChoice(userChoice);

	int compChoice = getComputerChoice();

	displayChoice(compChoice);

	cout<<"Well well well the winner is: ";

	determineWinnner(userChoice,compChoice);
	cout<<endl;
}