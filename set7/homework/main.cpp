#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hw {
    int start;
    int end;
};

bool acompare(const Hw& a, const Hw& b){
    return a.end > b.end; 
}

int main(){
    int n;
    cin >> n;
    vector<Hw> arr;
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        Hw newHw;
        newHw.start = start;
        newHw.end = end;
        arr.push_back(newHw); 
    }    
    sort(arr.begin(), arr.end(), acompare);
    int stT = 0, endT = 0;
    for(int i = 0; i < n; i++){
        stT += arr[i].start;
        if(stT + arr[i].end > endT){
            endT = stT + arr[i].end;
        }
    }

    cout << endT << endl;

}
