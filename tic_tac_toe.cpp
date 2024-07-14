#include<iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout<<"Current board:"<<endl;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player || board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player || board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void move(char board[3][3], char player) {
    int move;

    while(true) {
        cout<<"Enter your move player "<<player<<" from (1 - 9)"<<endl;
        cin>>move;

        int r = (move - 1) / 3;
        int c = (move - 1) % 3;

        if(board[r][c] == 'X' || board[r][c] == 'O') {
            cout<<"Invalid move, Cell already occupied! Please enter again"<<endl;
            continue;
        }
        else {
            board[r][c] = player;
            break;
        }
    }
}


int main() {
    char board[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        { '7', '8', '9'}};

    char currentPlayer = 'X'; 
    bool gameWon = false;

    while(1) {
        printBoard(board);
        move(board, currentPlayer);

        if(checkWin(board, currentPlayer)) {
            printBoard(board);
            cout<<"Player "<<currentPlayer<<" WINS!!"<<endl;
            gameWon = true;
            break;
        }

        if(checkDraw(board)) {
            printBoard(board);
            cout<<"This game is a DRAW!!"<<endl;
            break;
        }

        if(currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }

    return 0;   
}