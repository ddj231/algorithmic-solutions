#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long best_part(vector<int> &vals, int amt){
   int len = vals.size(); 
   long long high = 0, low = 0, mid = 0;
   for(int i = 0; i < len; i++){
        high += vals[i];
        if(low < vals[i]){
            low = vals[i];
        }
   }

   while(low < high){
        mid = (low + high)/2;

        long long sum = 0;
        int parts = 1;
        
        for(int i = 0; i < len; i++){
            if(sum + vals[i] > mid){
                sum = vals[i];
                parts++;
            }
            else{
                sum += vals[i];
            }
        }

        if(parts <= amt){
           high = mid; 
        }
        else{
            low = mid + 1;
        }
   }

   mid = (low + high)/2;

   return mid;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> vals;
    for(int i =0; i < n; i++){
        int val;
        cin >> val;
        vals.push_back(val);
    }        
    long long int partSize =  best_part(vals, m); 
    string output("");
    long long int curr = 0; 

    //find splits
    vector<int> splits;
   
    for(int i = n - 1; i > 0 ; i--){
       curr += vals[i]; 

       if(curr + vals[i - 1] > partSize){
            curr = 0;
            splits.push_back(i - 1);
       }
    }

    int diff = m - ((int) splits.size() + 1);
    reverse(splits.begin(), splits.end());
    int loc = 0;
    int i = 0;
    vector<int> newSplits;
    int ct = 0;
    while(i < (int) splits.size() && ct < diff){
      if(splits[i] - loc > 0){
           newSplits.push_back(loc); 
           loc += 1;
           ct++;
      } 
      else{
           loc = splits[i] + 1;
           i++;
      }
    } 

    if(m == 1){
        for(int i = 0; i < n - 1; i++){
            cout << vals[i] << " "; 
        }
        cout << vals[n - 1] << endl;
        return 0;
    }

    for(int i = 0; i < (int) newSplits.size(); i++){
        splits.push_back(newSplits[i]);
    }

    sort(splits.begin(), splits.end());

    int j = 0;

    for(int i = 0; i < n; i++){
       output += to_string(vals[i]);
       if(i != n - 1){
           output += " ";
       }
       if(i == splits[j]){
            output += "/ ";
            j++;
       }
    }
    
    cout << output << endl;
}


