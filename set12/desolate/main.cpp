#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    //int n = a + b;
    long long int output = 0;
    int i = 0;
    long long int mask = 1;
    string bnum("");
    if( a > 2 * b){
        int trailing = a - (2*b);
        while(trailing > 0){
            output |= (mask << i);
            bnum = "1" + bnum;
            trailing--;
            i++;
            a--;
        }
    }
    
    int start = 0;
    //2 
    //add trailing ones
    while( a > 0 || b > 0){
        if((start % 3 == 0 || start % 3 == 2) && a > 0){
            output |= (mask << i);
            bnum = "1" + bnum;
            a--;
        } 
        else if(start % 3 == 1 && b > 0){
            bnum = "0" + bnum;
            b--;
        }
        /*
        else if(a > 0 && b <= 0){
            output |= (mask << i);
            bnum = "1" + bnum;
            a--;
        }
        */
        else if(b > 0 && a <= 0){
            bnum = "0" + bnum;
            b--;
        }
        i++;
        start++;
    }
    cout << output << endl;
}

//2 2
//0 1 0 1
//3 2
//0 1 0 1 0 1
//4 2
//110101
//
// 8 3
//11101101101

//case b >= a // just place as optimally
// 5 5
// 0001101101
//
//case a > b
// 7  5
//001101101101

