//
// Created by Toluwabori Akinola on 03/05/2021.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

#ifndef PROJECTASSIGNMENT2_GAMEPLAY_H
#define PROJECTASSIGNMENT2_GAMEPLAY_H

// variable to keep track of the number of tiles on the board
int numOfTiles;

// global variable to hold the input of a player as game progresses
char slot[3];

#endif //PROJECTASSIGNMENT2_GAMEPLAY_H

/*
 * Functions declaration
 */

bool movesAvailable(char color);

void initialiseGame(void);

void playPlayer(player p);