//
// Created by Bori Akinola on 03/05/2021.
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