#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Patient {
    public:
    int id;
    int currT;
};

struct ComparePatient {
    bool operator() (Patient const& p1, Patient const& p2){
        if(p1.currT > p2.currT){
            return true;
        }
        else if(p1.currT < p2.currT){
            return false;
        }
        else if(p1.id > p2.id){
            return true;
        }
        else if(p1.id < p2.id){
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<Patient> patients(n);
    vector <priority_queue<Patient, vector<Patient>, ComparePatient > > offices(m);
    vector<queue<int> > toVisit(n);
    for(int i = 0; i < n; i++){
        int t, k;
        cin >> t >> k;
        patients[i].id = i;
        patients[i].currT = t;
        for(int j = 0; j < k; j++){
            int office;
            cin >> office;
            toVisit[i].push((office - 1));
        }
    }
    
    bool valid = true;
    int currT = 0;
 
    int newResult = 0;
    for(int i = 0; i < n; i++){ 
        offices[toVisit[i].front()].push(patients[i]);
    }
    int doneCount = 0;
    while(valid){
        int emptyCount = 0;
        for(int i = 0; i < m; i++){
           if(!offices[i].empty() && offices[i].top().currT <= currT){
                Patient p = offices[i].top();
                toVisit[p.id].pop();
                if(!toVisit[p.id].empty()){
                    offices[i].pop();
                    p.currT = currT + 1;
                    offices[toVisit[p.id].front()].push(p);
                    continue;
                }
                else if(toVisit[p.id].empty()){
                    newResult = currT + 1;
                    doneCount++;
                    offices[i].pop();
                }
           }
           else if(offices[i].empty()){
                emptyCount++;
           }
           if(emptyCount == m || doneCount == n){
                valid = false;
                break;
           }
        }
        currT++;
    }
    cout << newResult << endl;

}
