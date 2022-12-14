#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

int check_game_over();
void print_board();

int main() {
  int i, j;
  int game_over = 0;
  int player = 1;

  // Initialize the game board
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
  while (!game_over) {
    int row, col;

    // Print the game board
    print_board();

    // Get input from the player
    printf("Player %d, enter row and column (1-%d): ", player, BOARD_SIZE);
    scanf("%d%d", &row, &col);
    row--;
    col--;
    // Update the game board
    if (player == 1) {
      board[row][col] = 'X';
    } else {
      board[row][col] = 'O';
    }

    // Check if the game is over
    game_over = check_game_over();

    // Switch to the other player
    player = (player == 1) ? 2 : 1;
  }
  // Print the final game board
  print_board();

  // Print the result
  if (game_over == 1) {
    printf("Player %d wins!\n", player);
  } else if (game_over == 2) {
    printf("It's a draw!\n");
  }

  return 0;
}

int check_game_over() {
  int i, j;
  // Check for a horizontal win
  for (i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    char prev = ' ';
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == prev && prev != ' ') {
        count++;
      }
      prev = board[i][j];
    }
    if (count == BOARD_SIZE - 1) {
      return 1;
    }
  }
  // Check for a vertical win
  for (i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    char prev = ' ';
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[j][i] == prev && prev != ' ') {
        count++;
      }
      prev = board[j][i];
    }
    if (count == BOARD_SIZE - 1) {
      return 1;
    }
  }
  // Check for a diagonal win
  int count = 0;
  char prev = ' ';
  for (i = 0; i < BOARD_SIZE; i++) {
    if (board[i][i] == prev && prev != ' ') {
      count++;
    }
    prev = board[i][i];
  }
  if (count == BOARD_SIZE - 1) {
    return 1;
  }

  count = 0;
  prev = ' ';
  for (i = 0; i < BOARD_SIZE; i++) {
    if (board[i][BOARD_SIZE - i - 1] == prev && prev != ' ') {
      count++;
    }
    prev = board[i][BOARD_SIZE - i - 1];
  }
  if (count == BOARD_SIZE - 1) {
    return 1;
  }
  // Check for a draw
  int empty_cells = 0;
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        empty_cells++;
      }
    }
  }
  if (empty_cells == 0) {
    return 2;
  }

  // The game is not over
  return 0;
}
void print_board() {
  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      printf("%c |", board[i][j]);
    }
    printf("\n");
  }
}
