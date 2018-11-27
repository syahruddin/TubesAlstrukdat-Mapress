/* NIM/Nama  : Sutawijaya Adiputra 		*/
/* Nama file : array.c					*/
/* Tanggal   : 11 September 2018		*/
/* Deskripsi : file body ADT array		*/

//kamus file
#include "array.h"

/* Kamus Umum */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	T->Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
return T.Neff;}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
return IdxMax - T.Neff;}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
return IdxMin;}

IdxType GetLastIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
return T.Neff;}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i){
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
return T.TI[i];}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */


void SetTab (TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
	int i; //variabel looping
	//copy Neff
	Tout->Neff = Tin.Neff;
	
	for(i=IdxMin; i<=Tin.Neff; i++){
		Tout->TI[i] = Tin.TI[i];
	}
/* Assignment THsl -> Tin */
//THsl itu Tout? welp...
}

void SetEl (TabInt *T, IdxType i, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
	T->TI[i] = v;}

void SetNeff (TabInt *T, IdxType N){
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */	

//asalkan Nilai N sesuai dengan IdxMin<=N<=IdxMax
	T->Neff = N;}	

/* ********** Test Indeks yang valid ********** */


boolean IsIdxValid (TabInt T, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
	if((IdxMin <= i) && (i <= IdxMax)) return true;
	else return false;
}

boolean IsIdxEff (TabInt T, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

	if((GetFirstIdx(T) <= i) && (GetLastIdx(T) >= i)) return true;
	else return false;
}

/* ********** TEST KOSONG/PENUH ********** */


/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	if(NbElmt(T) == 0) return true;
	else return false; 
}

boolean IsFull (TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	if(NbElmt(T) == IdxMax) return true;
	else return false; 
}


