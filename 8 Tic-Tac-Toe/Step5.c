// Modified 2 players Tic-Tac-Toe game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 'X'
#define O 'O'
#define BOARD_SIZE 3

typedef struct
{
    int playerX;
    int playerO;
    int draw;
} Score;

Score score = {.playerX = 0, .playerO = 0, .draw = 0};

void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE], char current_player);

int main()
{
    srand(time(NULL));
    int choice;

    do
    {
        play_game();
        printf("\nWant to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\nBye bye, thanks for playing!\n");
    return 0;
}

void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char current_player = (rand() % 2 == 0) ? X : O;
    while (1)
    {
        print_board(board);
        player_move(board, current_player);

        if (check_win(board, current_player))
        {
            print_board(board); // Display winning board
            if (current_player == X)
            {
                score.playerX++;
                printf("Player X wins!\n");
            }
            else
            {
                score.playerO++;
                printf("Player O wins!\n");
            }
            break;
        }

        if (check_draw(board))
        {
            print_board(board); // Display final board on draw
            score.draw++;
            printf("It's a draw!\n");
            break;
        }

        current_player = (current_player == X) ? O : X;
    }
    print_board(board); // Show final board and updated scores

    if (score.playerX > score.playerO)
    {
        printf("\nPlayer X is leading!\n");
    }
    else if (score.playerO > score.playerX)
    {
        printf("\nPlayer O is leading!\n");
    }
    else
    {
        printf("\nIt's a tie overall!\n");
    }
}

void player_move(char board[BOARD_SIZE][BOARD_SIZE], char current_player)
{
    int empty_count = 0, last_row = -1, last_col = -1;

    // Count empty spaces and track the last empty slot
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                empty_count++;
                last_row = i;
                last_col = j;
            }
        }
    }

    // If only one slot is left, auto-fill it
    if (empty_count == 1)
    {
        board[last_row][last_col] = current_player;
        printf("\nOnly one slot left! Automatically placing %c at (%d, %d)\n", current_player, last_row + 1, last_col + 1);
        return;
    }

    int row, col;
    while (1)
    {
        printf("Player %c, enter your move (row and column 1-3): ", current_player);
        if (scanf("%d %d", &row, &col) != 2)
        {
            while (getchar() != '\n'); // Clear input buffer
            printf("Invalid input, please enter numbers between 1-3.\n");
            continue;
        }

        row--;
        col--; // Convert to zero-based index

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ')
        {
            board[row][col] = current_player;
            break;
        }
        else
        {
            printf("Invalid move, try again!\n");
        }
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[2][0] == player && board[1][1] == player && board[0][2] == player))
        return 1;
    return 0;
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    clear_screen();
    printf("Score - Player X: %d, Player O: %d, Draw: %d\n", score.playerX, score.playerO, score.draw);
    printf("\n   Tic-Tac-Toe\n\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }
        if (i < BOARD_SIZE - 1)
        {
            printf("\n---+---+---");
        }
    }
    printf("\n\n");
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
