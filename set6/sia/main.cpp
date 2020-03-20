//sia
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue <int, vector<int> > pq;
    queue <int> q;
    stack <int> mystack;
    bool whatDs [] = {true, true, true};
    for(int i = 0; i < n; i++){
        int op, val;
        cin >> op >> val;
        if(op == 1){
            pq.push(val);
            q.push(val);
            mystack.push(val);
        }
        else if(op == 2){
            //priority queue
            if(pq.empty()){
                whatDs[0] = false;
            }
            else if(pq.top() != val){
                whatDs[0] = false;
            }
            else{
                pq.pop();
            }

            //queue
            if(q.empty()){
                whatDs[1] = false;
            }
            else if(q.front() != val){
                whatDs[1] = false;
            }
            else{
                q.pop();
            }

            //stack
            if(mystack.empty()){
                whatDs[2] = false;
            }
            else if(mystack.top() != val){
                whatDs[2] = false;
            }
            else{
                mystack.pop();
            }

        }
    }
    if(whatDs[0] && !whatDs[1] && !whatDs[2]){
        cout << "priority queue" << endl;
    }
    else if(!whatDs[0] && whatDs[1] && !whatDs[2]){
        cout << "queue" << endl;
    }
    else if(!whatDs[0] && !whatDs[1] && whatDs[2]){
        cout << "stack" << endl;
    }
    else if(!whatDs[0] && !whatDs[1] && !whatDs[2]){
        cout << "impossible" << endl;
    }
    else{
        cout << "not sure" << endl;
    }
    return 0; 
}

