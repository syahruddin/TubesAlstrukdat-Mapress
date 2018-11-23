//jam.h 


#ifndef JAM_H
#define JAM_H

typedef struct{ 
	int Hour;
	int Minute;
    int Second;
} jam;

#define Hour(J) (J).Hour
#define Minute(J) (J).Minute
#define Second(J) (J).Second

//membuat jam
jam CreateJam(int j,int m,int d);

//menulis jam ke layar
void PrintJam(jam J);


#endif