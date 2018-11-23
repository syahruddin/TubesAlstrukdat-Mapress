#include "point.h"
#include <stdio.h>


//Membuat titik
point MakePoint(int x, int y){
    point temp;
    X(temp) = x;
    Y(temp) = y;
    return temp;
}
//menulis titik ke layar
void PrintPoint(point P){
    printf("(%d,%d)",X(P),Y(P));
}
