#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int ttime, int n, int m, int k, int* num){
    int i,j, atk = 0;
    for(i=0; i<n; i++){
        atk -= ttime;
        if(atk < 0){ atk = 0; }
        atk += num[i];
        if( atk >= m ){
            k--;
            atk = 0;
        }
    }
    if(k > 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){

    int i,j, n,m,k, ans;
    scanf("%d %d %d", &n, &m, &k);
    int* num = (int *)calloc(n+1, sizeof(int));
    for(i=0; i<n; i++){
        scanf("%d", &num[i]);
    }
    int mid, low = 1, high = m+1;
    ans = -1;
    while(low < high){
        mid = low + (high - low)/2;
        if(check(mid, n, m, k, num)){
            ans = mid;
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    printf("%d\n", ans);
    free(num);
    return 0;
}
