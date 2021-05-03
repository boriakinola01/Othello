#include <stdio.h>
#include "board.h"
#include "player.h"
#include "gamePlay.h"


int main(void){

    initialiseGame();
    printf("Enter name of Player 1 (Black):");
    scanf("%s", p1.name);
    printf("Enter name of Player 2 (White):");
    scanf("%s", p2.name);

    printBoard();
    printf("%s goes first\n", p1.name);


    while(numOfTiles != SIZE*SIZE && (checkMoves(p1.color) || checkMoves(p2.color))){

        playPlayer(p1);
        playPlayer(p2);
    }

    printf("Game Over!\n");

    if(p2.score > p1.score){
        printf("%s wins!!!\n", p2.name);
    } else {
        printf("%s wins!!!\n", p1.name);
    }

    return 0;
}