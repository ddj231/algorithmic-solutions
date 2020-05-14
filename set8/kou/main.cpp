#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int findbehind(int * arr, int start, int val){
    int loc = -1;
    for(int i = start; i >= 0; i--){
       if(arr[i] == val){
            loc = i;
            break;
       }
    }
    return loc;
}

void swapTo(int from, int to, int * arr){
    for(int i = from; i < to; i++){
       int temp = arr[i];
       arr[i] = arr[i + 1];
       arr[i + 1] = temp;
    } 
}*/

//Merge sort inspired by geeksforgeeks algorithm on counting inversions
long int merger(int arr[], int temp[], int left, int mid, int right);

long int merge_sort(int arr[], int temp[], int left, int right){
    long int ct = 0;
    int mid;
    if(right > left){
       mid = (right + left)/2;
       ct += merge_sort(arr, temp, left, mid);
       ct += merge_sort(arr, temp, mid + 1, right);

       ct += merger(arr, temp, left, mid + 1, right);
    }
    return ct;
}

long int merger(int arr[], int temp[], int left, int mid, int right){
    int i, j, k;
    i = left;
    j = mid;
    k = left;
    long int ct = 0;
    while(i <= mid - 1 && j <= right){
           if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
           } 
           else {
                temp[k++] = arr[j++];
                ct += (mid - i);
           }
    } 

    while(i <= mid -1){
        temp[k++] = arr[i++];
    }

    while(j <= right){
        temp[k++] = arr[j++];
    }

    for(int h = left; h <= right; h++){
        arr[h] = temp[h];
    }
    return ct;
}



int main(){
    int n;
    cin >> n;
    int * arr = (int *) malloc(sizeof(int) * n);
    vector<int> sorted_arr;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr[i] = val;
    }
    int * temp = (int *) malloc(sizeof(int) * n);

    long int ct = merge_sort(arr, temp, 0, n - 1);
    /*
    sort(sorted_arr.begin(), sorted_arr.end());
    int ct = 0;
    for(int i = n-1; i > 0; i--){
        if(sorted_arr[i] != arr[i]){
            int swap_from = findbehind(arr, i - 1, sorted_arr[i]);
            swapTo(swap_from, i, arr);
            ct += i - swap_from;
        } 
    }*/
    free(arr);
    free(temp);
    cout << ct << endl;
}
