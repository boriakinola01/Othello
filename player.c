//
// Created by Bori Akinola on 03/05/2021.
//

#include <stdbool.h>
#include "player.h"
#include "board.h"
#include <stdlib.h>

bool checkInput(const char input[3]){
    if(input[0] < 'a' || input[0] > 'h')
        return true;
    if(input[1] < '1' || input[1] > '8')
        return true;
    if(board[atoi(&input[1])-1][input[0]-'a'] != ' ')
        return true;
    return false;
}

bool checkSlot(char color, const char input[3]){
    int row = atoi(&input[1])-1;
    int col = input[0] - 'a';

    for(int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; ++j) {
            bool check = validMove(color, i, j, row, col);
            if(check)
                return true;
        }
    }
    return false;
}

bool validMove(char color, int dRow, int dCol, int row, int col){
    char opp;

    if(color == 'B')
        opp = 'W';
    else if(color == 'W')
        opp = 'B';

    if((row+dRow < 0) || (row+dRow > SIZE-1) || (col+dCol < 0) || (col+dCol > SIZE-1))
        return false;
    if(board[row+dRow][col+dCol] != opp)
        return false;
    if((row+dRow+dRow < 0) || (row+dRow+dRow > 7) || (col+dCol+dCol < 0) || (col+dCol+dCol > 7))
        return false;

    return lineCheck(color, dRow, dCol, row+dRow+dRow, col+dCol+dCol);
}

bool lineCheck(char color, int dRow, int dCol, int row, int col){
    if(board[row][col] == color)
        return true;
    if((row+dRow < 0) || (row+dRow > SIZE-1) || (col+dCol < 0) || (col+dCol > SIZE-1))
        return false;

    return lineCheck(color, dRow, dCol, row+dRow, col+dCol);
}

void playerMove(char color, const char input[3]){
    char opp;
    int dRow, dCol, x, y;

    int row = atoi(&input[1])-1;
    int col = input[0] - 'a';

    board[row][col] = color;

    if(color == 'B')
        opp = 'W';
    else if(color == 'W')
        opp = 'B';

    for(dCol = -1; dCol <= 1; dCol++){
        for(dRow = -1; dRow <= 1; dRow++){

            if((row+dRow < 0) || (row+dRow > SIZE-1) ||
               (col+dCol < 0) || (col+dCol > SIZE-1) || (dRow == 0 && dCol ==0))
                continue;

            if(board[row+dRow][col+dCol] == opp){
                x = row+dRow;
                y = col+dCol;

                while(true){
                    x += dRow;
                    y += dCol;

                    if(x < 0 || x > SIZE-1 || y < 0 || y > SIZE-1)
                        break;
                    if(board[x][y] == ' ')
                        break;

                    if(board[x][y] == color){
                        while(board[x-=dRow][y-=dCol] == opp)
                            board[x][y] = color;
                        break;
                    }
                }
            }
        }
    }
}