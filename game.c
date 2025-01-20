#include <stdio.h>
#include <stdlib.h>

// Function declarations
void drawBoard(char board[3][3]);
int checkWinner(char board[3][3]);
int isBoardFull(char board[3][3]);
void playerMove(char board[3][3], char player);

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer = 'X';
    int winner = 0;

    printf("Tic-Tac-Toe Game!\n");
    drawBoard(board);

    while (!winner && !isBoardFull(board)) {
        playerMove(board, currentPlayer);
        drawBoard(board);
        winner = checkWinner(board);

        if (winner == 1) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        } else if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function to draw the game board
void drawBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
            if (j != 2) printf("|");
        }
        printf("\n");
        if (i != 2) printf("--|---|--\n");
    }
    printf("\n");
}

// Function to check if any player has won
int checkWinner(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Function to check if the board is full
int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

// Function to handle player's move
void playerMove(char board[3][3], char player) {
    int move;
    int validMove = 0;
    while (!validMove) {
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &move);
        move--; // Adjust for 0-based indexing
        int row = move / 3;
        int col = move % 3;

        if (move >= 0 && move < 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            validMove = 1;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}
