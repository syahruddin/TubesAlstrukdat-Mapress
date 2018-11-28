
#ifndef GAME_H
#define GAME_H


#include "boolean.h"
#include "jam.h"
#include "listlinier.h"
#include "matriks.h"
#include "mesin_kar.h"
#include "mesin_kata.h"
#include "point.h"
#include "stacklist.h"
#include "queue.h"
#include <stdio.h>



void startGame();
// menjalankan permainan
void getMapFile();
// dijalankan saat permainan dimulai, mengambil file map dan menyimpannya di matrix
void drawgame();
// menggambar map dan fitur2 di permainan
void menu();
// menampilkan menu utama dan menavigasi untuk mengakses menu-menu yang tersedia

void updateMap();
//mengupdate peta dengan info terbaru(perpindahan player, pelanggan mendapatkan meja, dll)
void getCommand();
//membaca dan menjalankan perintah selama permainan berlangsung

/* Tipe Bentukan baru */
typedef struct Customer{
	int type;
	int time;
	int jumlah;
}Customer;

/* Variabel Global */
extern Stack hand;			//hand player, 					ADT Stack
extern MATRIKS rTamu;		//map pelanggan, 				ADT Matriks
extern MATRIKS dapur;		//map tempat pesanan diambbil, 	ADT Matriks
extern List antre;			//antrean pelanggan, 			ADT Queue
extern TabInt pesanan;		//jenis pesanan, 				ADT Array
extern point player;		//posisi pemain					ADT Point


/* Inisialisasi */
	//komentar pribadi -suta, inisialisasi di driver

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


/* Note
 * 
 *  1. File body bukan driver sehingga dibentuk terpisah
 *  2. Apabila ada ketidaksetujuan hubungi Sutawijaya, pls
 *  3. Inisialisasi dipanggil di driver, i think.. -Suta
 *  4. variabel dibuat extern karena ga yakin ditempatin di mana
 * 		(mungkin body) -Suta
 * 	5. Infotype bentrokan, ada yang char, ada yang Int. pls di fix
 * 	6. Belum ada type pelanggan dan pesanannya yang bener(masih prototype)
 * 	
 */ 