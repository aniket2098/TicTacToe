#include "GameOver.h"

#define N 3

//initializes gameBoard
void GameOver :: setGameBoard(int** board) {    

    gameBoard = board;

}

//checks if all positions are occupied
int GameOver :: gameBoardFull() {   

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(gameBoard[i][j] == 0)
                return 0;
    return 3;

}

//checks whether any player has won the game
//either horizontally or vertically
int GameOver :: gameOverOrthogonal() {      

    int i, j;

    for(i = 0; i < N; i++) {
        
        for(j = 0; j < N-1; j++)            //checks rows
            if(gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j]!=0)
                continue;
            else
                break;
        if(j == N-1)
            return gameBoard[i][j-1];
        
        for(j = 0; j < N-1; j++)            //checks columns
            if(gameBoard[j][i] == gameBoard[j+1][i] && gameBoard[j][i]!=0)
                continue;
            else 
                break;
        if(j == N-1)
            return gameBoard[j-1][i];

    }
    
    return 0;
}

//checks whether a player has won the game diagonally
int GameOver :: gameOverDiagonal() {        

    int i, j;

    for(i = 0; i < N-1; i++)                //checks diagonal 0 0 to N N
        if(gameBoard[i][i] == gameBoard[i+1][i+1] && gameBoard[i][i]!=0)
            continue;
        else
            break;
        if(i == N-1)
            return gameBoard[0][0];
    
    for(i = 0; i < N-1; i++)                //checks the other diagonal 
        if(gameBoard[i][N-i-1] == gameBoard[i+1][N-i-2] && gameBoard[i][N-i-1]!=0)
            continue;
        else
            break;
        if(i == N-1)
            return gameBoard[i][N-i-1];

    return 0;
}


int GameOver :: gameOver() {
    
    int result;

    if(result = gameOverDiagonal())
        return result;

    if(result = gameOverOrthogonal())
        return result;

    if(result = gameBoardFull())
        return result;

    return 0;
}