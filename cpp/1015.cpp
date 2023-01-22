
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
 
typedef struct node
{
    int num;
    int idx;
}node;
 
node A[55];
int P[55];
int N;
 
bool cmp(node A, node B)
{
    if(A.num < B.num)
    {
        return true;
    }
    else if(A.num == B.num)
    {
        if(A.idx < B.idx)
        {
            return true;
        }
        else
        {
            return false;    
        }
    }
    else
    {
        return false;
    }
}
 
int main(void)
{
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> A[i].num;
        A[i].idx = i;
    }
    
    sort(A, A+N, cmp);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == A[j].idx)
            {
                P[i] = j;
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        cout << P[i] << " ";
    }
    
    return 0;
}
