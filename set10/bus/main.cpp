#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    long int arr[n - 1];
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }

    long int mx = INT_MIN;
    long int curr = 0; 
    int start = 0;
    int max_start = 0;
    int end = 0;
    int ct = 0;
    int mx_ct = 0;

    for(int i = 0; i < n - 1; i++){
        curr += arr[i];
        ct++;

        if(mx < curr){
            mx = curr;
            end = i + 1;
            max_start = start;
            mx_ct = ct;
        }

        if(mx == curr && ct > mx_ct){
            mx = curr;
            end = i + 1;
            max_start = start;
            mx_ct = ct;
        }

        if(curr < 0){
            curr = 0;
            ct = 0;
            start = i + 1;
        } 
    }

    if(mx < 0){
        cout << "Yet another overrated tourist destination" << endl;
        return 0;
    }
    else{
        cout << "The nicest part of Y1 is between stops " << max_start + 1 << " and " << end + 1 << endl;
    }

    return 0;
}
