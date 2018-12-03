#include "stacklist.h"
#include <stdio.h>
#include <stdlib.h>


/***************/
/*  Prototype  */
/***************/

//Konstruktor/Kreator 
void CreateEmptyStack (Stack *S){
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong 
// Ciri stack kosong : TOP bernilai Nil 
    TopStack(*S) = NilStack;
}

// Prototype manajemen memori
void AlokasiStack (address *P, infotypeStack X){
// I.S. P Sembarang, X terdefinisi 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil 
// P = Nil jika alokasi gagal 
    (*P) = (address) malloc (sizeof (ElmtStack));
    if((*P) != NilStack){
        InfoStack(*P) = X;
        NextStack(*P) = NilStack;
    }else
        (*P) = NilStack;
}
void DealokasiStack (address *P){
// I.S. P adalah hasil alokasi, P != Nil 
// F.S. Alamat P didealokasi, dikembalikan ke sistem 
    free(*P);
}

// Predikat Untuk test keadaan KOLEKSI
boolean IsEmptyStack (Stack S){
// Mengirim true jika Stack kosong
    return TopStack(S) == NilStack;
}

// Operator Dasar Stack
void PushStack (Stack *S, infotypeStack X){
// Menambahkan X sebagai elemen Stack S. 
// I.S. S mungkin kosong
// F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. 
// Jika alokasi gagal, S tetap. 
    address P;
    AlokasiStack(&P,X);
    if(P != NilStack){
        NextStack(P) = TopStack(*S);
        TopStack(*S) = P;
    }
}
void PopStack (Stack *S, infotypeStack *X){
// Menghapus X dari Stack S. 
// I.S. S tidak kosong 
// F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, 
// TOP(S) = Next(TOP(S)). 
    address P;
    P = TopStack(*S);
    *X = InfoStack(P);
    TopStack(*S) = NextStack(P);
    DealokasiStack(&P);
}