#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <conio.h>

/* Call Function Here */
void thaifood();
void foodtype();
void comingsoon();
void select();

int main(){

    system ("CLS"); //Clear Console

    printf("\n\n\n\n\t\tSelect your order...\n\n");
    printf("\t\t1 Select Food\n");
    printf("\t\t2 See your bill\n");

    printf("\n\t\tPlease select number of order.... ");
    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            select();
            break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n\n\n\t\tComing Soon...\n\n");
            printf("\t\tPress any key to continue...\n");
            getch();
            main();
            break;
        default:
            printf("\n\t\t**  Invalid Choice  **\n\n\n");
            printf("\t\tPress any key to continue...\n");
            getch();
            main();
            break;
    }
}

/* Main Screen */
void select(){

    system ("CLS"); //Clear Console

    /* Select Type of Food */
    printf("\n\n\n\n\t\tOur type of food...\n\n");
    printf("\t\t1 Thai Food\n");
    printf("\t\t2 Chinese Food\n");
    printf("\t\t3 Japannese Food\n");
    printf("\t\t4 Korean Food\n");
    printf("\t\t5 Italian Food\n");
    printf("\t\t6 Ameican Food\n");
    printf("\t\t7 Mexican Food\n");
    printf("\t\t8 Dessert\n");
    printf("\t\t9 Drink\n");
    printf("\t\t10 Baby Food\n");

    printf("\n\t\t0 Back..\n");

    printf("\n\t\tPlease select number of types of food. ");
    int food_type;
    scanf("%d", &food_type);

    switch(food_type){
    case 0:
        main();
        break;
    case 1:
        thaifood();
        break;
    case 2:
        comingsoon();
        break;
    case 3:
        comingsoon();
        break;
    case 4:
        comingsoon();
        break;
    case 5:
        comingsoon();
        break;
    case 6:
        comingsoon();
        break;
    case 7:
        comingsoon();
        break;
    case 8:
        comingsoon();
        break;
    case 9:
        comingsoon();
        break;
    case 10:
        comingsoon();
        break;
    default:
        printf("\n\t\t**  Invalid Choice  **\n\n\n");
        printf("\t\tPress any key to continue...\n");
        getch();
        system("cls");
        select();
        break;
    }
}

/* Function for Coming Soon Type */
void comingsoon(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\tComing Soon...\n\n");
    printf("\t\tPress any key to continue...\n");
    getch();
    select();
}

void thaifood(){
    printf("\n\n\tComing Soon\n");
    printf("\tType Anything\n");
    getch();
    system ("CLS");
    main();
}
