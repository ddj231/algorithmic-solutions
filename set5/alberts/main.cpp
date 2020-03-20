#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

string toLowercase(string word){
    string newWord("");
    for(int i = 0; i < word.length(); i++){
        newWord += tolower(word[i]);
    }
    return newWord;
}

void getWords(string word, vector <string> &words){
    string newWord("");
    int i = 0;
    while(i < word.length()){
        if(isalpha(word[i])){
            newWord+= word[i];        
        }
        else if(newWord != ""){
            words.push_back(newWord);
            newWord = "";
        }

        if(newWord != "" && i + 1 >= word.length()){
            words.push_back(newWord);
        }

        i++;
    }

}
int main(){

    string word;
    set<string> dict;
    while(cin >> word){
        word = toLowercase(word);
        vector<string> words;
        getWords(word, words);
        if(!words.empty()){
            for(int i = 0; i < words.size(); i++){
                dict.insert(words[i]);
            }
        }
    }

    for(auto it = dict.begin(); it != dict.end(); it++){ 
        cout << *it << endl;
    }
}
