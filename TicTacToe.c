// TIC TAC TOE game between 2 players or player vs computer
#include<stdio.h>
#include <stdbool.h>


//global variable
char grid[3][3];
const char USER = 'X';
const char NPC = 'O';

/****FUNCTION PROTOTYPES****/

//function that initializes board
void initializeGrid();
//function that displays board
void displayGrid();
//check for a free space
int checkFreeSpace();
//function that gets users move
void getUserMove(char *);
//function that gets computer move
void getCompMove();
//function that switches players turn
void swapTurn(char *);
//check for game = win or draw
void checkGameOver();

int main () {
    //Declerations and initializations
    bool gameover = false;
    int turnCounter = 0;
    //prompt user game they wish to play
    printf("Welcome user!\nTicTacToe\n");
    
    //read information from console

    //initializeGrid
    initializeGrid(); 
    
    //LOOP maybe do-while?
    do {
        displayGrid();
        getUserMove(&USER);
        printf("\nGood!\n");
        printf("Current status is: \n");
        turnCounter++;


        swapTurn(&USER);
    } while(gameover == true || checkFreeSpace() == 0);
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

void getUserMove(char *turn) {
    char *ptr = turn;
    int x, y;
    printf("Enter X,Y coordinates for your move(%c): ", *turn);
    fflush(stdout);
    scanf("%d %*c %d", &x, &y);
    x--;
    y--;
    if(grid[x][y]!= ' ') {
        printf("Invalid move!\n");
        displayGrid();
        getUserMove(ptr);
    }
    else {
        grid[x][y] = *turn;
    }
}
void swapTurn(char *turn) {
    if (*turn == 'X') {
        *turn == 'O';
    }
    else {
    *turn == 'X';
    }
}