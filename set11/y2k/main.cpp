#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Comp {
    int ai;
    int bi;
    int yi;
};

int main(){
    int n;
    cin >> n;
    vector<Comp> computers;
    int best = 0;
    int maxInd = 0;
    for(int i=0; i < n; i++){
       int ai, bi, yi; 
       Comp c;
       cin >> yi >> ai >> bi;
       if(best < ai){
            best = ai;
            maxInd = i;
       }
       c.ai = ai;
       c.bi = bi;
       c.yi = yi;
       computers.push_back(c);
    }
    //get the computer with the maximum ai
    Comp testComp = computers[maxInd];    
    int display = testComp.yi;
    //cout << "display is " << display << endl;
    bool found = true;
    int output = -1;
    while(display < 10000){
       for(int i = 0; i < n; i++){
            if(!(((display - computers[i].ai)  % (computers[i].bi - computers[i].ai)) + computers[i].ai  == computers[i].yi)){
                   found = false; 
            }
       } 
       if(found == true){
            output = display;
            break;
       }
       
       display += testComp.bi - testComp.ai;
       found = true;
    }

    cout << output << endl;
}
