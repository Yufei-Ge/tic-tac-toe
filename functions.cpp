#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void greetAndInstruct() {
    string grt; //to present the grating message
    string a;//user reply
    string y = "y";//to check use input
    //string n = "n"; the other case
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.\n"
            "The board is numbered from 1 to 27 as per the following:\n"
            "1|2|3         10|11|12      19|20|21\n"
            "-------       ---------     ---------\n"
            "4|5|6         13|14|15      22|23|24\n"
            "-------       ---------     ---------\n"
            "7|8|9         16|17|18      25|26|27\n"
            "Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O.\n"
            "Start? (y/n):\n" << endl;
    cin >> a;//store user input in a
    if ((a.compare(y)) == 0)//compare if user input y
        return;//return to main
    else //the other case is n
        exit(1);//exit with failure
}

void displayBoard (char board[]) {
   int fill[27];
   int j = 1;// start of integer in int array
   for (int i=0; i<28; i++)//initialise an int array to fill in our board
   {
      fill[i]=j;
      j++;
   }
   for (int i=0; i<9; i+=3){
       for (int j=0; j<3; j++) {
           for (int n = 0; n<3; n++) {
               if ((board[i + n + (j * 9)])== '\0'){//if no updates in board
                   cout << fill[i + n + (j * 9)] << "|";//we fill the empty game board cell with int generated
               }
               else //if there is updates in board
               {
                   cout<< board[i + n + (j * 9)] << "|"; //print the game board cell
               }
           }
           cout << "      "; //for board format
       }
       cout <<"\n" << "--------"<<"   "<<"--------" << "   " << "------------"<< endl; //for board format
   }
}

bool checkIfLegal (int cellNbre, char board[]){
    int diffa; //to store another answer
    if ((cellNbre < 0)||(board[cellNbre] !='\0')||(cellNbre > 27)) {
        std::cout << "Not a Valid cell number, try again!" << endl;
        std::cin >> diffa;//store the next valid answer
        checkIfLegal(diffa, board); //recursion top check again for the input
    }else{
        board[cellNbre-1] = 'O'; //until it is right, update on the board and return true
        return true;
    }
}

bool helperWinner (int j, char board[]){ //this is a helper function to reduce reuse of code! for checkWinner
    for (int i=0;i<(27-2*j);i++){
        if ((board[i]=='X')&&(board[i+j*2]=='X')&&(board[i+j*3]=='X')){
            cout<<"Player wins!"<<endl;
            return (board[i]=='X')&&(board[i+j*2]=='X')&&(board[i+j*3]=='X') ;}
        else if ((board[i]=='O')&&(board[i+j*2]=='O')&&(board[i+j*3]=='O')){
            cout<< "computer wins!" << endl;
            return (board[i]=='O')&&(board[i+j*2]=='O')&&(board[i+j*3]=='O');
        }
    }
}

bool checkWinner (char board[]){
   helperWinner(9, board);//check  char placed into the same cells across the 3 table
   helperWinner(13, board);//check char placed into the diagonal cells across 3 tables
   helperWinner(7, board);//check char placed into the other diagonal cells across 3 tables
   helperWinner(10, board);//check char placed into cells across 3 tables consecutively
   helperWinner(3, board);//check char placed into the 3 cells vertically in a table
   helperWinner(1, board);//check char placed into the 3 cells next to each other in a table
   helperWinner(4, board);//check char placed into the diagonal cells in a table
}


bool helperEvaluate (int j, char board[]){ //this is an evaluating function for computer to learn its best move
    char player = 'X';
    char computer = 'O';
    int input = 27;
    for (int i = 0; i<(27-2*j); i++) {
        if ((board[i] == computer) && (board[i] == board[i + j]) && (board[i + 2 * j] == '\0'))
        {input = i+2*j;} else
        if ((board[i] == computer) && (board[i] == board[i + 2*j]) && (board[i + j] == '\0'))
        {input = i+j;} else
        if ((board[j] == computer) && (board[j] == board[i+2*j]) && (board[i] == '\0'))
        {input = i;} else
        if ((board[i] == player) && (board[i] == board[i+j]) && (board[i+2*j] == '\0'))
        {input = i+2*j;} else
        if ((board[i] == player) && (board[i] == board[i+2*j]) && (board[i+j] == '\0'))
        {input = i+j;} else
        if ((board[i+j] == player) && (board[i+j] == board[i+2*j]) && (board[i] == '\0'))
        {input = i;}
    }
    if (input != 27) {
        board[input]='O';
        return true;
    }

}


void computerMove(char board[]){
    cout<<"computer's turn..."<<endl;
    helperEvaluate(9, board);//check  char placed into the same cells across the 3 table
    helperEvaluate(13, board);//check char placed into the diagonal cells across 3 tables
    helperEvaluate(7, board);//check char placed into the other diagonal cells across 3 tables
    helperEvaluate(10, board);//check char placed into cells across 3 tables consecutively
    helperEvaluate(3, board);//check char placed into the 3 cells vertically in a table
    helperEvaluate(1, board);//check char placed into the 3 cells next to each other in a table
    helperEvaluate(4, board);//check char placed into the diagonal cells in a table

    for (int i=0;i<27;i++){
        if(board[i] == '\0')
            board[i] = 'O';
    }
}

bool boardFull (char board[]){
    int count = 0;
    for (int m=0;m<27;m++){
        if (board[m] != '\0'){
            count++;
        }
    }
    if (count == 27){
        return true;
    } else {
        return false;
    }
}













