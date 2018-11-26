#include<bits/stdc++.h>
#include "Game.h"

#define X (state->row-1)*x - (state->column-1)*(-y)+ 1
#define Y (state->column-1)*x + (state->row-1)*(-y) + 1
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

    decisionTree = movesTree.returnHead1();
    decisionTree2 = movesTree.returnHead2();
    state = decisionTree;
    movesTree.createDecisionTree1();
    movesTree.createDecisionTree2();
    winning.setGameBoard(gameBoard);
    gameOver.setGameBoard(gameBoard);
    flag = 0;
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
    cout<<"\n\tX :: Computer\n\n\tO :: Player\n\n\tEnter your input in the following format :: Row Column\n";
    showBoard();
}

int Game :: displayResult() {

    int result;
    if(result = gameOver.gameOver()) {

        if(result == 1)
            cout<<"\tComputer Wins!\n";
        else
            cout<<"\tDraw!\n";
        return 1;
    }
    return 0;
}

int Game :: isMoveValid(int row, int column) {

    if(row < N && row >=0 && column < N && column >= 0)
        if(gameBoard[row][column] == 0)
            return 1;
    return 0;

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

void Game :: initialMove(int player) {

    int row, column, i;
    gameBoard[0][0] = 1;
    showBoard();
    while(1)
    {   
        cout<<"\tEnter your move :: ";
        cin>>row>>column;
        if(isMoveValid(row,column))
            break;
        cout<<"\tInvalid move! Please Re-enter!\n";
    }
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

void Game :: computerFirst() {

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
        if(displayResult())
            break;
        while(1)
        {   
            cout<<"\tEnter your move :: ";
            cin>>row>>column;
            if(isMoveValid(row,column))
                break;
            cout<<"\tInvalid move! Please Re-enter!\n";
        }
        gameBoard[row][column] = 2;
        showBoard(); 
    }
}

void Game :: rotation(int* x, int* y, int row, int column) {

    if(row != 0 || column != 0) {

        if(row == -1 && column <= 0)
        {
            *x = 1;
            *y = 0;
        }
        else if(row <= 0 && column == 1) {

            *x = 0;
            *y = 1;
        }
        else if(row == 1 && column >= 0) {

            *x= -1;
            *y = 0;
        }
        else {

            *x = 0;
            *y =-1;
        }
    }
}

void Game :: playerFirst() {

    int row, column, i, j,tempFlag = 0, x = 1, y = 0;
    state = decisionTree2;
    tree* temp =state;

    while(1) {
        
        while(1)
        {   
            cout<<"\tEnter your move :: ";
            cin>>row>>column;
            if(isMoveValid(row,column))
                break;
            cout<<"\tInvalid move! Please Re-enter!\n";
        }

        gameBoard[row][column] = 2;
        showBoard();
        row--;
        column--;
        if(!tempFlag) {
            tempFlag = 1;
            rotation(&x, &y, row, column);
        }

        int temporary = row;
        row = row*x - column*y + 1;
        column = column*x + temporary*y + 1;
       
        if(displayResult())
            break;
        
        if(!winning.isWinning(1) && !winning.isWinning(2))
        {
            if(state != NULL && !flag) {
                for(i = 0; i < 3; i++) {
                    state = temp->link[i];
                    if(state->row == row && state->column == column)
                        break;
                }
                if(i == 3)
                {
                    state = NULL;
                    randomMove();
                }
                else {
                    state = state->link[0];
                    gameBoard[X][Y] = 1;
                    temp = state;
                    state = temp->link[0];
                }
            }
            else 
                randomMove();
        }
        else
            flag = 1;
        showBoard();

        if(displayResult())
            break;
    }
}