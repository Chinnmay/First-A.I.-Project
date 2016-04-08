#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

using namespace std;

int computerRandomPick; //random location which computer selects if first.
int computerPick; //used to decide computer vs player AI moves.
//player interaction
int playerChoice;
bool playerTurn;
int gameWin = 3;
int turnCounter = 1;
int cnt=0;
int firstPlayerChoice = 0;
int beepFrequency = 500;
int beepDuration = 500;
int colourCodeX = 12;
int colourCodeO = 14;
//gameWin is integer because it will allow program to explicitly say who wins instead of bool which will allow you to only declare game state.

//board arrays
char blockOne = ' ';
char blockTwo = ' ';
char blockThree = ' ';
char blockFour = ' ';
char blockFive = ' ';
char blockSix = ' ';
char blockSeven = ' ';
char blockEight = ' ';
char blockNine = ' ';
//random starting turn chooser
int turnFirst; //variable to decide whoever goes first

int checkWinComputer()
{
    if(blockOne == 'O' && blockFive == 'O' && blockNine == 'O') //diagonal, 1 - 5 = 9
        gameWin = 2; //This will make computer win.
    if(blockThree == 'O' && blockFive == 'O' && blockSeven == 'O') //diagonal, 3 - 5 = 7
        gameWin = 2;
    if(blockOne == 'O' && blockTwo == 'O' && blockThree == 'O') //horizontal 1 - 2 = 3
        gameWin = 2;
    if(blockFour == 'O' && blockFive == 'O' && blockSix == 'O') //horizontal 4 - 5 = 6
        gameWin = 2;
    if(blockSeven == 'O' && blockEight == 'O' && blockNine == 'O') //horizontal 7 - 8 = 9
        gameWin = 2;
    if(blockOne == 'O' && blockFour == 'O' && blockSeven == 'O') //vertical 1 - 4 = 7
        gameWin = 2;
    if(blockTwo == 'O' && blockFive == 'O' && blockEight == 'O') //vertical 2 - 5 = 8
        gameWin = 2;
    if(blockThree == 'O' && blockSix == 'O' && blockNine == 'O') //vertical 3 - 6 = 9
        gameWin = 2;
}
int checkWinPlayer()
{
    if(blockOne == 'X' && blockFive == 'X' && blockNine == 'X') //diagonal, 1 - 5 = 9
        gameWin = 1; //This will make player win.
    if(blockThree == 'X' && blockFive == 'X' && blockSeven == 'X') //diagonal, 3 - 5 = 7
        gameWin = 1;
    if(blockOne == 'X' && blockTwo == 'X' && blockThree == 'X') //horizontal 1 - 2 = 3
        gameWin = 1;
    if(blockFour == 'X' && blockFive == 'X' && blockSix == 'X') //horizontal 4 - 5 = 6
        gameWin = 1;
    if(blockSeven == 'X' && blockEight == 'X' && blockNine == 'X') //horizontal 7 - 8 = 9
        gameWin = 1;
    if(blockOne == 'X' && blockFour == 'X' && blockSeven == 'X') //vertical 1 - 4 = 7
        gameWin = 1;
    if(blockTwo == 'X' && blockFive == 'X' && blockEight == 'X') //vertical 2 - 5 = 8
        gameWin = 1;
    if(blockThree == 'X' && blockSix == 'X' && blockNine == 'X') //vertical 3 - 6 = 9
        gameWin = 1;
}

int checkTie()
{
    if(blockOne != ' ' && blockTwo != ' ' && blockThree != ' ' && blockFour != ' ' && blockFive != ' ' && blockSix != ' ' && blockSeven != ' ' && blockEight != ' ' && blockNine != ' ')
    {
        //cout << "\t\t\t\t\t\tIt's a tie!" << endl;
        gameWin = 0;
    }
}

int computerTrick1()
{
    if(playerTurn==false && turnCounter==3)
    {
        if(blockFive=='X')
        {
            if(computerPick==1)
            {
                blockNine = 'O';
                playerTurn=true;
            }
            else if(computerPick==3)
            {
                blockSeven = 'O';
                playerTurn=true;
            }
            else if(computerPick==7)
            {
                blockThree = 'O';
                playerTurn=true;
            }
            else if(computerPick==9)
            {
                blockOne = 'O';
                playerTurn=true;
            }
        }
        else
        {
            int random = rand() % 4 + 1;
            if(random==1 && blockOne==' ')
            {
                blockOne = 'O';
                playerTurn=true;
            }
            else if(random==2 && blockThree==' ')
            {
                blockThree = 'O';
                playerTurn=true;
            }
            else if(random==3 && blockSeven==' ')
            {
                blockSeven = 'O';
                playerTurn=true;
            }
            else if(random==4 && blockNine==' ')
            {
                blockNine = 'O';
                playerTurn=true;
            }
        }
    }
    return 0;
}

