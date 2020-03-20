//cims printer
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n, m, pos = 0, counter = 0;
    cin >> n >> m;
    int printq[n];
    int found = false;
    for(int i; i < n; i++){
        int priority;
        cin >> priority;
        printq[i] = priority;
    }

    std::vector <int> heap(printq, printq+n);
    std::make_heap(heap.begin(), heap.end());
    while(!found){
        if(pos % n == m && heap.front() == printq[m]){
            counter++;
            found = true;
            break; 
        }
        else if(heap.front() == printq[pos % n]){
            pop_heap(heap.begin(), heap.end()); 
            heap.pop_back(); 
            counter++;
        }
        pos++;
    }

    cout << counter << endl;
}
