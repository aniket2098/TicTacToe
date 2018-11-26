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
        void showBoard();
        void instructions();
        void play();
        void play1();
        void randomMove();
        void initialMove(int);
        int isMoveValid(int,int);
        int displayResult();
};