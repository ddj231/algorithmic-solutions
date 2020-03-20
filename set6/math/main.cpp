//math
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//92 929

bool compareNumsHelper(string num1, string num2){
       int size1 = num1.length();
       int size2 = num2.length(); 
       int i = 0;
       while(i < size1 || i < size2){
           if(num1[i] > num2[i]){
                return true;
           }
           else if (num1[i] <  num2[i]){
                return false;
           }
           else{
                i++; 
           }
       }
        
       return false;
}

bool compareNums(string nums1, string nums2){
    string temp1("");
    string temp2("");
    temp1 = nums1 + nums2;
    temp2 = nums2 + nums1;
    return compareNumsHelper(temp1, temp2); 
}

/*
bool compareNumsHelper(string num1, string num2){
       int size1 = num1.length();
       int size2 = num2.length(); 
       int i = 0;
       while(i < size1 || i < size2){
           if(i >= size1){
               if(num1[0] <= num2[i])
                   return false;
               return true; 
           }
           else if(i >= size2){
               if(num1[i] >= num2[0])
                    return true;
                return false;
           }
           else if(num1[i] > num2[i]){
                return true;
           }
           else if (num1[i] <  num2[i]){
                return false;
           }
           else if (num1[i] == num2[i]){
                i++; 
           }
       }
        
       return false;
}
*/
string stripLeadingZeros(string num){
    string output("");
    int start = 0;
    for(int i  = 0; i < (int) num.length(); i++){
       if(num[i] == '0'){
            continue; 
       }
       else{
            start = i;
            break;
       }
    }

    output = num.substr(start, num.npos);
    return output;
}

int main(){

    string output("");
    string curr("");
    vector<string> strings;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> curr;
        strings.push_back(stripLeadingZeros(curr));
    }
    std::sort(strings.begin(), strings.end(), compareNums);

    for(int i = 0; i < n; i++){
       cout << strings[i]; 
    }
    cout << endl;
    return 0;
}
