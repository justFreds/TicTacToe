// TIC TAC TOE game between 2 players or player vs computer
#include<stdio.h>
#include <stdbool.h>


//global variable
char grid[3][3];
const char USERTURN = 'X';

/****FUNCTION PROTOTYPES****/

//function that initializes board
void initializeGrid();
//function that displays board
void displayGrid();
//function that gets users move
void getUserMove();
//function that gets computer move
void getCompMove();
//function that switches players turn
void swapTurn();
//check for winner
void checkWin();
//check for draw
void checkDraw();

int main () {
    //Declerations and initializations


    //prompt user game they wish to play

    //read information from console

    //initializeGrid
    initializeGrid();
    displayGrid();
    
    //LOOP maybe do-while?
    //
    //displayGrid
    //get move
    //check for winner or draw
    //END LOOP

    //display winner then win state of board?

    return 0;
}

void initializeGrid() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}
void displayGrid() {
    for(int i = 0; i < 3; i++) {
    printf(" %c | %c | %c ", grid[i][0], grid[i][1], grid[i][2]);
    if(i !=2) {
        printf("\n---|---|---\n");
    }                       
    }        
    printf("\n");
}