int computerTrick2()
{
    if(cnt==0)
    {
        firstPlayerChoice=playerChoice;
        cnt++;
    }
    if(turnCounter==2 && playerChoice==5 && turnFirst==1&&playerTurn==false)
    {
        //int firstPlayerChoice=playerChoice;
        int random = rand() % 4 + 1;
        if(random==1 && blockOne==' ')
        {
            blockOne='O';
            playerTurn=true;
        }
        else if(random==2 && blockThree==' ')
        {
            blockThree='O';
            playerTurn=true;

        }
        else if(random==3 && blockSeven==' ')
        {
            blockSeven='O';
            playerTurn=true;
        }
        else if(random==4 && blockNine==' ')
        {
            blockNine='O';
            playerTurn=true;
        }
    }
    else if(turnCounter==2 && turnFirst==1 && playerTurn==false)
    {
        blockFive='O';
        playerTurn=true;
    }
    if(turnCounter==4 && firstPlayerChoice!=5 && turnFirst==1&&playerTurn==false)
    {
        if(firstPlayerChoice==1||firstPlayerChoice==3||firstPlayerChoice==7||firstPlayerChoice==9)
        {
            int random = rand() % 4 + 1;
            if(random==1 && blockTwo==' ')
            {
                blockTwo='O';
                playerTurn=true;
            }
            else if(random==2 && blockFour==' ')
            {
                blockFour='O';
                playerTurn=true;
            }
            else if(random==3 && blockSix==' ')
            {
                blockSix='O';
                playerTurn=true;
            }
            else if(random==4 && blockEight==' ')
            {
                blockEight='O';
                playerTurn=true;
            }
        }
        else if(firstPlayerChoice==2||firstPlayerChoice==4||firstPlayerChoice==6||firstPlayerChoice==8)
        {
            int random = rand() % 4 + 1;
            if(random==1 && blockOne==' ')
            {
                blockOne='O';
                playerTurn=true;
            }
            else if(random==2 && blockThree==' ')
            {
                blockThree='O';
                playerTurn=true;
            }
            else if(random==3 && blockSeven==' ')
            {
                blockSeven='O';
                playerTurn=true;
            }
            else if(random==4 && blockNine==' ')
            {
                blockNine='O';
                playerTurn=true;
            }
        }
    }
    if(turnCounter==4 && firstPlayerChoice==5 && turnFirst==1&&playerTurn==false)
    {
        if(blockOne==' ')
        {
            blockOne='O';
            playerTurn=true;
        }
        else if(blockThree==' ')
        {
            blockThree='O';
            playerTurn=true;
        }
        else if(blockSeven==' ')
        {
            blockSeven='O';
            playerTurn=true;
        }
        else if(blockNine==' ')
        {
            blockNine='O';
            playerTurn=true;
        }
    }
    return 0;
}

