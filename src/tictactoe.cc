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


//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//char toSymbol(int board[], int index) {
//  if (board[index] > 0) { return 'O'; }
//  else if (board[index] < 0) { return 'X'; }
//  else { return index + '1'; }
//}
//void printBoard(int board[]) {
//  printf("+---+---+---+\n");
//  printf("+ %c + %c + %c +\n",
//	 toSymbol(board, 0), toSymbol(board, 1), toSymbol(board, 2));
//  printf("+---+---+---+\n");
//  printf("+ %c + %c + %c +\n",
//	 toSymbol(board, 3), toSymbol(board, 4), toSymbol(board, 5));
//  printf("+---+---+---+\n");
//  printf("+ %c + %c + %c +\n",
//	 toSymbol(board, 6), toSymbol(board, 7), toSymbol(board, 8));
//  printf("+---+---+---+\n");
//}
//
//int playO(int board[]) {
//  int play = 0;
//  do {
//    cout << "Enter number for O: ";
//    cin >> play;
//    if (play < 1 || play > 9) {
//      cout << "Invalid play!\n";
//      continue;
//    }
//    play -= 1;
//    if (board[play] != 0) {
//      cout << "You cannot play here!\n";
//      continue;
//    }
//    break;
//  } while (true);
//  return play;
//}
//
//int playX(int board[]) {
//  int play = 0;
//  do {
//    cout << "Enter number for X: ";
//    cin >> play;
//    if (play < 1 || play > 9) {
//      cout << "Invalid play!\n";
//      continue;
//    }
//    play -= 1;
//    if (board[play] != 0) {
//      cout << "You cannot play here!\n";
//      continue;
//    }
//    break;
//  } while (true);
//  return play;
//}
//
//int isGameOver(int board[]) {
//  // Implement here. Return as following.
//  //  0 - not over yet.
//  //  1 - O win
//  // -1 - X win
//  return 0;
//}
//
//int main() {
//  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };
//  printBoard(board);
//  for (int i = 0;; ++i) {
//    int play = 0;
//    if (i % 2 == 0) {
//      play = playO(board);
//      board[play] = 1;
//    } else {
//      play = playX(board);
//      board[play] = -1;
//    }
//    printBoard(board);
//    int game_over = isGameOver(board);
//    if (game_over > 0) {
//      cout << "O win!\n";
//      break;
//    }
//    if (game_over < 0) {
//      cout << "X win!\n";
//      break;
//    }
//  }
//}
