//Solution inspired by Geeks For Geeks' Segmented Sieve Article

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void simpleSieve(int limit, bool * arr, vector<int>& primes){
    for(long int i = 2; i <= limit; i++){
        if(arr[i] == true){
            primes.push_back(i);
            for(long int j = i; j <= limit; j += i){
                arr[j] = false; 
            }
        }
    }

}

int main(){

    long int a, b;
    long int min1 = -1, min2 = -1, max1 = -1, max2 = -1;
    long int curr = -1, pre = -1, minDiff = INFINITY, maxDiff = 0;
    cin >> a >> b;

    bool * isPrimeVec = (bool *) malloc(sizeof(bool) * (b - a + 2));
    long int limit = floor(sqrt(b)) + 1;
    bool * simpleArr = (bool *) malloc(sizeof(bool) * (limit + 1));
    vector <int> primes;

    for(long int i = 0; i <= b - a + 1; i++){
        isPrimeVec[i] = true;
    }

    for(long int i = 0; i <= limit; i++){
        simpleArr[i] = true;
    }

    simpleSieve(limit, simpleArr, primes); 

    for(long int i = 0; i < primes.size(); i++){
        long int lowerBound = floor(a / primes[i]) * primes[i];
        if(lowerBound < a){
            lowerBound += primes[i];
        }

        if(lowerBound == primes[i]){
            lowerBound += primes[i];
        }
        
        for(long int j = lowerBound; j <= b; j += primes[i]){
            isPrimeVec[j - a] = false; 
        }
    }


    //get min and max
    for(long int i = a; i <= b; i++){
        if(isPrimeVec[i - a] && i != 0 && i != 1){
            pre = curr;
            curr = i;
           
            if(curr > 0 && pre > 0 && maxDiff < curr - pre){
                max1 = pre;
                max2 = curr;
                maxDiff = curr - pre; 
            }
            
            if(curr > 0 && pre > 0 && minDiff > curr - pre){
                min1 = pre;
                min2 = curr;
                minDiff = curr - pre; 
            }

        }

    }   


    if( min1 < 0 || min2 < 0){
        cout << -1 << endl;
    }
    else{
        cout << min1 << " " << min2 << " " << max1 << " " << max2 << endl; 
    }

    free(isPrimeVec);
}
