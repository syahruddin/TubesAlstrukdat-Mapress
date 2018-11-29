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
#include <stdio.h>

char CC;

/* Tipe Bentukan baru */
typedef struct Customer{
    
	int type;
	int time;
	int jumlah;
}Customer;
typedef struct{ //tiap info di permainan (antrian, uang, makanan, dll )masukin sini aja biar gampang pindahinnya
	int nyawa;
	int isKitchen;
	int money;
    int time;
}infopermainan;

void startmain(char name[]);
// yang dijalanin

void BacaFileMap(MATRIKS *peta,char* namafile);
//masukin dari file peta ke matrix

void getInput(MATRIKS *peta1, MATRIKS *peta2, infopermainan *infogame, char name[], point *player);
// buat dapet input selama main

void drawGame(MATRIKS peta1, MATRIKS peta2, infopermainan infogame,char name[]);
// gambar semua interface pertick

/* Movement - Mengubah posisi Player */
	/* Matriks disusun dari kecil - besar ke bawah
	 * Perubahan posisi ke atas -> Y-1
	 * Perubahan posisi ke bawah -> Y+1
	 * Tidak ada perubahan kanan kiri, kanan > kiri
	 * 
	 */
void GetPosP(MATRIKS rTamu, point player);
//mengisi posisi player pada map	  
void GU(point player);
//go up
void GD(point player);
//go down
void GR(point player);
//go right
void GL(point player);
//go Left
void PLACE(point player, Customer c, List antre);
//menempatkan pelanggan ke meja duduk sesuai jumlah


/* Give-and-Take */
void CT(Stack hand);
//membuang isinya (to be simple, createEmpty)
void ORDER(Customer c);
//mengambil pesanan pelanggan, 
void TAKE(Stack hand, Customer c);
//mengambil makanan, sesuai posisi produk
void GIVE(Stack hand, Customer c);
//memberikan pesanan, harus sesuai pelanggan


/* Gameplay */
void EXIT();








#endif