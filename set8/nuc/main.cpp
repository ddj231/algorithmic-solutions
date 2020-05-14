#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int sortedness(string s, int len){
    int total = 0;
    //cout << "string is " << s << endl;
    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if(s[i] > s[j]){
                //cout << "char " << s[i] << " is greater than " << "char " << s[j] << endl;
                total++;
            }
        }
    }
    return total;
}

struct Acid {
    string s;
    int sness;
    int index;
};

bool acompare(const Acid& a, const Acid& b){
   if(a.sness != b.sness){
        return a.sness < b.sness;
   } 
   else{
        return a.index < b.index;
   }
}

int main(){
    int n, m;
    cin >> n >> m;
    if( n == 0 || m == 0){
        return 0;
    }
    vector<Acid> acids;
    for(int i = 0; i < m; i++){
        string mystr;
        cin >> mystr;
        Acid newAcid;
        newAcid.s = mystr;
        newAcid.index = i;
        newAcid.sness = sortedness(mystr, n); 
        //cout << " sortedness of " << mystr << " is " << newAcid.sness << endl;
        acids.push_back(newAcid);
    }

    sort(acids.begin(), acids.end(), acompare);

    for(int i = 0; i < m; i++){
        cout << acids[i].s << endl;
    }

    return 0;
}

