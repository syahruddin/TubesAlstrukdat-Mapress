#include "stacklist.h"
#include <stdio.h>
#include <stdlib.h>


/***************/
/*  Prototype  */
/***************/

//Konstruktor/Kreator 
void CreateEmpty (Stack *S){
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong 
// Ciri stack kosong : TOP bernilai Nil 
    Top(*S) = Nil;
}

// Prototype manajemen memori
void Alokasi (address *P, infotype X){
// I.S. P Sembarang, X terdefinisi 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil 
// P = Nil jika alokasi gagal 
    (*P) = (address) malloc (sizeof (ElmtStack));
    if((*P) != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }else
        (*P) = Nil;
}
void Dealokasi (address *P){
// I.S. P adalah hasil alokasi, P != Nil 
// F.S. Alamat P didealokasi, dikembalikan ke sistem 
    free(*P);
}

// Predikat Untuk test keadaan KOLEKSI
boolean IsEmpty (Stack S){
// Mengirim true jika Stack kosong
    return Top(S) == Nil;
}

// Operator Dasar Stack
void Push (Stack *S, infotype X){
// Menambahkan X sebagai elemen Stack S. 
// I.S. S mungkin kosong
// F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. 
// Jika alokasi gagal, S tetap. 
    address P;
    Alokasi(&P,X);
    if(P != Nil){
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}
void Pop (Stack *S, infotype *X){
// Menghapus X dari Stack S. 
// I.S. S tidak kosong 
// F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, 
// TOP(S) = Next(TOP(S)). 
    address P;
    P = Top(*S);
    *X = Info(P);
    Top(*S) = Next(P);
    Dealokasi(&P);
}