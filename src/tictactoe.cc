#include <iostream>
#include <cstdio>

using namespace std;

int isGameOver(int board[]);

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
            printf("| O ");
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
//  int play = 0;
  int check;
  int wf[8][4] = {{1,2,3,0},{1,4,7,0},{1,5,9,0},{4,5,6,0},{2,5,8,0},{3,5,7,0},{7,8,9,0},{3,6,9,0}};
  for(int h=-1;h<2;h+=2) {
    for(int i=0;i<9;i++) {
      if(board[i]==0) {
        board[i]=h;
        check = isGameOver(board);
        board[i]=0;
        if(check!=0)
          return i;
      }
    }
  }

  if(board[4]==0)
      return 4;

  int min = 1000;
  int cand = -1;
  for(int i=0;i<9;i++) {
    if(board[i]!=0) continue;
    if(cand==-1) cand = i;
    board[i]=-1;
    int sum = 0;
    for(int j=0;j<8;j++) {
      wf[j][3]=0;
      for(int k=0;k<3;k++) {
        wf[j][3] = wf[j][3] + board[wf[j][k]-1];
      }
      sum += wf[j][3];
    }
    if(sum <= min) {
        min = sum;
        cand = i;
    }
    board[i]=0;
  }
  return cand;
}

int isGameOver(int board[]) {
  // Implement here. Return as following.
  //  0 - not over yet.
  //  1 - O win
  // -1 - X win
  // 1 2 3
  // 4 5 6
  // 7 8 9
  int check[8][3] = {{1,2,3},{1,4,7},{1,5,9},{4,5,6},{2,5,8},{3,5,7},{7,8,9},{3,6,9}};
  int win = 0;
  for(int i = 0; i < 8 ; i++) {
    win = 0;
    for(int j = 0; j < 3 ; j++) {
      //cout << board[check[i][j]-1] << " ";
      win += board[check[i][j]-1];
    }
    win = win / 3;
    //cout << " " << win;
    if(win!=0) return win;
    //cout << endl;
  }
  return 0;
}

int main() {
  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };
  //int board[9] = {0, 0, 0, 0, 0, 0, 1, 1, 1 };
  printBoard(board);

  //printf("%d\n", isGameOver(board));
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


