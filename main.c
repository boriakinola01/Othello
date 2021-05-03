#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 8

typedef struct player{
    int score;
    char name[10];
    char color;
} player;


char board[SIZE][SIZE];
player p1, p2;

void printBoard();
void initialise(char arr[][SIZE]);
void playerMove(char color, const char slot[3]);
bool checkSlot(char color, const char input[3]);
bool validMove(char color, int dRow, int dCol, int row, int col);
bool lineCheck(char color, int dRow, int dCol, int row, int col);
bool checkInput(const char input[3]);
void updateScore(void);
bool lineFLip(char color, int dRow, int dCol, int row, int col);
void flip(char color, const char input[3]);

int main(void){

    initialise(board);

    p1.color = 'B';
    p2.color = 'W';
    p1.score = 0;
    p2.score = 0;


    char slot[3];
    int numOfTiles = 4;

    printf("Enter name of player one (Black):");
    scanf("%s", p1.name);
    printf("Enter name of player two (White):");
    scanf("%s", p2.name);

    printBoard();
    printf("%s goes first\n", p1.name);


    while(numOfTiles != SIZE*SIZE){

        printf("%s's turn\n", p1.name);
        printf("Your move:");
        scanf("%s", slot);

        if(strcmp(slot,"p")!=0){

            while(!checkSlot(p1.color, slot) || checkInput(slot)){
                printf("Invalid input, enter a valid slot:");
                scanf("%s", slot);
            }
            playerMove(p1.color, slot);
            flip(p1.color, slot);
            numOfTiles++;
            updateScore();
            printBoard();
        }


        printf("%s's turn\n", p2.name);
        printf("Your move:");
        scanf("%s", slot);

        if(strcmp(slot,"p")!=0){

            while(!checkSlot(p2.color, slot) || checkInput(slot)){
                printf("Invalid input, enter a valid slot:");
                scanf("%s", slot);
            }
            playerMove(p2.color, slot);
            flip(p2.color, slot);
            numOfTiles++;
            updateScore();
            printBoard();

        }


    }

}

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

void initialise(char arr[][SIZE]){
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

void playerMove(char color, const char slot[3]){
    int x;

    x = slot[0] - 'a';

    board[atoi(&slot[1])-1][x] = color;
}

bool checkInput(const char input[3]){
    if(input[0]<'a' || input[0]>'h')
        return true;
    if(input[1] < '1' || input[1] > '8')
        return true;
    if(board[atoi(&input[1])-1][input[0]-'a'] != ' ')
        return true;
    return false;
}

void updateScore(void){
    for(int row=0; row<SIZE;row++){
        for(int col=0;col<SIZE;col++){
            if(board[row][col] == 'B')
                p1.score++;
            if(board[row][col] == 'W')
                p2.score++;
        }
    }
}

bool checkSlot(char color, const char input[3]){
    int col = atoi(&input[1])-1;
    int row = input[0] - 'a';

    bool nw = validMove(color, -1, -1, row, col);
    bool nn = validMove(color, -1, 0, row, col);
    bool ne = validMove(color, -1, 1, row, col);
    bool ee = validMove(color, 0, 1, row, col);
    bool sw = validMove(color, 1, -1, row, col);
    bool ss = validMove(color, 1, 0, row, col);
    bool se = validMove(color, 1, 1, row, col);
    bool ww = validMove(color, 0, -1, row, col);

    if(nw || nn || ne || ee || sw || ss || se || ww)
        return true;

    return false;
}

bool validMove(char color, int dRow, int dCol, int row, int col){
    char opp;

    if(color == 'B')
        opp = 'W';
    else if(color == 'W')
        opp = 'B';

    // check if we're walking off the board

    if((row + dRow < 0) || (row + dRow > SIZE-1))
        return false;
    if((col + dCol < 0) || (col + dCol > SIZE-1))
        return false;
    if(board[row + dRow][col + dCol] != opp)
        return false;
    if((row + dRow + dRow < 0) || (row + dRow + dRow > 7))
        return false;
    if((col + dCol + dCol < 0) || (col + dCol + dCol > 7))
        return false;

    return lineCheck(color, dRow, dCol, row+dRow+dRow, col+dCol+dCol);
}

bool lineCheck(char color, int dRow, int dCol, int row, int col){
    if(board[row][col] == color)
        return true;
    if((row + dRow < 0) || (row + dRow > SIZE-1))
        return false;
    if((col + dCol < 0) || (col + dCol > SIZE-1))
        return false;

    return lineCheck(color, dRow, dCol, row+dRow, col+dCol);
}

void flip(char color, const char input[3]){
    int col = atoi(&input[1])-1;
    int row = input[0] - 'a';

    lineFLip(color, -1, -1, row, col);
    lineFLip(color, -1, 0, row, col);
    lineFLip(color, -1, 1, row, col);
    lineFLip(color, 0, 1, row, col);
    lineFLip(color, 1, -1, row, col);
    lineFLip(color, 1, 0, row, col);
    lineFLip(color, 1, 1, row, col);
    lineFLip(color, 0, -1, row, col);
}


// Function to check the stuff and the other stuff

bool lineFLip(char color, int dRow, int dCol, int row, int col){
    if((row + dRow < 0) || (row + dRow > SIZE-1))
        return false;
    if((col + dCol < 0) || (col + dCol > SIZE-1))
        return false;

    if(board[row+dRow][col+dCol] == ' ')
        return false;

    if(board[row+dRow][col+dCol] == color)
        return true;
    else{
        if(lineFLip(color, dRow, dCol, row+dRow, col+dCol)){
            board[row+dRow][col+dCol] = color;
            return true;
        } else
            return false;
    }
}