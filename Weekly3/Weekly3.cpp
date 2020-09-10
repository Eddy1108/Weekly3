//Weekly 3 assignment by Edvard Helgetun.

#include <iostream>
#include <stdlib.h>
#include <time.h>

int randomNumber{ 0 };
int difChoice{ 1 };
int difficulty{ 5 };

int guess{ 0 };

int highscore{ 10 };
int attempts{ 0 };

bool i = true;

void setDifficulty()
{
    while (i == true)
    {
        std::cout << "Please choose a difficuly: \n[1] Easy \n[2] Medium \n[3] Hard \n";
        std::cin >> difChoice;


        switch (difChoice)
        {
        case 1:
            difficulty = 5;
            i = false;
            break;
        case 2:
            difficulty = 10;
            i = false;
            break;
        case 3:
            difficulty = 30;
            i = false;
            break;
        default:
            std::cout << "That is not a valid option!\n";
            system("pause");
            system("cls");
            break;
        }
    }

}

void generateNumber() 
{
    std::srand(static_cast<unsigned int>(time(nullptr)));       //changes rand() functions seed based on the system clock, if not i get the same "random" numbers each time

    for (int i = 0; i < 5; i++) {
        randomNumber = rand() % difficulty + 1;
    }
}

void play() 
{
    system("cls");
    std::cout << "Guess what the random number is: (1-" << difficulty << ").\n\n";
    std::cin >> guess;

    while (true)
    {
        attempts++;
        if (guess == randomNumber)
        {
            break;
        }
        else if (guess > randomNumber) {
            std::cout << "Guess Lower!\n";
        }
        else if (guess < randomNumber) {
            std::cout << "Guess Higher!\n";
        }

        std::cin >> guess;
    }

    std::cout << "\nYou guessed correctly in " << attempts << " tries!";
    if (attempts < highscore) {
        std::cout << "\nYou beat the highscore!" << "\n The Highscore was " << highscore;
        highscore = attempts;
    }
    else {
        std::cout << "\nThe Highscore is: " << highscore;
    }
}

int main()
{
    while (true) {
        setDifficulty();
        generateNumber();
        play();

        std::cout << "\n\nRestarting the game . . .\n";
        attempts = 0;
        i = true;

        system("pause");
        system("cls");
    }
}
