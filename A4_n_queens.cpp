#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;

bool isSafe(int row, int col) {
    for(int k=1; k<=row; k++){
    if(board[row-k][col])
        return false;
    if(board[row-k][col-k])
        return false;
    if(board[row-k][col+k])
        return false;
    }
    return true;
}

bool solve(int row) {
    if(row==n)
        return true;
        for(int col=0; col<n; col++){
            if(isSafe(row, col)){
                board[row][col]=1;
                if(solve(row+1))
                    return true;
                board[row][col] = 0;
            }
        }
    return false;
}

int main(){
    int firstCol;
    cout << "n : ";
    cin >> n;
    cout << "firstCol : ";
    cin >> firstCol;

    if(n<=0 || firstCol<0 || firstCol>=n){
        cout << "Invalid Input!" << endl;
        return 0;
    }

    board.assign(n, vector<int>(n, 0));
    board[0][firstCol] = 1;

    if (solve(1)){
        cout << "Matrix of " << n << "-Queens is : " << endl;
        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "A Matrix can't be formed for n = " << n << endl;
    }
    return 0;
}