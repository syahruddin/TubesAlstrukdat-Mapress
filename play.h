//adt untuk hal2 yang dilakukan selama permainan

#ifndef PLAY_H
#define PLAY_H

void startgame(char name[], char map[]);
// yang dijalanin

void getInput();
// buat dapet input selama main

void drawGame();
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