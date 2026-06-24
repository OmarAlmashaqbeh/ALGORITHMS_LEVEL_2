#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };
enum enFinalResult { PASS = 1, FAIL = 2 };

struct stQuestion
{
    enQuestionLevel questionLevel;
    enOpType opType;
    short num1;
    short num2;
    int correctAnswer;
    int playerAnswer;
    bool answerResult = false;
};
struct stGameResults
{
    stQuestion questionList[100];
    short numberOfQuestions;
    enQuestionLevel questionLevel;
    enOpType opType;
    short numberOfRightAnswers = 0;
    short numberOfWrongAnswers = 0;
    enFinalResult finalResult;
};

bool playAgain()
{
    cout << "\nDo you want to play again? Y/N? ?";
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
short readHowManyQuestions()
{
    short num;
    do
    {
        cout << "How many questions do you want to answer ? ";
        cin >> num;
    } while (num <= 0);
    return num;
}
enQuestionLevel readQuestionsLevel()
{
    short num;
    do
    {
        cout << "Enter questions level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> num;
    } while (num <= 0 || num > 4);
    return (enQuestionLevel)num;
}
enOpType readOpType()
{
    short num;
    do
    {
        cout << "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> num;
    } while (num <= 0 || num > 5);
    return (enOpType)num;
}
short getRandomNumber(short from, short to)
{
    short num = rand() % (to - from + 1) + from;
    return num;
}
string getOpTypeSymbol(enOpType opType) {
    string arrOpSymbol[5] = { "+", "-", "*", "/","Mix" };
    return arrOpSymbol[opType - 1];
}
string getQuestionLevel(enQuestionLevel questionLevel) {
    string arrOpSymbol[4] = { "Easy", "Med", "Hard","Mix" };
    return arrOpSymbol[questionLevel - 1];
}
enQuestionLevel getRandomLevel()
{
    return (enQuestionLevel)getRandomNumber(1, 3);
}
short getRandomNumberForTheLevel(enQuestionLevel questionLevel)
{
    switch (questionLevel)
    {
    case Easy:
        return getRandomNumber(1, 10);
    case Med:
        return getRandomNumber(10, 50);
    case Hard:
        return getRandomNumber(50, 100);
    default:
        return getRandomNumberForTheLevel(getRandomLevel());
    }
}
enOpType getRandomOpType()
{
    return (enOpType)getRandomNumber(1, 4);
}
short calculateQuestionAnswer(stQuestion questionInfo)
{
    switch (questionInfo.opType)
    {
    case enOpType::Add:
        return questionInfo.num1 + questionInfo.num2;
    case enOpType::Sub:
        return questionInfo.num1 - questionInfo.num2;
    case enOpType::Mul:
        return questionInfo.num1 * questionInfo.num2;
    case enOpType::Div:
        return questionInfo.num1 / questionInfo.num2;
    default:
        return 0;
    }
}
short readPlayerAnswer()
{
    short num;
    cin >> num;
    return num;
}
string getFinalGameResultHeader(enFinalResult finalResult)
{
    if (finalResult == enFinalResult::PASS)
    {
        return " Final Result is PASS :-)";
    }
    return " Final Result is FAIL :-(";
}
void startQuestion(stQuestion& questionInfo)
{
    cout << questionInfo.num1 << "\n";
    cout << questionInfo.num2 << " " << getOpTypeSymbol(questionInfo.opType) << "\n";
    cout << "_________\n";
    questionInfo.playerAnswer = readPlayerAnswer();
    if (questionInfo.playerAnswer == questionInfo.correctAnswer)
    {
        system("color 27");
        cout << "Right Answer :-)" << endl;
        questionInfo.answerResult = true;
    }
    else
    {
        system("color 47");
        cout << "Wrong Answer :-(\n";
        cout << "The Right Answer is: " << questionInfo.correctAnswer << endl;
        questionInfo.answerResult = false;
    }
}
void playMathGame(stGameResults& gameResults)
{
    for (short i = 0; i < gameResults.numberOfQuestions; i++)
    {
        gameResults.questionList[i].questionLevel = (gameResults.questionLevel == enQuestionLevel::MixLevel) ? getRandomLevel() : gameResults.questionLevel;
        gameResults.questionList[i].opType = (gameResults.opType == enOpType::MixOp) ? getRandomOpType() : gameResults.opType;
        gameResults.questionList[i].num1 = getRandomNumberForTheLevel(gameResults.questionList[i].questionLevel);
        gameResults.questionList[i].num2 = getRandomNumberForTheLevel(gameResults.questionList[i].questionLevel);
        gameResults.questionList[i].correctAnswer = calculateQuestionAnswer(gameResults.questionList[i]);
        cout << "\nQuestion [" << i + 1 << "/" << gameResults.numberOfQuestions << "]\n" << endl;
        startQuestion(gameResults.questionList[i]);
        if (gameResults.questionList[i].answerResult)
        {
            gameResults.numberOfRightAnswers++;
        }
        else
        {
            gameResults.numberOfWrongAnswers++;
        }
    }
    if (gameResults.numberOfRightAnswers >= gameResults.numberOfWrongAnswers)
    {
        gameResults.finalResult = enFinalResult::PASS;
    }
    else
    {
        gameResults.finalResult = enFinalResult::FAIL;
    }
}
void printGameOverScreenHeader(enFinalResult finalResult)
{
    cout << "\n__________________________________________\n";
    cout << "\n" << getFinalGameResultHeader(finalResult) << "\n";
    cout << "__________________________________________\n";
}
void printFinalGameResults(stGameResults& gameResults)
{
    printGameOverScreenHeader(gameResults.finalResult);
    cout << "Number of question      : " << gameResults.numberOfQuestions << "\n";
    cout << "Question level          : " << getQuestionLevel(gameResults.questionLevel) << "\n";
    cout << "Operation Type          : " << getOpTypeSymbol(gameResults.opType) << "\n";
    cout << "Number of right answers : " << gameResults.numberOfRightAnswers << "\n";
    cout << "Number of Wrong answers : " << gameResults.numberOfWrongAnswers << "\n";
    cout << "__________________________________________" << endl;
}
void startGame()
{
    do
    {
        resetScreen();
        stGameResults gameResults;
        gameResults.numberOfQuestions = readHowManyQuestions();
        gameResults.questionLevel = readQuestionsLevel();
        gameResults.opType = readOpType();
        playMathGame(gameResults);
        printFinalGameResults(gameResults);
    } while (playAgain());
}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}