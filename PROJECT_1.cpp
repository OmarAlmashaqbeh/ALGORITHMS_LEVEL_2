#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

enum enChoices { stone = 1, paper = 2, scissors = 3 };
enum enWinner { player1Win = 1, computerWin = 2, noWinner = 3 };

struct stRoundInfo
{
    short roundNumber;
    enChoices player1Choice;
    enChoices computerChoice;
    enWinner winner;
    string winnerName;
};
struct stGameResults
{
    short gameRounds;
    short player1WinTimes = 0;
    short computerWinTimes = 0;
    short drawTimes = 0;
    enWinner gameWinner;
    string winnerName;
};

bool playAgain()
{
    cout << "\n\t\tDo you want to play again? Y/N? ?";
    char ch;
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        return true;
    }
    return false;
}
void resetScreen()
{
    system("cls");
    system("color 07");
}
int readHowManyRounds(string text)
{
    int num;
    do
    {
        cout << text << endl;
        cin >> num;
    } while (num <= 0 || num > 10);
    return num;
}
enChoices readPlayerChoice(string text)
{
    short num;
    do
    {
        cout << text;
        cin >> num;
    } while (num <= 0 || num > 3);
    return (enChoices)num;
}
short getRandomNumber(short from, short to)
{
    short num = rand() % (to - from + 1) + from;
    return num;
}
enChoices computerChoice()
{
    return (enChoices)getRandomNumber(1, 3);
}
string choiceName(enChoices Choice)
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}
string winnerName(enWinner winner)
{
    string arrWinnerName[3] = { "Player1", "Computer", "No Winner (Draw)" };
    return arrWinnerName[winner - 1];
}
enWinner whoWonTheRound(stRoundInfo roundInfo)
{
    if (roundInfo.computerChoice == roundInfo.player1Choice)
    {
        return enWinner::noWinner;
    }
    switch (roundInfo.player1Choice)
    {
    case enChoices::stone:
        return (roundInfo.computerChoice == enChoices::paper) ? enWinner::computerWin : enWinner::player1Win;
    case enChoices::paper:
        return (roundInfo.computerChoice == enChoices::scissors) ? enWinner::computerWin : enWinner::player1Win;
    case enChoices::scissors:
        return (roundInfo.computerChoice == enChoices::stone) ? enWinner::computerWin : enWinner::player1Win;
    }
}
enWinner whoWonTheGame(short player1WinTimes, short computerWinTimes)
{
    if (player1WinTimes == computerWinTimes)
    {
        return enWinner::noWinner;
    }
    return (player1WinTimes > computerWinTimes) ? enWinner::player1Win : enWinner::computerWin;
}
void setWinnerScreen(stRoundInfo roundInfo)
{
    switch (roundInfo.winner)
    {
    case enWinner::player1Win:
        system("color 27");
        break;
    case enWinner::computerWin:
        system("color 47");
        cout << "\a";
        break;
    default:
        system("color 67");
        break;
    }
}
void printRoundResults(stRoundInfo roundInfo)
{
    cout << "\nPlayer1 choice  : " << choiceName(roundInfo.player1Choice) << "\n";
    cout << "Computer choice : " << choiceName(roundInfo.computerChoice) << "\n";
    cout << "Round winner    : " << roundInfo.winnerName << "\n";
    setWinnerScreen(roundInfo);
}
void fillRoundInfo(stRoundInfo roundInfo, short& playerWonTimes, short& computerWonTimes, short& drawTimes)
{
    switch (roundInfo.winner)
    {
    case enWinner::player1Win:
        playerWonTimes++;
        break;
    case enWinner::computerWin:
        computerWonTimes++;
        break;
    default:
        drawTimes++;
        break;
    }
}
void startRound(short roundNumber, stRoundInfo& roundInfo)
{
    cout << "\n________________Round [" << roundNumber << "]________________\n";
    roundInfo.player1Choice = readPlayerChoice("\nYour choice : [1]:stone, [2]:paper, [3]:scissors ? ");
    roundInfo.computerChoice = computerChoice();
    roundInfo.winner = whoWonTheRound(roundInfo);
    roundInfo.winnerName = winnerName(roundInfo.winner);
    printRoundResults(roundInfo);
    cout << "_________________________________________" << endl;
}
stGameResults fillGameResults(short gameRounds, short player1WinTimes, short computerWinTimes, short drawTimes, enWinner gameWinner, string winnerName)
{
    stGameResults gameResults;

    gameResults.gameRounds = gameRounds;
    gameResults.player1WinTimes = player1WinTimes;
    gameResults.computerWinTimes = computerWinTimes;
    gameResults.drawTimes = drawTimes;
    gameResults.gameWinner = gameWinner;
    gameResults.winnerName = winnerName;

    return gameResults;
}
stGameResults playGame(short numberOfRounds)
{
    stRoundInfo roundInfo;
    short playerWonTimes = 0, computerWonTimes = 0, drawTimes = 0;
    for (short roundNumber = 1; roundNumber <= numberOfRounds; roundNumber++)
    {
        cout << "\n\nRound [" << roundNumber << "] begins:\n";
        startRound(roundNumber, roundInfo);
        fillRoundInfo(roundInfo, playerWonTimes, computerWonTimes, drawTimes);
    }
    return fillGameResults(numberOfRounds, playerWonTimes, computerWonTimes, drawTimes, whoWonTheGame(playerWonTimes, computerWonTimes), winnerName(whoWonTheGame(playerWonTimes, computerWonTimes)));
}
void showGameOverScreen()
{
    cout << "\n\t\t_______________________________________________________________\n";
    cout << "\n\t\t\t\t+++ G a m e  O v e r +++\n";
    cout << "\t\t_______________________________________________________________\n";
}
void showFinalGameResults(stGameResults gameResults)
{
    cout << "\n\t\t____________________ [ Game Results ] __________________________\n";
    cout << "\n\t\tGame rounds      : " << gameResults.gameRounds << "\n";
    cout << "\t\tPlayer1 won times  : " << gameResults.player1WinTimes << "\n";
    cout << "\t\tComputer won times : " << gameResults.computerWinTimes << "\n";
    cout << "\t\tDraw times         : " << gameResults.drawTimes << "\n";
    cout << "\t\tFinal winner       : " << gameResults.winnerName << endl;
}
void startGame()
{
    resetScreen();
    short numberOfRounds = readHowManyRounds("How many rounds 1 to 10 ? ");
    stGameResults gameResults = playGame(numberOfRounds);
    showGameOverScreen();
    showFinalGameResults(gameResults);
    if (playAgain())
    {
        startGame();
    }
}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}