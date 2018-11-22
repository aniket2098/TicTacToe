#include<bits/stdc++.h>
#include "Game.h"

#define N 3

using namespace std;

Game :: Game() {

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            gameBoard[i][j] = 0;

    decisionTree = movesTree.returnHead();
    state = decisionTree;
    movesTree.createDecisionTree1();
    flag = 0;
}

void Game :: initialMove(int player) {

    int row, column, i;
    gameBoard[0][0] = 1;
    showBoard();
    cout<<"Enter your move :: ";
    cin>>row>>column;
    gameBoard[row][column] = 2;    
    showBoard();
    if(column < row)
        flag = 1;
    for(i = 0; i < 5; i++) {
        state = decisionTree->link[i];
        if(!flag)
        {
            if(state->row == row && state->column == column)
                break;
        }else
            if(state->row == column && state->column == row)
                break;        
    }
    state = state->link[0];

}

void Game :: showBoard() {

    cout<<endl;
    cout<<"\t     0   1   2\n\t    -----------\n";
    for(int i = 0; i < N; i++)
    {
        cout<<"\t "<<i<<" |";
        for(int j = 0; j < N; j++)
        {
            if(gameBoard[i][j] == 1)
                cout<<" X |";
            else if(gameBoard[i][j] == 2)
                cout<<" O |";
            else 
                cout<<"   |";
        }
        cout<<endl<<"\t    -----------\n";
    }
        cout<<endl;
}

void Game :: instructions() {

    char choice;
    cout<<"\n\n\tX :: Computer\n\n\tO :: Player\n\n\tEnter your input in the following format :: Row Column\n";

}

int Game :: isWinningOrthogonal(int player) {

    int countHorizontal, countVertical, posHorizontal, posVertical, i, j; 
    
    for(i = 0; i < N; i++) {

        countHorizontal = 0;
        countVertical = 0;
        posHorizontal = -1;
        posVertical = -1;
        
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

        if(countHorizontal == 2 && posHorizontal!=-1) {
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

int Game :: isWinningDiagonal(int player) {

    int countDiagonal1, countDiagonal2, posDiagonal1, posDiagonal2, i, j; 

    countDiagonal1 = 0;
    countDiagonal2 = 0;
    posDiagonal1 = -1;
    posDiagonal2 = -1;

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

    if(countDiagonal1 == 2 && posDiagonal1!=-1) {
        gameBoard[posDiagonal1][posDiagonal1] = 1;
        return 1;
    }

    if(countDiagonal2 == 2 && posDiagonal2!=-1) {
        gameBoard[posDiagonal2][N-posDiagonal2-1] = 1;
        return 1;
    }

    return 0;
}

int Game :: isWinning(int player) {

    if(isWinningOrthogonal(player)) 
        return 1;

    if(isWinningDiagonal(player)) 
        return 1;

    return 0;
}

void Game :: play() {

    int row, column, i, j;
    initialMove(1);
    for(int i = 2; i < N*N; i++) {

        if(!isWinning(1) && !isWinning(2))
        {
            
            if(state!=NULL) {
                if(!flag)
                    gameBoard[state->row][state->column] = 1;
                else{
                    gameBoard[state->column][state->row] = 1;
                }
                state = state->link[0];
            }
            else {
                
                for(i = 0; i < N; i++)
                {
                    for(j = 0;j < N; j++)
                        if(gameBoard[i][j] == 0)
                        {
                            gameBoard[i][j] = 1;
                            break;
                        }
                    if(j != N)
                        break;
                }
            }
        }
        showBoard();
        if(gameOver()) {
            cout<<"Computer Wins!\n";
            break;
        }
        cout<<"Enter your move :: ";
        cin>>row>>column;
        gameBoard[row][column] = 2;
        showBoard();
        if(gameOver()) {
            cout<<"Player Wins!\n";
            break;
        } 
    }
}

int Game :: gameOver() {
    
    int i, j;

    for(i = 0; i < N-1; i++)
        if(gameBoard[i][i] == gameBoard[i+1][i+1] && gameBoard[i][i]!=0)
            continue;
        else
            break;
        if(i == N-1)
            return gameBoard[0][0];
    
    for(i = 0; i < N-1; i++)
        if(gameBoard[i][N-i-1] == gameBoard[i+1][N-i-2] && gameBoard[i][N-i-1]!=0)
            continue;
        else
            break;
        if(i == N-1)
            return gameBoard[i][N-i-1];
    
    for(i = 0; i < N; i++) {
        
        for(j = 0; j < N-1; j++)
            if(gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j]!=0)
                continue;
            else
                break;
        if(j == N-1)
            return gameBoard[i][j-1];
        
        for(j = 0; j < N-1; j++)
            if(gameBoard[j][i] == gameBoard[j+1][i] && gameBoard[j][i]!=0)
                continue;
            else 
                break;
        if(j == N-1)
            return gameBoard[j-1][i];

    }
    return 0;
}