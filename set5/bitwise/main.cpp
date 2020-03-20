//bitwise
#include <iostream>
#include <vector>

using namespace std;

int twoToThe(int num){
    int output = 1;
    for(int i = 0; i < num; i++){
        output *= 2; 
    }
    return output;
}
//100 50 60
// 100 = 1100110 50 = 0110010 60 = 011110 best answer 59 = 0111011
int main(){
    unsigned int n, l, r;
    cin >> n >> l >> r;
    vector <unsigned int> locOfZeros;
    unsigned int x = 0, sofar = 0;
    int i;

    if(l == r){
        cout << l << endl;
        return 0;
    }

    for(i = 31; i >= 0; i--){
        if(n & (1 << i)){
            if(x + twoToThe(i) <= l){
                x |= (1 << i); 
            }
        }
        else{
            if(x + (1 << i) <= r){
                x |= (1 << i);
            }
        }
    }

    cout << x << endl;
}
