// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/MIXTURES/
// Decent

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[101];
ll min_smoke[101][101];
int n;

int color(int i, int j)
{
    int sum = 0;
    for(int k = i; k <= j; ++k)
    {
        sum += a[k];
        sum %= 100;
    }
    return sum;
}

int smoke(int l, int r)
{
    if(l >= r)
        return 0;
        
    if(min_smoke[l][r] != -1)
        return min_smoke[l][r];
        
    min_smoke[l][r] = INT_MAX;
    for(int k = l; k < r; ++k)
    {
        min_smoke[l][r] = min(min_smoke[l][r], (ll)(color(l,k) * color(k+1,r)) + smoke(l,k) + smoke(k+1,r));
    }
    return min_smoke[l][r];
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        memset(min_smoke, -1, sizeof(min_smoke));
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << smoke(0,n-1) << endl;
    }
}
