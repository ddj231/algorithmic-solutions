//stack puzzle
//worked with Willie Yee
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

std::stack <char> mystack;
string sword, tword;
string output("[\n");

void getCombs(int i, int j, string sofar){
   
    //Base case
    if(i == sword.length() && j == tword.length()){
        //found a combination add to final string
        output += sofar;
        output = output.substr(0, output.length() - 1);
        output += "\n";
        return;
    } 
    else if(i == sword.length() && j < tword.length()){
        //not a valid combination
        if(!mystack.empty() && mystack.top() == tword[j]){
            string popstring(sofar);
            char theTop = mystack.top();
            popstring += "o ";
            mystack.pop();
            getCombs(i, j + 1, popstring);
            mystack.push(theTop);
        }
       // return;
    }
    

    //recursive step 
    
    //pushing
    if(i < sword.size()){
        sofar += "i ";
        mystack.push(sword[i]);
        getCombs(i + 1, j, sofar);
        sofar = sofar.substr(0, sofar.length() - 2);
        mystack.pop();
    }

    //popping    
    if(!mystack.empty() && i != sword.length()){
        if(mystack.top() == tword[j]){
            string popstring(sofar);
            char theTop = mystack.top();
            popstring += "o ";
            mystack.pop();
            getCombs(i, j + 1, popstring);
            mystack.push(theTop);
        }
    }

    return;
}

int main(){

    cin >> sword >> tword;
    
    //recursively compute possibilities
    string sofar("");
    getCombs(0, 0, sofar);

    cout << output << "]" << endl;
}
