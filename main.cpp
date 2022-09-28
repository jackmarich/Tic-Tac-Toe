#include <iostream>
#include <ctime>

using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    
    drawBoard(spaces);
    
    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
        
        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
        
    }
    cout << "Thanks for playing!" << endl;
    
    return 0;
}
void drawBoard(char *spaces){
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}
void playerMove(char *spaces, char player){
    int num;
    do{
        cout << "Pick a spot to play (1-9)";
        cin >> num;
        num--;
        if(spaces[num] == ' '){
            spaces[num] = player;
            break;
        }
    }while(!num > 0 || !num < 8);
}
void computerMove(char *spaces, char computer){
    int num;
    srand(time(0));
    
    while(true){
        num = rand() % 9;
        if(spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? cout << "You won!" << endl: cout << "You lost!" << endl;
    }
    else{
        return false;
    }
    return true;
}
bool checkTie(char *spaces){
    for(int i=0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "You tie!" << endl;
    return true;
}
