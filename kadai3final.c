#include <stdio.h>
#include <string.h>
#define NUM 16

int main (void)
{   
    FILE *f;
    char str[100];
    char str0[50000];
    int NoR = 0;
    int NoR1 = 0;
    char *pj; //繋げるためのポインタ
    char *LoS;
    int i;
    int k = 0;
    char *pE[100]; //検索した文字列の最初の位置のポインタ
    char *pH[100]; //検索した文字列の最初の位置のポインタ
    char *pB[100]; //検索した文字列の最初の位置のポインタ
    char *pN[100]; //検索した文字列の最初の位置のポインタ
    char *pA[NUM]; //検索した文字列(全て)の最初の位置のポインタ
    
    int NumAll = 0; //全酵素での切断箇所がいくつあるか
    int length[100];
    long lenstr0;
    char *tmp;
    int s;
    int t;

    
    f = fopen("NC_001416.fna", "r");
    
    while (fgets(str,500,f) != NULL){
    
        NoR=NoR+1; //行数カウント
        
    }
    

    printf("%d\n",NoR);

    fclose(f);

    

    f = fopen("NC_001416.fna", "r");

    while (fgets(str,500,f) != NULL){
    
        NoR1=NoR1+1; //今の行
        
        
        if(NoR1==2){
            pj = strstr(str, "\n");
            *pj = NULL;
            strcpy(str0,str);
        }
        
        if(2<NoR1 && NoR1<=NoR){  //全体の行数に達したらストップ
            pj = strstr(str, "\n");
            *pj = NULL;
            strcat(str0,str);
        }
        

    }
    
    printf("%s\n",str0);
    LoS = strrchr(str0,NULL);//str0の終端文字のポインタ
    
    /*EcoRIで切った時の各断片の長さ(GAATTC)*/
    pE[0] = strstr(str0, "GAATTC");//最初のGAATTCを検索

    if(pE[0]==NULL){ //GAATTCが一つもない場合
        length[0]=strlen(str0);
    }
    else{ //GAATTCがあった場合、二つ目以降
        pA[0] = pE[0]; //最初の切断箇所を代入
        NumAll++; //最初の切断箇所をカウント
        

        length[0]=pE[0]+3-str0;//各断片の長さ、最初
        printf("GAATTCで切った時の断片の長さは、%d,",length[0]);

        for(i=1; pE[i-1] != NULL; i++){ //1つ前のポインタがNULLならp[i+1]?
            pE[i]=strstr(pE[i-1]+4,"GAATTC"); 
            

            if(pE[i] != NULL){ //検索する文字列がある
                length[i]=pE[i]-pE[i-1];//各断片の長さ、最初と最後以外
                printf("%d,",length[i]);
                pA[i] = pE[i]; //pAにpEのアドレスを代入
                NumAll++;
                
            }
            else{ //NULLに達したとき
                length[i]=LoS-pE[i-1]-3;//各断片の長さ、最後
                printf("%d\n",length[i]);
            }
            
        }
    }
    
    /*HindIIIで切った時の各断片の長さ(AAGCTT)*/
    pH[0] = strstr(str0, "AAGCTT");
    
    if(pH[0]==NULL){
        length[0]=strlen(str0);
    }
    else{
        pA[NumAll] = pH[0]; //最初の切断箇所を代入
        NumAll++; //最初の切断箇所をカウント
        
        length[0]=pH[0]+3-str0;//各断片の長さ、最初
        printf("AAGCTTで切った時の断片の長さは、%d,",length[0]);

        for(i=1; pH[i-1] != NULL; i++){ //p[i+1]?
            pH[i]=strstr(pH[i-1]+4,"AAGCTT"); 
            if(pH[i] != NULL){
                length[i]=pH[i]-pH[i-1];//各断片の長さ、最初と最後以外
                printf("%d,",length[i]);
                pA[NumAll] = pH[i]; //pAにpHのアドレスを代入
                NumAll++;
                
            }
            else{
                length[i]=LoS-pH[i-1]-3;//各断片の長さ、最後
                printf("%d\n",length[i]);
            }
            
        }

    }
    
    /*BamHIで切った時の各断片の長さ(GGATCC)*/
    pB[0] = strstr(str0, "GGATCC");
    
    if(pB[0]==NULL){
        length[0]=strlen(str0);
    }
    else{
        pA[NumAll] = pB[0]; //最初の切断箇所を代入
        NumAll++; //最初の切断箇所をカウント
        

        length[0]=pB[0]+3-str0;//各断片の長さ、最初
        printf("GGATCCで切った時の断片の長さは、%d,",length[0]);

        for(i=1; pB[i-1] != NULL; i++){ //p[i+1]?
            pB[i]=strstr(pB[i-1]+4,"GGATCC"); 
            if(pB[i] != NULL){
                length[i]=pB[i]-pB[i-1];//各断片の長さ、最初と最後以外
                printf("%d,",length[i]);
                pA[NumAll] = pB[i]; 
                NumAll++;
                
            }
            else{
                length[i]=LoS-pB[i-1]-3;//各断片の長さ、最後
                printf("%d\n",length[i]);
            }
            
        }

    }
    
    /*NotIで切った時の各断片の長さ(GCGGCCGC)*/
    pN[0] = strstr(str0, "GCGGCCGC");
    
    if(pN[0]==NULL){
        length[0]=strlen(str0);
        printf("GCGGCCGCで切った時の断片の長さは、%d\n",length[0]);
    }
    else{
        pA[NumAll] = pN[0]; //最初の切断箇所を代入
        NumAll++; //最初の切断箇所をカウント
        
        length[0]=pN[0]+4-str0;//各断片の長さ、最初
        printf("GCGGCCGCで切った時の断片の長さは、%d,",length[0]);

        for(i=1; pN[i-1] != NULL; i++){ //p[i+1]?
            pN[i]=strstr(pN[i-1]+8,"GCGGCCGC"); 
            if(pN[i] != NULL){
                length[i]=pN[i]-pN[i-1];//各断片の長さ、最初と最後以外
                printf("%d,",length[i]);
                pA[NumAll] = pN[i];
                NumAll++;
                
            }
            else{
                length[i]=LoS-pN[i-1]-4;//各断片の長さ、最後
                printf("%d\n",length[i]);
            }

        }
        
    }
    
    /*pAをソート*/
    for(s=0; s<NUM-1; s++){
        for(t=s+1; t<NUM; t++){
            if(pA[t] < pA[s]){
                tmp = pA[t];
                pA[t] = pA[s];
                pA[s] = tmp;
            }
        }
    }

    
    length[0]=pA[0]+3-str0;//各断片の長さ、最初
        printf("全酵素で切った時の断片の長さは、%d,",length[0]);

        for(i=1; pA[i-1] != NULL; i++){ //1つ前のポインタがNULLならp[i+1]?
            
            

            if(pA[i] != NULL){ //検索する文字列がある
                length[i]=pA[i]-pA[i-1];//各断片の長さ、最初と最後以外
                printf("%d,",length[i]);
                
            }
            else{ //NULLに達したとき
                length[i]=LoS-pA[i-1]-3;//各断片の長さ、最後
                printf("%d\n",length[i]);
            }
            
        }

    fclose(f);

    return 0;

}
