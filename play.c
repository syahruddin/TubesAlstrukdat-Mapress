#include "play.h"
#include <stdio.h>
#include <string.h>


void startmain(char name[]){
// yang dijalanin
    infopermainan infogame;
    Queue antrian;
    infogame.stateEnd = 0;
    Queue nunggumakan;
    CreateEmptyQueue(&antrian,6);
    
    infogame.money = 0;
    infogame.tangan = 0;
    infogame.nyawa = 2;
    infogame.time = 0;
    infogame.isDoor = 0;
    infogame.meja.penduduk[1] = 0;
    infogame.meja.penduduk[2] = 0;
    infogame.meja.penduduk[3] = 0;
    infogame.meja.penduduk[4] = 0;
    infogame.meja.makanan[1] = 0;
    infogame.meja.makanan[2] = 0;
    infogame.meja.makanan[3] = 0;
    infogame.meja.makanan[4] = 0;
    infogame.isKitchen = 0; //boolean yg nentuin apakah player lagi di kitchen atau engga(r tamu)
    point player = MakePoint(5,3);
    AddQueue(&antrian,createCustomer());
    
    MATRIKS petaTamu, petaDapur;
    BacaFileMap(&petaTamu,"ruangtamu.txt");
    BacaFileMap(&petaDapur,"kitchen.txt");
    
    petaTamu.Mem[X(player)][Y(player)] = 'P';
    
    
    while(!infogame.stateEnd){
        drawGame(petaTamu,petaDapur,infogame,name,&antrian);
        getInput(&petaTamu,&petaDapur,&infogame,name,&player,&antrian);
    }
    GameOver();
    Credit();
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

void getInput(MATRIKS *peta1, MATRIKS *peta2, infopermainan *infogame, char name[], point *player , Queue *antrian){
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
            if(      (!IsEmptyQueue(*antrian))    &&       (((X(*player) <= 3)  &&     (!(((Y(*player) == 4)||(Y(*player) == 5))&&(!(X(*player) == 2))  ) )    )      ||          ((X(*player) >= 6)&&((Y(*player) > 5 )||(Y(*player) < 4))   &&   (!((Y(*player) == 5) && (!((Y(*player) == 2)||(Y(*player) == 7))) )   ))      )         ){
                
                
                if(((*infogame).meja.penduduk[quadran(*player)]) != 0){
                    (*infogame).meja.makanan[quadran(*player)] = 2; //nanti randomin
                }
            }
        
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
            if(      (!IsEmptyQueue(*antrian))    &&       (((X(*player) <= 3)  &&     (!(((Y(*player) == 4)||(Y(*player) == 5))&&(!(X(*player) == 2))  ) )    )      ||          ((X(*player) >= 6)&&((Y(*player) > 5 )||(Y(*player) < 4))   &&   (!((Y(*player) == 5) && (!((Y(*player) == 2)||(Y(*player) == 7))) )   ))      )         ){
                
                
                if(((*infogame).meja.penduduk[quadran(*player)]) == 0){
                    if((quadran(*player) == 2) || (quadran(*player) == 3) || (InfoHeadQueue(*antrian).jumlah == 2)){
                        Customer getter;
                        
                        DelQueue(antrian,&getter);
                        (*infogame).meja.penduduk[quadran(*player)] = getter.jumlah;
                        
                        (*infogame).meja.kesabaran[quadran(*player)] = 15; 
                        
                        switch (quadran(*player)){
                            case 1:
                                if(getter.jumlah == 2){
                                    (*peta1).Mem[8][2] = 'C';
                                    (*peta1).Mem[6][2] = 'C';
                                }
                                
                            break;
                            
                            case 2:
                            if(getter.jumlah == 2){
                                    (*peta1).Mem[2][1] = 'C';
                                    (*peta1).Mem[1][2] = 'C';
                                }else{
                                    (*peta1).Mem[2][1] = 'C';
                                    (*peta1).Mem[1][2] = 'C';
                                    (*peta1).Mem[2][3] = 'C';
                                    (*peta1).Mem[3][2] = 'C';
                                }
                            
                            break;
                            
                            case 3:
                            if(getter.jumlah == 2){
                                    (*peta1).Mem[2][6] = 'C';
                                    (*peta1).Mem[2][8] = 'C';
                                }else{
                                    (*peta1).Mem[2][6] = 'C';
                                    (*peta1).Mem[2][8] = 'C';
                                    (*peta1).Mem[3][7] = 'C';
                                    (*peta1).Mem[1][7] = 'C';
                                }
                            
                            break;
                            
                            case 4:
                            if(getter.jumlah == 2){
                                    (*peta1).Mem[6][7] = 'C';
                                    (*peta1).Mem[8][7] = 'C';
                                }
                            
                            break;
                            
                            
                        }
                    }
                }
                
            }
        }else
        
        
        if(!strcmp(input,"GIVE")){
            if(      (!IsEmptyQueue(*antrian))    &&       (((X(*player) <= 3)  &&     (!(((Y(*player) == 4)||(Y(*player) == 5))&&(!(X(*player) == 2))  ) )    )      ||          ((X(*player) >= 6)&&((Y(*player) > 5 )||(Y(*player) < 4))   &&   (!((Y(*player) == 5) && (!((Y(*player) == 2)||(Y(*player) == 7))) )   ))      )         ){
                
                
                if(((*infogame).meja.penduduk[quadran(*player)]) != 0){
                    if(((*infogame).makanan[(*infogame).tangan]) == (*infogame).meja.makanan[quadran(*player)]){
                        (*infogame).tangan -= 1;
                        (*infogame).money += 50;
                        (*infogame).meja.makanan[quadran(*player)] = 0;
                        (*infogame).meja.penduduk[quadran(*player)] = 0;
                    }
                }
            }
            
        }else
        
        
        if(!strcmp(input,"SAVE")){
        
        }else
        
        
        if(!strcmp(input,"LOAD")){
        
        }else
        
        
        if(!strcmp(input,"EXIT")){
            (*infogame).stateEnd = 1;
        }
    
    ((*infogame).isDoor) = door;    
    ((*infogame).time) += 1;   
   
}

