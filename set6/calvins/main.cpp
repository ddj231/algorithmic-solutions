#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
    float x;
    float y;
};

class Dset {
    public:
        int find(int x);   
        int finditr(int x);   
        bool sameSet(int x, int y);
        void dounion(int x, int y);
        int countUnique(int n);
        Dset(int);
        ~Dset();
    
    private:
        int * theSet;
    
};
    
Dset::Dset(int size){
    theSet = (int *) malloc(sizeof(int) * size);
    memset(theSet, -1, size*sizeof(int));
}

Dset::~Dset(){
   free(theSet); 
}

int Dset::find(int x){
   if(theSet[x] < 0){
        return x;
   }
   return theSet[x] = find(theSet[x]);
}

bool Dset::sameSet(int x, int y){
    return find(x) == find(y);
}

void Dset::dounion(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    //note the rank is stored as negative numbers
    //thus "greater" rank is actually less in value 
    if (rootX != rootY){
        if(theSet[rootX] > theSet[rootY]){
            //theSet[rootY] += theSet[rootX];
            theSet[rootX] = rootY;
        }
        else if(theSet[rootX] <  theSet[rootY]){
            //theSet[rootX] += theSet[rootY];
            theSet[rootY] = rootX;
        }
        else {
            //theSet[rootY] += theSet[rootX];
            theSet[rootX] = rootY;
            theSet[rootY] -= 1;
        }
    }
}

int Dset::countUnique(int n){
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(theSet[i] < 0){
            counter++;
        }
    }
    return counter;
}

float calculateDistance(struct Point p1, struct Point p2){
   float distance = 0;
   float xs = (p1.x - p2.x) * (p1.x - p2.x);
   float ys = (p1.y - p2.y) * (p1.y - p2.y);
   distance = sqrt(xs + ys);
   return distance;
}

int main(){

    int n;
    float d;
    cin >> n >> d;
    struct Point points[n];
    Dset myset(n);

    for(int i = 0; i < n; i++){
       float x, y;
       cin >> x >> y;
       struct Point tempPoint = {x, y};
       points[i] = tempPoint;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(calculateDistance(points[i], points[j]) <= d){
                myset.dounion(i, j);
            }
        }
    }

    cout << myset.countUnique(n);

    return 0;
}
