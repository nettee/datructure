#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NQUEEN 8

int board[NQUEEN];
int nsolution = 0;

void init_board()
{
    memset(board, 0, NQUEEN * sizeof(int));
}

void print_board()
{
    printf("[");
    for (int i = 0; i < NQUEEN; i++) {
        printf("%d%s", board[i]+1, (i == NQUEEN-1) ? "]\n" : ", ");
    }
}

bool can_place(int k)
{
    for (int i = 0; i < k; i++) {
        if (board[i] == board[k]  // same column
                || k + board[i] == board[k] + i  // main diagonal
                || k + board[k] == i + board[i]) {
            return false;
        }
    }
    //printf("can place queen[%d] at column %d\n", k, board[k]);
    return true;
}

void queen(int n)
{
    for (int i = 0; i < NQUEEN; i++) {
        board[n] = i;
        if (can_place(n)) {
            if (n == NQUEEN - 1) {  // the eighth queen can place
                ++nsolution;
                print_board();
                return;
            } else {
                queen(n+1);
            }
        }
    }
    return;  // all columns cannot place
}

int main()
{
    init_board();
    queen(0);
    printf("%d solutions.\n", nsolution);
    return 0;
}
