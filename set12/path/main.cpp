#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int rows, cols, start;

int main(){
    cin >> rows >> cols >> start;
    vector<vector<char> > maze;
    vector<vector<int> > visited;
    for(int i = 0; i < rows; i++){
        vector<char> col;
        vector<int> colVis;
        for(int j = 0; j < cols; j++){
            char val;
            cin >> val;
            col.push_back(val);
            colVis.push_back(0);
        }
        maze.push_back(col);
        visited.push_back(colVis);
    }

    int row = 0;
    int col = start - 1;
    int totalSteps = 0;
    int cycle = false;
    int cycleRow = -1;
    int cycleCol = -1;
    
    while(true){
        if(row >= rows || col >= cols || row < 0 || col < 0){
            //made it out woohoo
            cout << totalSteps << " step(s) to exit" << endl;
            break;
        }

        if(visited[row][col] == 1){
            //uh oh found a cycle
            //retrace steps
            cycle = true;
            cycleRow = row;
            cycleCol = col;
            break;
        }
        
        visited[row][col] = 1;
        if(maze[row][col] == 'N'){
            row--;
        }
        else if(maze[row][col] == 'S'){
            row++;
        }
        else if(maze[row][col] == 'E'){
            col++;
        }
        else if(maze[row][col] == 'W'){
            col--;
        }
        totalSteps++;
    }

    if(cycle){
        int cycleSteps = 0;
        row = cycleRow;
        col = cycleCol;
        
        do {
            if(maze[row][col] == 'N'){
                row--;
            }
            else if(maze[row][col] == 'S'){
                row++;
            }
            else if(maze[row][col] == 'E'){
                col++;
            }
            else if(maze[row][col] == 'W'){
                col--;
            }
            cycleSteps++;
        }while(row != cycleRow || col != cycleCol);
        cout << totalSteps - cycleSteps << " step(s) before a loop of " << cycleSteps << " step(s)" << endl;
    }
}
