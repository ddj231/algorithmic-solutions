#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    long int num;
    vector<long int> nums;
    while(cin >> num){
        nums.push_back(num);
    }
    std::priority_queue<long int, vector<long int>, greater<int> > minHeap;
    std::priority_queue<long int, vector<long int>, less<long int> > maxHeap;
    int countMin =0;
    int countMax = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums.size() == 1){
            cout << nums[i];
            break;
        }

        if(i == 0 && nums[0] <= nums[1]){
            maxHeap.push(nums[0]);
            minHeap.push(nums[1]);
            countMax++;
            countMin++;
            cout << nums[0] << endl;
            cout << (nums[1] + nums[0]) / 2 << endl;
        }
        else if(i == 0){
            maxHeap.push(nums[1]);
            minHeap.push(nums[0]);
            countMax++;
            countMin++;
            cout << nums[0] << endl;
            cout << (nums[1] + nums[0]) / 2 << endl;
        }
        else if(i != 1){
            if(nums[i] <= maxHeap.top()){
                maxHeap.push(nums[i]);
                countMax++;
            }
            else{
                minHeap.push(nums[i]);
                countMin++;
            }
            if(countMax - countMin >= 2){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                countMax--;
                countMin++;
            }
            else if(countMin - countMax >= 2){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                countMin--;
                countMax++;
            }

            cout << ((countMax == countMin) ? (minHeap.top() + maxHeap.top())/2 : ((countMax > countMin) ? maxHeap.top() : minHeap.top())) << endl;
        }
    }
}
