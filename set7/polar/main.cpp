#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


class Dset {
    public:
        int find(int x);   
        int finditr(int x);   
        bool sameSet(int x, int y);
        void dounion(int x, int y);
        int countUnique(int n);
        bool isRoot(int x);
        int numSets;
        Dset(int);
        ~Dset();
    
    private:
        int * theSet;
    
};
    
Dset::Dset(int size){
    theSet = (int *) malloc(sizeof(int) * size);
    numSets = size;
    memset(theSet, -1, size*sizeof(int));
}

Dset::~Dset(){
   free(theSet); 
}

bool Dset::isRoot(int x){
    return theSet[x] < 0; 
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
            numSets--;
            theSet[rootX] = rootY;
        }
        else if(theSet[rootX] <  theSet[rootY]){
            numSets--;
            theSet[rootY] = rootX;
        }
        else {
            numSets--;
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

struct Point {
    int x;
    int y;
    int elev;
    int ind;
};

bool pcompare(const Point &p1, const Point &p2){
    return p2.elev < p1.elev;
}

void neighbors(vector<int> &all, Point &p, int dimenx, int dimeny){
   //right
   if(p.x + 1 < dimenx){
        int r = p.y * dimenx + p.x + 1;
        all.push_back(r);
   }
   //left
   if(p.x - 1 >= 0){
        int l = p.y * dimenx + p.x - 1;
        all.push_back(l);
   }

   //up
   if(p.y - 1 >= 0){
       int u = (p.y - 1) * dimenx + p.x;
       all.push_back(u);
   }
   //down
   if(p.y + 1 < dimeny){
       int d = (p.y + 1) * dimenx + p.x;
       all.push_back(d);
   }
   return;
}
int main(){
    int n, m;
    cin >> n >> m;
    Point * points = (Point *) malloc(n*m*sizeof(Point));
    Dset islands(n*m);
    vector<Point> sorted_points;
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
            Point newPoint;
            int elev;
            cin >> elev;   
            newPoint.x = j;
            newPoint.y = i;
            newPoint.elev = elev;
            newPoint.ind = i * m + j;
            points[i*m+j] = newPoint;
            sorted_points.push_back(newPoint); 
       }
    }

    sort(sorted_points.begin(), sorted_points.end(), pcompare);
    int t;
    cin >> t;
    int elevs[t];
    for(int i = 0; i < t; i++){
        cin >> elevs[i];
    }

    int islandCts[t];
    int above = 0;
    int j = 0;
    for(int i = t-1; i >= 0; i--){
        islandCts[i] = 0;
        vector<int> inds; 
        while(j < n*m){
            if(sorted_points[j].elev > elevs[i]){
                above++;
                vector<int> nexts;
                neighbors(nexts, sorted_points[j], m, n);
                for(int k = 0; k < (int) nexts.size(); k++){
                    if(points[nexts[k]].elev > elevs[i]){
                       islands.dounion(points[nexts[k]].ind, sorted_points[j].ind); 
                    }
                }
                j++;
            }
            else {
                break;
            }
        }

        islandCts[i] = islands.numSets - (n*m - above);
    }

    //print
    for(int i = 0; i < t; i++){
        if(i < t - 1){
            cout << islandCts[i] << " ";
        }
        else {
            cout << islandCts[i];
        }
    }
    cout << endl;
    free(points);
    return 0;    
}
