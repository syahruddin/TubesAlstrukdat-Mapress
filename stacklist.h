#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* MODUL STACK */
/* Deklarasi stack yang diimplementasi dengan list linier dengan representasi fisik pointer */

#define NilStack NULL

/*  Definisi Type Stack  */
typedef char infotypeStack;
typedef struct tElmtStack * address;
typedef struct tElmtStack {
	infotypeStack Info;
	address Next;
} ElmtStack;
typedef struct {
	address TOP;
} Stack;

/***************************************************** 
TOPStack(S) = Nil adalah stack dengan elemen kosong
Definisi stack dengan representasi berkait :
  Jika S adalah Stack maka akses elemen :
    TOPStack(S) adalah alamat elemen TOP
    InfoStack(P) untuk mengakses elemen info dengan alamat P 
    NextStack(P) untuk mengakses elemen next dengan alamat P 
******************************************************/
#define TopStack(S) (S).TOP
#define NextStack(P) (P)->Next
#define InfoStack(P) (P)->Info

/***************/
/*  Prototype  */
/***************/

//Konstruktor/Kreator 
void CreateEmptyStack (Stack *S);
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong 
// Ciri stack kosong : TOP bernilai Nil 

// Prototype manajemen memori
void AlokasiStack (address *P, infotypeStack X);
// I.S. P Sembarang, X terdefinisi 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil 
// P = Nil jika alokasi gagal 
void DealokasiStack (address *P);
// I.S. P adalah hasil alokasi, P != Nil 
// F.S. Alamat P didealokasi, dikembalikan ke sistem 

// Predikat Untuk test keadaan KOLEKSI
boolean IsEmptyStack (Stack S);
// Mengirim true jika Stack kosong

// Operator Dasar Stack
void PushStack (Stack *S, infotypeStack X);
// Menambahkan X sebagai elemen Stack S. 
// I.S. S mungkin kosong
// F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. 
// Jika alokasi gagal, S tetap. 
void PopStack (Stack *S, infotypeStack *X);
// Menghapus X dari Stack S. 
// I.S. S tidak kosong 
// F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, 
// TOP(S) = Next(TOP(S)). 

#endif