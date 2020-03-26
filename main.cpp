#include <iostream>
#include "functions.cpp"
using namespace std;
int main() {
    char board[27];
    greetAndInstruct();
    displayBoard(board);
    int playerNbre;
    do {
        std::cout << "Hey! you make the call, you go! which cell do you want to put your X?" << endl;
        std::cin >> playerNbre;
        if(checkIfLegal(playerNbre, board)==true)
                    board[playerNbre-1] = 'X';
        displayBoard(board);
        computerMove(board);
        displayBoard(board);
    }while (!boardFull(board));
    displayBoard(board);
    checkWinner(board);
}