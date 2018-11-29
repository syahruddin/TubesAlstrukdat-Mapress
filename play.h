//adt untuk hal2 yang dilakukan selama permainan

#ifndef PLAY_H
#define PLAY_H
#include "matriks.h"
#include "mesin_kar.h"
#include "point.h"
#include "listlinier.h"
#include "boolean.h"
#include "jam.h"
#include "mesin_kata.h"
#include "point.h"
#include "stacklist.h"
#include "queue.h"
#include <stdio.h>

char CC;

typedef struct{
    int makanan[5];
    int penduduk[5];
    int kesabaran[5];
}Meja;

typedef struct{ //tiap info di permainan (antrian, uang, makanan, dll )masukin sini aja biar gampang pindahinnya
	int nyawa;
	int isKitchen;
	int money;
    int stateEnd;
    int time;
    int isDoor;
    int makanan[5];
    Meja meja;
    int tangan;
}infopermainan;

void startmain(char name[]);
// yang dijalanin

void BacaFileMap(MATRIKS *peta,char* namafile);
//masukin dari file peta ke matrix

void getInput(MATRIKS *peta1, MATRIKS *peta2, infopermainan *infogame, char name[], point *player, Queue *antrian);
// buat dapet input selama main

void drawGame(MATRIKS peta1, MATRIKS peta2, infopermainan infogame,char name[], Queue *antrian);
// gambar semua interface pertick

Customer createCustomer();
char* makanan(int x);
int quadran(point a);
void GameOver();
#endif