#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;
enum enChoices { stone = 1, paper = 2, scissors = 3 };
enum enResult { player1Win = 1, computerWin = 2, noWinner = 3 };
short readPositiveNumber(string text)
{
    short num;
    do
    {
        cout << text;
        cin >> num;
    } while (num <= 0);
    return num;
}
bool playAgain()
{
    char ch;
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        return true;
    }
    return false;
}
short getRandomNumber(short from, short to)
{
    short num = rand() % (to - from + 1) + from;
    return num;
}
string printChoice(short num)
{
    switch (num)
    {
    case 1:
        return "stone";
    case 2:
        return "paper";
    default:
        return "scissors";
    }
}
short getResultOfRound(short player1Choice, short computerChoice)
{
    if (player1Choice == enChoices::stone)
    {
        if (computerChoice == enChoices::paper)
        {
            return enResult::computerWin;
        }
        else if (computerChoice == enChoices::scissors)
        {
            return enResult::player1Win;
        }
    }
    else if (player1Choice == enChoices::paper)
    {
        if (computerChoice == enChoices::scissors)
        {
            return enResult::computerWin;
        }
        else if (computerChoice == enChoices::stone)
        {
            return enResult::player1Win;
        }
    }
    else if (player1Choice == enChoices::scissors)
    {
        if (computerChoice == enChoices::stone)
        {
            return enResult::computerWin;
        }
        else if (computerChoice == enChoices::paper)
        {
            return enResult::player1Win;
        }
    }
    return enResult::noWinner;
}
void printResultOfRound(short player1Choice, short computerChoice, short winner)
{
    cout << "\nPlayer1  choice: " << printChoice(player1Choice) << endl;
    cout << "Computer choice: " << printChoice(computerChoice) << endl;
    switch (winner)
    {
    case 1:
        cout << "Round    winner: [Plaayer1]" << endl;
        break;
    case 2:
        cout << "Round    winner: [Computer]" << endl;
        break;
    default:
        cout << "Round    winner: [No winner]" << endl;
        break;
    }
}
void startRound(short player1Choice, short roundNmber, short& playerWonTimes, short& computerWonTimes, short& drawTimes)
{
    cout << "\n________________Round [" << roundNmber << "]________________" << endl;
    short computerChoice = getRandomNumber(1, 3);
    switch (getResultOfRound(player1Choice, computerChoice))
    {
    case 1:
        system("color 27");
        printResultOfRound(player1Choice, computerChoice, 1);
        playerWonTimes++;
        break;
    case 2:
        system("color 47");
        cout << "\a";
        printResultOfRound(player1Choice, computerChoice, 2);
        computerWonTimes++;
        break;
    default:
        system("color 67");
        printResultOfRound(player1Choice, computerChoice, 3);
        drawTimes++;
        break;
    }
    cout << "_________________________________________" << endl;
}
void gameOver(short numberOfRounds, short playerWonTimes, short computerWonTimes, short drawTimes)
{
    cout << "\t\t_______________________________________________________________" << endl;
    cout << "\n\t\t\t\t+++ G a m e  O v e r +++" << endl;
    cout << "\t\t_______________________________________________________________" << endl;
    cout << "\n\t\t____________________ [ Game Results ] __________________________" << endl;
    cout << "\n\t\tGame rounds      : " << numberOfRounds << endl;
    cout << "\t\tPlayer1 won times  : " << playerWonTimes << endl;
    cout << "\t\tComputer won times : " << computerWonTimes << endl;
    cout << "\t\tDraw times         : " << drawTimes << endl;
    if (playerWonTimes > computerWonTimes)
    {
        cout << "\t\tFinal winner       : Player1" << endl;
    }
    else if (computerWonTimes > playerWonTimes)
    {
        cout << "\t\tFinal winner       : Computer" << endl;
    }
    else
    {
        cout << "\t\tFinal winner       : No winner" << endl;
    }
    cout << "\t\t_______________________________________________________________" << endl;
}
void startGame()
{
    short numberOfRounds = readPositiveNumber("How many rounds 1 to 10 ? ");
    short playerWonTimes = 0, computerWonTimes = 0, drawTimes = 0;
    for (int i = 1; i <= numberOfRounds; i++)
    {
        cout << "\n\nRound [" << i << "] begins:" << endl;
        short player1Choice = readPositiveNumber("\nYour choice : [1]:stone, [2]:paper, [3]:scissors ? ");
        startRound(player1Choice, i, playerWonTimes, computerWonTimes, drawTimes);
    }
    gameOver(numberOfRounds, playerWonTimes, computerWonTimes, drawTimes);
    cout << "\n\t\tDo you want to play again? Y/N? ?";
    if (playAgain())
    {
        system("cls");
        system("color 07");
        startGame();
    }
}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}