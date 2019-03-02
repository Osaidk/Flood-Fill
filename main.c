#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char grid[25][25];
int row=0;
int col=0;


void FloodFill(int Row, int Col, char OldColor, char NewColor)
{
    if (grid[Row][Col] == OldColor) {
        grid[Row][Col]=NewColor;

       if (Row+1<row){
           FloodFill(Row+1,Col,OldColor,NewColor);}
       if (Row+1<row && Col-1 >=0){
           FloodFill(Row+1,Col-1,OldColor,NewColor);}
       if (Row+1<row && Col+1 < col){
           FloodFill(Row+1,Col+1,OldColor,NewColor);}
       if (Col+1<col){
           FloodFill(Row,Col+1,OldColor,NewColor); }
       if (Row-1>=0) {
           FloodFill(Row-1,Col,OldColor,NewColor); }
       if (Row-1>=0 && Col-1>=0){
           FloodFill(Row-1,Col-1,OldColor,NewColor);}
       if (Row-1>=0 && Col+1 < col){
           FloodFill(Row-1,Col+1,OldColor,NewColor); }
       if (Col-1>=0) {
           FloodFill(Row,Col-1,OldColor,NewColor); }
    }
}
//int argc , char *argv[]

int main () {
    int entry_row = 0;
    int entry_col = 0;
    char old_color;
    char entry_color;


   // strcpy(fName, argv[1]);
    FILE *fptr;
    fptr = fopen("fake_picture.txt", "r");
    char buf[BUFSIZ];

    while (fscanf(fptr, "%s", buf) != EOF) {
        strcpy(grid[row], buf);
        row++;
    }

    col = strlen(grid[0]);
    for (int k = 0; k < row; k++) {
        printf("%s", grid[k]);
        printf("\n");
    }

  while (1) {
      printf("\n\nEnter Row Number : ");
      scanf("%d", &entry_row);
      printf("Enter Column Number: ");
      scanf("%d", &entry_col);
      printf("Enter Color: ");
      scanf("%s", &entry_color);

      old_color = grid[entry_row][entry_col];

      if ((entry_col==-1 || entry_row==-1)) { // This condition is for the termination code (-1)..
          printf("---------------------------");
          return 0;}
      if ((entry_col<0 || entry_row<0 || entry_row>row || entry_col>col)) { //This condition is for error entries, the (continue;) is to
          printf("Error! Your entries are out of bound! Try again.");      // prompt the user to try again instead of terminating the program all together
          continue; }

      FloodFill(entry_row, entry_col, old_color, entry_color);

      printf("\n");
      for (int k = 0; k < row; k++) {
          printf("%s", grid[k]);
          printf("\n");
      }

  }

}