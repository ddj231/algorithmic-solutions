#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int memo[100][100];
long int ways(int n, int k){
    if(memo[n][k] > 0){
        return memo[n][k];
    }
    if(k == 1){
        return 1;
    }

    long int sum = 0;
    for(int i=0; i <= n; i++){
      sum += ways(n - i, k-1);   
    }

    memo[n][k] = sum % int(pow(10, 9) + 7.5);
    return memo[n][k];
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << ways(n, k) << endl;
}


// 6 2
// ways(6,2) - ways(5,1) ways(4,1) ways(3,1) ways(2,1) ways(1, 1) ways(0, 1)
// 1 1 
// 1 2 
// 1 3 
// 1 4  
// 1 5
// 1 6 
// 1 7 
//
//
//
//
