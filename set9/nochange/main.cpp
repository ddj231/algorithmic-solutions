#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int INF = 1000000000;
int global_ct = 0;
int answer[10001];
int sols[10001];

int coins(int n, int i, vector<int>& vals){

    if(i < 0 && n > 0){
        return INF;
    }
    else if(n <= 0){
        return (n * -1);
    }
    //else if(answer[i] != -1){
     //   return answer[i];
    //}
    
    int val1 = coins(n - vals[i], i - 1, vals);
    int val2 = coins(n, i-1, vals);

    answer[i] = min(val1, val2);
    return answer[i];
}

int sol(int sum, int i, vector<int>& vals){

   if(sum == 0){
        return 0;
   }       
   else if(sum < 0 || i < 0){
        return INF;
   }
   else if(sum > 0 && i < 0){
        return INF;
   }

   //recurrence relation 
   // sol(n) = min(sol(n - coin[i]), sol(n, i -1))
   
   int val1 = sol(sum - vals[i], i - 1, vals) + 1; 
   int val2 = sol(sum, i - 1, vals);
   sols[i] = min(val1, val2);
   return sols[i];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> coinVals;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        coinVals.push_back(val);
    }
    memset(answer, -1, sizeof(int) * 10001);
    memset(sols, -1, sizeof(int) * 10001);
    //recurence relation: coins(n, i) = min(coins(n - ci, i - 1), coins(n, i -1));
    //base case: i >= size and n > 0, return INF
    //n <= 0 return (n * -1)
    //14 , 5 10 20     
    int cost = coins(m, n-1, coinVals);
    int amt = sol(m + cost, n - 1, coinVals); 
    cout << m + cost << " " << amt << endl;
}
