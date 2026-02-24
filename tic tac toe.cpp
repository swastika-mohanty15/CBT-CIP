#include<iostream>
using namespace std;

char board[9];

void initBoard() {
    for (int i = 0; i < 9; ++i) board[i] = '1' + i; // '1'..'9'
}

void drawBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "-----------\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "-----------\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

bool isWin(char player) {
    // rows
    for (int r = 0; r < 3; ++r)
        if (board[r*3] == player && board[r*3+1] == player && board[r*3+2] == player)
            return true;
    // cols
    for (int c = 0; c < 3; ++c)
        if (board[c] == player && board[c+3] == player && board[c+6] == player)
            return true;
    // diagonals
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 9; ++i)
        if (board[i] != 'X' && board[i] != 'O') return false;
    return true;
}

int getMove(char player) {
    int pos;
    while (true) {
        cout << "Player " << player << " - enter position (1-9): ";
        if (!(cin >> pos)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        if (pos < 1 || pos > 9) {
            cout << "Choose a number between 1 and 9.\n";
            continue;
        }
        if (board[pos-1] == 'X' || board[pos-1] == 'O') {
            cout << "That cell is already taken. Pick another.\n";
            continue;
        }
        break;
    }
    return pos - 1;
}

int main() {
    cout << "=== Tic-Tac-Toe ===\nTwo players: X and O\n";
    initBoard();
    char current = 'X';

    while (true) {
        drawBoard();
        int move = getMove(current);
        board[move] = current;

        if (isWin(current)) {
            drawBoard();
            cout << "Player " << current << " wins! Congratulations!\n";
            break;
        }
        if (isDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            break;
        }
        // switch player
        current = (current == 'X') ? 'O' : 'X';
    }

    cout << "Thanks for playing!\n";
    cout<< "Developed by: Swastika Mohanty...\n";
    return 0;
}

