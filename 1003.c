#include <stdio.h>
 
void fibonacci(int N)
{
    int last, current, result;
    current=1, last = result = 0;
    int i;
    for (i = 0; i <=N; i++)
    {
        last = current;
        current = result;
        result = last + current;
    }
    printf("%d %d\n", last, current);
}
int main()
{
    int N,M;
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &M);
        fibonacci(M);
    }
}
