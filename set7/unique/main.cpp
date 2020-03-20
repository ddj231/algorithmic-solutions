#include <iostream>
#include <unordered_map>

using namespace std;

void dupsFrom(int start, int end, int*nums, unordered_map<int, int>&uniq){
    for(int i = start; i <= end; i++){
        uniq[nums[i]] = i;
    } 
}
int main(){
    int n; 
    cin >> n;
    int nums[n];
    unordered_map <int, int> uniq; 
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
   int maxC = 0;
   int c = 0;
   
    for(int i = 0; i < n; i++){
        if(uniq.count(nums[i]) == 0){ 
            uniq[nums[i]] = i;
            c++;
        } 
        else {
            if(maxC < c)
                maxC = c;
            int ind = uniq[nums[i]];
            c = i - uniq[nums[i]];
            uniq.clear();
            dupsFrom(ind, i, nums, uniq);
        }
    }
    if(maxC < c){
        maxC = c;
    }
    cout << maxC << endl;
}   

