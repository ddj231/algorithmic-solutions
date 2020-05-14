#include <iostream>
#include <math.h>
#include <iomanip>
#include <limits>
#include <cmath>
#include <type_traits>

using namespace std;

double testeq(double x, int a, int b,int c, int d, int e, int f){
    return a*exp(-x) + b * sin(x) + c * cos(x) + d * tan(x) + e * x * x + f;
}


int main(){
    int a, b, c, d, e,f;
    cin >> a >> b >> c >> d >> e >> f; 
    double start = 0.0;
    double end = 1.0;
    bool increasing;
    
    if(testeq(0.0, a, b, c, d, e, f) >= testeq(1.0, a, b, c, d, e, f)){
        increasing = false; 
    }
    else{
        increasing = true;
    }
     
    double sol = -1.0;
    int ct = 0;

    if(testeq(0.0, a, b, c, d, e, f) == 0){
        cout << "0.0000" << endl;
        return 0;
    }
    else if(testeq(1.0, a, b, c, d, e, f) == 0){
        cout << "1.0000" << endl;
        return 0;
    }
    
    double eps  = 0.00001;

    while(start < end){
            double middle = (start + end) / 2;
            if(fabs(testeq(middle, a, b, c, d, e, f)) <= eps){
                sol = middle;
                break; 
            } 
            else if(testeq(middle, a, b, c, d, e, f) > 0){
                if(increasing){
                    end = middle;
                }
                else {
                    start = middle;
                }
            }
            else if(testeq(middle, a, b, c, d, e, f) < 0){
                if(increasing){
                    start = middle;
                }
                else{
                    end = middle;
                }
            }
            ct++;
    }

    if(sol == -1.0){
        cout << "No solution" << endl;
    }
    else{
        cout << fixed << setprecision(4) << sol << endl;
    }
}
