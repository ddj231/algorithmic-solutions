//inspired by geeks for geeks pancake sorting algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> flipPoints;

void rev(vector<int>&vec, int end){
    int temp, start = 0;
    while(start < end){
        temp = vec[start];
        vec[start] = vec[end];
        vec[end] = temp;
        start++;
        end--;
    }
}

int maxInd(vector<int>& vec, int size){
    int best = 0, ind = -1;
    for(int i = 0; i < size; i++){
        if(best < vec[i]){
            best = vec[i];
            ind = i;
        }
    }
    return ind;
}

void pancakeSort(vector<int>& vec){
    int size = vec.size();
    for(int currSize = size; currSize > 1; currSize--){
        
        int currMax = maxInd(vec, currSize);
        
        if(currMax != currSize - 1){
            flipPoints.push_back(currMax);
            rev(vec, currMax);
            flipPoints.push_back(currSize - 1);
            rev(vec, currSize - 1);
        }    
    }
}

void printFlips(int size){
    for(int i = 0; i < (int) flipPoints.size(); i++){
        cout << size - flipPoints[i] << " ";
    }
    cout << 0 << endl;
}

int main(){
    vector<int> vec;
    int val;
    while(cin >> val){
        vec.push_back(val);
    } 

    pancakeSort(vec);
    printFlips(vec.size());
    return 0;
}
