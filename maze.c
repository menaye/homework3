#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * \file maze.c
 * \brief Provides maze-related functionalities
 *
 * \details This source file implements all maze-related functionalities for reading/writing/solving/generating the maze and releasing related memories.
 */

/* The function to read the maze from a file given the filename, maze
   array, maze width and maze height: open file, read sizes, read maze, close file
*/
// TODO: write the entirety of this readMaze function
int readMaze(char* argv[], char maze[][200], int maze_width, int maze_height) {
  FILE* input = fopen(argv[1], "r");
  if (input == NULL) {
    return -1;
  }
  char print = '0';
  fscanf(input, "%d", &maze_width);
  fscanf(input, "%d", &maze_height);
  printf("%d\n %d\n", maze_width, maze_height);
  for (int i = 0; i < maze_height; i++) {
    for (int j = 0; j < maze_width + 1; j++) {
      fscanf(input, "%c", &maze[i][j]);
       if (ferror(input)) {
       return -2;
  }
       else {

      printf("%c", maze[i][j]);
       }

    }
  }
  printf("\n");
  fclose(input);
  return 0;
}
    
      
/* The function to write the maze to a file given the filename, maze
   array, maze width and maze height: open file, write maze, close file
*/
// TODO: write the entirety of this writeMaze function
int writeMaze(char* argv[], char maze[][200], int maze_width, int maze_height) {
  FILE* output = fopen(argv[1], "w");
  if (argv[1] == NULL) {
    return -4;
  }
  fprintf(output, "%d %d\n", maze_width, maze_height);
  for (int i = 0; i < maze_height; i++) {
    for (int j = 0; j < maze_width; j++) {
      if (j + 1 == maze_width) {
	fprintf(output, "%c\n", maze[i][j]);
      }
      else {
	fprintf(output, "%c", maze[i][j]);
      }
  if (ferror(output)) {
    return -5;
  }
    }
  }
  fclose(output);
  return 0;
}
 

// The function to solve a solution path for the maze
int solveMaze(char maze[][200], const int maze_width, const int maze_height, char sol[][200]) {
  // TODO: implement this function
   int start_row = 0;
  int start_col = 0;
  for (int i = 0; i < maze_height; i++) {
    for (int j = 0; j < maze_width; j++) {
      if (maze[i][j] == '@') {
        start_row = i;
        start_col = j;
      }
    }
  }

  return solvePath(maze, maze_width, maze_height, start_col, start_row, sol); // TODO: replace this stub
}

// The function to solve a solution path recursively
int solvePath(char maze[][200], const int maze_width, const int maze_height, const int col, const int row, char sol[][200]) {
  // TODO: implement this function
  int col_pos = col;
  int row_pos = row;
  for (int i = 0; i < maze_height; i++) {
    for (int j = 0; j < maze_width; j++) {
      if (sol[i][j] == ' ') {
      sol[i][j] = 'X';
      }
    }
 }
  if (sol[row][col] == '<') {
  return 0;
  }
  else if ((sol[row][col - 1] && sol[row][col + 1] && sol[row - 1][col] && sol[row + 1][col]) == ('#' || 'O')) {
    return 1;
  }
  else {
    if (sol[row][col - 1] != ("#" || 'O')) {
    sol[row][col - 1] = 'O';
    col_pos--;
    }
    else if (sol[row][col + 1] != ("#" || 'O')) {
      sol[row][col + 1] = 'O';
      col_pos++;
    }
    else if (sol[row - 1][col] != ("#" || 'O')) {
      sol[row - 1][col] = 'O';
      row_pos--;
    }
    else if (sol[row + 1][col] != ("#" || 'O')) {
      sol[row + 1][col] = 'O';
      row_pos++;
    }
    return solvePath(maze, maze_width, maze_height, col_pos, row_pos, sol);
  }
    
    
    
    // TODO: replace this stub
}
// The function to generate a maze (given)
void genMaze(char maze[][200], const int maze_width, const int maze_height, const double threshold, const int seed) {
  // set random seed
  srand(seed);
  // gen start and end positions
  int start_x = rand() % (maze_width - 2) + 1;
  int start_y = rand() % (maze_height - 2) + 1;
  int end_x = rand() % (maze_width - 2) + 1;
  int end_y = rand() % (maze_height - 2) + 1;
  // gen maze
  for (int r = 0; r < maze_height; ++r) {
    for (int c = 0; c < maze_width; ++c) {
      if (r == 0 || c == 0 || r == maze_height - 1 || c == maze_width - 1) maze[r][c] = '#';
      else if (c == start_x && r == start_y) maze[r][c] = '@';
      else if (c == end_x && r == end_y) maze[r][c] = '<';
      else {
        double rand_value = rand() / (double) RAND_MAX;
        if (rand_value >= threshold) maze[r][c] = '#';
        else maze[r][c] = ' ';
      }
    }
  }
}

