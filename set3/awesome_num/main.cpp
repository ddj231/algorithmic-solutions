#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int n, counter = 0;
    cin >> n;
    if(n < 3){
        cout << 0 << endl;
        return 0;
    }
    //std::vector <bool> isPrimeVec(n + 1, true);
    bool * isPrimeVec = (bool *) malloc(sizeof(bool) * (n+1));
    for(int i = 0; i <= n; i++){
        isPrimeVec[i] = true;
    }

    for(long int i = 2; i <= n; i++){
        if(isPrimeVec[i]){ 
            if(i % 10  == 1){
                counter++;
            }
            for(long int j = i * i; j <= n; j += i){
                isPrimeVec[j] = false; 
            }
        }
    }
    cout << counter << endl;
    free(isPrimeVec);
}
