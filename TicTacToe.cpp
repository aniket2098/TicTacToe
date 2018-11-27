//Driver function for the program
#include "GameLogic/Game.cpp"

int main() {
    
    int choice = 0;
    
    do {
        
        Game game;
        if(!choice) //display instructions for the first time only
            game.instructions();
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
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"\n\tWrong choice!\n\t\tPlease Re-enter\n";
                break;
        }
    }while(choice != 3);    //exit if choice = 3

    return 0;
}