//
// Created by Toluwabori Akinola on 03/05/2021.
//

#ifndef PROJECTASSIGNMENT2_BOARD_H
#define PROJECTASSIGNMENT2_BOARD_H

/*
 * Define global variables and/or constants
 */

// size of the board defined
#define SIZE 8

// using a 2d-array for the board
char board[SIZE][SIZE];

#endif //PROJECTASSIGNMENT2_BOARD_H

/*
 * Functions declaration
 */
void printBoard();
void initialiseBoard(char arr[][SIZE]);
void updateScore(void);