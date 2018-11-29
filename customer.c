
#include "queue.h"
#include "array.h"
#include <stdlib.h>

/* Catatan khusus 
	ini bisa langsung kopas ke play.h, whatever... aku buat ini biar
	* drivernya bisa dicoba satu-satu */

/* Tipe Bentukan Customer */
typedef struct Customer{
	int type;
	int time;
	int jumlah;
}Customer;

/* Konstanta */
const int w8que = 30;

/* variabel */
time_t t;


/* generate */
void genCustomer(Customer c){
	c.type = (rand()%8) + 1; //random 1-8
	c.time = (rand()%11) +20; //random 20 - 30
	c.jumlah = ((rand() %2) +1) *2; //random 2 atau 4	
}

