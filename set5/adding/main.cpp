//adding
#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;
    long int cost = 0;
    priority_queue<int, vector<int>, greater<int> > nums;
    for(int i = 0; i < n; i++){
        long int val;
        cin >> val;
        nums.push(val);
    } 

    while(nums.size() >= 2){
        long int temp = nums.top();
        nums.pop();
        long int tempCost = temp + nums.top();
        cost += tempCost;
        nums.pop();
        nums.push(tempCost);
    }

    cout << cost << endl;
    return 0;
}

//1 2 3 4

