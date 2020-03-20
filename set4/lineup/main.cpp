//line up
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){ 
    int n;
    cin >> n;
    std::map <int, int> qLoc;
    std::vector <queue <int> > allQs;
    std::queue <int> order;

    int curr = 0;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        queue <int> newQ;
        allQs.push_back(newQ);
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            qLoc[val] = i;
        }
    }

    string cmd;
    cin >> cmd;
    while(cmd != "Shutdown"){
        if(cmd == "Push"){
            int ind;
            cin >> ind;
            int loc = qLoc[ind];
            if(allQs[loc].empty()){
                order.push(loc);
            }
            allQs[loc].push(ind);
        }
        else if(cmd == "Pop"){ 
            if(order.empty()){
                return 0;
            }
            int printVal = allQs[order.front()].front();
            allQs[order.front()].pop();
            if(allQs[order.front()].empty()){
                order.pop();
            }
            cout << printVal << endl;
        }
        cin >> cmd;
    }

    return 0;

}
