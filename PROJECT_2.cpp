#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };
enum enFinalResult { PASS = 1, FAIL = 2 };

struct stQuestionInfo
{
    enQuestionLevel questionLevel;
    short num1;
    short num2;
    enOpType opType;
    enFinalResult result;
};
struct stGameResults
{
    short numberOfQuestion;
    enQuestionLevel questionLevel;
    enOpType opType;
    short numberOfRightAnswers;
    short numberOfWrongAnswers;
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
short readHowManyQuestions(string text)
{
    short num;
    do
    {
        cout << text;
        cin >> num;
    } while (num <= 0);
    return num;
}
enQuestionLevel readQuestionsLevel(string text)
{
    short num;
    do
    {
        cout << text;
        cin >> num;
    } while (num <= 0 || num > 4);
    return (enQuestionLevel)num;
}
enOpType readOpType(string text)
{
    short num;
    do
    {
        cout << text;
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
        return getRandomNumber(1, 9);
    case Med:
        return getRandomNumber(10, 40);
    case Hard:
        return getRandomNumber(41, 99);
    default:
        return getRandomNumberForTheLevel(getRandomLevel());
    }
}
enOpType getRandomOpType()
{
    return (enOpType)getRandomNumber(1, 4);
}
short calculateQuestionAnswer(short num1, short num2, enOpType opType)
{
    switch (opType)
    {
    case enOpType::Add:
        return num1 + num2;
    case enOpType::Sub:
        return num1 - num2;
    case enOpType::Mul:
        return num1 * num2;
    case enOpType::Div:
        return num1 / num2;
    default:
        return 0;
    }
}
short readUserAnswer()
{
    short num;
    cin >> num;
    return num;
}
void startQuestion(stQuestionInfo& questionInfo, short& numberOfRightAnswers, short& numberOfWrongAnswers)
{
    enQuestionLevel currentLevel = (questionInfo.questionLevel == enQuestionLevel::MixLevel) ? getRandomLevel() : questionInfo.questionLevel;
    enOpType currentOpType = (questionInfo.opType == MixOp) ? getRandomOpType() : questionInfo.opType;
    questionInfo.num1 = getRandomNumberForTheLevel(currentLevel);
    questionInfo.num2 = getRandomNumberForTheLevel(currentLevel);
    short rightAnswer = calculateQuestionAnswer(questionInfo.num1, questionInfo.num2, currentOpType);
    cout << "\n" << questionInfo.num1 << "\n";
    cout << questionInfo.num2 << " " << getOpTypeSymbol(currentOpType) << "\n";
    cout << "___________\n";
    short userAnswer = readUserAnswer();
    if (userAnswer == rightAnswer)
    {
        system("color 27");
        cout << "Right answer :-)" << endl;
        numberOfRightAnswers++;
    }
    else
    {
        system("color 47");
        cout << "Wrong answer :-(\n";
        cout << "The right answer is: " << rightAnswer << endl;
        numberOfWrongAnswers++;
    }
}
enFinalResult getFinalGameResult(short numberOfRightAnswers, short numberOfWrongAnswers)
{
    if (numberOfRightAnswers >= numberOfWrongAnswers)
    {
        return enFinalResult::PASS;
    }
    return enFinalResult::FAIL;
}
stGameResults fillGameResults(short numberOfQuestions, enQuestionLevel questionLevel, enOpType opType, short numberOfRightAnswers, short numberOfWrongAnswers)
{
    stGameResults gameResults;

    gameResults.numberOfQuestion = numberOfQuestions;
    gameResults.questionLevel = questionLevel;
    gameResults.opType = opType;
    gameResults.numberOfRightAnswers = numberOfRightAnswers;
    gameResults.numberOfWrongAnswers = numberOfWrongAnswers;
    gameResults.finalResult = getFinalGameResult(numberOfRightAnswers, numberOfWrongAnswers);

    return gameResults;
}
stGameResults playGame(short numberOfQuestions, enQuestionLevel questionLevel, enOpType opType)
{
    stQuestionInfo questionInfo;
    questionInfo.questionLevel = questionLevel;
    questionInfo.opType = opType;
    short numberOfRightAnswer = 0, numberOfWrongAnswer = 0;
    for (short questionNumber = 1; questionNumber <= numberOfQuestions; questionNumber++)
    {
        cout << "\nQuestion [" << questionNumber << "/" << numberOfQuestions << "]\n";
        startQuestion(questionInfo, numberOfRightAnswer, numberOfWrongAnswer);
    }
    return fillGameResults(numberOfQuestions, questionLevel, opType, numberOfRightAnswer, numberOfWrongAnswer);
}
string getFinalGameResultHeader(enFinalResult finalResult)
{
    if (finalResult == enFinalResult::PASS)
    {
        return " Final Result is PASS :-)";
    }
    return " Final Result is FAIL :-(";
}
void showGameOverScreen(enFinalResult finalResult)
{
    cout << "\n__________________________________________\n";
    cout << "\n" << getFinalGameResultHeader(finalResult) << "\n";
    cout << "__________________________________________\n";
}
void showFinalGameResults(stGameResults gameResults)
{
    cout << "Number of question      : " << gameResults.numberOfQuestion << "\n";
    cout << "Question level          : " << getQuestionLevel(gameResults.questionLevel) << "\n";
    cout << "Operation Type          : " << getOpTypeSymbol(gameResults.opType) << "\n";
    cout << "Number of right answers : " << gameResults.numberOfRightAnswers << "\n";
    cout << "Number of Wrong answers : " << gameResults.numberOfWrongAnswers << "\n";
    cout << "__________________________________________" << endl;
}
void startGame()
{
    resetScreen();
    short numberOfQuestions = readHowManyQuestions("How many questions do you want to answer ? ");
    enQuestionLevel questionsLevel = readQuestionsLevel("Enter questions level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ");
    enOpType opType = readOpType("Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ");
    stGameResults gameResults = playGame(numberOfQuestions, questionsLevel, opType);
    showGameOverScreen(gameResults.finalResult);
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