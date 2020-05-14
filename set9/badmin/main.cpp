#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m, f;
    cin >> m >> f;
    if(m <= f){
        cout << 0 << endl;
        return 0;
    }

    vector<int> males;
    vector<int> females;
    for(int i=0; i < m; i++){
        int val;
        cin >> val;
        males.push_back(val);
    }

    for(int i=0; i < f; i++){
        int val;
        cin >> val;
        females.push_back(val);
    }
    sort(males.begin(), males.end());
    cout << m - f << " " << males[0] << endl;
}
