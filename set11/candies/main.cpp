#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main(){
    long int box1[3], box2[3], box3[3];
    long int total = 0;
    long int large = LONG_MAX;
    for(int i = 0; i < 3; i++){
        cin >> box1[i];
        total += box1[i];
    }
    for(int i = 0; i < 3; i++){
        cin >> box2[i];
        total += box2[i];
    }
    for(int i = 0; i < 3; i++){
        cin >> box3[i];
        total += box3[i];
    }

    //all combinations
    long int tempTotal = total;
    string bestStr("ZZZ");
    long int best = INT_MAX;
    
    //GCB
    tempTotal -= (box1[1] + box2[2] + box3[0]);
    if(tempTotal < best){
        best = tempTotal;
        bestStr = "GCB";
    } 
    else if(tempTotal == best && bestStr.compare("GCB") > 0){
        best = tempTotal;
        bestStr = "GCB";
    }

    tempTotal = total;

    //GBC
    tempTotal -= (box1[1] + box2[0] + box3[2]);
    if(tempTotal < best){
        best = tempTotal;
        bestStr = "GBC";
    } 
    else if(tempTotal == best && bestStr.compare("GBC") > 0){
        best = tempTotal;
        bestStr = "GBC";
    }

    tempTotal = total;
    //CBG
    tempTotal -= (box1[2] + box2[0] + box3[1]);
    if(tempTotal < best){
        best = tempTotal;
        bestStr = "CBG";
    } 
    else if(tempTotal == best && bestStr.compare("CBG") > 0){
        best = tempTotal;
        bestStr = "CBG";
    }
    tempTotal = total;

    //CGB
    tempTotal -= (box1[2] + box2[1] + box3[0]);
    if(tempTotal < best){
        best = tempTotal;
        bestStr = "CGB";
    } 
    else if(tempTotal == best && bestStr.compare("CGB") > 0){
        best = tempTotal;
        bestStr = "CGB";
    }
    tempTotal = total;

    //BCG
    tempTotal -= (box1[0] + box2[2] + box3[1]);
    if(tempTotal < best){
        best = tempTotal;
        bestStr = "BCG";
    } 
    else if(tempTotal == best && bestStr.compare("BCG") > 0){
        best = tempTotal;
        bestStr = "BCG";
    }

    tempTotal = total;
    
    //BGC
    tempTotal -= (box1[0] + box2[1] + box3[2]);
    if(tempTotal < best){
        best = tempTotal;
        bestStr = "BGC";
    } 
    else if(tempTotal == best && bestStr.compare("BGC") > 0){
        best = tempTotal;
        bestStr = "BGC";
    }

    cout << bestStr << " " << best << endl;
}
