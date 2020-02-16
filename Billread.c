#include <stdio.h>
#include <string.h>

struct food
{
    char name[20];
    char type[20];
    int hot;
};

int main(){
    char type[20];
    char name[20];
    char mody[20];
    FILE *fp,*fp2;
    fp = fopen("Bill.txt", "r+");
    fp2 = fopen("Bill2.txt", "w+");


    while(fscanf(fp,"%s %s %s\n",type,name,mody) != EOF){
         if(!strcmp(type, "Food")){
            fprintf(fp2,"%s %s %s\n",type,name,mody);
        }
    }

    fclose(fp);

    return 0;
}
