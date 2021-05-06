//
// Created by Toluwabori Akinola on 03/05/2021.
//

#include "gamePlay.h"
#include "player.h"
#include "board.h"


/*
 * Function to start the game up initialising each players colour, initialising the board
 * and updating the score and number of tiles on the board
 */
void initialiseGame(void){

    initialiseBoard(board);
    updateScore();

    //player one is always black
    p1.color = 'B';

    // player two is always white
    p2.color = 'W';

    numOfTiles = 4;
} // end of initialise game function


/*
 * Function to check if a player has any valid moves at each turn of their play
 * This will help determine the end of the game if neither players have any valid
 * moves to play
 */
bool movesAvailable(char color){
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
} // end of check moves function



/*
 * Function to run the play for each player:
 */
void playPlayer(player p){
    // request user input
    printf("%s's turn (%c)\n", p.name, p.color);
    printf("Your move:");
    scanf("%s", slot);

    // check if user chooses to pass their turn
    if(strcmp(slot,"p")!=0){
        // check if the string entered is of a valid format and/or the move is valid
        while(!checkMove(p.color, slot) || !checkInput(slot)){
            printf("Invalid input, enter a valid slot:");
            scanf("%s", slot);
        }
        // implement the move
        playerMove(p.color, slot);
        // increment the number of tiles counter, update the score and print the board
        numOfTiles++;
        updateScore();
        printBoard();
    }
}// end of play player function