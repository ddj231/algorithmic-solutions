#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Circle{
    double start;
    double end;
    double radius;   
};

bool cirCompare(const Circle& cir1, const Circle& cir2){
    if(cir1.start < cir2.start){
        return true;
    }
    else if(cir1.start > cir2.start){
        return false;
    }
    else {
        return cir1.end < cir2.end;
    }
}

void formatCircle(double w, double loc, double rad, Circle & cir){
    //pytagorean theorem.
   double side1 = w/2.0;  
   double side2 = rad;
   //a^2 + b^2 = c^2 , b = sqrt(c^2 - a^2)
   double side3;
   if(side2 * side2 - side1 * side1 < 0){
        side3 = 0;
   }
   else{
        side3 = sqrt(side2 * side2 - side1 * side1);
   }
   cir.start = loc - side3;
   cir.end = loc + side3;
}

int main(){
   int n;
   double l, w;
   cin >> n >> l >> w;
   vector<Circle> circles;
   for(int i = 0; i < n; i++){
        double rad, loc;
        cin >> loc >> rad;
        Circle cir;
        formatCircle(w, loc, rad, cir); 
        circles.push_back(cir);
   }

   sort(circles.begin(), circles.end(), cirCompare);

   //count circles needed
   double i = 0;
   int ct = 0;
   int index  = 0;

   int max_ind;
   while(i < l){
        bool found = false;
        double maxE = -1; 
        while(index < n){
           if(circles[index].start <= i){
                found = true;
                if(circles[index].end >= maxE){
                    maxE = circles[index].end;
                    max_ind = index;
                }
                index++;
           }
           else{
               break;
           }
        }

        i = maxE;
        ct++;

        if(!found){
            cout << -1 << endl;
            return 0;
        }

   }

   cout << ct << endl;

}
