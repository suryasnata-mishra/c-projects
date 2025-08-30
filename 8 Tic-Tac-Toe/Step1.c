
// Menu & Board

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