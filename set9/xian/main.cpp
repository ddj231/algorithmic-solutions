#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> heads;
    vector<int> archers;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        heads.push_back(val);
    }

    for(int i = 0; i < m; i++){
        int val;
        cin >> val;
        archers.push_back(val);
    }

    if( m < n){
        cout << "Xia is doomed!" << endl;
        return 0;
    }

    //simulate
    sort(heads.begin(), heads.end()); 
    sort(archers.begin(), archers.end()); 
    int i = 0;
    int j = 0;
    int slayed = 0;
    int cost = 0;
    while(i < (int) heads.size() && j < (int) archers.size()){
       if(heads[i] <= archers[j]){
            slayed++;
            cost += archers[j];
            i++; j++;
       } 
       else{
            j++;
        }
    }
    if(slayed == (int) heads.size()){
        cout << cost << endl;
    }
    else{
        cout << "Xia is doomed!" << endl;
    }
    return 0; 
}
