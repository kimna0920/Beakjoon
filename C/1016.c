#include <stdio.h>
#include <math.h>
int arr[1000001];
int main(){
    long long min, max;
    scanf("%lld %lld", &min, &max);
    int sq = (int)sqrt(max), cnt = 0;
    for (long i = 2; i <= sq; i++){
        long pow = i*i;
        for (long j = ((min-1)/pow +1)*pow; j <= max; j += pow)
            arr[j-min]++;
    } 
    for (int i = 0; i < (max-min +1); i++)
        arr[i] && cnt++;
    printf("%d\n", max-min-cnt +1);
}
