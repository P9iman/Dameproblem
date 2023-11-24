#include "Header/checkers.h"

void handleBedrohung(BOARD* schachbrett);

bool werdenDamenBedroht(int zeile, int spalte, BOARD* schachbrett)
{
    bool werdenBedroht = false;
    char** board = schachbrett->board;
    typedef struct{
        int x;
        int y;
    }Position;
    /**
     * Fälle die abgeprüft werden müssen:
     * -Diagonale der Dame
     * -Horizontale der Dame
     * -Vertikale der Dame
     * Auf diesen Bahnen dürfen keine anderen Damen stehen sonst werden sie bedroht.
     *
     * Position einer Damefigur: P(X;Y)
     */
    if(zeile == 0 && spalte == 0){
        return false;
    }else{
        //checke vertikale
        for(int i = 0; i < zeile; i++){
            if(i != zeile && board[i][spalte] != '_'){
                werdenBedroht = true;
                return werdenBedroht;
            }
        }
        int zeile_cp = zeile;
        int spalte_cp = spalte;
        //Prüfe die Diagonale in Richtung links nach oben ab
        while(zeile_cp > 0 || spalte_cp > 0){
            if(board[--zeile_cp][--spalte_cp] != '_'){
                werdenBedroht = true;
                return werdenBedroht;
            }
            zeile_cp--;
            spalte_cp--;
        }
        zeile_cp = zeile;
        spalte_cp = spalte;
        //Prüfe die Diagonale in Richtung rechts nach unten ab
        while(zeile_cp != zeile-1 || spalte_cp != spalte-1){
            if(board[++zeile_cp][++spalte_cp] != '_'){
                werdenBedroht = true;
                return werdenBedroht;
            }
            zeile_cp++;
            spalte_cp++;
        }
        zeile_cp = zeile;
        spalte_cp = spalte;
        //Prüfe die Diagonale in Richtung rechts nach oben ab
        while(zeile_cp != 0 || spalte_cp != spalte-1){
            if(board[--zeile_cp][++spalte_cp] != '_'){
                werdenBedroht = true;
                return werdenBedroht;
            }
            zeile_cp--;
            spalte_cp++;
        }
        zeile_cp = zeile;
        spalte_cp = spalte;
        //Prüfe die Diagonale in Richtung links nach unten ab
        while(zeile_cp != zeile-1  || spalte_cp != 0){
            if(board[++zeile_cp][--spalte_cp] != '_'){
                werdenBedroht = true;
                return werdenBedroht;
            }
        }
    }
     return werdenBedroht;
} 


int loeseNDamenProblem(BOARD* schachbrett)
{
    int anzahlDerLoesungen = 0;
    int zeile = 0;
    int spalte = 0;
    int platzierteFiguren = 0;
    //TODO Die gesammte while Schleife muss anscheinend noch in eine weitere Schleife, da es mehrere Lösungen geben kann je nach Größe des Schachfeldes

    //Auf dem Schachfeld kann pro Zeile (oder Spalte wie man es sehen mag), eine Dame platziert werden. Damit geht der Algorithmus nur solange
    //bis platzierteFiguren gleich der Schachbrettgröße wird.
    while(platzierteFiguren < schachbrett->groesse){

        setzteFigurAufsFeld(schachbrett, zeile, spalte);
        if(!werdenDamenBedroht(zeile, spalte, schachbrett)){
            zeile++;    //Inkrementiere Zeile, da die nächste Dame nicht in der selben Zeile platziert werden kann
            //TODO Nicht ganz sicher mit dem spalte++
            spalte++;   //Inkrementiere auch die Spalte, da die nächste Dame sonst direkt unterhalb der letzen Dame ist
            platzierteFiguren++;
        }else{
            //Wenn hier angekommen, dann wurde eine oder mehrere Damen bedroht. Handle die Situation mit Backtracking.
            handleBedrohung(schachbrett);
        }
    }
    anzahlDerLoesungen++;

    return anzahlDerLoesungen;
}

void handleBedrohung(BOARD* schachbrett)
{

}

