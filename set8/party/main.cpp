#include <iostream>
#include <string.h>

using namespace std;

class Dset {
    public:
        int find(int x);   
        int finditr(int x);   
        bool sameSet(int x, int y);
        void dounion(int x, int y);
        int countUnique(int n);
        void setOwes(int index, int val);
        void isPossible(int n);
        Dset(int);
        ~Dset();
    
    private:
        int * theSet;
        int * owes;
};
    
Dset::Dset(int size){
    theSet = (int *) malloc(sizeof(int) * size);
    owes = (int *) malloc(sizeof(int) * size);
    memset(theSet, -1, size*sizeof(int));
    memset(owes, 0, size*sizeof(int));
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

void Dset::setOwes(int index, int val){
    owes[index] = val;
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
            owes[rootY] += owes[rootX];
            owes[rootX] = 0;
        }
        else if(theSet[rootX] <  theSet[rootY]){
            //theSet[rootX] += theSet[rootY];
            theSet[rootY] = rootX;
            owes[rootX] += owes[rootY];
            owes[rootY] = 0;
        }
        else {
            //theSet[rootY] += theSet[rootX];
            theSet[rootX] = rootY;
            theSet[rootY] -= 1;
            owes[rootY] += owes[rootX];
            owes[rootX] = 0;
        }
    }
}
void Dset::isPossible(int n){
    for(int i = 0; i < n; i++){
        if(owes[i] != 0){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << "POSSIBLE" << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    Dset myset(n);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        myset.setOwes(i, val);
    }

    for(int i = 0; i < m; i++){
        int val1, val2;
        cin >> val1 >> val2;
        myset.dounion(val1, val2);        
    }

    myset.isPossible(n);
    return 0;
}

