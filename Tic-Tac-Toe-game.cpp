// the Tic-Tac-Toe board game


#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    cout << " -------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << "|";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << "|";
        }
        cout << endl;
        cout << " -------" << endl;
    }
}

// Function to check if the game is over
bool isGameOver(const vector<vector<char>>& board) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals for a win
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') return false;
        }
    }
    return true;
}

// Function to handle player's move
void playerMove(vector<vector<char>>& board, char player) {
    int row, col;
    cout << "Player " << player << "'s turn. Enter row and column (1-3): ";
    cin >> row >> col;
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-') {
        cout << "Invalid move. Enter row and column (1-3): ";
        cin >> row >> col;
    }
    board[row - 1][col - 1] = player;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '-'));

    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X | Player 2: O" << endl;
    cout << "-------------------------" << endl;

    while (!isGameOver(board)) {
        drawBoard(board);
        playerMove(board, currentPlayer);
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    drawBoard(board);
    if (isGameOver(board)) {
        cout << "Game Over!" << endl;
        if (currentPlayer == 'X') {
            cout << "Player O wins!" << endl;
        } else {
            cout << "Player X wins!" << endl;
        }
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

