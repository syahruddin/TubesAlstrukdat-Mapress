#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool IsEmptyList (List L){
/* Mengirim true jika list kosong */
  return (FirstList(L) == NilList);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
  FirstList(*L) = NilList;
}

/****************** Manajemen Memori ******************/
addressList AlokasiList (infotypeList X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
  //Kamus Lokal
  addressList P;
  
  //Algoritma
  P = (addressList) malloc (sizeof (ElmtList));
  if (P!=NilList){
    InfoList(P) = X;
    NextList(P) = NilList;
    return P;
  }
  else {
    return NilList;
  }
}
void DealokasiList (addressList *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList SearchList (List L, infotypeList X){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
  //Kamus Lokal
  addressList P;
  bool Found;
  
  //Algoritma
  P = FirstList(L);
  Found = false;
  while ((P!=NilList) && (!Found)){
    if (X==InfoList(P)){
      Found = true;
    }
    else{
      P = NextList(P);
    }
  }
  return P;
}
bool FSearchList (List L, addressList P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
  //Kamus Lokal
  addressList Pt;
  bool Found;
  
  //Algoritma
  Pt = FirstList(L);
  Found = false;
  while ((Pt!=NilList) && (!Found)){
    if (Pt==P){
      Found = true;
    }
    else {
      Pt = NextList(Pt);
    }
  }
  return Found;
}
addressList SearchPrecList (List L, infotypeList X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
  //Kamus Lokal
  addressList P;
  bool Found;
  
  //Algoritma
  P = FirstList(L);
  Found = false;
  if (P == NilList) {
      return NilList;
    } 
    else {
      while ((NextList(P) != NilList) && (!Found)) {
        if (X == InfoList(NextList(P))) {
          Found = true;
        } 
        else {
          P = NextList(P);
       }
      }
    }
    if (NextList(P) == NilList) {
      return NilList;
    } else {
      return P;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, infotypeList X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
  //Kamus Lokal
  addressList P;
  
  //Algoritma
  P = AlokasiList(X);
  if (P!=NilList){
    InsertFirstList(L,P);
  }
}
void InsVLastList (List *L, infotypeList X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  //Kamus Lokal
  addressList P;
  
  //Algoritma
  P = AlokasiList(X);
  if (P!=NilList){
    InsertLastList(L,P);
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (List *L, infotypeList *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
  //Kamus Lokal
  addressList P;
  
  //Algoritma
  P = FirstList(*L);
  *X = InfoList(P);
  FirstList(*L) = NextList(FirstList(*L));
  //Next(P) = Nil;
  DealokasiList(&P);
}
void DelVLastList (List *L, infotypeList *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
  //Kamus Lokal
  addressList P;
  
  //Algoritma
  DelLastList(L,&P);
  *X = InfoList(P);
  DealokasiList(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, addressList P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
  NextList(P) = FirstList(*L);
  FirstList(*L) = P;
}
void InsertAfterList (List *L, addressList P, addressList Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
  NextList(P) = NextList(Prec);
  NextList(Prec) = P;
}
void InsertLastList (List *L, addressList P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
  //Kamus lokal
  addressList Last;
  
  //Algoritma
  Last = FirstList(*L);
  if (FirstList(*L) == NilList){
    InsertFirstList(L,P);
  }
  else{
    while (NextList(Last)!= NilList){
      Last = NextList(Last);
    }
    InsertAfterList(L,P,Last);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, addressList *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
  *P = FirstList(*L);
  FirstList(*L) = NextList(FirstList(*L));
}
void DelPListList (List *L, infotypeList X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

  
  //Kamus Lokal
  addressList P, Prec;
  
  //Algoritma
  P = FirstList(*L);
  Prec = NilList;
  if (InfoList(P) == X){
    DelVFirstList(L,&X);
  }
  else{
    while (P!=NilList){
      if (InfoList(P) == X){
        DelAfterList(L,&P,Prec);
        DealokasiList(&P);
      }
      else {
        Prec = P;
        P = NextList(P);
      }
    }
  }
}
void DelLastList (List *L, addressList *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
  //Kamus Lokal
  addressList Last, PrecLast;
  
  //Algoritma
  Last = FirstList(*L);
  PrecLast = NilList;
  while (NextList(Last) != NilList){
    PrecLast = Last;
    Last = NextList(Last);
  }
  *P = Last;
  if (PrecLast == NilList){
    FirstList(*L) = NilList;
  }
  else {
    NextList(PrecLast) = NilList;
  }
}
void DelAfterList (List *L, addressList *Pdel, addressList Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = NextList(Prec);
    NextList(Prec) = NextList(NextList(Prec));
    //Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoList (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
  //Kamus Lokal
  addressList P;
  
  //Algoritma
  P = FirstList(L);
  if (!IsEmptyList(L)){
      printf("[");
    while (NextList(P)!=NilList){
      printf("%d,",InfoList(P));
      P=NextList(P);
    }
    printf("%d]\n", InfoList(P));
  }
  else{
    printf("[]");
  }
}
int NbElmtList (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
  //Kamus lokal
  addressList P;
  int count;
  
  //Algoritma
  count = 0;
  P = FirstList(L);
  while (P!=NilList){
    count++;
    P = NextList(P);
  }
  return count;
}
