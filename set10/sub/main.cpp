#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    long int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long int mx = INT_MIN;
    long int curr = 0; 
    for(int i = 0; i < n; i++){
        curr += arr[i];

        if(mx < curr){
            mx = curr;
        }

        if(curr < 0){
            curr = 0;
        } 
    }

    cout << mx << endl;
}
