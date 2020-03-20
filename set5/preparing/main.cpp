//preparing
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int start, leftover = 0;
    vector<int> created;
    vector<int> needed;
    vector<string> response;
    string alot = "A lot of grading.";
    string no = "No homework.";
    cin >> start;
    leftover = start;
    for(int i = 0; i < 24; i++){
        int curr;
        cin >> curr;
        if(i < 12){
            created.push_back(curr);
        }
        else{
            needed.push_back(curr);
        }
    }

    for(int i = 0; i < 12; i++){
       if(needed[i] <= leftover){
            leftover -= needed[i];
            response.push_back(alot);
       }
       else{
            response.push_back(no);
       }
       leftover += created[i];
    }

    for(int i = 0; i < 12; i++){
        cout << response[i] << endl;
    }

    return 0;
}
