#include "queue.h"
#include <stdlib.h>

/* *** Predikat Pemeriksaan Kondisi Queue *** */
boolean IsEmptyQueue(Queue Q){
/* Mengirim true jika Q kosong */
    return((HeadQueue(Q) == NilQueue)&&(TailQueue(Q) == NilQueue));
}
boolean IsFullQueue(Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
MaxEl elemen */
    return(NBElmtQueue(Q) == Q.MaxEl);
}
int NBElmtQueue(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    int temp;
    if(IsEmptyQueue(Q)){
        temp = 0;
    }else if(TailQueue(Q) < HeadQueue(Q)){
        temp = TailQueue(Q) + (Q.MaxEl - HeadQueue(Q)+1);
    }else{
        temp = HeadQueue(Q) - TailQueue(Q) + 1;
    }
    return temp;
}

/* *** Konstruktor *** */
void CreateEmptyQueue(Queue *Q,int Max){
/* I.S. Max terdefinisi }
   F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
   Jika alokasi berhasil, tabel memori dialokasi berukuran Max
   atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
   Proses : Melakukan alokasi memori dan membuat sebuah Q kosong */
   (*Q).T = (infotypeQueue *) malloc ((Max) * sizeof(infotypeQueue));
   (*Q).MaxEl = Max;
   HeadQueue(*Q) = Nil;
   TailQueue(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasiQueue(Queue *Q){
/* Proses : Mengembalikan memori Q
   I.S. Q pernah dialokasi
   F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
   free((*Q).T);
}
/* *** Operator-Operator Dasar Queue *** */
void AddQueue(Queue *Q,infotypeQueue X){
/* Proses : Menambahkan X pada Q dengan aturan FIFO
   I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
   F.S. X menjadi TAIL yang baru, TAIL "maju" */
   if(IsEmptyQueue(*Q)){
       HeadQueue(*Q) = 1;
       TailQueue(*Q) = 1;
       InfoHeadQueue(*Q) = X;
   }else if(TailQueue(*Q) = (*Q).MaxEl){
       TailQueue(*Q) = 1;
       InfoTailQueue(*Q) = X;
   }else {
       TailQueue(*Q)++;
       InfoTailQueue(*Q) = X;
   }
       
}
void DelQueue(Queue *Q,infotypeQueue *X){
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
   I.S. Q tidak kosong
   F.S. X = nilai elemen HEAD pada I.S.,
        Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
        HEAD yang lama digeser ke "kiri", TAIL = TAIL � 1;
        Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
    if(NBElmtQueue(*Q) == 1){
        *X = InfoHeadQueue(*Q);
        HeadQueue(*Q) = NilQueue;
        TailQueue(*Q) = NilQueue;
    }else{
        *X = InfoHeadQueue(*Q);
        if(HeadQueue(*Q) < TailQueue(*Q)){
            int i = HeadQueue(*Q);
            while(i < TailQueue(*Q)){
                (*Q).T[i] = (*Q).T[i+1];
                i++;
            }
            Tail(*Q)--;
        }else{
            int j = HeadQueue(*Q);
            while(j < (*Q).MaxEl){
                (*Q).T[j] = (*Q).T[j+1];
                j++;
            }
            j = 1;
            (*Q).T[(*Q).MaxEl] = (*Q).T[j];
            while(j < TailQueue(*Q)){
                (*Q).T[j] = (*Q).T[j+1];
                j++;
            }
            if(TailQueue(*Q) ==1){
                TailQueue(*Q) = (*Q).MaxEl;
            }else{
                TailQueue(*Q)--;
            }
        }
    }
}