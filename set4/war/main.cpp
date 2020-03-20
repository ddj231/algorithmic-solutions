//war
#include <iostream>
#include <string>

using namespace std;


void markInvalid(int* arr, int start, int end){
    for(int i = start; i <= end; i++){
        arr[i] = -1;
    }
}

int lookLeft(int * arr, int start){
    for(int i = start - 1; i > 0; i--){
        if(arr[i] != -1){
            return i;
        }
    }
    return -1;
}

int lookRight(int * arr, int start, int n){
    for(int i = start + 1; i <= n; i++){
        if(arr[i] != -1){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    for(int i = 0; i <= n; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        markInvalid(arr, start, end);
        int left = lookLeft(arr, start);
        int right = lookRight(arr, end, n);
        cout << (left < 0 ? "*": std::to_string(left)) << " " << (right < 0 ? "*": std::to_string(right)) << endl;
    }
    
    return 0;
}
