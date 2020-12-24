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

int playO(int board[]) {
  int play = 0;
  do {
    cout << "Enter number for O: ";
    cin >> play;
    if (play < 1 || play > 9) {
      cout << "Invalid play!\n";
      continue;
    }
    play -= 1;
    if (board[play] != 0) {
      cout << "You cannot play here!\n";
      continue;
    }
    break;
  } while (true);
  return play;
}

int playX(int board[]) {
  int play = 0;
  do {
    cout << "Enter number for X: ";
    cin >> play;
    if (play < 1 || play > 9) {
      cout << "Invalid play!\n";
      continue;
    }
    play -= 1;
    if (board[play] != 0) {
      cout << "You cannot play here!\n";
      continue;
    }
    break;
  } while (true);
  return play;
}

int isGameOver(int board[]) {
    int GameOver = 0;
    int sum;
    // -->
    for(int i = 0; i <=6; i +=3) {
        sum =  board[i] + board[i+1] + board[i+2];
        if (abs(sum) == 3) {
            return sum/3;
        } 
    }
    // V
    for (int i = 0; i <=3; i++) {
        sum =  board[i] + board[i+3] + board[i+6];
        if (abs(sum) == 3) {
            return sum/3;
        } 
    }
    // X
    sum = board[0] + board[4] + board[8];
    if (abs(sum) == 3) {
        return sum/3;
    }

    sum = board[2] + board[4] + board[6];
    if (abs(sum) == 3) {
        return sum/3;
    }

    return 0;
  // Implement here. Return as following.
  //  0 - not over yet.
  //  1 - O win
  // -1 - X win
  //return 0;
}

int main() {
  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };
  printBoard(board);
  for (int i = 0;; ++i) {
    int play = 0;
    if (i % 2 == 0) {
      play = playO(board);
      board[play] = 1;
    } else {
      play = playX(board);
      board[play] = -1;
    }
    printBoard(board);
    int game_over = isGameOver(board);
    if (game_over > 0) {
      cout << "O win!\n";
      break;
    }
    if (game_over < 0) {
      cout << "X win!\n";
      break;
    }
  }
}

