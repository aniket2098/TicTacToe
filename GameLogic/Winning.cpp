#include "Winning.h"

void Winning :: setGameBoard(int** board) {

    gameBoard = board; 
}

//Checks if any winning position is available orthogonally
int Winning :: isWinningOrthogonal(int player) {      

    int countHorizontal, countVertical, posHorizontal, posVertical, i, j; 
    
    for(i = 0; i < N; i++) {

        countHorizontal = 0;
        countVertical = 0;
        posHorizontal = -1;
        posVertical = -1;
        
        //count the horizontal and vertical occurences of the players moves
        for(j = 0;j < N; j++) {
            if(gameBoard[i][j] == player)
                countHorizontal++;
            else if(gameBoard[i][j] == 0)
                posHorizontal = j;
            if(gameBoard[j][i] == player)
                countVertical++;
            else if(gameBoard[j][i] == 0)
                posVertical = j;
        }

        if(countHorizontal == 2 && posHorizontal!=-1) {     //if more than two positions belong to the same player
            gameBoard[i][posHorizontal] = 1;
            return 1;
        }

        if(countVertical == 2 && posVertical!=-1) {
            gameBoard[posVertical][i] = 1;
            return 1;
        }

    }

    return 0;
}

//Checks if any winning position is available diagonally
int Winning :: isWinningDiagonal(int player) {

    int countDiagonal1, countDiagonal2, posDiagonal1, posDiagonal2, i, j; 

    countDiagonal1 = 0;
    countDiagonal2 = 0;
    posDiagonal1 = -1;
    posDiagonal2 = -1;

    //count the diagonal occurences of the players moves
    for(i = 0; i < N; i++) {
        
        if(gameBoard[i][i] == player)
            countDiagonal1++;
        else if(gameBoard[i][i] == 0)
            posDiagonal1 = i;
        if(gameBoard[i][N-i-1] == player)
            countDiagonal2++;
        else if(gameBoard[i][N-i-1] == 0)
            posDiagonal2 = i;

    }

    if(countDiagonal1 == 2 && posDiagonal1!=-1) {       //if more than two positions belong to the same player
        gameBoard[posDiagonal1][posDiagonal1] = 1;
        return 1;
    }

    if(countDiagonal2 == 2 && posDiagonal2!=-1) {
        gameBoard[posDiagonal2][N-posDiagonal2-1] = 1;
        return 1;
    }

    return 0;
}

int Winning :: isWinning(int player) {

    if(isWinningOrthogonal(player)) 
        return 1;

    if(isWinningDiagonal(player)) 
        return 1;

    return 0;
}