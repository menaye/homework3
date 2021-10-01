#include "print_functions.h"
#include <stdio.h>

/**
 * \file print_functions.c
 * \brief Provides print-related functionalities
 *
 * \details This source file implements all print-related functionalities for printing the maze, solution, and errors
 */

// The function to print the maze
void printMaze(char maze[][200], const int maze_width, const int maze_height) {
  printf("Maze: %d, %d\n", maze_width, maze_height);
  for (int i = 0; i < maze_height; i++) {
    for (int j = 0; j < maze_width; j++) {
      if (j + 1 == maze_width) {
	printf("%c\n", maze[i][j]);
      }
      else {
	printf("%c", maze[i][j]);
      }
    }
  }
}

// The function to print the maze's solution
void printSolution(char maze[][200], const int maze_width, const int maze_height, char sol[][200]) {
  // TODO: implement this function
  int sol_found = 0;
  for (int i = 0; i < maze_height; i++) {
    for (int j = 0; j < maze_width; j++) {
      if ((sol[i][j] == '<') && (sol[i - 1][j] && sol[i + 1][j] && sol[i][j + 1] && sol[i][j - 1] != 'O')) {
	sol_found = 1;
	printf("Info: ");
	printError(1);
      }
    }
  }
  if (sol_found == 0) {
    for (int i = 0; i < maze_height; i++) {
    for (int j = 0; j < maze_width; j++) {
        printf("Solution path (*):\n");
            if (sol[i][j] == 'O') {
              maze[i][j] = '*';
        }
    }
    }
        printMaze(maze, maze_width, maze_height);
  }
}
    
      

// The function to print the error message
void printError(const int return_code) {
  // TODO: implement this function
  switch (return_code) {
  case 1:
    printf("No solution found for the input maze\n");
    break;
  case 2:
    printf("Wrong usages - i.e. invalid number of arguments\n");
    break;
  case -1:
    printf("Cannot open the file to read\n");
    break;
  case -2:
    printf("File read errors\n");
    break;
  case -3:
    printf("Invalid parameters\n");
    break;
  case -4:
    printf("Cannot open the file to write\n");
    break;
  case -5:
    printf("File write errors\n");
    break;
  }
}
