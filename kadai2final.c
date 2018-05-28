#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char str[5];
    int NA;
    int *NEN;
    int x = 0;
    int NENwa = 0;
    long NENseki = 1;
    char *EPC;
    char *NucTable;
    int place = 0;
    int y = 0;
    int j;
    int k;
    int i;
    int z;
    int a;
    int NPI = 0;
    int NTN; //NucTableの横の塩基数(トータルの塩基配列のパターン数＊３)
    int NOR;
    int NL = 1;

    printf("アミノ酸配列は？\n");
    scanf("%s",&str);
    NA = strlen(str);

    NEN = (int*)malloc(sizeof(int)*NA);

    for(x=0;x<NA;x++){
        if(str[x]=='A'){
            NEN[x]=4;
        }
        else if(str[x]=='C'){
            NEN[x]=2;
        }
        else if(str[x]=='D'){
            NEN[x]=2;
        }
        else if(str[x]=='E'){
            NEN[x]=2;
        }
        else if(str[x]=='F'){
            NEN[x]=2;
        }
        else if(str[x]=='G'){
            NEN[x]=4;
        }
        else if(str[x]=='H'){
            NEN[x]=2;
        }
        else if(str[x]=='I'){
            NEN[x]=3;
        }
        else if(str[x]=='K'){
            NEN[x]=2;
        }
        else if(str[x]=='L'){
            NEN[x]=6;
        }
        else if(str[x]=='M'){
            NEN[x]=1;
        }
        else if(str[x]=='N'){
            NEN[x]=2;
        }
        else if(str[x]=='P'){
            NEN[x]=4;
        }
        else if(str[x]=='Q'){
            NEN[x]=2;
        }
        else if(str[x]=='R'){
            NEN[x]=6;
        }
        else if(str[x]=='S'){
            NEN[x]=6;
        }
        else if(str[x]=='T'){
            NEN[x]=4;
        }
        else if(str[x]=='V'){
            NEN[x]=4;
        }
        else if(str[x]=='W'){
            NEN[x]=1;
        }
        else if(str[x]=='Y'){
            NEN[x]=2;
        }
        
        NENwa = NENwa + NEN[x];
        NENseki = NENseki * NEN[x];
        
        

    }

    NTN = NENseki * 3;
    NOR = NTN/3;

    EPC = (char*)malloc(sizeof(char)*(NENwa*3+1));
    NucTable = (char*) malloc ( sizeof(char) * (NA * NENseki * 3 +1) );

    for(y=0; y < NA; y++){
        
        if(str[y]=='A'){
            
            EPC[place+0]='G';
            EPC[place+1]='C';
            EPC[place+2]='U';
            EPC[place+3]='G';
            EPC[place+4]='C';
            EPC[place+5]='C';
            EPC[place+6]='G';
            EPC[place+7]='C';
            EPC[place+8]='A';
            EPC[place+9]='G';
            EPC[place+10]='C';
            EPC[place+11]='G';
            
        }

        else if(str[y]=='C'){

            EPC[place+0]='U';
            EPC[place+1]='G';
            EPC[place+2]='U';
            EPC[place+3]='U';
            EPC[place+4]='G';
            EPC[place+5]='C';
            
        }

        else if(str[y]=='D'){

            EPC[place+0]='G';
            EPC[place+1]='A';
            EPC[place+2]='U';
            EPC[place+3]='G';
            EPC[place+4]='A';
            EPC[place+5]='C';
            
        }

        else if(str[y]=='E'){

            EPC[place+0]='G';
            EPC[place+1]='A';
            EPC[place+2]='A';
            EPC[place+3]='G';
            EPC[place+4]='A';
            EPC[place+5]='G';
            
        }

        else if(str[y]=='F'){

            EPC[place+0]='U';
            EPC[place+1]='U';
            EPC[place+2]='U';
            EPC[place+3]='U';
            EPC[place+4]='U';
            EPC[place+5]='C';
            
        }

        else if(str[y]=='G'){

            EPC[place+0]='G';
            EPC[place+1]='G';
            EPC[place+2]='U';
            EPC[place+3]='G';
            EPC[place+4]='G';
            EPC[place+5]='C';
            EPC[place+6]='G';
            EPC[place+7]='G';
            EPC[place+8]='A';
            EPC[place+9]='G';
            EPC[place+10]='G';
            EPC[place+11]='G';
            
        }

        else if(str[y]=='H'){

            EPC[place+0]='C';
            EPC[place+1]='A';
            EPC[place+2]='U';
            EPC[place+3]='C';
            EPC[place+4]='A';
            EPC[place+5]='C';
            
        }

        else if(str[y]=='I'){

            EPC[place+0]='A';
            EPC[place+1]='U';
            EPC[place+2]='U';
            EPC[place+3]='A';
            EPC[place+4]='U';
            EPC[place+5]='C';
            EPC[place+6]='A';
            EPC[place+7]='U';
            EPC[place+8]='A';
            
        }

        else if(str[y]=='K'){

            EPC[place+0]='A';
            EPC[place+1]='A';
            EPC[place+2]='A';
            EPC[place+3]='A';
            EPC[place+4]='A';
            EPC[place+5]='G';
            
        }

        else if(str[y]=='L'){

            EPC[place+0]='C';
            EPC[place+1]='U';
            EPC[place+2]='U';
            EPC[place+3]='C';
            EPC[place+4]='U';
            EPC[place+5]='C';
            EPC[place+6]='C';
            EPC[place+7]='U';
            EPC[place+8]='A';
            EPC[place+9]='C';
            EPC[place+10]='U';
            EPC[place+11]='G';
            EPC[place+12]='U';
            EPC[place+13]='U';
            EPC[place+14]='A';
            EPC[place+15]='U';
            EPC[place+16]='U';
            EPC[place+17]='G';
            
        }

        else if(str[y]=='M'){

            EPC[place+0]='A';
            EPC[place+1]='U';
            EPC[place+2]='G';
            
        }

        else if(str[y]=='N'){

            EPC[place+0]='A';
            EPC[place+1]='A';
            EPC[place+2]='U';
            EPC[place+3]='A';
            EPC[place+4]='A';
            EPC[place+5]='C';
            
        }

        else if(str[y]=='P'){

            EPC[place+0]='C';
            EPC[place+1]='C';
            EPC[place+2]='U';
            EPC[place+3]='C';
            EPC[place+4]='C';
            EPC[place+5]='C';
            EPC[place+6]='C';
            EPC[place+7]='C';
            EPC[place+8]='A';
            EPC[place+9]='C';
            EPC[place+10]='C';
            EPC[place+11]='G';
            
        }

        else if(str[y]=='Q'){

            EPC[place+0]='C';
            EPC[place+1]='A';
            EPC[place+2]='A';
            EPC[place+3]='C';
            EPC[place+4]='A';
            EPC[place+5]='G';
            
        }

        else if(str[y]=='R'){

            EPC[place+0]='C';
            EPC[place+1]='G';
            EPC[place+2]='U';
            EPC[place+3]='C';
            EPC[place+4]='G';
            EPC[place+5]='C';
            EPC[place+6]='C';
            EPC[place+7]='G';
            EPC[place+8]='A';
            EPC[place+9]='C';
            EPC[place+10]='G';
            EPC[place+11]='G';
            EPC[place+12]='A';
            EPC[place+13]='G';
            EPC[place+14]='A';
            EPC[place+15]='A';
            EPC[place+16]='G';
            EPC[place+17]='G';
            
        }

        else if(str[y]=='S'){

            EPC[place+0]='A';
            EPC[place+1]='G';
            EPC[place+2]='U';
            EPC[place+3]='A';
            EPC[place+4]='G';
            EPC[place+5]='C';
            EPC[place+6]='U';
            EPC[place+7]='C';
            EPC[place+8]='U';
            EPC[place+9]='U';
            EPC[place+10]='C';
            EPC[place+11]='C';
            EPC[place+12]='U';
            EPC[place+13]='C';
            EPC[place+14]='A';
            EPC[place+15]='U';
            EPC[place+16]='C';
            EPC[place+17]='G';
            
        }

        else if(str[y]=='T'){

            EPC[place+0]='A';
            EPC[place+1]='C';
            EPC[place+2]='U';
            EPC[place+3]='A';
            EPC[place+4]='C';
            EPC[place+5]='C';
            EPC[place+6]='A';
            EPC[place+7]='C';
            EPC[place+8]='A';
            EPC[place+9]='A';
            EPC[place+10]='C';
            EPC[place+11]='G';
              
        }

        else if(str[y]=='V'){

            EPC[place+0]='G';
            EPC[place+1]='U';
            EPC[place+2]='U';
            EPC[place+3]='G';
            EPC[place+4]='U';
            EPC[place+5]='C';
            EPC[place+6]='G';
            EPC[place+7]='U';
            EPC[place+8]='A';
            EPC[place+9]='G';
            EPC[place+10]='U';
            EPC[place+11]='G';
              
        }

        else if(str[y]=='W'){

            EPC[place+0]='U';
            EPC[place+1]='G';
            EPC[place+2]='G';
            
        }

        else if(str[y]=='Y'){

            EPC[place+0]='U';
            EPC[place+1]='A';
            EPC[place+2]='U';
            EPC[place+3]='U';
            EPC[place+4]='A';
            EPC[place+5]='C';
            
        }

        place = place + NEN[y]*3;
        
    }
    printf("塩基配列は\n");

    for(x=0; x < NA; x++){
        NOR = NOR/NEN[x];
        for(j=0;j < NL ; j++){
            for(k=0; k<NEN[x]; k++){
                for(i=0; i<NOR; i++){
                    
                    NucTable[3*(i+NOR*k+j*NEN[x]*NOR)+NTN*x] = EPC[NPI+3*k];
                    NucTable[3*(i+NOR*k+j*NEN[x]*NOR)+NTN*x+1] = EPC[NPI+3*k+1];
                    NucTable[3*(i+NOR*k+j*NEN[x]*NOR)+NTN*x+2] = EPC[NPI+3*k+2];
                    
                }
            }
        }
        
        NL = NL*NEN[x];
        NPI = NPI + 3*NEN[x];
    }

    for(z = 0; z < NENseki; z++){
        for(a=0; a<NA; a++){
            printf("%c",NucTable[NENseki*a*3+0+3*z]);
            printf("%c",NucTable[NENseki*a*3+1+3*z]);
            printf("%c",NucTable[NENseki*a*3+2+3*z]);
        }
        printf("\n");
    }
    

    free(NEN);
    free(EPC);
    free(NucTable);
    return 0;

}