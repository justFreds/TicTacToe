// TIC TAC TOE game between 2 players or player vs computer
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


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
void getUserMove();
//function that gets computer move
void getCompMove();
//function that switches players turn
//void swapTurn(char *);
//check for game = win or draw
char checkGameOver();
void displayWinner(char);

int main () {
    //Declerations and initializations
    //prompt user game they wish to play
    char playAgain, winner = ' ';
    printf("Welcome user!\nTicTacToe\n");    

    //initializeGrid
    initializeGrid(); 
    
    //LOOP
    do {
            //displayGrid
            //get move
        while(winner == ' ' && checkFreeSpace() == 0) {
            displayGrid();
            getUserMove();
            winner = checkGameOver();
            if(winner != ' ' || checkFreeSpace == 0)
            break;

            getCompMove();
            winner = checkGameOver();
            if(winner != ' ' || checkFreeSpace == 0)
            break;
        }

            displayGrid();
            displayWinner(winner);

            printf("\nPlay again? (Y/N) ");
            scanf("%c", &playAgain);      
            //swapTurn(&USER);
        
    } while(playAgain == 'Y' || playAgain == 'y');
    //

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

void getUserMove() {
    
    int x, y;
    do {
    printf("Enter X coordinates for your move: ");
    scanf("%d", &x);
    x--;
    printf("Enter Y coordinates for your move: ");
    scanf("%d", &y);
    y--;
    if(grid[x][y] != ' ') {
        printf("Invalid move!\n");       
    }
    else {
        grid[x][y] = USER;
        break;
    }
    } while(grid[x][y]!= ' ');
}

/* void swapTurn(char *turn) {
    if (*turn == 'X') {
        *turn == 'O';
    }
    else {
    *turn == 'X';
    }
} */

int checkFreeSpace() {
    int spaces = 9;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] != ' ') {
                spaces--;
            }
        }
    }
    return spaces;
}

void getCompMove() {
    srand(time(0));
    int x, y;

    if(checkFreeSpace() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while(grid[x][y] != ' ');

        grid[x][y] = NPC;
    }
    else {
        displayWinner(' ');
    }
}

char checkGameOver() {
    //rows
    for(int i = 0; i < 3; i++) {
        if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) {
            return grid[i][0];
        }
    }
    //columns
    for(int i = 0; i < 3; i++) {
        if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) {
            return grid[0][i];            
        }
    }
    //diagnol    
   if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
        return grid[0][0];        
   }
   if(grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) {
        return grid[0][2];        
   }
   return ' ';
}

void displayWinner(char winner) {
    if(winner == USER) {
        printf("\nYou win!");
    }
    else if(winner == NPC) {
        printf("\nNPC wins!");
    }
    else {
        printf("\nIt's a draw!");
    }
}