#include "Tree/Tree.cpp"
#include "Winning.cpp"
#include "GameOver.cpp"

#define N 3

class Game {

    Tree movesTree;
    Winning winning;
    GameOver gameOver;
    tree* decisionTree;
    tree* decisionTree2;
    tree* state;
    int **gameBoard, choice;
    int flag;
    public:
        Game();
        void computerFirst();
        void playerFirst();
        void showBoard();
        void instructions();
        void randomMove();
        void initialMove(int);
        void rotation(int*,int*,int,int);
        int isMoveValid(int,int);
        int displayResult();
};