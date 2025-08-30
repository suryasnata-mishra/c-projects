
// 2 players Tic-Tac-Toe game
// Game play k lie function

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 'X'
#define O 'O'
#define BOARD_SIZE 3

typedef struct
{
    int player;
    int computer;
    int draw;
} Score;

int difficulty;
Score score = {.player = 0, .computer = 0, .draw = 0};

void input_difficulty();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE] , char player);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE] , char player);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE] , int row , int column);

int main()
{
    srand(time(NULL));
    int choice;
    input_difficulty(); // first this will be printed
    do
    {
        play_game();                                             // One game will be played by this function
        printf("\nWant to play again ? (1 for Yes , 0 for No)"); // Then will ask for to play or not
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\nBye bye , Thanks for playing !");
}

void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    char current_player = rand() % 2 == 0 ? 'X' : 'O'; // or if-else
    print_board(board);

    while (1)
    {
        
        if (current_player == X)
        {
            player_move(board , X);
            print_board(board);
            if (check_win(board, X))
            {
                score.player++;
                print_board(board);
                printf("Congo , You have won !!!");
                break;
            }
            current_player = O;
        }
        else
        {
            computer_move(board , O);
            print_board(board);
            if (check_win(board, O))
            {
                score.computer++;
                print_board(board);
                printf("Better luck next time !");
                break;
            }
            current_player = X;
        }
        if(check_draw(board)){
          score.draw++;
          print_board(board);
          printf("\nIt's a draw !");
          break;
        }
    }
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE] , int row , int col){
    return !(row < 0 || col < 0 || row > 2 || col > 2 || board[row][col] != ' ');

}

void player_move(char board[BOARD_SIZE][BOARD_SIZE] , char player)
{
    int row , col;
    do{
        printf("\n Player %c's turn . " , player);
        printf("\nEnter row & column (1-3) for %c : " , player);
        scanf("%d" , &row);
        scanf("%d" , &col);
        // user has given in (1-3) range , we will convert to (0-2) .... Converting to 0 based
        row--; 
        col--;
    } while(!is_valid_move(board , row , col));
    
    board[row][col] = player;
}
void computer_move(char board[BOARD_SIZE][BOARD_SIZE] , char player)
{
    player_move(board , player);
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        { // For raw
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        { // For column
            return 1;
        }
    }

    // For Cross
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[2][0] == player && board[1][1] == player && board[0][2] == player))
    {
        return 1;
    }
    return 0;
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE]) // Always check after check win function
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')

            {
                return 0; // Not draw , Immediately Exit !
            }
        }
    }
    return 1; // Draw case
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  clear_screen();
  printf("Score - Player X: %d, Computer: %d, Draws: %d", score.player, score.computer, score.draw);
  printf("\nTic-Tac-Toe\n");

  for (int i = 0 ; i < BOARD_SIZE; i++) {
    printf("\n");
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(" %c ", board[i][j]);
      if (j < BOARD_SIZE - 1) {
        printf("|");
      }
    }
    if (i < BOARD_SIZE - 1) {
      printf("\n---+---+---");
    }
  }
  printf("\n\n");
}

void input_difficulty()
{
    while (1)
    {
        printf("\nSelect difficulty level:");
        printf("\n1. Human (Standard)");
        printf("\n2. God (Impossible to win");
        printf("\nEnter your choice: ");
        scanf("%d", &difficulty);

        if (difficulty != 1 && difficulty != 2)
        {
            printf("\nIncorrect choice please enter (1/2)");
        }
        else
        {
            break;
        }
    };
}

void clear_screen()
{
#ifdef _Win32
    system("clear");
#else
    system("cls");
#endif
}