void drawGame(MATRIKS peta1, MATRIKS peta2, infopermainan infogame, char name[], Queue *antrian){
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
            printf("Order");
            if (infogame.meja.makanan[1] != 0){
                printf("%s",makanan(infogame.meja.makanan[1]));
            }else{printf("     ");
            }
        
        }else if((j == 6)&&(infogame.meja.makanan[2] != 0)){
            printf("%s,        ",makanan(infogame.meja.makanan[2]));
        }else if((j == 7)&&(infogame.meja.makanan[3] != 0)){
            printf("%s,        ",makanan(infogame.meja.makanan[3]));
        }else if((j == 8)&&(infogame.meja.makanan[4] != 0)){
            printf("%s,        ",makanan(infogame.meja.makanan[4]));
            
            
            
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
int quadran(point a){
    int temp;
    if(X(a) >= 4){
        if(Y(a) > 4){
            temp = 4;
        }else{
            temp = 1;
        }
    }else if(Y(a) > 4){
            temp = 3;
        }else{
            temp = 2;
        }

    return temp;
}
void GameOver(){
	printf("          _____                    _____                    _____                    _____                           \n");                       
	printf("         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                       \n");                          
	printf("        /::\\    \\                /::\\    \\                /::\\____\\                /::\\    \\                           \n");                     
	printf("       /::::\\    \\              /::::\\    \\              /::::|   |               /::::\\    \\                                 \n");              
	printf("      /::::::\\    \\            /::::::\\    \\            /:::::|   |              /::::::\\    \\                                     \n");         
	printf("     /:::/\\:::\\    \\          /:::/\\:::\\    \\          /::::::|   |             /:::/\\:::\\    \\                                      \n");       
	printf("    /:::/  \\:::\\    \\        /:::/__\\:::\\    \\        /:::/|::|   |            /:::/__\\:::\\    \\                                          \n");  
	printf("   /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\      /:::/ |::|   |           /::::\\   \\:::\\    \\                                           \n");
	printf("  /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\    /:::/  |::|___|______    /::::::\\   \\:::\\    \\                                          \n");
	printf(" /:::/    /   \\:::\\ ___\\  /:::/\\:::\\   \\:::\\    \\  /:::/   |::::::::\\    \\  /:::/\\:::\\   \\:::\\    \\                                         \n");
	printf("/:::/____/  ___\\:::|    |/:::/  \\:::\\   \\:::\\____\\/:::/    |:::::::::\\____\\/:::/__\\:::\\   \\:::\\____\\                                        \n");
	printf("\\:::\\    \\ /\\  /:::|____|\\::/    \\:::\\  /:::/    /\\::/    / ~~~~~/:::/    /\\:::\\   \\:::\\   \\::/    /                                        \n");
	printf(" \\:::\\    /::\\ \\::/    /  \\/____/ \\:::\\/:::/    /  \\/____/      /:::/    /  \\:::\\   \\:::\\   \\/____/                                         \n");
	printf("  \\:::\\   \\:::\\ \\/____/            \\::::::/    /               /:::/    /    \\:::\\   \\:::\\    \\                                             \n");
	printf("   \\:::\\   \\:::\\____\\               \\::::/    /               /:::/    /      \\:::\\   \\:::\\____\\                                            \n");
	printf("    \\:::\\  /:::/    /               /:::/    /               /:::/    /        \\:::\\   \\::/    /                                            \n");
	printf("     \\:::\\/:::/    /               /:::/    /               /:::/    /          \\:::\\   \\/____/                                             \n");
	printf("      \\::::::/    /               /:::/    /               /:::/    /            \\:::\\    \\                                                 \n");
	printf("       \\::::/    /               /:::/    /               /:::/    /              \\:::\\____\\                                                \n");
	printf("        \\::/____/                \\::/    /                \\::/    /                \\::/    /                                                \n");
	printf("                                  \\/____/                  \\/____/                  \\/____/                                                 \n");
	printf("                                                                                                                                            \n");
	printf("                                                 _______                   _____                    _____                    _____          \n");
	printf("                                                /::\\    \\                 /\\    \\                  /\\    \\                  /\\    \\      \n");   
	printf("                                               /::::\\    \\               /::\\____\\                /::\\    \\                /::\\    \\        \n");
	printf("                                              /::::::\\    \\             /:::/    /               /::::\\    \\              /::::\\    \\       \n");
	printf("                                             /::::::::\\    \\           /:::/    /               /::::::\\    \\            /::::::\\    \\      \n");
	printf("                                            /:::/~~\\:::\\    \\         /:::/    /               /:::/\\:::\\    \\          /:::/\\:::\\    \\     \n");
	printf("                                           /:::/    \\:::\\    \\       /:::/____/               /:::/__\\:::\\    \\        /:::/__\\:::\\    \\    \n");
	printf("                                          /:::/    / \\:::\\    \\      |::|    |               /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\   \n");
	printf("                                         /:::/____/   \\:::\\____\\     |::|    |     _____    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\  \n");
	printf("                                        |:::|    |     |:::|    |    |::|    |    /\\    \\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\____\\ \n");
	printf("                                        |:::|____|     |:::|    |    |::|    |   /::\\____\\/:::/__\\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::|    |\n");
	printf("                                         \\:::\\    \\   /:::/    /     |::|    |  /:::/    /\\:::\\   \\:::\\   \\::/    /\\::/   |::::\\  /:::|____|\n");
	printf("                                          \\:::\\    \\ /:::/    /      |::|    | /:::/    /  \\:::\\   \\:::\\   \\/____/  \\/____|:::::\\/:::/    / \n");
	printf("                                           \\:::\\    /:::/    /       |::|____|/:::/    /    \\:::\\   \\:::\\    \\            |:::::::::/    /  \n");
	printf("                                            \\:::\\__/:::/    /        |:::::::::::/    /      \\:::\\   \\:::\\____\\           |::|\\::::/    /   \n");
	printf("                                             \\::::::::/    /         \\::::::::::/____/        \\:::\\   \\::/    /           |::| \\::/____/    \n");
	printf("                                              \\::::::/    /           ~~~~~~~~~~               \\:::\\   \\/____/            |::|  ~|          \n");
	printf("                                               \\::::/    /                                      \\:::\\    \\                |::|   |          \n");
	printf("                                                \\::/____/                                        \\:::\\____\\               \\::|   |          \n");
	printf("                                                 ~~                                               \\::/    /                \\:|   |          \n");
	printf("                                                                                                   \\/____/                  \\|___|               \n");                                                                                                                                                                              
    char c;
    printf("---Press enter to continue---\n");
	scanf("%c",&c);
}

