#include "play.h"
#include <stdio.h>
#include <string.h>


void startmain(char name[]){
// yang dijalanin
    infopermainan infogame;
    CreateEmptyQueue(&infogame.antrian,6);
    infogame.money = 0;
    infogame.tangan = 0;
    infogame.nyawa = 2;
    infogame.time = 0;
    infogame.isDoor = 0;
    infogame.isKitchen = 0; //boolean yg nentuin apakah player lagi di kitchen atau engga(r tamu)
    point player = MakePoint(5,3);
    AddQueue(&infogame.antrian,createCustomer());
    
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
    int door = 0;
    printf("Command: ");
    scanf("%s",input);
        if(!strcmp(input,"GU")){
            if((Y(*player) > 1)||((*infogame).isDoor)){
                if((*infogame).isKitchen == 0){
                    if(((*peta1).Mem[X(*player)][(Y(*player))-1] == ' ')||((*peta1).Mem[X(*player)][(Y(*player))-1] == 'D')){
                        if((*peta1).Mem[X(*player)][(Y(*player))-1] == 'D'){
                            door =1;
                        }
                        (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                        if(((*infogame).isDoor)){
                            (*peta1).Mem[X(*player)][Y(*player)] = 'D';
                            
                            
                        }
                        Y(*player) -=1;
                        (*peta1).Mem[X(*player)][Y(*player)] = 'P';
                    }
                }else{
                    if(((*peta2).Mem[X(*player)][(Y(*player))-1] == ' ')||((*peta2).Mem[X(*player)][(Y(*player))-1] == 'D')||((*infogame).isDoor)){
                        if((*peta2).Mem[X(*player)][(Y(*player))-1] == 'D'){
                            door =1;
                        }
                        (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                        if(((*infogame).isDoor)){
                            (*peta2).Mem[X(*player)][Y(*player)] = 'D';
                            (*infogame).isKitchen = 0;
                            door = 1;
                            
                            X(*player) =5;
                            Y(*player) =8;
                            (*peta1).Mem[X(*player)][Y(*player)]  = 'P';
                            
                        }else{
                            Y(*player) -=1;
                            (*peta2).Mem[X(*player)][Y(*player)] = 'P';
                        }
                    }
                }
            }
        }else
        
        
        if(!strcmp(input,"GD")){
            if((Y(*player) < 8)||((*infogame).isDoor)){
                if((*infogame).isKitchen == 0){
                    if(((*peta1).Mem[X(*player)][(Y(*player))+1] == ' ')||((*peta1).Mem[X(*player)][(Y(*player))+1] == 'D')||((*infogame).isDoor)){
                        if((*peta1).Mem[X(*player)][(Y(*player))+1] == 'D'){
                            door =1;
                        }
                        (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                        if(((*infogame).isDoor)){
                            (*peta1).Mem[X(*player)][Y(*player)] = 'D';
                            (*infogame).isKitchen = 1;
                            door = 1;
                            X(*player) =5;
                            Y(*player) =1;
                            (*peta2).Mem[X(*player)][Y(*player)]  = 'P';
                            
                        }else{
                            Y(*player) +=1;
                            (*peta1).Mem[X(*player)][Y(*player)] = 'P';
                        }
                    }
                }else{
                    if(((*peta2).Mem[X(*player)][(Y(*player))+1] == ' ')||((*peta2).Mem[X(*player)][(Y(*player))+1] == 'D')){
                        if((*peta2).Mem[X(*player)][(Y(*player))+1] == 'D'){
                            door =1;
                        }
                        (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                        if(((*infogame).isDoor)){
                            (*peta2).Mem[X(*player)][Y(*player)] = 'D';
                        }
                        Y(*player) +=1;
                        (*peta2).Mem[X(*player)][Y(*player)] = 'P';
                    }
                }
            }
        }else
        
        
        if(!strcmp(input,"GL")){
            if((X(*player) > 1)){
                if((*infogame).isKitchen == 0){
                    if(((*peta1).Mem[(X(*player))-1][(Y(*player))] == ' ')||((*peta1).Mem[(X(*player))-1][(Y(*player))] == 'D')){
                        if((*peta1).Mem[(X(*player))-1][(Y(*player))] == 'D'){
                            door =1;
                        }
                        (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                        if(((*infogame).isDoor)){
                            (*peta1).Mem[X(*player)][Y(*player)] = 'D';
                        }
                        X(*player) -=1;
                        (*peta1).Mem[X(*player)][Y(*player)] = 'P';
                    }
                }else{
                    if(((*peta2).Mem[(X(*player))-1][(Y(*player))] == ' ')||((*peta2).Mem[(X(*player))-1][(Y(*player))] == 'D')){
                        if((*peta2).Mem[(X(*player))-1][(Y(*player))] == 'D'){
                            door =1;
                        }
                        (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                        if(((*infogame).isDoor)){
                            (*peta2).Mem[X(*player)][Y(*player)] = 'D';
                        }
                        X(*player) -=1;
                        (*peta2).Mem[X(*player)][Y(*player)] = 'P';
                    }
                }
            }
        }else
        
        
        if(!strcmp(input,"GR")){
            if((X(*player) < 8)){
                if((*infogame).isKitchen == 0){
                    if(((*peta1).Mem[((X(*player))+1)][(Y(*player))] == ' ')||((*peta1).Mem[((X(*player))+1)][(Y(*player))] == 'D')){
                        if((*peta1).Mem[((X(*player))+1)][(Y(*player))] == 'D'){
                            door =1;
                        }
                            (*peta1).Mem[X(*player)][Y(*player)] = ' ';
                            if(((*infogame).isDoor)){
                                (*peta1).Mem[X(*player)][Y(*player)] = 'D';
                            }
                            X(*player) +=1;
                            (*peta1).Mem[X(*player)][Y(*player)] = 'P';
                    }
                }else{
                    if(((*peta2).Mem[((X(*player))+1)][(Y(*player))] == ' ')||((*peta2).Mem[((X(*player))+1)][(Y(*player))] == 'D')){
                        if((*peta2).Mem[((X(*player))+1)][(Y(*player))] == 'D'){
                            door =1;
                        }
                        (*peta2).Mem[X(*player)][Y(*player)] = ' ';
                        if(((*infogame).isDoor)){
                            (*peta2).Mem[X(*player)][Y(*player)] = 'D';
                        }
                        X(*player) +=1;
                        (*peta2).Mem[X(*player)][Y(*player)] = 'P';
                    }
                }
            }
        }else
        
        
        if(!strcmp(input,"ORDER")){
        
        }else
        
        
        if(!strcmp(input,"TAKE")){
            if(((*infogame).tangan <= 3)&&((*infogame).isKitchen)&&(X(*player) == 2)){
                (*infogame).tangan +=1;
                (*infogame).makanan[(*infogame).tangan] = Y(*player);
            }
        
        }else
        
        
        if(!strcmp(input,"CT")){
            (*infogame).tangan = 0;
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
    
    ((*infogame).isDoor) = door;    
    ((*infogame).time) += 1;   
   
}

void drawGame(MATRIKS peta1, MATRIKS peta2, infopermainan infogame, char name[]){
    // gambar semua interface pertick
    
    
    int i = 1;
    int j = 1;
    int k = 1;
    
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
        }else if((j == 2)&&(infogame.tangan >= 1)){
            printf("%s\n",makanan(infogame.makanan[j-1]));
        }else if((j == 3)&&(infogame.tangan >= 2)){
            printf("%s\n",makanan(infogame.makanan[j-1]));
        }else if((j == 4)&&(infogame.tangan >= 3)){
            printf("%s\n",makanan(infogame.makanan[j-1]));
        }else{
            printf("\n");
        }
    }
    printf("\n");
}
Customer createCustomer(){
    Customer temp;
    temp.sabar = 9;
    temp.antre = 9;
    temp.jumlah= 2;
    return temp;
}
char* makanan(int x){
    char *temp;
    switch(x){
        case 1:
            temp = "Bubur";
        break;
        case 2:
            temp = "Steak";
        break;
        case 3:
            temp = "Toast";
        break;
        case 4:
            temp = "Jelly";
        break;
        case 5:
            temp = "Tempe";
        break;
        case 6:
            temp = "Penyu";
        break;
        case 7:
            temp = "Bebek";
        break;
        case 8:
            temp = "Kadal";
        break;
    }
    return temp;
}

