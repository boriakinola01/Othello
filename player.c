//
// Created by Toluwabori Akinola on 03/05/2021.
//

#include <stdbool.h>
#include "player.h"
#include "board.h"
#include <stdlib.h>


/* Function to check the user input and makes sure it is valid
 * and within the range of the board*/

bool checkInput(const char input[]){
    // check if the letter part is within 'a' and 'h'
    if(input[0] < 'a' || input[0] > 'h')
        return false;
    // check if the integer part is within 1 and 8
    if(input[1] < '1' || input[1] > '8')
        return false;
    // check if where the user intends to play is empty or not
    if(board[atoi(&input[1])-1][input[0]-'a'] != ' ')
        return false;

    // if no issue, return true
    return true;
} // end of check input function

/*
 * Function to check if there slot the player is playing in is
 * empty or not
 */
bool isNotEmpty(const char input[]){
    if(board[atoi(&input[1])-1][input[0]-'a'] == 'B')
        return true;
    if(board[atoi(&input[1])-1][input[0]-'a'] == 'W')
        return true;

    return false;
}


/* Function to check if a slot entered by the user is a valid move
 * to be made by that player depending on their colour
 */

bool checkMove(char color, const char input[3]){
    // get the row and column entered by the user
    int row = atoi(&input[1])-1;
    int col = input[0] - 'a';

    /* check in all directions using the i and j as offset positions */
    for(int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; ++j) {
            // check if any of the directions make the move valid
            bool check = validMove(color, i, j, row, col);
            if(check) // if so, return true
                return true;
        }
    }
    return false; // if not a valid move, return false
} // end check slot function

/* Function to check if a move is valid, based on the surrounding
 * tile pieces on the board */
bool validMove(char color, int dRow, int dCol, int row, int col){
    // variable to hold the opposite of the color we're searching with
    char opp;

    if(color == 'B')
        opp = 'W';
    else if(color == 'W')
        opp = 'B';

    // if out of bounds, return false
    if((row+dRow < 0) || (row+dRow > SIZE-1) || (col+dCol < 0) || (col+dCol > SIZE-1))
        return false;

    // if search reaches the same colour, return false
    if(board[row+dRow][col+dCol] != opp)
        return false;

    // if two tiles over in any direction of the tile we're looking at is the end of the board,
    // return false
    if((row+dRow+dRow < 0) || (row+dRow+dRow > 7) || (col+dCol+dCol < 0) || (col+dCol+dCol > 7))
        return false;

    // if not return what is gotten from the lineCheck function
    // passing the position(dRow, dCol) as the new row and col
    return lineCheck(color, dRow, dCol, row+dRow+dRow, col+dCol+dCol);
} // end of valid move function


/* Function to find a corresponding colour along the path of search*/

bool lineCheck(char color, int dRow, int dCol, int row, int col){
    // if in the new position, the colour is found, return true
    if(board[row][col] == color)
        return true;
    // if out of bounds, return false
    if((row+dRow < 0) || (row+dRow > SIZE-1) || (col+dCol < 0) || (col+dCol > SIZE-1))
        return false;
    // repeat until out of bounds or colour is matched
    return lineCheck(color, dRow, dCol, row+dRow, col+dCol);
} // end of lineCheck function


/* Function to implement a player move*/

void playerMove(char color, const char input[]){
    char opp;
    int dRow, dCol, x, y;

    // get the row and column from the user input
    int row = atoi(&input[1])-1;
    int col = input[0] - 'a';

    board[row][col] = color; // set the board value to the color

    if(color == 'B')
        opp = 'W';
    else if(color == 'W')
        opp = 'B';

    // from the location, check in all directions for tiles to flip to the correct colour
    for(dCol = -1; dCol <= 1; dCol++){
        for(dRow = -1; dRow <= 1; dRow++){

            // if out of bounds, skip and continue
            if((row+dRow < 0) || (row+dRow > SIZE-1) ||
               (col+dCol < 0) || (col+dCol > SIZE-1) || (dRow == 0 && dCol ==0))
                continue;

            // if tile is of opposite colour
            if(board[row+dRow][col+dCol] == opp){
                // update the location
                x = row+dRow;
                y = col+dCol;

                while(true){
                    // increment the location to the next along the line
                    x += dRow;
                    y += dCol;

                    // if out of bounds, break
                    if(x < 0 || x > SIZE-1 || y < 0 || y > SIZE-1)
                        break;
                    // if tile is empty, break
                    if(board[x][y] == ' ')
                        break;

                    // if tile is of same colour
                    if(board[x][y] == color){
                        // as long as previous tile along the line is of opposite colour
                        while(board[x-=dRow][y-=dCol] == opp)
                            //set tile to the color
                            board[x][y] = color;
                        break;
                    }
                }
            }
        }
    }
} // end of player move function