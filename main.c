#include <stdio.h>
#include <time.h>
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


    while(numOfTiles != SIZE*SIZE){
        if(checkMoves(p1.color))
            playPlayer(p1);
        else if(checkMoves(p2.color))
            playPlayer(p2);
        else
            break;
    }

    printf("Game Over!\n");

    if(p2.score > p1.score){
        printf("%s wins!!!\n", p2.name);
    } else {
        printf("%s wins!!!\n", p1.name);
    }

    FILE *fp;
    time_t t;
    time(&t);

    fp = fopen("/Users/boriakinola/Desktop/CompProgProject1/Othello/othello-results.txt", "a");

    fprintf(fp,"\nGame played on %s\n", ctime(&t));
    fprintf(fp, "Player 1: %s \tScore: %d\n"
                "Player 2: %s \tScore: %d\n", p1.name,
                p1.score, p2.name, p2.score);
    return 0;
}