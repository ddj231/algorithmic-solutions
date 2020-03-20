#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, i;
    cin >> n;
    int heights[n];
    for(i = 0; i < n; i++){
        cin >> heights[i];
    }
    int maxDist = heights[0];
    for(i = 0; i < n - 1; i++){
        if(maxDist < heights[i + 1] - heights[i]){
            maxDist = heights[i + 1] - heights[i];
        }
        else if(maxDist == heights[i + 1] - heights[i]){
        }
    }

    //play game 
   int k = (maxDist == heights[0]) ? maxDist - 1 : maxDist; 
    for(int i = 0; i < n - 1; i++){
       if(heights[i + 1] - heights[i] == k){
            k--;
       } 
       else if(heights[i + 1] - heights[i] > k){
            cout << maxDist + 1 << endl;
            return 0;
       }
    }
    
    cout << maxDist << endl;
    return 0;
}
