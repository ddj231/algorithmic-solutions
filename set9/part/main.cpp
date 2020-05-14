#include <iostream>
#include <vector>

using namespace std;
//inspired by stack overflow solution
// https://stackoverflow.com/questions/39673898/divide-array-into-k-contiguos-partitions-such-that-sum-of-maximum-partition-is-m
long long best_part(vector<int> &vals, int amt){
   int len = vals.size(); 
   long long high = 0, low = 0, mid = 0;
   for(int i = 0; i < len; i++){
        high += vals[i];
        if(low < vals[i]){
            low = vals[i];
        }
   }

   while(low < high){
        mid = (low + high)/2;

        long long sum = 0;
        int parts = 1;
        
        for(int i = 0; i < len; i++){
            if(sum + vals[i] > mid){
                sum = vals[i];
                parts++;
            }
            else{
                sum += vals[i];
            }
        }

        if(parts <= amt){
           high = mid; 
        }
        else{
            low = mid + 1;
        }
   }

   mid = (low + high)/2;

   return mid;
}

int main(){
    int n, m;
    cin >> n >> m;
    //[4,3,2,1]
    //[4,3] [2,1]
    //[4] [3] [2, 1]
    vector<int> vals;
    for(int i =0; i < n; i++){
        int val;
        cin >> val;
        vals.push_back(val);
    }        
    cout << best_part(vals, m) << endl;
    
}
