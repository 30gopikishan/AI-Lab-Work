//LAB 05: Implement the Minimax Algorithm for Game Playing
#include <bits/stdc++.h>
using namespace std;

char board[3][3];

// Function to print the board
void printBoard() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Check if moves are left
bool isMovesLeft() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]=='_') return true;
    return false;
}

// Evaluate board state
int evaluate() {
    // Rows
    for(int row=0;row<3;row++) {
        if(board[row][0]==board[row][1] && board[row][1]==board[row][2]) {
            if(board[row][0]=='X') return +10;
            else if(board[row][0]=='O') return -10;
        }
    }
    // Columns
    for(int col=0;col<3;col++) {
        if(board[0][col]==board[1][col] && board[1][col]==board[2][col]) {
            if(board[0][col]=='X') return +10;
            else if(board[0][col]=='O') return -10;
        }
    }
    // Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        if(board[0][0]=='X') return +10;
        else if(board[0][0]=='O') return -10;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        if(board[0][2]=='X') return +10;
        else if(board[0][2]=='O') return -10;
    }
    return 0;
}

// Minimax function
int minimax(int depth, bool isMax) {
    int score = evaluate();

    // Terminal states
    if(score==10) return score-depth;   // maximize wins faster
    if(score==-10) return score+depth;  // minimize loses slower
    if(!isMovesLeft()) return 0;        // draw

    if(isMax) {
        int best=-1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]=='_') {
                    board[i][j]='X';
                    best=max(best,minimax(depth+1,false));
                    board[i][j]='_';
                }
            }
        }
        return best;
    } else {
        int best=1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]=='_') {
                    board[i][j]='O';
                    best=min(best,minimax(depth+1,true));
                    board[i][j]='_';
                }
            }
        }
        return best;
    }
}

// Find best move for X (AI)
pair<int,int> findBestMove() {
    int bestVal=-1000;
    pair<int,int> bestMove={-1,-1};

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j]=='_') {
                board[i][j]='X';
                int moveVal=minimax(0,false);
                board[i][j]='_';
                if(moveVal>bestVal) {
                    bestMove={i,j};
                    bestVal=moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main() {
    // Initial board
    char init[3][3]={{'X','O','X'},{'O','O','X'},{'_','_','_'}};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=init[i][j];

    cout << "Initial Board:\n";
    printBoard();

    pair<int,int> bestMove=findBestMove();
    cout << "Best Move for X: Row=" << bestMove.first << " Col=" << bestMove.second << endl;

    // Apply best move
    board[bestMove.first][bestMove.second]='X';
    cout << "\nBoard after AI move:\n";
    printBoard();

    return 0;
}
