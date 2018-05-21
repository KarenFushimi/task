#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 6214 //行数を数えた結果

int main ()
{

    char a[3000];
    char *ec = "ec";
    FILE *f;
    char file_name_in[] = "enzyme.txt";
    char *ec1, *strnum1, *strnum2, *strnum3, *strnum4, *strnum5;
    int numLine = 0;
    int numSort[NUM]; //ソート用の数値、NUMは結局自分で設定した
    int j = 0;
    int tmp;
    int k,s,t;


    /*行数をカウント*/
    f=fopen(file_name_in, "r");

    if (f == NULL) {
        fprintf(stderr, "%s\n", "error: can't read file.");
        return EXIT_FAILURE;
    }

    while (fgets(a,3000,f) != NULL){
        if(strncmp(a,ec,2) == 0){
            numLine = numLine + 1;
            }
    }

    fclose(f);

    

    int num[numLine][4]; //行数分だけ数値を入れる箱を用意

    
    f=fopen(file_name_in, "r");
    
    /* ファイルオープン */
    if (f == NULL) {
        fprintf(stderr, "%s\n", "error: can't read file.");
        return EXIT_FAILURE;
    }

    

    

    while (fgets(a,500,f) != NULL){
        if(strncmp(a,ec,2) == 0){ //ecから始まる行のみ操作
            
            /* 1回目の呼出し、ecを切る*/
            ec1 = strtok(a, ":");

            /* 2回目以降の呼出し、数字を切る*/
            strnum1 = strtok(NULL, ".");
            strnum2 = strtok(NULL, ".");
            strnum3 = strtok(NULL, ".");
            strnum4 = strtok(NULL, ".");
            strnum5 = strtok(NULL, "\t");


            /*文字データを数値に変換*/
            num[j][0]=atoi(strnum1);
            num[j][1]=atoi(strnum2);
            num[j][2]=atoi(strnum3);
            num[j][3]=atoi(strnum4);

            
            /*ソート用の数値*/
            numSort[j] = num[j][0]*(10000000)+num[j][1]*(100000)+num[j][2]*(1000)+num[j][3];

            j = j + 1;
        }
    }
    
    

    /*numSortをソート*/
    for(s=0; s<NUM-1; s++){
        for(t=s+1; t<NUM; t++){
            if(numSort[t] < numSort[s]){
                tmp = numSort[t];
                numSort[t] = numSort[s];
                numSort[s] = tmp;
            }
        }
    }

    /*numSortからec番号に変換*/
    while(numSort[k] != 0){
        num[k][0] = numSort[k]/10000000;
        num[k][1] = (numSort[k]/100000)%100;
        num[k][2] = (numSort[k]/1000)%100;
        num[k][3] = numSort[k]%1000;
        printf("EC:%d,%d,%d,%d\n",num[k][0],num[k][1],num[k][2],num[k][3]);
        k++;
    }
    

    printf("numLine:%d\n",numLine);//一応行数を表示

    


    fclose(f);


    return 0;

}