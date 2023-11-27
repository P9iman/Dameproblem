/**
 * @file main.c 
 * @brief Main Funktion wo das Dameproblem gestartet wird. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "Header/board.h"
#include "Header/checkers.h"

#define START 's'
#define HELP 'h'
#define PRINT_BOARD 'p'
#define PLACE_FIGURE 'f'

void printBegruessung();
void printBedienung();
void readInputFromStdin(void);

int main()
{
    int schachbrettSize = 10;
    int input = 0;
    BOARD* boardp = NULL; 
    printBegruessung();
    printBedienung();

    readInputFromStdin();
     


    // gebeSchachbrettAus(boardp);
    // setzteFigurAufsFeld(boardp, 0, 0);
    // gebeSchachbrettAus(boardp);
    // setzteFigurAufsFeld(boardp, 1,2);
    // gebeSchachbrettAus(boardp);
    // printf("%d\n", werdenDamenBedroht(1,2,boardp));

    // //printf("%d\n", istFeldBelegt(boardp, 0,0));

    // //Lösche ASCII Schachbrett und Board Struct vom Heap
    // loescheSchachbrett(boardp);
    // free(boardp);
    return 0;
}

void printBedienung()
{
    printf("EINGABE:                   FUNKTION:\n\
s = START                  Startet das Dameproblem\n\
q = QUIT                   Beendet das Dameproblem und löscht das Schachbrett vom Heap\n\
h = HELP                   Gibt diese Bedienung aus\n\
p = PRINT_BOARD            Gibt das aktuelle Schachbrett auf stdout aus. Wenn kein Schachbrett existiert gibt es eine Meldung\n\
f = PLACE_FIGURE           Setzt eine Figur an eine gewünschte Stelle auf dem Schachbrett\n\
Andere Eingaben werden ignoriert.\n"); 

}

void printBegruessung()
{
    printf("Willkommen beim Dameproblem, bei dem auf ein NxN großes Schachbrett mithilfe des Backtracking Algorithmus versucht wird\n\
N Damefiguren so zu platzieren, das sie sich nicht gegenseitig gefährden. Die Anzahl der Lösungen wird ausgegeben.\n\n");     

}

void readInputFromStdin(void)
{
    char input = 0; 
    BOARD* boardp = NULL;
    int schachbrettSize = 0;
    printf("Bitte ein Zeichen eingeben > ");
    while((input = getchar()) != 'q')
    {
        switch (input)
        {
            case START:
                if(boardp != NULL){ 
                    printf("Altes Schachbrett wird gelöscht...\n");
                    loescheSchachbrett(boardp);
                }
                printf("Gib die Groesse des Schachbretts/Anzahl der Damefiguren an oder wähle mit 0 den Default-Wert\n");
                scanf("%d", &schachbrettSize); 
                if(schachbrettSize == 0){
                    boardp = erstelleSchachbrett(DEFAULT_BOARDSIZE);
                }else{
                    boardp = erstelleSchachbrett(schachbrettSize); 
                }
                break;
            case HELP:
                printBedienung(); 
                break; 
            case PRINT_BOARD:
                if(boardp != NULL){
                    gebeSchachbrettAus(boardp); 
                }else{
                    printf("Es wurde noch kein Schachbrett erstellt!\n"); 
                }
                break; 
            case PLACE_FIGURE:
                if(boardp != NULL){
                    int zeile = 0; 
                    int spalte = 0; 
                    printf("Gib eine Zeilenummer zwischen 0 und %d ein > ", boardp->groesse); 
                    scanf("%d", &zeile); 
                    printf("\nGib eine Spaltennummer zwischen 0 und %d ein > ", boardp->groesse); 
                    scanf("%d", &spalte); 
                    if(!istFeldBelegt(boardp, zeile, spalte)){
                        setzteFigurAufsFeld(boardp, zeile, spalte);
                    }else{
                        printf("Diese Position ist schon belegt!\n"); 
                        continue;
                    }
                    gebeSchachbrettAus(boardp);
                }else
                {
                    printf("Es wurde noch kein Schachbrett erstellt!\n");
                }
                break; 
            default:
            fflush(stdin); 
                break;
            }
    }
    if(boardp != NULL) loescheSchachbrett(boardp);
}