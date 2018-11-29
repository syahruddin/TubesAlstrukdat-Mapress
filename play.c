#include "play.h"
#include <stdio.h>


void startmain(char name[]){
// yang dijalanin
    MATRIKS petaTamu, petaDapur;
    BacaFileMap(&petaTamu,"ruangtamu.txt");
    BacaFileMap(&petaDapur,"kitchen.txt");
    TulisMATRIKS(petaTamu);
    printf("\n");
    TulisMATRIKS(petaDapur);
    for(;;){
    }
}
void BacaFileMap(MATRIKS *peta,char *namafile){
//masukin dari file peta ke matrix
    START(namafile);
    int i = 1;
    while(CC != MARK){
        (*peta).Mem[i][(i % 8)] = CC;
        ADV();
        i++;
    }
    (*peta).NBrsEff = 8;
    (*peta).NKolEff = 8;
}

void getInput(){
// buat dapet input selama main
}

void drawGame(){
// gambar semua interface pertick
}

/* Movement - Mengubah posisi Player */
	/* Matriks disusun dari kecil - besar ke bawah
	 * Perubahan posisi ke atas -> Y-1
	 * Perubahan posisi ke bawah -> Y+1
	 * Tidak ada perubahan kanan kiri, kanan > kiri
	 * 
	 */
void GetPosP(MATRIKS rTamu, point player){
//mengisi posisi player pada map
}	  
void GU(point player){
//go up
}
void GD(point player){
//go down
}
void GR(point player){
//go right
}
void GL(point player){
//go Left
}
void PLACE(point player, Customer c, List antre){
//menempatkan pelanggan ke meja duduk sesuai jumlah
}


/* Give-and-Take */
void CT(Stack hand){
//membuang isinya (to be simple, createEmpty)
}
void ORDER(Customer c){
//mengambil pesanan pelanggan, 
}
void TAKE(Stack hand, Customer c){
//mengambil makanan, sesuai posisi produk
}
void GIVE(Stack hand, Customer c){
//memberikan pesanan, harus sesuai pelanggan
}


/* Gameplay */
void EXIT(){
}