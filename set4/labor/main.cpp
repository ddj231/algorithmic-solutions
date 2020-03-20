//labor
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int m, n;
    cin >> m >> n;
    vector <int> days;
    int strikes = 0;
    vector <bool> sched(m + 1);

    for(int i = 0; i <= m; i++){
        sched[i] = false; 
    }
    for(int i = 0; i < n; i++){
        int day;
        cin >> day;
        days.push_back(day);
    }

    for(int i = 0; i < days.size(); i++){
        int start = days[i];
        while(start <= m){
            if(start % 7 != 0 && start % 7 != 6 && sched[start] == false){ 
                sched[start] = true;
                strikes++; 
            }
            start = start + days[i];
        }
    }

    cout << strikes << endl;
}
