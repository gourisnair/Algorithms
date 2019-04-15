#include<stdio.h>
#define size 9

int m[9][9] = {
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,0,5,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,5,0,3},
    {5,7,8,3,0,1,0,2,6},
    {2,0,0,0,4,8,9,0,0},
    {0,9,0,6,2,5,0,8,1}
};

void printSudoku() {
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d", m[i][j]);
    }
    printf("\n");
  }
}

int isVacant(int *row, int *col) {
  int i, j;
  int vacant = 0;
  for(i = 0; i < size; i++) {
    for(j = 0; j < size; j++) {
      if(m[i][j] == 0) {
          *row = i;
          *col = j;
          vacant = 1;
          return vacant;
      }
    }
  }
  return vacant;
}

int isSafe(int num, int r, int c) {
  int i, j;
  for(i = 0; i < size; i++) {
    if(m[i][c] == num) {
      return 0;
    }
  }

  for(j = 0; j < size; j++) {
    if(m[i][j] == 0) {
      return 0;
    }
  }

  int row_sub = (r/3)*3;
  int col_sub = (c/3)*3;
  for(i = row_sub; i < row_sub + 3; i++) {
    for(j = col_sub; i < col_sub + 3; i++) {
      if(m[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int solveSudoku() {
  int row, col, num, i;
  if(!isVacant(&row, &col)) {
    return 1;
  }
  for(i = 0; i < size; i++) {
    if(isSafe(i, row, col)) {
      m[row][col] = i;
      if(solveSudoku()) {
        return 1;
      }
      m[row][col] = 0;
    }
  }
  return 0;
}

int main() {

  if(solveSudoku()) {
    printSudoku();
  } else {
    printf("Invalid Sudoku");
  }
  return 0;
}
