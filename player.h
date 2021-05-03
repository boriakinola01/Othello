//
// Created by Bori Akinola on 03/05/2021.
//

#ifndef PROJECTASSIGNMENT2_PLAYER_H
#define PROJECTASSIGNMENT2_PLAYER_H


typedef struct player{
    int score;
    char name[10];
    char color;
} player;

player p1, p2;

#endif //PROJECTASSIGNMENT2_PLAYER_H


bool checkSlot(char color, const char input[3]);
bool validMove(char color, int dRow, int dCol, int row, int col);
bool lineCheck(char color, int dRow, int dCol, int row, int col);
bool checkInput(const char input[3]);
void playerMove(char color, const char input[3]);