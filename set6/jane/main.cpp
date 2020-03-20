//jane
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long int> pool;
    long long int total = 0;
    for(int i = 0; i < n; i++){
       long long int amt;
       cin >> amt;
       for(int j = 0; j < amt; j++){
           long long int val;
           cin >> val;
           pool.push_back(val);
       }
       sort(pool.begin(), pool.end());
       total += pool[pool.size() - 1] - pool[0];
       pool.pop_back();
       pool.erase(pool.begin());
    }
    cout << total << endl;
    return 0;
}

/*
int main(){
    int n;
    cin >> n;
    int * arr = (int *) malloc(sizeof(int) * 100000 * 6000);
    int start = 0, end = 0;
    int total = 0;
    for(int i = 0; i < n; i++){
       int amt;
       cin >> amt;
       for(int j = 0; j < amt; j++){
           int val;
           cin >> val;
           arr[end++] = val;
       }
       sort(arr + start, arr + end);
       total += arr[end - 1] - arr[start];
       start++;
       end--; 
    }
    cout << total << endl;
    return 0;
}
*/
