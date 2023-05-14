#include "tictactoe.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void initBoard(TicTacToe **game, int boardSize)
{
    *game = malloc(sizeof(TicTacToe));

    (*game)->boardSize = boardSize;
    int winningSequencesCount = 2 * boardSize + 2;
    (*game)->playerAMoves = malloc(sizeof(int) * winningSequencesCount);
    (*game)->playerBMoves = malloc(sizeof(int) * winningSequencesCount);

    for (int i = 0; i < winningSequencesCount; i++)
    {
        (*game)->playerAMoves[i] = 0;
        (*game)->playerBMoves[i] = 0;
    }
}

int performMoves(TicTacToe *game, Move *moves, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        int columnIndex = moves[i].column - 1;
        int rowIndex = moves[i].row + game->boardSize - 1;

        int *playerMoves = moves[i].player == 1 ? game->playerAMoves : game->playerBMoves;

        playerMoves[columnIndex]++;
        playerMoves[rowIndex]++;

        if (moves[i].column == moves[i].row)
            playerMoves[2 * game->boardSize]++;

        if (moves[i].column == game->boardSize - moves[i].row + 1)
            playerMoves[2 * game->boardSize + 1]++;
    }

    for (int j = 0; j < 2 * game->boardSize + 2; j++)
    {
        printf("Player A index value: %i \n", game->playerAMoves[j]);
        printf("Player B index value: %i \n\n", game->playerBMoves[j]);

        if (game->playerAMoves[j] == 3)
            return 1;
        if (game->playerBMoves[j] == 3)
            return 2;
    }

    return 0;
}

void deleteBoard(TicTacToe* game){
    free(game->playerAMoves);
    free(game->playerBMoves);
    free(game);
}