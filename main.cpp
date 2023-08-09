#include <iostream>
using namespace std;

int main(){ //main=primary function

  int q[8][8] = {};// Initialize the board to 0
  int r = 0, c = 0;// Start in the 1st row, 1st column
  q[r][c] = 1; // Place the first queen on the upper left corner

nextCol:
  // Move to the next column
  c++;
  // If you passed the last column
      //goto print
  if (c == 8) goto print;
  r = -1; //start at row 0 bc r++ will start row after r=

nextRow:
  // testing rows
  r++;
  if (r == 8) goto backtrack;
  
    // row test: after 1st ^ backtracking and deleting queen
  for (int i = 0; i < c; i++){   //c = column we up to in program r=row upto    i = temporary clumn
    if (q[r][i] == 1) goto nextRow; //bc theres a queen on row, we cant put another on this row, we need to go to next row loop==== r++ */
  } //if passes test (no queen in row then goes to next test (diag)
  
// up diagonal test because no queen on same row
  
for (int i = 1; ((r-i)>=0 && (c-i)>=0); i++){ //only checks diagonal ON THE BOARD from 0-7
    if (q[r-i][c-i] == 1) goto nextRow;
  }
  // down diagonal test
  for (int i = 1; ((r+i)<8 && (c-i)>=0); i++){
    if (q[r+i][c-i] == 1) goto nextRow;
  }
  q[r][c] = 1;
  goto nextCol;

backtrack:
  // Move to previous column
  c--;
    //if move  to the left of the board
            //exit the program
      if (c == -1){ //this is when c becomes -1 the program endss
        return 0;
      }
      // Find the square in the column with a queen in it and set r to the row number of that square
      r = 0;
     
    // if theres no queen we increase row by 1 until we find queen (1) and make it 0 (empty)
    while (q[r][c] != 1){ //whenever theres an empty space then r++ (no queen)
        r++;
      }
      // Remove the queen from the current square
      q[r][c] = 0;
      //goto nextRow;
      goto nextRow;
    
    print:
      static int sol_num = 0;
      cout << "Solution #" << ++sol_num << ":\n";
      for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
          cout << q[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      goto backtrack;}
