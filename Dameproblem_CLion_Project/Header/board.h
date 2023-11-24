#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

//Die Default groesse des Schachbretts ist 8x8
#define DEFAULT_BOARDSIZE 8

//Schachfeld
typedef struct BOARD{
    int groesse;    // Dimensionen des Schachfeld, bsp 3x3
    char **board;   //ein 2 Dimensionales VLA = Variable Length Array
                    //die Größe von dem 2D Array wird während der Laufzeit bestimmt
}BOARD;

extern BOARD* P_BOARD;

/**
 * @brief Diese Funktion erstellt ein Schachbrett auf dem Heap. Es kann optional die Größe des Schachbretts bzw die Anzahl der Damen
 * mit übergeben werden.  
 * 
 * @param groesse Die Groesse des Schachbretts bzw die Anzahl der Damen die platziert werden. 
 *                Der Default-Wert ist 8
*/
BOARD* erstelleSchachbrett(int groesse);


BOARD* erstelleSchachbrettDefaultGroesse();

/**
 * @brief Diese Funktion löscht das Schachbrett vom Heap. 
 * 
 * @param schachbrett Das zulöschende Schachbrett
*/
void loescheSchachbrett(BOARD* schachbrett);

/**
 * @brief Diese Funktion gibt das Schachbrett auf der Konsole als ASCII-Grafik aus. 
 * 
 * @param schachbrett Das Schachbrett welches aktuelle auf dem Heap liegt. 
*/
void gebeSchachbrettAus(BOARD* schachbrett);

/**
 * @brief Diese Funktion setzt Damefiguren auf das Schachbrett. 
 * 
 * @param schachbrettP Das Schachbrett worauf die Damefigur gesetzt werden soll.
 * @param zeile Die Zeile in der die Damefigur platziert wird.
 * @param spalte Die Spalte in der die Damefigur platziert wird.
*/
void setzteFigurAufsFeld(BOARD* schachbrettP, int zeile, int spalte);

/**
 * @brief Diese Funktion überprüft ob ein Feld auf dem Schachbrett schon belegt ist. 
*/
bool istFeldBelegt(BOARD* schachbrett, int zeile, int spalte); 


#endif