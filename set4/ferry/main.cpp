//ferry
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main(){

    queue <vector<int> > leftQ;
    queue <vector<int> > rightQ;

    int carsPer, ttime, totalCars;
    cin >> carsPer >> ttime >> totalCars;
    int arr[totalCars];
    for(int i = 0; i < totalCars; i++){
        arr[i] = 0;
    }
    
    for(int i = 0; i < totalCars; i++){
        int arrivingAt;
        string bank;
        cin >> arrivingAt >> bank;
        if(bank == "left"){
            std::vector<int>  valAndLoc;
            valAndLoc.push_back(arrivingAt);
            valAndLoc.push_back(i);
            leftQ.push(valAndLoc);
        }
        else{
            std::vector<int>  valAndLoc;
            valAndLoc.push_back(arrivingAt);
            valAndLoc.push_back(i);
            rightQ.push(valAndLoc);
        } 
    }

    int loc = 0;
    int currTime = 0;
    int done = false;
    int cars;
    std::vector <int> times;
    
    
    while(!done){
        if(loc == 0){
            cars = 0; 
            while(!leftQ.empty() && (leftQ.front())[0] <= currTime && cars < carsPer){
                cars++;
                std::vector<int> car = leftQ.front();
                arr[car[1]] = ttime + currTime;
                leftQ.pop();
                //times.push_back(currTime + ttime); 

            }

            if(cars == 0 && !leftQ.empty() && !rightQ.empty() && (rightQ.front())[0] >= (leftQ.front())[0]){
                currTime = (leftQ.front())[0]; 
                continue;
            }
            else if(cars == 0 && !leftQ.empty() && !rightQ.empty() && (rightQ.front())[0] < (leftQ.front())[0]){
                currTime = ttime + (rightQ.front())[0] < currTime + ttime ? currTime + ttime : ttime + (rightQ.front())[0]; 
                loc = 1;
            }
            else if(cars == 0 && !rightQ.empty() && leftQ.empty()){
                currTime = ttime + (rightQ.front())[0] < currTime + ttime ? currTime + ttime : ttime + (rightQ.front())[0]; 
                loc = 1;
            }
            else if(cars == 0 && rightQ.empty() && !leftQ.empty()){
                currTime = (leftQ.front())[0]; 
            }
            else{
                loc = 1;
                currTime += ttime; 
            }
        }
        else if(loc == 1){
            cars = 0; 
            while(!rightQ.empty() && (rightQ.front())[0] <= currTime && cars < carsPer){
                cars++;
                std::vector<int> car = rightQ.front();
                arr[car[1]] = ttime + currTime;
                rightQ.pop();
                //times.push_back(currTime + ttime); 
            }

            if(cars == 0 && !leftQ.empty() && !rightQ.empty() && (rightQ.front())[0] <= (leftQ.front())[0]){
                currTime = (rightQ.front())[0]; 
                continue;
            }
            else if(cars == 0 && !leftQ.empty() && !rightQ.empty() && (rightQ.front())[0] > (leftQ.front())[0]){
                currTime = ttime + (leftQ.front())[0] < currTime + ttime ? currTime + ttime : ttime + (leftQ.front())[0]; 
                loc = 0;
            }
            else if(cars == 0 && rightQ.empty() && !leftQ.empty()){
                currTime = ttime + (leftQ.front())[0] < currTime + ttime ? currTime + ttime : ttime + (leftQ.front())[0]; 
                loc = 0;
            }
            else if(cars == 0 && !rightQ.empty() && leftQ.empty()){
                currTime = (rightQ.front())[0]; 
            }
            else{
                loc = 0;
                currTime += ttime; 
            } }

        if(rightQ.empty() && leftQ.empty()){
            done = true;
        }
    } 

    for(int i = 0; i < totalCars; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
