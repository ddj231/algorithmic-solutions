//I was helped by Willie Yee to understand
//the Trigonometry for this problem 
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

double getlen(double l, double d){
    double r = (l*l)/(8*d) + d/2.0;
    double theta = 2.0 * asin(l/(2.0*r));
    return r * theta;
}

double find_d(double arclen, double l){
   //curr_len = r*theta 
   double start = 0;
   double end = l;
   while(start < end){
        double mid = (start + end) / 2;
        double curr_len = getlen(l, mid); 
        if(fabs(curr_len - arclen) < .000001){
            return mid;
        }
        else if(curr_len > arclen){
            end = mid;
        }
        else{
            start = mid;
        }
   }
   return -1;
}

int main(){
    double l, c, t;
    cin >> l >> t >> c; 
    if(l == 0 || t == 0 || c == 0){
        cout << "0.000" << endl;
        return 0;
    }
    double arclen = l*(1+t*c);
    cout << fixed << setprecision(3) << find_d(arclen, l) << endl;

}
