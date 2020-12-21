#include <iostream>
#include <cstdio>

using namespace std;

// When the board has no plays.
// Put the indexes in each box.
// +---+---+---+
// | 1 | 2 | 3 |
// +---+---+---+
// | 4 | 5 | 6 |
// +---+---+---+
// | 7 | 8 | 9 |
// +---+---+---+
//
// When the board has plays.
// Put O or X using the values in board.
//  0 -> None
//  1 -> O
// -1 -> X
// For example,
// int board[9] = {0, -1, -1, 0, 1, 0, 1, -1, 1 };
// +---+---+---+
// | 1 | X | X |
// +---+---+---+
// | 4 | O | 6 |
// +---+---+---+
// | O | X | O |
// +---+---+---+
void printBoard(int board[]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            printf("+---+---+---+\n");
        }
        if (board[i] == 0) {
            printf("| %d ", i + 1);
        }
        else if(board[i] == -1) {
            printf("| X ");
        }
        else if(board[i] == 1) {
            printf("| 0 ");
        }
        if (i%3 == 2) {
            printf("| \n");
        }     
    }   
    printf("+---+---+---+\n");
}

int main() {
  //int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };

  int board[9] = {0, -1, -1, 0, 1, 0, 1, -1, 1 };
  printBoard(board);
}
