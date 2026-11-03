
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
using namespace std;

enum enGameChoice {Rock = 1,Paper,Scissors};
enum enGameResult { Draw = 0, PlayerWin, ComputerWin };


struct stGameResults {
short playerCount = 0;
short computerCount = 0;
short drawCount = 0;

};


int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enGameChoice ReadPlayerChoice()
{
	short PlayerChoice = 0;
	do {
		cout << " enter your choice (1) for stone, (2) for paper, (3) for scissor :  ";
		cin >> PlayerChoice;
	} while (PlayerChoice < 1 || PlayerChoice > 3);

	return (enGameChoice)PlayerChoice;
}

enGameChoice ReadComputerChoice()
{
	enGameChoice Computerchoice = (enGameChoice)RandomNumber(1, 3);
	return Computerchoice;
}

void showPlayerchoice( enGameChoice PlayerChoice)
{
	if (PlayerChoice == enGameChoice::Rock)
	{
		cout << " Player choice : stone \n";
	}
	else if(PlayerChoice == enGameChoice::Paper)
	{
		cout << " Player choice : Paper \n";
	}
	else 
		cout<< "  Player choice : scissor \n";

}
void showcomputerchoice(enGameChoice ComputerChoice)
{
	switch (ComputerChoice)
	{
	case enGameChoice::Rock:
		cout << " Computer choice : stone \n";
		break;
	case enGameChoice::Paper:
		cout << " Computer choice : Paper \n";
		break;
	case enGameChoice::Scissors:
		cout << " Computer choice : scissor \n";
		break;
	}

}

void ShowRoundWinner(enGameChoice PlayerChoice, enGameChoice ComputerChoice , stGameResults& GameResults )
{

	if (PlayerChoice == ComputerChoice)
	{
		system("color 6F");
		cout << " Round Result : Draw \n";
	    GameResults.drawCount++;
	}
	else if ((PlayerChoice == enGameChoice::Rock && ComputerChoice == enGameChoice::Scissors) ||
		(PlayerChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Rock) ||
		(PlayerChoice == enGameChoice::Scissors && ComputerChoice == enGameChoice::Paper))
	{
		system("color 2F");
		
		cout << " Round Result : Player Wins \n";
		GameResults.playerCount++;
	}
	else
	{
		
		system("color 4F");
		Beep(750, 400);
		cout << " Round Result : Computer Wins \n";
		GameResults.computerCount++;
	    
	}
	
}

void RoundStatus(int count, stGameResults& GameRes)
{
	

	enGameChoice PlayerChoice = ReadPlayerChoice();
	enGameChoice ComputerChoice = ReadComputerChoice();
	cout << " ---------------Round " << count << " ---------------\n";
	showPlayerchoice ( PlayerChoice );
	showcomputerchoice( ComputerChoice );
	ShowRoundWinner(PlayerChoice, ComputerChoice,GameRes);
	cout << "-----------------------------\n";

}


void PlayGame(short HowManyRounds,stGameResults& GameRes)
{
	for (int i = 1; i <= HowManyRounds; i++)
	{

		cout << " Round [" << i << "] Begins : \n";
		RoundStatus(i,GameRes);
	}


}

string FinalWinner(stGameResults GameResults)
{
	if (GameResults.computerCount > GameResults.playerCount)
	{
		system("color 4F");
		return "Computer ,,\n";
	}
	else if (GameResults.computerCount < GameResults.playerCount)
	{
		system("color 2F");
		return "Player ,,\n";
	}

	else
		system("color 6F");
		return "No Winner ,,\n";
	
}

void PrintGameOverScreen( short rounds,stGameResults GameResults)
{
	cout << " __________________________________________________________________________\n";
	cout << "                          ++++++ Game Over ++++++                           \n";
	cout << " __________________________________________________________________________\n";
	cout << " ___________________________________________ [Game Results]___________________________________________\n";
	cout << " Game Rounds : " << rounds << endl;
	cout << " Pleayer Won Times : " << GameResults.playerCount << endl;
	cout << " Computer Won Times : " << GameResults.computerCount << endl;
	cout << " Draw Times : " << GameResults.drawCount << endl;
	cout << " Final Winner : " << FinalWinner(GameResults);


}

void ResetScreen()
{
	system("cls");
	system("color 07");
	cout << "                             Welcome to the Stone-Paper-Scissors Game! \n" << endl;

}

short ReadRoundsNumber()
{
	short HowManyRounds = 0;
	cout << " Enter How Many Round Would You Like To Play : ";
		cin >> HowManyRounds;
		return HowManyRounds;
}

void StartGame()
{
	ResetScreen();
    stGameResults GameRes;
	short rounds = ReadRoundsNumber();
	PlayGame(rounds,GameRes);

	PrintGameOverScreen(rounds,GameRes);
}

void RunGame()
{
	char answer = 'Y';

	do {

		StartGame();

		cout << "\n would you like to play another game ?? y/n   :";

		cin >> answer;

	} while (answer == 'y' || answer == 'Y');


}


int main()
{
	srand((unsigned)time(NULL));

	RunGame();
	return 0;
}
