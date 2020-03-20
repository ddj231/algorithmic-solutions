#include <stdio.h>

using namespace std;

int main(){
   int buckets[101];
   for(int i = 0; i < 101; i++){
        buckets[i] = 0;
   }
   int n;
   int c = 0;
   scanf("%d", &n);
   for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        buckets[val]++;
   }
   for(int i = 0; i < 101; i++){
        int amt = buckets[i];
        for(int j = 0; j < amt; j++){
            if(c < n - 1){
                printf("%d ", i);
                c++;
            }
            else{
                printf("%d\n", i);
            }
        }
   }
   return 0;
}
