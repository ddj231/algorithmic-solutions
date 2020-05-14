#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    long int l, u;
    bitset<10000000> arr;
    cin >> l >> u;  
    long int gaps[1000];
    for(int i =0;i < 1000; i++){
        gaps[i] = 0;
    }

    long int prv;
    bool found = false;
    long int mx = 0;
    long int best = 0;
    for(long int i = 2; i <= u; i++){
        if(!arr.test(i)){
            if(i >= l){
                if(found){
                    int gap = i - prv; 
                    prv = i;
                    gaps[gap]++;
                    if(gaps[gap] > mx){
                        mx = gaps[gap];
                        best = gap;
                    }
                }
                else{
                    prv = i;
                    found = true;
                }
            }

            for(long int j = i + i; j <= u; j += i){
                arr[j] = 1;
            }
        }
    }

    bool invalid = false;
    
    for(long int i=0;i < 1000; i++){
        if(mx == gaps[i] && i != best){
            invalid = true;
            break;
        }
    }
    if(invalid || mx == 0){
        cout << -1 << endl;
    }
    else{
        cout << best << endl;
    }

}
