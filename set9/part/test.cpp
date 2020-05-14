#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_max_sum(vector<int> & a, int K) {        

    int n = a.size();    
    long long high = 0, low = 0, mid = 0;

    for (int i = 0; i < n; ++i) {
        high += a[i];
        low = max((long long) a[i], low);
    }

    while(low <= high) {
        mid = (low+high)/2;

        long long part_sum = 0;
        int parts = 1;
        for (int i = 0; i < n; ++i) {
            if (part_sum + a[i] > mid) {
                part_sum = 0;
                parts++;
            } else {
                part_sum += a[i];
            }
        }

        // if no. of parts in less than (or equal to) K then mid needs to (,or can) be more constrained by reducing upper limit
        if (parts <= K) {
            high = mid - 1;
        } else { 
            low = mid + 1;
        }
    }

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
    cout << min_max_sum(vals, m) << endl;
    
}
