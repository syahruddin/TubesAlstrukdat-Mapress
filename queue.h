/* Modul ADT Queue � Alternatif I */
/* *** Deklarasi Queue yang diimplementasi dengan tabel kontigu *** */
/* *** HEAD dan TAIL adalah alamat elemen pertama dan terakhir *** */
/* *** Queue mampu menampung MaxEl buah elemen *** */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "boolean.h"
#include <stdlib.h>

/* *** konstanta *** */
#define Nil 0

/* *** Definisi elemen dan address *** */
typedef int infotype;
typedef int address; /* indeks tabel */

/* *** Definisi Type Queue *** */
typedef struct {
    infotype *T; /* tabel penyimpan elemen */
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
    int MaxEl; /* maksimum banyaknya elemen queue */
} Queue;

/* Definisi Queue kosong: Head = Nil; TAIL = Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* Definisi akses dengan Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/* *** Predikat Pemeriksaan Kondisi Queue *** */
boolean IsEmpty(Queue Q);
/* Mengirim true jika Q kosong */
boolean IsFull(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
MaxEl elemen */
int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Konstruktor *** */
void CreateEmpty(Queue *Q,int Max);
/* I.S. Max terdefinisi }
   F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
   Jika alokasi berhasil, tabel memori dialokasi berukuran Max
   atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
   Proses : Melakukan alokasi memori dan membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue *Q);
/* Proses : Mengembalikan memori Q
   I.S. Q pernah dialokasi
   F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Operator-Operator Dasar Queue *** */
void Add(Queue *Q,infotype X);
/* Proses : Menambahkan X pada Q dengan aturan FIFO
   I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
   F.S. X menjadi TAIL yang baru, TAIL "maju" */
void Del(Queue *Q,infotype *X);
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
   I.S. Q tidak kosong
   F.S. X = nilai elemen HEAD pada I.S.,
        Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
        HEAD yang lama digeser ke "kiri", TAIL = TAIL � 1;
        Jika Queue menjadi kosong, HEAD = TAIL = Nil. */

#endif // __QUEUE_H__