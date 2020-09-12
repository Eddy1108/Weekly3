//Weekly 3 assignment by Edvard Helgetun.

#include <iostream>
#include <stdlib.h>
#include <time.h>

int randomNumber{ 0 };
int difficulty{ 5 };        //The highest number for each difficulty is stored here. (defaults to easy)
int guess{ 0 };
int highscore{ 0 };         //Where the highscore for each round is stored
int highscore1{ 3 };       //Highscore for Easy
int highscore2{ 5 };       //Highscore for Medium
int highscore3{ 8 };       //Highscore for Hard
int attempts{ 0 };

bool i = true;      //Used to keep the while loop to continue while choosing a difficulty, set to false when a valid selection is made.

void setDifficulty()
{
    int difChoice{ 1 };

    while (i == true)
    {
        std::cout << "Please choose a difficuly: \n[1] Easy \n[2] Medium \n[3] Hard \n";
        std::cin >> difChoice;

        switch (difChoice)
        {
        case 1:
            difficulty = 5;
            highscore = highscore1;
            i = false;
            break;
        case 2:
            difficulty = 10;
            highscore = highscore2;
            i = false;
            break;
        case 3:
            difficulty = 30;
            highscore = highscore3;
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

    while (true)    //This is where the game happens.
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

    //Post-game 
    std::cout << "\nYou guessed correctly in " << attempts << " tries!";
    if (attempts < highscore) {
        std::cout << "\nYou beat the highscore!" << "\nThe Highscore was " << highscore;
        switch (difficulty) {
        case 5:
            highscore1 = attempts;      //Storeing the new highscore for each difficulty respectively.
            break;
        case 10:
            highscore2 = attempts;
            break;
        case 30:
            highscore3 = attempts;
            break;
        }
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
        highscore = 0;
        i = true;
        system("pause");
        system("cls");
    }
}
//Is 120 lines of code perhaps a bit much for a simple number guessing game??