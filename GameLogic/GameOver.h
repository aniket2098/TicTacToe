class GameOver {

    int** gameBoard;
    public:
        void setGameBoard(int**);
        int gameOverOrthogonal();
        int gameOverDiagonal();
        int gameBoardFull();
        int gameOver();
};