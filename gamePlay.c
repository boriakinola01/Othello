//
// Created by Toluwabori Akinola on 03/05/2021.
//

#include "gamePlay.h"
#include "player.h"
#include "board.h"

void initialiseGame(void){
    initialiseBoard(board);
    updateScore();

    p1.color = 'B';
    p2.color = 'W';

    numOfTiles = 4;
}

bool checkMoves(char color){
    for(int row = 0; row<SIZE; row++){
        for(int col = 0; col<SIZE; col++){
            if(board[row][col] == ' '){
                for(int i = -1; i <= 1; i++){
                    for (int j = -1; j <= 1; ++j) {
                        bool check = validMove(color, i, j, row, col);
                        if(check)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

void playPlayer(player p){
    printf("%s's turn (%c)\n", p.name, p.color);
    printf("Your move:");
    scanf("%s", slot);

    if(strcmp(slot,"p")!=0){

        while(checkSlot(p.color, slot) || checkInput(slot)){
            printf("Invalid input, enter a valid slot:");
            scanf("%s", slot);
        }
        playerMove(p.color, slot);
        numOfTiles++;
        updateScore();
        printBoard();
    }
}