int computerAI() //work on computerAI part where the computer tries to win before countering.
{
    //playerTurn == false;

    if(blockOne == 'O' && blockTwo == 'O' && playerTurn == false && blockThree == ' ') //1 - 2 = 3 win
    {
        blockThree = 'O';
        playerTurn = true;
    }
    if(blockTwo == 'O' && blockThree == 'O' && playerTurn == false && blockOne == ' ') //1 - 2 = 3 win
    {
        blockOne = 'O';
        playerTurn = true;
    }
    if(blockOne == 'O' && blockThree == 'O' && playerTurn == false && blockTwo == ' ') //1 - 2 = 3 win
    {
        blockTwo = 'O';
        playerTurn = true;
    }
    ////////////////////////////////////////////
    if(blockFour == 'O' && blockFive == 'O' && playerTurn == false && blockSix == ' ') //4 - 5 = 6 win
    {
        blockSix = 'O';
        playerTurn = true;
    }
    if(blockFive == 'O' && blockSix == 'O' && playerTurn == false && blockFour == ' ') //1 - 2 = 3 win
    {
        blockFour = 'O';
        playerTurn = true;
    }
    if(blockFour == 'O' && blockSix == 'O' && playerTurn == false && blockFive == ' ') //1 - 2 = 3 win
    {
        blockFive = 'O';
        playerTurn = true;
    }
    ////////////////////////////////////////////
    if(blockSeven == 'O' && blockEight == 'O' && playerTurn == false && blockNine == ' ') //7 - 8 = 9 win
    {
        blockNine = 'O';
        playerTurn = true;
    }
    if(blockSeven == 'O' && blockNine == 'O' && playerTurn == false && blockEight == ' ') //1 - 2 = 3 win
    {
        blockEight = 'O';
        playerTurn = true;
    }
    if(blockNine == 'O' && blockEight == 'O' && playerTurn == false && blockSeven == ' ') //1 - 2 = 3 win
    {
        blockSeven = 'O';
        playerTurn = true;
    }
    ///////////////////////////////////////////////
    if(blockOne == 'O' && blockFour == 'O' && playerTurn == false && blockSeven == ' ') //1 - 4 = 7 win
    {
        blockSeven = 'O';
        playerTurn = true;
    }
    if(blockOne == 'O' && blockSeven == 'O' && playerTurn == false && blockFour == ' ') //1 - 2 = 3 win
    {
        blockFour = 'O';
        playerTurn = true;
    }
    if(blockFour == 'O' && blockSeven == 'O' && playerTurn == false && blockOne == ' ') //1 - 2 = 3 win
    {
        blockOne = 'O';
        playerTurn = true;
    }
    //////////////////////////////////////////////
    if(blockTwo == 'O' && blockFive == 'O' && playerTurn == false && blockEight == ' ') //2 - 5 = 8 win
    {
        blockEight = 'O';
        playerTurn = true;
    }
    if(blockTwo == 'O' && blockEight == 'O' && playerTurn == false && blockFive == ' ') //1 - 2 = 3 win
    {
        blockFive = 'O';
        playerTurn = true;
    }
    if(blockEight == 'O' && blockFive == 'O' && playerTurn == false && blockTwo == ' ') //1 - 2 = 3 win
    {
        blockTwo = 'O';
        playerTurn = true;
    }
    ///////////////////////////////////////////////////
    if(blockThree == 'O' && blockSix == 'O' && playerTurn == false && blockNine == ' ') //3 - 6 = 9 win
    {
        blockNine = 'O';
        playerTurn = true;
    }
    if(blockThree== 'O' && blockNine == 'O' && playerTurn == false && blockSix == ' ') //1 - 2 = 3 win
    {
        blockSix = 'O';
        playerTurn = true;
    }
    if(blockNine == 'O' && blockSix == 'O' && playerTurn == false && blockThree == ' ') //1 - 2 = 3 win
    {
        blockThree = 'O';
        playerTurn = true;
    }
    ///////////////////////////////////////////////////
    if(blockOne == 'O' && blockFive == 'O' && playerTurn == false && blockNine == ' ') //1 - 5 = 9 win
    {
        blockNine = 'O';
        playerTurn = true;
    }
    if(blockOne == 'O' && blockNine == 'O' && playerTurn == false && blockFive == ' ') //1 - 2 = 3 win
    {
        blockFive = 'O';
        playerTurn = true;
    }
    if(blockNine == 'O' && blockFive == 'O' && playerTurn == false && blockOne == ' ') //1 - 2 = 3 win
    {
        blockOne = 'O';
        playerTurn = true;
    }
    //////////////////////////////////////////////
    if(blockThree == 'O' && blockFive == 'O' && playerTurn == false && blockSeven == ' ') //3 - 5 = 7 win
    {
        blockSeven = 'O';
        playerTurn == true;
    }
    if(blockThree == 'O' && blockSeven == 'O' && playerTurn == false && blockFive == ' ') //1 - 2 = 3 win
    {
        blockFive = 'O';
        playerTurn = true;
    }
    if(blockSeven == 'O' && blockFive == 'O' && playerTurn == false && blockThree == ' ') //1 - 2 = 3 win
    {
        blockThree = 'O';
        playerTurn = true;
    }
    ///////////////////////////////////////////////
    if((playerChoice == 1 || playerChoice == 5 || playerChoice == 9) && playerTurn == false)
    {
        if((blockOne == 'X' && blockFive == 'X') && playerTurn == false && blockNine == ' ') //1 - 5 = 9 diagonal
        {
            blockNine = 'O';
            playerTurn = true;
        }

        if((blockOne == 'X' && blockNine == 'X') && playerTurn == false && blockFive == ' ') //1 - 9 = 5 diagonal
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockNine == 'X') && playerTurn == false && blockOne == ' ') //5 - 9 = 1 diagonal
        {
            blockOne = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 3 || playerChoice == 5 || playerChoice == 7) && playerTurn == false)
    {
        if((blockSeven == 'X' && blockFive == 'X') && playerTurn == false && blockThree == ' ') //7 - 5 = 3 diagonal
        {
            blockThree = 'O';
            playerTurn = true;
        }

        if((blockSeven == 'X' && blockThree == 'X') && playerTurn == false && blockFive == ' ') //7 - 3 = 5 diagonal
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockThree == 'X') && playerTurn == false && blockSeven == ' ') //5 - 3 = 7 diagonal
        {
            blockSeven = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 1 || playerChoice == 2 || playerChoice == 3) && playerTurn == false)
    {
        if((blockOne == 'X' && blockTwo == 'X') && playerTurn == false && blockThree == ' ') // 1 - 2 = 3 horizontal
        {
            blockThree = 'O';
            playerTurn = true;
        }

        if((blockOne == 'X' && blockThree == 'X') && playerTurn == false && blockTwo == ' ') //1 - 3 = 2 horizontal
        {
            blockTwo = 'O';
            playerTurn = true;
        }

        if((blockTwo == 'X' && blockThree == 'X') && playerTurn == false && blockOne == ' ') //2 - 3 = 1 horizontal
        {
            blockOne = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 4 || playerChoice == 5 || playerChoice == 6) && playerTurn == false)
    {
        if((blockFour == 'X' && blockFive == 'X') && playerTurn == false && blockSix == ' ') //4 - 5 = 6 horizontal line 2
        {
            blockSix = 'O';
            playerTurn = true;
        }

        if((blockFour == 'X' && blockSix == 'X') && playerTurn == false && blockFive == ' ') //4 - 6  = 5 horizontal line 2
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockSix == 'X') && playerTurn == false && blockFour == ' ') //5 - 6 = 4 horizontal line 2
        {
            blockFour = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 7 || playerChoice == 8 || playerChoice == 9) && playerTurn == false)
    {
        if((blockSeven == 'X' && blockEight == 'X') && playerTurn == false && blockNine == ' ') //7 - 8 = 9 horizontal line 3
        {
            blockNine = 'O';
            playerTurn = true;
        }

        if((blockSeven == 'X' && blockNine == 'X') && playerTurn == false && blockEight == ' ') //7 - 9 = 8 horizontal line 3
        {
            blockEight = 'O';
            playerTurn = true;
        }

        if((blockEight == 'X' && blockNine == 'X') && playerTurn == false && blockSeven == ' ') //8 - 9 = 7 horizontal line 3
        {
            blockSeven = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 1 || playerChoice == 4 || playerChoice == 7) && playerTurn == false)
    {
        if((blockOne == 'X' && blockFour == 'X') && playerTurn == false && blockSeven == ' ') //1 - 4 = 7 vertical row 1
        {
            blockSeven = 'O';
            playerTurn = true;
        }

        if((blockOne == 'X' && blockSeven == 'X') && playerTurn == false && blockFour == ' ') //1 - 7 = 4 vertical row 1
        {
            blockFour = 'O';
            playerTurn = true;
        }

        if((blockFour == 'X' && blockSeven == 'X') && playerTurn == false && blockOne == ' ') //4 - 7 = 1 vertical row 1
        {
            blockOne = 'O';
            playerTurn = true;
        }

    }

    if((playerChoice == 2 || playerChoice == 5 || playerChoice == 8) && playerTurn == false)
    {
        if((blockTwo == 'X' && blockFive == 'X') && playerTurn == false && blockEight == ' ') //2 - 5 = 8 vertical row 2
        {
            blockEight = 'O';
            playerTurn = true;
        }

        if((blockTwo == 'X' && blockEight == 'X') && playerTurn == false && blockFive == ' ') //2 - 8 = 5 vertical row 2
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockEight == 'X') && playerTurn == false && blockTwo == ' ') //5 - 8 = 2 vertical row 2
        {
            blockTwo = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 3 || playerChoice == 6 || playerChoice == 9) && playerTurn == false)
    {
        if((blockThree == 'X' && blockSix == 'X') && playerTurn == false && blockNine == ' ') //3 - 6 = 9 vertical row 3
        {
            blockNine = 'O';
            playerTurn = true;
        }

        if((blockThree == 'X' && blockNine == 'X') && playerTurn == false && blockSix == ' ') //3 - 9 = 6 vertical row 3
        {
            blockSix = 'O';
            playerTurn = true;
        }

        if((blockSix == 'X' && blockNine == 'X') && playerTurn == false && blockThree == ' ') //6 - 9 = 3 vertical row 3
        {
            blockThree = 'O';
            playerTurn = true;
        }
    }
    computerTrick1();
    computerTrick2();
    if(playerTurn == false)
    {
        do
        {

            if(blockOne == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockOne = 'O';
            }
            if(blockTwo == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockTwo = 'O';
            }
            if(blockThree == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockThree = 'O';
            }
            if(blockFour == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockFour = 'O';
            }
            if(blockFive == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockFive = 'O';
            }
            if(blockSix == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockSix = 'O';
            }
            if(blockSeven == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockSeven = 'O';
            }
            if(blockEight == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockEight = 'O';
            }
            if(blockNine == ' ' && playerTurn == false)
            {
                playerTurn = true;
                blockNine = 'O';
            }
        }
        while(playerTurn == false);
    }
    return 0;
}

