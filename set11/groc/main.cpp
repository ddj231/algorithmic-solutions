#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int size;
int cap;
vector<int> volumes;
int memo[300][10100];
string bestStr("");
long int opt;
bool print = false;

long int box(int i, int w1,long int * sums, string s){
    if(i >= 0){
        int w2 = sums[i] - w1;
   //     cout << "i is " << i << " and w1 is " << w1 << " and w2 is " << w2 << endl;
        if(w2 > cap || w1 > cap || i >= size){
            // cout << s;
            if(print == true && i - 1 == opt){
                cout << s.substr(0, s.length() - 4);
                print = false;
            }
            return i - 1;
        }
    }

    //adding one to i to shift memo table, 
    //so no negative indices
        
    if(memo[i+1][w1] != -1){
        if(print == true && i - 1 == opt){
            cout << s.substr(0, s.length() - 4);
            print = false;
        }
        return memo[i+1][w1];
    }

    string s1 = s + "1st\n";
    string s2 = s + "2nd\n";
    int pos1 = box(i + 1, w1 + volumes[i + 1], sums, s1);
    int pos2 = box(i + 1, w1, sums, s2);

    //return max(pos1, pos2);
    
    memo[i+1][w1] =  max(pos1, pos2);
    return memo[i+1][w1]; 
}

int main(){
    int n, w;
    cin >> n >> w;
    cap = w;
    size = n;
    long int sums[n];
    for(int i = 0; i < n; i++){
        long int val; 
        cin >> val;
        volumes.push_back(val);
    }
  //  cout << "out of loop" << endl;

    //initialize memo table
      
    for(int i = 0; i < n+5; i++){
        for(int j = 0; j < w+1; j++){
            memo[i][j] = -1;
        }
    } 
    
    
    //get prefix sums
    sums[0] = volumes[0]; 
    for(int i = 1; i < n; i++){
        sums[i] = sums[i - 1] + volumes[i];
 //       cout << "sums " << i << " is " << sums[i] << endl;
    }
//    cout << "out of second loop" << endl;

    opt = box(-1, 0, sums, "");
    cout << opt + 1 << endl;
    print = true;
    
    
    for(int i = 0; i < n+5; i++){
        for(int j = 0; j < w+1; j++){
            memo[i][j] = -1;
        }
    } 

    box(-1, 0, sums, "");

    return 0;
}
