#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <string.h>

class Dset {
    public:
        int find(int x);   
        int finditr(int x);   
        bool sameSet(int x, int y);
        void dounion(int x, int y);
        int countUnique(int n);
        //void moveElem(int a, int b, int n);
        void moveElem2(int a, int b);
        long long int getSetSum(int a);
        int getSetSize(int a);
        Dset(int, int size);
        //~Dset();
    
    private:
        //int * theSet;
        vector<long long int> theSet;
        vector<long long int> sums;
        vector<long long int> identities;
        int availble;
    
};
    
Dset::Dset(int size, int n){
    //theSet = (int *) malloc(sizeof(int) * size);
    //memset(theSet, -1, size*sizeof(int));
    //initialize default sums 
    //and set
    for(int i = 0; i < n; i++){
        theSet.push_back(-1);
        sums.push_back(i);
        identities.push_back(i);
    }
    for(int i = n + 1; i < size; i++){
        theSet.push_back(-1);
    }
    availble = n + 1;
}

/*
Dset::~Dset(){
   free(theSet); 
}
*/

int Dset::find(int x){
   if(theSet[x] < 0){
        return x;
   }
   return theSet[x] = find(theSet[x]);
}

long long int Dset::getSetSum(int a){
    //cout << " get set sum of " << a << endl;
    //cout << " identity of a is " << identities[a] << endl;
    int rootA = find(identities[a]);
    return sums[rootA];
}

int Dset::getSetSize(int a){
    int rootA = find(identities[a]);
    return theSet[rootA] * -1;
}


//void Dset::moveElem(int a, int b, int n){
//    int rootA = find(a);
//    int rootB = find(b);
//
//    rootA = identities[rootA];
//    rootB = identities[rootB];
//
//    if(rootA == rootB){
//        return;
//    }
//
//    if(a == rootA){
//        //a was a root more work to do
//        int newRoot = -1;
//        int size = theSet[rootA]; 
//        //find new root
//        for(int i = 0; i < n; i++){
//            if(theSet[i] == rootA){
//                newRoot = i; 
//                theSet[i] = theSet[rootA];
//                theSet[a] = newRoot;
//                theSet[newRoot] = size;
//                sums[newRoot] = sums[a];
//                break;
//            } 
//        }
//        //update all
//        for(int i = newRoot + 1; i < n; i++){
//            //move all children of a to new root
//            if(theSet[i] == rootA){
//                theSet[i] = newRoot;
//                size--;
//            } 
//            if(size <= 0){
//                break;
//            }
//        }
//
//        //move a to set b
//        theSet[a] = rootB;
//        theSet[newRoot] += 1;
//        theSet[rootB] -= 1;
//        sums[rootB] += a;
//        sums[newRoot] -= a;
//    }
//    else{
//        /*
//        for(int i = 0; i < n; i++){
//            //move all children of a to root
//            if(theSet[i] == a){
//                theSet[i] = rootA;
//            } 
//        }
//        */
//        //move a to b's set 
//        //make b one size bigger
//        //theSet[a] = rootB;
//        theSet[rootA] += 1;
//        theSet[rootB] -= 1;
//        sums[rootB] += a;
//        sums[rootA] -= a;
//        theSet[availble] = rootB;
//        identities[a] = availble;
//        availble++;
//    }
//}

void Dset::moveElem2(int a, int b){
    //cout << "moving " << a << " to " << b << endl;
    int rootA = find(identities[a]);
    int rootB = find(identities[b]);
    //cout << " root a is " << rootA << endl;
    //cout << " root b is " << rootB << endl;
    identities[a] = ++availble;    
    //cout << "identity of new A is " << availble << endl;
    //availble++;
    theSet[availble] = rootB;
    //cout << "identity of new A is " << availble << endl;
    theSet[rootA] += 1;
    theSet[rootB] -= 1;
    //cout << "set a size now " << theSet[rootA]<< endl;
    //cout << "set b size set now " << theSet[rootB]<< endl;
    sums[rootB] += a;
    sums[rootA] -= a;
    //cout << "sums of set a former set now " << sums[rootA]<< endl;
    //cout << "sums of set b set now " << sums[rootB]<< endl;
}

void Dset::dounion(int x, int y){
    //cout << "union of " << x << " and " << y << endl;
    int rootX = find(identities[x]);
    int rootY = find(identities[y]);
    //cout << " root x is " << rootX << endl;
    //cout << " root y is " << rootY << endl;
    //note the rank is stored as negative numbers
    //thus "greater" rank is actually less in value 
    //rootX = identities[rootX];
    //rootY = identities[rootY];

    if (rootX != rootY){
        if(theSet[rootX] > theSet[rootY]){
            theSet[rootY] += theSet[rootX];
            theSet[rootX] = rootY;
            sums[rootY] += sums[rootX];
            sums[rootX] = 0;
        }
        else if(theSet[rootX] <  theSet[rootY]){
            theSet[rootX] += theSet[rootY];
            theSet[rootY] = rootX;
            sums[rootX] += sums[rootY];
            sums[rootY] = 0;
        }
        else {
            theSet[rootY] += theSet[rootX];
            theSet[rootX] = rootY;
            sums[rootY] += sums[rootX];
            sums[rootX] = 0;
            //theSet[rootY] -= 1;
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    Dset mySet(n + m + 1, n + 1);
    for(int i = 0; i < m; i++){
        int todo;
        int a, b;
        cin >> todo;
        if(todo == 1){
            cin >> a >> b;
            mySet.dounion(a, b);
        }
        else if(todo == 2){
            cin >> a >> b;
            mySet.moveElem2(a, b);
        }
        else {
            cin >> a;
            cout <<  mySet.getSetSize(a) << " " << mySet.getSetSum(a) << endl; 
        }
    }
    return 0;
}







