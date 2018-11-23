#include "jam.h"
#include <stdio.h>

//membuat jam
jam CreateJam(int j,int m,int d){
    jam temp;
    Hour(temp) = j;
    Minute(temp) = m;
    Second(temp) = d;
    return temp;
}

//menulis jam ke layar
void PrintJam(jam J){
    printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}