int checkPlayerInput()
{
    if(playerChoice == 1 && blockOne == ' ')
        blockOne = 'X';
    if(playerChoice == 2 && blockTwo == ' ')
        blockTwo = 'X';
    if(playerChoice == 3 && blockThree == ' ')
        blockThree = 'X';
    if(playerChoice == 4 && blockFour == ' ')
        blockFour = 'X';
    if(playerChoice == 5 && blockFive == ' ')
        blockFive = 'X';
    if(playerChoice == 6 && blockSix == ' ')
        blockSix = 'X';
    if(playerChoice == 7 && blockSeven == ' ')
        blockSeven = 'X';
    if(playerChoice == 8 && blockEight == ' ')
        blockEight = 'X';
    if(playerChoice == 9 && blockNine == ' ')
        blockNine = 'X';
    return 0;
}

int checkComputerInput()
{
    if(playerTurn==false && turnCounter==1 && turnFirst==2)
    {
        int random = rand() % 4 + 1;
        if(random==1)
        {
            computerPick=1;
            blockOne = 'O';
            //playerTurn=true;
        }
        else if(random==2)
        {
            computerPick=3;
            blockThree = 'O';
            //playerTurn=true;
        }
        else if(random==3)
        {
            computerPick=7;
            blockSeven = 'O';
            //playerTurn=true;
        }
        else if(random==4)
        {
            computerPick=9;
            blockNine = 'O';
            //playerTurn=true;
        }
        playerTurn=true;
    }
    return 0;
}

