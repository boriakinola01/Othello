//
// Created by Bori Akinola on 03/05/2021.
//
#include <stdio.h>
#include "board.h"
#include "player.h"

void printBoard(){
    printf("\nScores: %s (Black): %d\t %s (White): %d\n\n", p1.name, p1.score,
           p2.name, p2.score);
    puts("     a   b   c   d   e   f   g   h");
    for(int i = 0; i<SIZE;i ++){
        printf("   ");
        for(int j = 0;j<SIZE;j++){
            printf(" ---");
        }
        puts(" ");
        printf("%d  |", i+1);
        for(int j=0;j<SIZE;j++){
            printf(" %c", board[i][j]);
            printf(" |");
        }
        printf("\n");
    }
    printf("   ");
    for(int j = 0;j<SIZE;j++){
        printf(" ---");
    }

    printf("\n    ");
    puts(" a   b   c   d   e   f   g   h");
    printf("\n");
}

void initialiseBoard(char arr[][SIZE]){
    for(int i = 0; i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            arr[i][j] = ' ';
        }
    }

    arr[3][3] = 'W';
    arr[3][4] = 'B';
    arr[4][3] = 'B';
    arr[4][4] = 'W';
}

void updateScore(void){
    int x = 0, y = 0;
    for(int row=0; row<SIZE; row++){
        for(int col=0; col<SIZE; col++){
            if(board[row][col] == 'B')
                x++;
            if(board[row][col] == 'W')
                y++;
        }
    }
    p1.score = x;
    p2.score = y;
}