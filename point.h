
// point.h 


#ifndef POINT_H
#define POINT_H

typedef struct{ 
	int X;
	int Y;
} point;

#define X(P) ((P).X)
#define Y(P) ((P).Y)

//Membuat titik
point MakePoint(int x, int y);

//menulis titik ke layar
void PrintPoint(point p);



#endif