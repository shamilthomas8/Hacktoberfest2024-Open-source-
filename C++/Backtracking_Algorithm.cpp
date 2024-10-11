#include <iostream>
#define N 8

int board[N][N];

// Knight's possible movements
int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to check if the move is valid
bool isValidMove(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Backtracking utility to solve the Knight's Tour problem
bool solveKTUtil(int x, int y, int movei) {
    if (movei == N * N) {
        return true;
    }

    for (int k = 0; k < 8; k++) {
        int nextX = x + moveX[k];
        int nextY = y + moveY[k];

        if (isValidMove(nextX, nextY)) {
            board[nextX][nextY] = movei;
            if (solveKTUtil(nextX, nextY, movei + 1)) {
                return true;
            } else {
                board[nextX][nextY] = -1;  // Backtracking
            }
        }
    }
    return false;
}

// Solving Knight's Tour problem using backtracking
bool solveKnightTour() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    // Starting the knight at the first block
    board[0][0] = 0;

    if (!solveKTUtil(0, 0, 1)) {
        std::cout << "Solution does not exist!";
        return false;
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                std::cout << board[i][j] << "\t";
            std::cout << std::endl;
        }
    }
    return true;
}

int main() {
    solveKnightTour();
    return 0;
}
