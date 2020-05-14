#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<double> vec;
    for(int i = 0; i < n; i++){
        double num;
        cin >> num;
        vec.push_back(num);
    }

    for(int i = n; i < 2*m; i++){
        vec.push_back(0);
    } 
    sort(vec.begin(), vec.end()); 
    
    int start = 0;
    int end = 2*m - 1;
    vector<double> nodes;
    double avg = 0.0;
    for(int i = 0; i < m; i++){
        double val = vec[start++] + vec[end--];
        nodes.push_back(val);
        avg += val;
    }
    avg /= m;
    
    double imb = 0.0; 
    for(int i = 0; i < m; i++){
       imb += abs(avg - nodes[i]);
    }
    cout << "IMBALANCE = " << fixed << setprecision(5) << round(imb * 100000.0) / 100000.0 << endl;
}
