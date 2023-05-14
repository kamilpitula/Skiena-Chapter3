#include <stddef.h>

typedef struct
{
    int *playerAMoves;
    int *playerBMoves;
    int boardSize;
} TicTacToe;

typedef struct
{
    int column;
    int row;
    int player;
} Move;

extern void initBoard(TicTacToe **game, int boardSize);
extern int performMoves(TicTacToe *game, Move *moves, size_t len);
extern void deleteBoard(TicTacToe* game);