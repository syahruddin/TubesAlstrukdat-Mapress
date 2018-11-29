#include "play.h"
#include <stdio.h>
#include <string.h>


void startmain(char name[]){
// yang dijalanin
    infopermainan infogame;
    infogame.money = 0;
    infogame.nyawa = 2;
    infogame.time = 0;
    infogame.isKitchen = 0; //boolean yg nentuin apakah player lagi di kitchen atau engga(r tamu)
    point player = MakePoint(5,3);
    
    
    MATRIKS petaTamu, petaDapur;
    BacaFileMap(&petaTamu,"ruangtamu.txt");
    BacaFileMap(&petaDapur,"kitchen.txt");
    
    petaTamu.Mem[X(player)][Y(player)] = 'P';
    
    
    while(1){
        drawGame(petaTamu,petaDapur,infogame,name);
        getInput(&petaTamu,&petaDapur,&infogame,name,&player);
    }
}
void BacaFileMap(MATRIKS *peta,char* namafile){
//masukin dari file peta ke matrix
    START(namafile);
    int i = 1;
    int j = 1;
    while(CC != MARK){
        (*peta).Mem[i][j] = CC;
        ADV();
        i++;
        if(i > 8){
            i = 1;
            j++;
        }
    }
    (*peta).NBrsEff = 8;
    (*peta).NKolEff = 8;
}

void getInput(MATRIKS *peta1, MATRIKS *peta2, infopermainan *infogame, char name[], point *player ){
    // buat dapet input selama main
    char input[10];
    printf("Command: ");
    scanf("%s",input);
        if(!strcmp(input,"GU")){
            if((*infogame).isKitchen == 0){
                (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                Y(*player) -=1;
                (*peta1).Mem[X(*player)][Y(*player)] = 'P';
            }else{
                (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                Y(*player) -=1;
                (*peta2).Mem[X(*player)][Y(*player)] = 'P';
            }
        }else
        
        
        if(!strcmp(input,"GD")){
            if((*infogame).isKitchen == 0){
                (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                Y(*player) +=1;
                (*peta1).Mem[X(*player)][Y(*player)] = 'P';
            }else{
                (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                Y(*player) +=1;
                (*peta2).Mem[X(*player)][Y(*player)] = 'P';
            }
        }else
        
        
        if(!strcmp(input,"GL")){
            if((*infogame).isKitchen == 0){
                (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                X(*player) -=1;
                (*peta1).Mem[X(*player)][Y(*player)] = 'P';
            }else{
                (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                X(*player) -=1;
                (*peta2).Mem[X(*player)][Y(*player)] = 'P';
            }
        }else
        
        
        if(!strcmp(input,"GR")){
            if((*infogame).isKitchen == 0){
                (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                X(*player) +=1;
                (*peta1).Mem[X(*player)][Y(*player)] = 'P';
            }else{
                (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                X(*player) +=1;
                (*peta2).Mem[X(*player)][Y(*player)] = 'P';
            }
        }else
        
        
        if(!strcmp(input,"ORDER")){
        
        }else
        
        
        if(!strcmp(input,"TAKE")){
        
        }else
        
        
        if(!strcmp(input,"CT")){
        
        }else
        
        
        if(!strcmp(input,"PLACE")){
        
        }else
        
        
        if(!strcmp(input,"GIVE")){
        
        }else
        
        
        if(!strcmp(input,"SAVE")){
        
        }else
        
        
        if(!strcmp(input,"LOAD")){
        
        }else
        
        
        if(!strcmp(input,"EXIT")){
        
        }
    
        
}

void drawGame(MATRIKS peta1, MATRIKS peta2, infopermainan infogame, char name[]){
    // gambar semua interface pertick
    
    
    int i = 1;
    int j = 1;
    
    printf("%s   Money: %d   Life: %d   Time: %d \n",name,infogame.money,infogame.nyawa,infogame.time);
    printf("Waiting Cust  ");
    for(j = 1; j <=8; j++){
        if(j == 2){
            printf("0             ");
        }else if(j == 5){
            printf("Order         ");
        }else if(j == 6){
            printf("burger,2      ");
        }else if(j != 1){
            printf("              ");
        }
        for(i = 1; i<=8;i++){
            if(infogame.isKitchen){
                printf("%c  ",peta2.Mem[i][j]);
            }else{
                printf("%c  ",peta1.Mem[i][j]);
            }
        }
        if(j == 1){
            printf("Food Stack \n");
        }else if(j == 2){
            printf(" balda,2 \n");
        }else{
            printf("\n");
        }
    }
    printf("\n");
}

/* Movement - Mengubah posisi Player */
	/* Matriks disusun dari kecil - besar ke bawah
	 * Perubahan posisi ke atas -> Y-1
	 * Perubahan posisi ke bawah -> Y+1
	 * Tidak ada perubahan kanan kiri, kanan > kiri
	 * 
	 */
void GetPosP(MATRIKS rTamu, point player){
//mengisi posisi player pada map
}	  
void GU(point player){
//go up
}
void GD(point player){
//go down
}
void GR(point player){
//go right
}
void GL(point player){
//go Left
}
void PLACE(point player, Customer c, List antre){
//menempatkan pelanggan ke meja duduk sesuai jumlah
}

/* Give-and-Take */
void CT(Stack hand){
//membuang isinya (to be simple, createEmpty)
}
void ORDER(Customer c){
//mengambil pesanan pelanggan, 
}
void TAKE(Stack hand, Customer c){
//mengambil makanan, sesuai posisi produk
}
void GIVE(Stack hand, Customer c){
//memberikan pesanan, harus sesuai pelanggan
}


/* Gameplay */
void EXIT(){
}