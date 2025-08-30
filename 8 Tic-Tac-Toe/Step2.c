

// Check win & check draw

#include <stdio.h>
#include <stdlib.h>

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
int check_win();
int check_draw();

int main()
{

    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    input_difficulty();
    print_board(board);
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

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[2][0] == player && board[1][1] == player && board[0][2] == player))
    { // Cross
        return 1;
    }
    return 0;
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE])   // Always check after check win function
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
                ;
            {
                return 0;
            }
        }
    }
    return 1;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    clear_screen();
    printf("Score - Player Surya: %d , Computer : %d , Draw : %d", score.player, score.computer, score.draw);
    printf("\n Tic-Tac-Toe");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);

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

void input_difficulty()
{
    while (1)
    {
        printf("\nSelect difficulty level:");
        printf("\n1. Human (Standard)");
        printf("\n2. God (Impossible to win)");
        printf("\nEnter your choice: ");
        scanf("%d", &difficulty);

        if (difficulty != 1 && difficulty != 2)
        {
            printf("\nIncorrect choice enter (1/2)!!");
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
    system("cls");
#else
    system("clear");
#endif
}