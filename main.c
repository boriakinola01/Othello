#include <stdio.h>
#include <string.h>
#include "board.h"
#include "player.h"
#include "gamePlay.h"


int main(void){

    printf("Enter name of player one (Black):");
    scanf("%s", p1.name);
    printf("Enter name of player two (White):");
    scanf("%s", p2.name);

    printBoard();
    printf("%s goes first\n", p1.name);


    while(numOfTiles != SIZE*SIZE){

        printf("%s's turn (%c)\n", p1.name, p1.color);
        printf("Your move:");
        scanf("%s", slot);

        if(strcmp(slot,"p")!=0){

            while(!checkSlot(p1.color, slot) || checkInput(slot)){
                printf("Invalid input, enter a valid slot:");
                scanf("%s", slot);
            }
            playerMove(p1.color, slot);
            numOfTiles++;
            updateScore();
            printBoard();
        }

        printf("%s's turn (%c)\n", p2.name, p2.color);
        printf("Your move:");
        scanf("%s", slot);

        if(strcmp(slot,"p")!=0){

            while(!checkSlot(p2.color, slot) || checkInput(slot)){
                printf("Invalid input, enter a valid slot:");
                scanf("%s", slot);
            }
            playerMove(p2.color, slot);
            numOfTiles++;
            updateScore();
            printBoard();
        }
    }
}