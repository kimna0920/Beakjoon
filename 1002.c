#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, x1, y1, r1, x2, y2, r2, result;
    double distanse, subtract;
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        distanse = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        subtract = r1 > r2 ? r1 - r2 : r2 - r1;
        
        if(distanse == 0 && r1 == r2) result = -1; 
        else if(distanse < r1 + r2 && (subtract < distanse)) result = 2;
        else if(distanse == r1 + r2 || distanse == subtract) result = 1;
        else result = 0;
        
        printf("%d\n", result);
    }
}
