#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


void isValid(int * arr, int n){
    std::stack <int> mystack;
    int tofind = 0, pos = 1;
    bool valid = true;

    while(valid){ 
        if(tofind == n){
            break;
        }
        else if(!mystack.empty()){
           if(mystack.top() == arr[tofind]){
                mystack.pop();
                tofind++;
           }
           else if(pos <= n){
                mystack.push(pos);
                pos++;
           }
           else{
                valid = false;
           }
           
        }
        else if(mystack.empty() && pos <= n){
            mystack.push(pos);
            pos++;
        }
        else{
            valid = false;
        }
    }
    cout << (valid ? "Yes\n" : "No\n");
}

int main(){

    int n;
    vector <string> inputs;
    string currline;
    cin >> n;
   
    //get inputs 
    getline(cin, currline);
    while(currline[0] != '0'){
        inputs.push_back(currline);
        getline(cin, currline);
    }

    for(int i = 1; i < inputs.size(); i++){
        int arr[n]; 
        std::istringstream iss(inputs[i]); 
        for(int j = 0; j < n; j++){
           int a;
           iss >> a;
           arr[j] = a;
        }

        isValid(arr, n);
    }
}
