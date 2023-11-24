#include <stdio.h>
#include <stdlib.h>

/**
 * Als Parameter wird ein Pointer auf die erste Stelle des Arrays
 * übergeben und die Größe des Arrays.
 * Deshalb können wir dann innerhalb der Funktion, den Pointer
 * derefernzieren und an den reservierten Platz für dieses Array
 * Elemente reinschreiben  
*/
void fkt(int a[], int size)
{
    for (int i = 0; i < size; i++){
        a[i] = 5;
    }
    int i = 0; 
    for(i = 0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printMatrix()
{
    int zeilen = 3;
    int spalten = 3;

    char** matrixp = (char**)calloc(zeilen*spalten, zeilen*sizeof(char*));
    for(int i = 0; i < zeilen; i++){
        matrixp[i] = calloc(spalten, spalten* sizeof(char));
    }

    for(int i = 0; i < zeilen; i++){
        for(int j = 0; j < spalten; j++){
            matrixp[i][j] = '_';
        }
    }
    for(int i = 0; i < zeilen; i++){
        for(int j = 0; j < spalten; j++){
            printf("%c ", matrixp[i][j]);
        }
        printf("\n");
    }
    // 5. Speicher freigeben
    for (int i = 0; i < zeilen; ++i) {
        free(matrixp[i]);
    }
    free(matrixp);
}

void pointerSize(){
    /**
     * Die Größe eines Pointer hängt in C nicht von dem Typ ab auf den der Pointer
     * zeigt. Je nach Rechner ist ein Pointer 8 (8*8=64 Bit System) oder
     * 4 Byte (4*8=32 Bit System) groß
     */
    //Größe eines Int Pointers ist auf meinem Rechner 8Byte
    int number = 10;
    printf("%ld\n", sizeof(&number));

    //Größe eines Int Pointers ist auf meinem Rechner 8Byte
    char ch = 'A';
    printf("%ld\n", sizeof(&ch));
}

int main(int argc, char const *argv[])
{
    int size = 10; 
    int a[10]; 
//    fkt(a, size);


    return 0;
}
