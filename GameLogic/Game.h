#include "Tree/Tree.cpp"

#define N 3

class Game {

    int flag;
    Tree movesTree;
    tree* decisionTree;
    tree* state;
    int gameBoard[N][N], choice;
    public:
        Game();
        void showBoard();
        void instructions();
        void play();
        int gameOver();
        int isWinning(int);
        int isWinningOrthogonal(int);
        int isWinningDiagonal(int);
        void initialMove(int);
           
};