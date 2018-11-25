#include<bits/stdc++.h>
#include "Game.h"

#define N 3

using namespace std;

Game :: Game() {

    gameBoard = new int* [N];
    for(int i = 0; i < N; i++)
    {
        gameBoard[i] = new int[N];    
        for(int j = 0; j < N; j++)
            gameBoard[i][j] = 0;
    }
    decisionTree = movesTree.returnHead();
    state = decisionTree;
    movesTree.createDecisionTree1();
    movesTree.createDecisionTree2();
    winning.setGameBoard(gameBoard);
    gameOver.setGameBoard(gameBoard);
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



void Game :: randomMove() {
    
    int i, j;

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
void Game :: play() {

    int row, column, i, j, result;
    initialMove(1);
    while(1) {

        if(!winning.isWinning(1) && !winning.isWinning(2))
        {            
            if(state!=NULL) {
                if(!flag)
                    gameBoard[state->row][state->column] = 1;
                else{
                    gameBoard[state->column][state->row] = 1;
                }
                state = state->link[0];
            }
            else
                randomMove();
        }
        showBoard();
        if(result = gameOver.gameOver()) {

            if(result == 1)
                cout<<"Computer Wins!\n";
            else
                cout<<"Draw!\n";
            break;
        }
        cout<<"Enter your move :: ";
        cin>>row>>column;
        gameBoard[row][column] = 2;
        showBoard();
        if(gameOver.gameOver()) {
            cout<<"Player Wins!\n";
            break;
        } 
    }
}