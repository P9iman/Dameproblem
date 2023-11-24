/**
 * @file main.c 
 * @brief Main Funktion wo das Dameproblem gestartet wird. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "Header/board.h"
#include "Header/checkers.h"

int main()
{
    int schachbrettSize = 10;
    BOARD* boardp =  erstelleSchachbrett(schachbrettSize);
    gebeSchachbrettAus(boardp);
    setzteFigurAufsFeld(boardp, 0, 0);
    gebeSchachbrettAus(boardp);
    setzteFigurAufsFeld(boardp, 1,2);
    gebeSchachbrettAus(boardp);
    printf("%d\n", werdenDamenBedroht(1,2,boardp));

    //printf("%d\n", istFeldBelegt(boardp, 0,0));

    //Lösche ASCII Schachbrett und Board Struct vom Heap
    loescheSchachbrett(boardp);
    free(boardp);
    return 0;
}