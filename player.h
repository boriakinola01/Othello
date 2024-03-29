//
// Created by Toluwabori Akinola on 03/05/2021.
//

#include <stdbool.h>
#ifndef PROJECTASSIGNMENT2_PLAYER_H
#define PROJECTASSIGNMENT2_PLAYER_H

/*
 * Declare a struct for a player.
 */
typedef struct player{

    int score; // a players score
    char name[30]; // a players name
    char color; // a players colour
} player;

// game is only played with two players so declare each player
player p1, p2;

#endif //PROJECTASSIGNMENT2_PLAYER_H

/*
 * Functions declaration
 */

bool validMove(char color, int dRow, int dCol, int row, int col);
bool lineCheck(char color, int dRow, int dCol, int row, int col);

bool checkMove(char color, const char input[]);
void playerMove(char color, const char input[]);

bool checkInput(const char input[]);
bool isNotEmpty(const char input[]);
