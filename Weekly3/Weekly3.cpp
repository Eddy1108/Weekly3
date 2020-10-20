//Weekly 3 assignment by Edvard Helgetun.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "VariableHeader.h"

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