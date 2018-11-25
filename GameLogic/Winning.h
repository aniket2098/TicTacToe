#define N 3

class Winning {

        int** gameBoard;
    public:
        void setGameBoard(int**);
        int isWinning(int);
        int isWinningOrthogonal(int);
        int isWinningDiagonal(int);
};