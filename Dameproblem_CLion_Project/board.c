#include <stdio.h>
#include <stdlib.h>

#include "Header/board.h"

BOARD* erstelleSchachbrett(int groesse)
{
    //Initialisiere P_BOARD. Zeigt auf ein Block für den Typ BOARD
    BOARD* P_BOARD = (BOARD*) malloc(sizeof(BOARD));
    int zeilen = groesse;
    int spalten = groesse;
    char** schachbrett = NULL;
    /**
     * Dynamische Speicherreservierung:
     * malloc reserviert Zeilen * Pointer Größe also auf diesem Rechner 8Byte
     * Wenn es 3 Zeilen geben soll, dann werden 3*8=24 Byte benötigt.
     * Das heißt man bekommt nach dem malloc einen Pointer der nur auf die Zeilen zeigt.
     * Hinter den Zeilen kommen nun noch die Spalten.
     *
     * Wir reservieren Speicher für N (Anzahl an Zeilen) Pointer auf Integer
     * @image Aufgabe/PointAufPointer.png
     */
    schachbrett = malloc(zeilen * sizeof(char*));
    //Jetzt gehen wir durch jede Zeile und reservieren genügen Speicher
    // für die einzelnen Spalten.
    for(int i = 0; i < zeilen; i++){
        /**
         * Malloc gibt uns einen Pointer auf den Anfang eines Speicherblock
         * für Chars. Diesen Pointer speichern wir ganze vorne in jeder Zeile ab.         *
         */
        schachbrett[i] = (char*)malloc(spalten * sizeof(char));
    }

    //Initialisiere das Schachbrett
    for(int i = 0; i < zeilen; i++){
        for(int j = 0; j < spalten; j++){
            schachbrett[i][j] = '_';
        }
    }
    P_BOARD->board = schachbrett;
    P_BOARD->groesse = groesse;
    return P_BOARD;
}

BOARD* erstelleSchachbrettDefaultGroesse()
{
    return erstelleSchachbrett(DEFAULT_BOARDSIZE);
}

 void loescheSchachbrett(BOARD* schachbrett)
 {
    int zeilen = schachbrett->groesse;
    char** _schachbrett = schachbrett->board;
    //Free als erstes die Pointer auf die Int Array Blöcke
    for(int i = 0; i < zeilen; i++){
        free(_schachbrett[i]);
    }
    //Free als nächstes den Pointer auf Pointer
    free(_schachbrett);
    printf("Schachbrette wurde erfolgreich gelöscht.\n");
 }


 void gebeSchachbrettAus(BOARD* schachbrettP)
 {
    char** schachbrett = schachbrettP->board;
    if(schachbrett == NULL){
        fprintf(stderr, "Schachbrett war NULL. Ausgabe nicht möglich");
        exit(EXIT_FAILURE);
    }
    int groesse = schachbrettP->groesse;
     for(int i = 0; i<groesse; i++){
         for(int j = 0; j < groesse; j++){
             printf("|%c", schachbrett[i][j]);
            if(j == groesse-1){
                printf("|");
            }
         }
         printf("\n");
     }
    printf("\n");
 }

 void setzteFigurAufsFeld(BOARD* schachbrettP, int zeile, int spalte)
 {
    int groesse = schachbrettP->groesse;
    char** board = schachbrettP->board;
    if(zeile > groesse-1 || spalte > groesse-1){
        fprintf(stderr, "Zeile oder Spalte falsch gewählt!\n");
        fprintf(stderr, "Zeilen und Spalten gehen von 0 bis %d\n",groesse-1);
        return;
    }
    board[zeile][spalte] = 'D';
 }


 bool istFeldBelegt(BOARD* schachbrettP, int zeile, int spalte)
 {
    return schachbrettP->board[zeile][spalte] == 'D';
 }
