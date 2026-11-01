//2. 8-Queens Problem (Backtracking)
#include <bits/stdc++.h>
using namespace std;

int N = 8;
vector<int> board(8);

bool isSafe(int row, int col) {
    for(int i=0;i<col;i++) {
        if(board[i]==row || abs(board[i]-row)==abs(i-col))
            return false;
    }
    return true;
}

void solveQueens(int col) {
    if(col==N) {
        cout << "Solution: ";
        for(int i=0;i<N;i++) cout << board[i] << " ";
        cout << endl;
        return;
    }
    for(int row=0;row<N;row++) {
        if(isSafe(row,col)) {
            board[col]=row;
            solveQueens(col+1);
        }
    }
}

int main() {
    solveQueens(0);
    return 0;
}
