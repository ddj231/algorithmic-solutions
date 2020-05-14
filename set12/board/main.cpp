#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

// recurrence relation
// game(board, row) = min i - to I (board - coli, row + 1)
// base case row == size; return 0
int n;
int inf = INT_MAX;

int game(vector<vector<int> >& board, int row, set<int> invalidCols){
    if(row >= n){
        return 0;
    }
    
    int best = INT_MAX;
    for(int i = 0; i < n; i++){
        if(invalidCols.count(i) == 0){
            invalidCols.insert(i);
            best = min(best, game(board, row + 1, invalidCols) + board[row][i]);
            invalidCols.erase(i);
        }
    }

    return best;
}

int main(){
    cin >> n;
    vector<vector<int> >board;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            row.push_back(val);
        }
        board.push_back(row);
    }
    set<int> invalidCols;
    cout << game(board, 0, invalidCols) << endl;
}
