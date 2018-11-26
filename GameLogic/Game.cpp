//For the following program
//value 1 in gameBoard represents Computer
//value 2 represents Player
//value 0 represents empty cell
#include<bits/stdc++.h>
#include "Game.h"

#define X (state->row-1)*x - (state->column-1)*(-y)+ 1 //Formulae for mathematical transformation operation
#define Y (state->column-1)*x + (state->row-1)*(-y) + 1
#define N 3     //Default grid size

using namespace std;

Game :: Game() {        //Default constructor

    gameBoard = new int* [N];   //Allocation of memory to the gameBoard
    for(int i = 0; i < N; i++)  //Loop to allocate memory to all cells of the gameBoard
    {
        gameBoard[i] = new int[N];    
        for(int j = 0; j < N; j++)
            gameBoard[i][j] = 0;    //Initializing default value of 0 to each cell 
    }

    decisionTree = movesTree.returnHead1();
    decisionTree2 = movesTree.returnHead2();
    state = decisionTree;   
    movesTree.createDecisionTree1();
    movesTree.createDecisionTree2();
    winning.setGameBoard(gameBoard);    //initializing gameBoard in other classes
    gameOver.setGameBoard(gameBoard);
    flag = 0;
}

//Logic for when computer plays first
//First check if winning positions are available for computer
//If available fill it
//If player is winning block it
//Find the optimal move in the decision tree according to the user input
//If no position found then fill any random position 
void Game :: computerFirst() {  

    int row, column, i, j, result;
    initialMove(1); //first move decides the branch to be taken in the decision tree
    while(1) {

        if(!winning.isWinning(1) && !winning.isWinning(2))  //check if there are any winning positions (for both player or computer) 
        {                                                   //if present block it or fill it            
            //if no one is winning then search for optimal positions in decision tree
            if(state!=NULL) {
                if(!flag)
                    gameBoard[state->row][state->column] = 1;
                else{
                    gameBoard[state->column][state->row] = 1;
                }
                state = state->link[0];
            }
            else
                randomMove();   //if no optimal position found then select a random position
        }
        showBoard();
        if(displayResult())     //if there is a winner then display result and break
            break;
        while(1)        //a loop to ascertain whether the position entered is legal or not
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

//Function which calculates the multipliers for 2d-rotation
//This function is used only when Player plays first 
void Game :: rotation(int* x, int* y, int row, int column) {

    if(row != 0 || column != 0) {   //Calculate the multipliers by determining the quadrant of the first user move

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

//Executed when player goes first
//Over here the fact that the grid is symmetric is used
//Accordingly the grid gets rotated to match the input quadrant to the first quadrant
//If no winning positions can be found
//Then using these transformed values optimal move is searched in the decision tree
//If optimal value not found then random value is used
void Game :: playerFirst() {

    int row, column, i, j,tempFlag = 0, x = 1, y = 0;   
    state = decisionTree2;  
    tree* temp =state;

    while(1) {  //iterate till gameover
        
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
        if(!tempFlag) {     //multipliers for rotation calculated according to first move
            tempFlag = 1;
            rotation(&x, &y, row, column);
        }

        int temporary = row;     
        row = row*x - column*y + 1;     //Equations to tranform the input
        column = column*x + temporary*y + 1;
       
        if(displayResult())     //check if game is over
            break;
        
        if(!winning.isWinning(1) && !winning.isWinning(2))  //check for winning positions
        {
            if(state != NULL && !flag) {        //search the decision tree to find the optimal move
                for(i = 0; i < 3; i++) {
                    state = temp->link[i];      
                    if(state->row == row && state->column == column)
                        break;
                }
                if(i == 3)      //if no optimal move found
                {
                    state = NULL;
                    randomMove();
                }
                else {      //if optimal position was found
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

//Displays the GameBoard
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

//Displays Instructions
void Game :: instructions() {

    cout<<"\n\tX :: Computer\n\n\tO :: Player\n\n\tEnter your input in the following format :: Row Column\n";
    showBoard();
}

//Displays the Result if game is over else returns false
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

//Determines if the user input is a valid move
int Game :: isMoveValid(int row, int column) {

    if(row < N && row >=0 && column < N && column >= 0)
        if(gameBoard[row][column] == 0)
            return 1;
    return 0;

}

//Iterates through the entire gameBoard and finds the first empty cell to use as the next move
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

//First move when computer plays first
void Game :: initialMove(int player) {

    int row, column, i;     //variable i is used as a looping variable
    gameBoard[0][0] = 1;    //First move by the computer
    showBoard();
    while(1)
    {   
        cout<<"\tEnter your move :: ";  
        cin>>row>>column;
        if(isMoveValid(row,column))     //Check if move is a legal move
            break;
        cout<<"\tInvalid move! Please Re-enter!\n";
    }
    gameBoard[row][column] = 2;    
    showBoard();
    if(column < row)    //
        flag = 1;
    for(i = 0; i < 5; i++) {
        state = decisionTree->link[i];  //state stores the current position in the decision tree
        if(!flag)   //
        {
            if(state->row == row && state->column == column)    //if the current input from user matches a node in the decision tree
                break;
        }else
            if(state->row == column && state->column == row)
                break;        
    }
    state = state->link[0];     //next level

}