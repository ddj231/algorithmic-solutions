#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int arr[6];
    int boxes = 0;
    for(int i = 0; i < 6; i++){
        cin >> arr[i];
    }
    
    //6 x 6 boxes
    boxes += arr[5];

    //5 x 5 boxes
    for(int i = 0; i < arr[4]; i++){
        boxes += 1;

        arr[0] -= min(arr[0], 11); 
        /*
        for(int j = 0; j < 11; j++){
           if(arr[0] > 0)
              arr[0]--; 
        }
        */
    }

    //4x4 boxes
    for(int i = 0; i < arr[3]; i++){
        int left = 36;
        boxes += 1;
        left -= 16;
        for(int j = 0; j < 5; j++){
            if(arr[1] > 0){
                arr[1]--;
                left -= 4;
            }
        }

        arr[0] -= min(arr[0], left); 
        /*
        for(int j = 0; j < left; j++){
            if(arr[0] > 0)
                arr[0]--;
        }
        */
    }

    //3x3 boxes
    boxes += arr[2] / 4; 
    int rem = arr[2] % 4;
    if(rem == 1){
        boxes += 1;
        int left = 27;
        for(int j = 0; j < 5; j++){
            if(arr[1] > 0){
                arr[1]--;
                left -= 4;
            }
        }

        /* 
        for(int j = 0; j < left; j++){
            if(arr[0] > 0)
                arr[0]--;
        }
        */
        arr[0] -= min(arr[0], left); 
    }
    else if(rem == 2){
        boxes += 1;
        int left = 18;
        for(int j = 0; j < 3; j++){
            if(arr[1] > 0){
                arr[1]--;
                left -= 4;
            }
        }
        
        
        arr[0] -= min(arr[0], left); 
        /*
        for(int j = 0; j < left; j++){
            if(arr[0] > 0)
                arr[0]--;
        }
        */

    }
    else if(rem == 3){
        boxes += 1;
        int left = 9;
        if(arr[1] > 0){
             arr[1]--;
             left -= 4;
        }

        arr[0] -= min(arr[0], left); 
        /*
        for(int j = 0; j < left; j++){
            if(arr[0] > 0)
                arr[0]--;
        }
        */
    }

    //2x2
    boxes += arr[1] / 9;
    rem = arr[1] % 9;
    if(rem > 0){
        boxes += 1;
        int left = 36 - (4 * rem);

        arr[0] -= min(arr[0], left); 
        /*
        for(int j = 0; j < left; j++){
            if(arr[0] > 0)
                arr[0]--;
        }
        */
    }

    //1x1
    boxes += arr[0] / 36;
    rem = arr[0] % 36;
    if(rem > 0)
        boxes += 1;


    cout << boxes << endl;
    return 0;
    
}
