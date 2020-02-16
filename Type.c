#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(){

    srand(time(0)); //ตั้งให้สุ่มใหม่ทุกรอบ

    /*ตัวแปรของเกม*/
    int i,num;
    char a, letter;
    char array[] = {'w', 'a', 's','d'};
    int pass = 0, fail = 0;

    /*ตัวแปรของตัวจับเวลา*/
    double elapMilli, elapSeconds, elapMinutes;
    clock_t Begin, End;
    int elapTicks;

    printf("\n\n\tWhat times do you want to type... (Type integer that more than 0) ");
    scanf("%d", &num);

    system ("CLS"); //เคลีย Console

    printf("\n\n\tType Anything to start...");
    getch();

    Begin = clock() * CLK_TCK; //เริ่มจับเวลา
    printf("\n\n\tType the letter..\n\n");

    for (i=1;i<=num;i++){
        a = array[rand()%4];
        printf("\t%c ", a);
        letter = getch();

        if (letter == a){
            printf("True\n");
            pass++;
        }

        else{
            printf("False\n");
            fail++;
        }
    }
    End = clock() * CLK_TCK; //จบการจับเวลา

    elapTicks = End - Begin;        //จำนวน Ticks ตั้งแต่ Begin ถึง End
    elapMilli = elapTicks/1000;     //milliseconds
    elapSeconds = elapMilli/1000;   //seconds

    printf("\n\t\tScore : Correct %d Fail %d Time %.2lf s\n",pass,fail,elapSeconds);
    printf("\n\t\tType Anything for exit...\n\n");
    getch();

    system ("CLS");

    return 0;
}
