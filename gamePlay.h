//
// Created by Bori Akinola on 03/05/2021.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

#ifndef PROJECTASSIGNMENT2_GAMEPLAY_H
#define PROJECTASSIGNMENT2_GAMEPLAY_H

int numOfTiles;

char slot[2];

#endif //PROJECTASSIGNMENT2_GAMEPLAY_H


void initialiseGame(void);
bool checkMoves(char color);
void playPlayer(player p);