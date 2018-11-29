#include "queue.h"
#include <stdlib.h>

/* *** Predikat Pemeriksaan Kondisi Queue *** */
boolean IsEmpty(Queue Q){
/* Mengirim true jika Q kosong */
    return((Head(Q) == Nil)&&(Tail(Q) == Nil));
}
boolean IsFull(Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
MaxEl elemen */
    return(NBElmt(Q) == Q.MaxEl);
}
int NBElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    int temp;
    if(IsEmpty(Q)){
        temp = 0;
    }else if(Tail(Q) < Head(Q)){
        temp = Tail(Q) + (Q.MaxEl - Head(Q)+1);
    }else{
        temp = Head(Q) - Tail(Q) + 1;
    }
    return temp;
}

/* *** Konstruktor *** */
void CreateEmpty(Queue *Q,int Max){
/* I.S. Max terdefinisi }
   F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
   Jika alokasi berhasil, tabel memori dialokasi berukuran Max
   atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
   Proses : Melakukan alokasi memori dan membuat sebuah Q kosong */
   (*Q).T = (infotype *) malloc ((Max) * sizeof(infotype));
   (*Q).MaxEl = Max;
   Head(*Q) = Nil;
   Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(Queue *Q){
/* Proses : Mengembalikan memori Q
   I.S. Q pernah dialokasi
   F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
   free((*Q).T);
}
/* *** Operator-Operator Dasar Queue *** */
void Add(Queue *Q,infotype X){
/* Proses : Menambahkan X pada Q dengan aturan FIFO
   I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
   F.S. X menjadi TAIL yang baru, TAIL "maju" */
   if(IsEmpty(*Q)){
       Head(*Q) = 1;
       Tail(*Q) = 1;
       InfoHead(*Q) = X;
   }else if(Tail(*Q) = (*Q).MaxEl){
       Tail(*Q) = 1;
       InfoTail(*Q) = X;
   }else {
       Tail(*Q)++;
       InfoTail(*Q) = X;
   }
       
}
void Del(Queue *Q,infotype *X){
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
   I.S. Q tidak kosong
   F.S. X = nilai elemen HEAD pada I.S.,
        Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
        HEAD yang lama digeser ke "kiri", TAIL = TAIL � 1;
        Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
    if(NBElmt(*Q) == 1){
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }else{
        *X = InfoHead(*Q);
        if(Head(*Q) < Tail(*Q)){
            int i = Head(*Q);
            while(i < Tail(*Q)){
                (*Q).T[i] = (*Q).T[i+1];
                i++;
            }
            Tail(*Q)--;
        }else{
            int j = Head(*Q);
            while(j < (*Q).MaxEl){
                (*Q).T[j] = (*Q).T[j+1];
                j++;
            }
            j = 1;
            (*Q).T[(*Q).MaxEl] = (*Q).T[j];
            while(j < Tail(*Q)){
                (*Q).T[j] = (*Q).T[j+1];
                j++;
            }
            if(Tail(*Q) ==1){
                Tail(*Q) = (*Q).MaxEl;
            }else{
                Tail(*Q)--;
            }
        }
    }
}