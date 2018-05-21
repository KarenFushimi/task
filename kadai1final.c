#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{

    char a[1000];
    char *id = "ID=gene";
    FILE *f;
    char file_name[] = "NC_010473.gff";
    int NoScan = 1;
    char *strnum0;
    char *strnum1;
    char *strnum2;
    char *strnum3;
    char *strnum4;
    char *strnum5;
    char *strnum6;
    char *strnum7;
    char *strnum8;
    char *Rstrstr;
    int j = 0;
    int NBegin;
    int NEnd;
    int NCDS=1;

    printf("遺伝子長は");
    
    /* ファイルオープン */
    if ((f = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "%s\n", "error: can't read file.");
        return EXIT_FAILURE;
    }

    while (fgets(a,1000,f) != NULL){

        
        Rstrstr = strstr(a,"CDS");

        

        if(Rstrstr != NULL){
            

            strnum0 = strtok(a, "\t");
            strnum1 = strtok(NULL, "\t");
            strnum2 = strtok(NULL, "\t");
            strnum3 = strtok(NULL, "\t");
            strnum4 = strtok(NULL, "\t");
            strnum5 = strtok(NULL, "\t");
            strnum6 = strtok(NULL, "\t");
            strnum7 = strtok(NULL, "\t");
            strnum8 = strtok(NULL, "\t");
            
            
            NBegin = atoi(strnum3);
            NEnd = atoi(strnum4);
            printf(",%d",NEnd-NBegin);
            
            NCDS++;
        }

        
        
    }


    printf("\n含まれる遺伝子数は、%d\n",NCDS-1);

    fclose(f);

    return 0;

}