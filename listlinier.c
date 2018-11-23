#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool IsEmpty (List L){
/* Mengirim true jika list kosong */
  return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
  //Kamus Lokal
  address P;
  
  //Algoritma
  P = (address) malloc (sizeof (ElmtList));
  if (P!=Nil){
    Info(P) = X;
    Next(P) = Nil;
    return P;
  }
  else {
    return Nil;
  }
}
void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
  //Kamus Lokal
  address P;
  bool Found;
  
  //Algoritma
  P = First(L);
  Found = false;
  while ((P!=Nil) && (!Found)){
    if (X==Info(P)){
      Found = true;
    }
    else{
      P = Next(P);
    }
  }
  return P;
}
bool FSearch (List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
  //Kamus Lokal
  address Pt;
  bool Found;
  
  //Algoritma
  Pt = First(L);
  Found = false;
  while ((Pt!=Nil) && (!Found)){
    if (Pt==P){
      Found = true;
    }
    else {
      Pt = Next(Pt);
    }
  }
  return Found;
}
address SearchPrec (List L, infotype X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
  //Kamus Lokal
  address P;
  bool Found;
  
  //Algoritma
  P = First(L);
  Found = false;
  if (P == Nil) {
      return Nil;
    } 
    else {
      while ((Next(P) != Nil) && (!Found)) {
        if (X == Info(Next(P))) {
          Found = true;
        } 
        else {
          P = Next(P);
       }
      }
    }
    if (Next(P) == Nil) {
      return Nil;
    } else {
      return P;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
  //Kamus Lokal
  address P;
  
  //Algoritma
  P = Alokasi(X);
  if (P!=Nil){
    InsertFirst(L,P);
  }
}
void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  //Kamus Lokal
  address P;
  
  //Algoritma
  P = Alokasi(X);
  if (P!=Nil){
    InsertLast(L,P);
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
  //Kamus Lokal
  address P;
  
  //Algoritma
  P = First(*L);
  *X = Info(P);
  First(*L) = Next(First(*L));
  //Next(P) = Nil;
  Dealokasi(&P);
}
void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
  //Kamus Lokal
  address P;
  
  //Algoritma
  DelLast(L,&P);
  *X = Info(P);
  Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
  Next(P) = First(*L);
  First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
  Next(P) = Next(Prec);
  Next(Prec) = P;
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
  //Kamus lokal
  address Last;
  
  //Algoritma
  Last = First(*L);
  if (First(*L) == Nil){
    InsertFirst(L,P);
  }
  else{
    while (Next(Last)!= Nil){
      Last = Next(Last);
    }
    InsertAfter(L,P,Last);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
  *P = First(*L);
  First(*L) = Next(First(*L));
}
void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
/*  address Prec;
  address Temp;
  
  if (X == Info(First(*L)))
  {
    DeleteFirst(&(*L),&Prec);
  }
  else
  {
    Prec = First(*L);
    while(Info(Next(Prec)) != X);
    {
      Prec = Next(Prec);
    }
    DeleteAfter(&(*L),&Temp,Prec);
  }*/
  
  //Kamus Lokal
  address P, Prec;
  
  //Algoritma
  P = First(*L);
  Prec = Nil;
  if (Info(P) == X){
    DelVFirst(L,&X);
  }
  else{
    while (P!=Nil){
      if (Info(P) == X){
        DelAfter(L,&P,Prec);
        Dealokasi(&P);
      }
      else {
        Prec = P;
        P = Next(P);
      }
    }
  }
}
void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
  //Kamus Lokal
  address Last, PrecLast;
  
  //Algoritma
  Last = First(*L);
  PrecLast = Nil;
  while (Next(Last) != Nil){
    PrecLast = Last;
    Last = Next(Last);
  }
  *P = Last;
  if (PrecLast == Nil){
    First(*L) = Nil;
  }
  else {
    Next(PrecLast) = Nil;
  }
}
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    //Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
  //Kamus Lokal
  address P;
  
  //Algoritma
  P = First(L);
  if (!IsEmpty(L)){
      printf("[");
    while (Next(P)!=Nil){
      printf("%d,",Info(P));
      P=Next(P);
    }
    printf("%d]\n", Info(P));
  }
  else{
    printf("[]");
  }
}
int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
  //Kamus lokal
  address P;
  int count;
  
  //Algoritma
  count = 0;
  P = First(L);
  while (P!=Nil){
    count++;
    P = Next(P);
  }
  return count;
}