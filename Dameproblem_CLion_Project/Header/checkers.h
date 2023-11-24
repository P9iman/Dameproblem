#ifndef CHECKERS_H
#define CHECKERS_H

#include "board.h"

/**
 * Diese Funktion überprüft, ob die Positionierung einer Dame auf einem bestimmten Feld
 * zur Bedrohung schon platzierter Damen führt.
 *
 * @param zeile
 * @param spalte
 * @param schachbrett
 * @return true für das Platzieren führt zur Bedrohung und false für Platzieren führt nicht zur Bedrohung.
 */
bool werdenDamenBedroht(int zeile, int spalte, BOARD* schachbrett);

/**
 * Diese Funktion berechnet mithilfe von Backtracking alle Lösungen des n-Damen Problems
 * und liefert die Anzahl der Lösungen zurück.
 *
 * Optional können die Lösungen als ASCII Grafiken auf stdout ausgegeben werden.
 * @param schachbrett
 * @return Anzahl der Lösungen
 */
int loeseNDamenProblem(BOARD* schachbrett); 


#endif