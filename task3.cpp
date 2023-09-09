#include <iostream>
#include <vector>
using namespace std;
class TicTacToe {
public:
    TicTacToe() : currentPlayer('X'), gameWon(false), gameDraw(false) {
        board = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
    }

    void displayBoard() {
        cout << "  1   2   3" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < 2) {
                    cout << "|";
                }
            }
            cout << endl;
            if (i < 2) {
                cout << "  ---+---+---" << endl;
            }
        }
        cout << endl;
    }

    bool isValidMove(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                gameWon = true;
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                gameWon = true;
                return true;
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            gameWon = true;
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            gameWon = true;
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        gameDraw = true;
        return true;
    }

    void switchPlayers() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;

        while (!gameWon && !gameDraw) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (isValidMove(row - 1, col - 1)) {
                makeMove(row - 1, col - 1);
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }
                if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!" << endl;
                    break;
                }
                switchPlayers();
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

private:
    char currentPlayer;
    vector<vector<char>> board;
    bool gameWon;
    bool gameDraw;
};

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        TicTacToe game;
        game.play();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
