#include<bits/stdc++.h>
#include "GameLogic/Game.cpp"

int main() {
    
    Game game;
    int choice;
    game.instructions();
    
    while(1) {
        cout<<"\n\tEnter your choice ::\n\n\t1) Computer First\n\t2) Player First\n\t3) Exit\n\n\t";
        cin>>choice;
        switch(choice) {

            case 1:
                game.computerFirst();
                break;
            case 2:
                game.playerFirst();
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\tWrong choice!\n\t\tPlease Re-enter\n";
                break;
        }
    }

    return 0;
}