void gameBoard()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //cout << "\t\t\t     +-----+-----+-----+" << endl;
    cout << "\n\n\n\t\t\t\t    -__- \n \n \t\t\t        " ;
    if(blockOne=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockOne=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockOne;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  |  ";
    if(blockTwo=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockTwo=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockTwo;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  |  ";
    if(blockThree=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockThree=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockThree;
    SetConsoleTextAttribute(hConsole, 15);
    cout<< "  " << endl;
    cout << "\t\t\t     +-----+-----+-----+" << endl;
    cout << "\t\t\t        ";
    if(blockFour=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockFour=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockFour;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  |  ";
    if(blockFive=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockFive=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockFive;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  |  ";
    if(blockSix=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockSix=='X')
            SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockSix;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "   " << endl;
    cout << "\t\t\t     +-----+-----+-----+" << endl;
    cout << "\t\t\t        ";
    if(blockSeven=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockSeven=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout <<blockSeven;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  |  ";
    if(blockEight=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockEight=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockEight;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  |  ";
    if(blockNine=='O')
        SetConsoleTextAttribute(hConsole, colourCodeO);
    if(blockNine=='X')
        SetConsoleTextAttribute(hConsole, colourCodeX);
    cout << blockNine;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "   \n";
    //cout << "\t\t\t     +-----+-----+-----+" << endl;
}

int main()
{
    //RNGs
    srand(time(0));
    int playAgain;

    int playerScore = 0;
    int computerScore = 0;
    int ties = 0;

    //do
    //{
        system("CLS");
        turnFirst = rand()% (2 - 1 + 1)+1;//generates starting person.
        //computerRandomPick = rand()% (9 - 1 + 1)+1;//computer first pick - random
        gameWin = 3;
        blockOne = ' ';
        blockTwo = ' ';
        blockThree = ' ';
        blockFour = ' ';
        blockFive = ' ';
        blockSix = ' ';
        blockSeven = ' ';
        blockEight = ' ';
        blockNine = ' ';

        //BEGIN OF PROGRAM
        cout << "\t\t\t     Welcome to Tic Tac Toe!";
        //cout << "\t\t\t  Player: " << playerScore << " Computer: "<< computerScore << " Ties: " << ties << endl;
                if(turnFirst == 1)//Player first
        {
            gameBoard();//Gameboard for tic tac toe
            cout << "\n\n\t\t\t Please choose a grid to place (X): "<<endl<<endl;
            cout << "\t\t\t\t\t";
            while (!(cin >> playerChoice)) //error traps letters and words
            {
                cout << endl;
                cout << "\t\t\t     Numbers only." << endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }
            checkPlayerInput();
            system("CLS");
            gameBoard();
            playerTurn = false; //switches to computer
            Beep(beepFrequency,beepDuration);
        }
        if(turnFirst == 2)//Computer first
        {
            //computerRandomPick;
            //computerPick = computerRandomPick;
            Beep(beepFrequency,beepDuration);
            checkComputerInput();
            playerTurn = true;
            gameBoard();
        }
        do
        {
            turnCounter++;
            if(playerTurn == true) //player loop
            {
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                cout << "\n\n\t\t\t Please choose a grid to place (";
                SetConsoleTextAttribute(hConsole, colourCodeX);
                cout << "X";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "): "<<endl<<endl;
                cout << "\t\t\t\t\t";
                while (!(cin >> playerChoice)) //error traps letters and words
                {
                    cout << endl;
                    cout << "\t\t\t     Numbers only." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                checkPlayerInput();
                checkWinPlayer();
                system("CLS");
                gameBoard();
                Beep(beepFrequency,beepDuration);
                Sleep(1150);
                if(gameWin==1)
                    break;
                checkTie();
                playerTurn = false;
            }
            else if(playerTurn == false) //computer loop
            {
                computerAI();
                system("CLS");
                gameBoard();
                checkWinComputer();
                if(gameWin==2)
                    break;
                checkTie();
                playerTurn = true;
            }
        }
        while(gameWin > 2);
        if(gameWin == 0)
        {
            system("CLS");
            gameBoard();
            cout << "\n\t\t\t     The game is a Tie!" << endl;
            ++ties;
            Beep(beepFrequency,beepDuration);
        }
        if(gameWin == 1)
        {
            system("CLS");
            gameBoard();
            cout << "\n\t\t\t     The player wins!" << endl;
            ++playerScore;
            Beep(beepFrequency,beepDuration);
        }
        if(gameWin == 2)
        {
            system("CLS");
            gameBoard();
            cout << "\n\t\t\t     The computer wins!" << endl;
            ++computerScore;
            Beep(beepFrequency,beepDuration);
        }
        //cout << "\n\t\t     Player: " << playerScore << " "<< "Computer: " << computerScore << " Ties: "<< ties << endl;
        //cout << "\n\t\t\t       Play again?\n\t\t\t         1. Yes\n\t\t\t         2. No\n" << endl;
        //cout << "\t\t\t\t\t";
        //while (!(cin >> playAgain)) //error traps letters and words
        //{
            //cout << endl;
            //cout << "\n\t\t\t       Play again?\n\t\t\t         1. Yes\n\t\t\t         2. No\n" << endl;
            //cout << "\t\t\t\t\t\t\t";
            //cout << "\t\t\t\t";
          //  cin.clear();
            //cin.ignore(10000,'\n');
        //}
        turnCounter=1;
        cnt=0;
        firstPlayerChoice=0;
        playerChoice;
        playerTurn;
        gameWin = 3;
    //}
    //while(playAgain == 1);
    return 0;
}
