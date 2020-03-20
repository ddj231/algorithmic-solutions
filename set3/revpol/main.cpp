#include <iostream>
#include <set>
#include <stack>

using namespace std;

bool hasHigherPrec(char one, char two){
    if(one == two){
        return true;
    }
    if((one == '+' || one == '-') && (two == '*' || two == '/')){
        return false;
    }
    return true;
}

int main(){

    char ch;
    string infix("");
    string postfix("");
    std::stack<char> mystack;

    while(cin >> ch){
       infix += ch; 
    }

    char operators[] = {'*', '+', '-', '/'};
    std::set <char> oprators (operators, operators+4);
    char operands[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::set <char> oprands (operands, operands+10);

    for(int i = 0; i < infix.length(); i++){
        if(oprands.count(infix[i]) != 0){
            postfix += infix[i];
        }
        else if(infix[i] == '('){
            mystack.push(infix[i]);
        }
        else if(oprators.count(infix[i]) != 0){
            if(!mystack.empty()){
                while(!mystack.empty() && mystack.top() != '(' && hasHigherPrec(mystack.top(), infix[i])){
                    postfix += mystack.top();
                    mystack.pop();
                }
            }
            mystack.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(!mystack.empty()){
                if(mystack.top() != '('){
                    postfix += mystack.top();
                    mystack.pop();
                }
                else{
                    mystack.pop();
                    break; 
                }
            }
            
        }
    }

    while(!mystack.empty()){
        postfix += mystack.top();
        mystack.pop(); 
    }
    
    cout << postfix << endl;

    return 0;    
}
