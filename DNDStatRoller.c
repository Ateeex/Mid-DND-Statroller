#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolled_dices[4];
int rolled_stats[6];
int rDicesLen = sizeof(rolled_dices)/sizeof(rolled_dices[0]);
int rStatsLen = sizeof(rolled_stats)/sizeof(rolled_stats[0]);

void printArray(int arr[] , int size);
void bubbleSort(int arrVals[] , int arrLen);
void allocation(int num , int rolledVals[]);
int chosenVal(int userNum);
int addArrayVals(int arrNums[] , int arrNumsLen);

char stats[250] = "\n1 - Strength\n2 - Dexterity\n3 - Constitution\n4 - Intelligence\n5 - Wisdom\n6 - Charisma";
int str;
int dex;
int con;
int intel;
int wis;
int cha;

int main() {
    srand(time(0));
    int userChoice;


    for(int i = 0 ; i < 6 ; i++) {


        for(int j = 0 ; j < 4 ; j++) {
            rolled_dices[j] = (rand() % 6) + 1;
        }

        bubbleSort(rolled_dices,rDicesLen);
        int stat = rolled_dices[1] + rolled_dices[2] + rolled_dices[3];
        rolled_stats[i] = stat;
    }

    printf("The stats you have rolled for are: ");
    printArray(rolled_stats , rStatsLen);
    printf("%s" , stats);
    while(addArrayVals(rolled_stats , rStatsLen) != 0) {
        printf("\nAllocate the rolled numbers to each stat of your liking(1-6):\n");
        scanf("%d" , &userChoice);
        allocation(userChoice , rolled_stats);
        printf("%s" , stats);
    }

    printf("\nYou have completely allocated all of your points!");
    printf("\nSTR - %d\nDEX - %d\nCON - %d\nINT - %d\nWIS - %d\nCHA - %d" , str , dex , con , intel , wis , cha);

    return 0;
}


void printArray(int arr[] , int size) {

    for(int i = 0 ; i < size ; i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%d" , arr[i]);
    }

}

void bubbleSort(int arrVals[] , int arrLen) {
    int temp;
    for(int i = 0 ; i < arrLen - 1 ; i++) {
        for(int j = 0; j < arrLen - i - 1 ; j++) {
            if(arrVals[j] > arrVals[j + 1]) {
                temp = arrVals[j+1];
                arrVals[j+1] = arrVals[j];
                arrVals[j] = temp;
            }
        }
    }
}

int addArrayVals(int arrNums[] , int arrNumsLen) {
    int sum = 0;
    for(int i = 0 ; i < arrNumsLen ; i++) {
       sum = sum + arrNums[i];
    }
    return sum;

}

int chosenVal(int userNum) {
    if(userNum <= 0 || userNum > 6) {
        printf("\nYou entered an invalid number!");
        return -1;
    }


    return rolled_stats[userNum - 1];
}

void allocation(int num , int rolledVals[]){
    int choice;
    int returnVal;
    switch(num) {
        case 1:
            printArray(rolledVals , 6);
            printf("\nChoose which rolled stat should be allocated to strength!(1-6):\n");
            scanf("%d" , &choice);
            returnVal = chosenVal(choice);
            str = returnVal;
            rolled_stats[choice - 1] = 0;
            printf("You allocated %d to strength!" , returnVal);
            break;
        case 2:
            printArray(rolledVals , 6);
            printf("\nChoose which rolled stat should be allocated to dexterity!(1-6):\n");
            scanf("%d" , &choice);
            returnVal = chosenVal(choice);
            dex = returnVal;
            rolled_stats[choice - 1] = 0;
            printf("You allocated %d to dexterity!" , returnVal);
            break;
        case 3:
            printArray(rolledVals , 6);
            printf("\nChoose which rolled stat should be allocated to constituition!(1-6):\n");
            scanf("%d" , &choice);
            returnVal = chosenVal(choice);
            con = returnVal;
            rolled_stats[choice - 1] = 0;
            printf("You allocated %d to constituition!" , returnVal);
            break;
        case 4:
            printArray(rolledVals , 6);
            printf("\nChoose which rolled stat should be allocated to intelligence!(1-6):\n");
            scanf("%d" , &choice);
            returnVal = chosenVal(choice);
            intel = returnVal;
            rolled_stats[choice - 1] = 0;
            printf("You allocated %d to intelligence!" , returnVal);
            break;
        case 5:
            printArray(rolledVals , 6);
            printf("\nChoose which rolled stat should be allocated to wisdom!(1-6):\n");
            scanf("%d" , &choice);
            returnVal = chosenVal(choice);
            wis = returnVal;
            rolled_stats[choice - 1] = 0;
            printf("You allocated %d to wisdom!" , returnVal);
            break;
        case 6:
            printArray(rolledVals , 6);
            printf("\nChoose which rolled stat should be allocated to charisma!(1-6):\n");
            scanf("%d" , &choice);
            returnVal = chosenVal(choice);
            cha = returnVal;
            rolled_stats[choice - 1] = 0;
            printf("You allocated %d to charisma!" , returnVal);
            break;
        default:
            printf("\nYou entered an invalid number, input(1-6): ");
    }

}

