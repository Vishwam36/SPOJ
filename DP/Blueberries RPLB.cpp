// By Vishwam Shriram Mundada
// Good Problem 
// https://www.spoj.com/problems/RPLB/
// print dp array to understand

#include <bits/stdc++.h>
using namespace std;

int n=0, k=0;
int dp[1001][1001];

int rec(int index, int a[], int w)
{
    if(index >= n)
    {
        return w;
    }
    if(dp[index][w] != -1)
    {
        return dp[index][w];
    }
    if(w+a[index] > k)
    {
        dp[index][w] = rec(index+1, a, w);
    }
    else if(w + a[index] <= k)
    {
        int x = rec(index+1, a, w);
        int y = rec(index+2, a, w+a[index]);
        dp[index][w] = max(x,y);
    }
    return dp[index][w];
}

int main()
{
    int t=0;
    cin>>t;
    for(int j=0; j<t; ++j)
    {
        memset(dp,-1,sizeof(dp));
        cin >> n >> k;
        int a[n];
        for(int i=0; i<n; ++i)
        {
            cin >> a[i];
        }
        int ans = rec(0,a,0);
        cout << "Scenario #" << j+1 << ": " << ans << endl;
    }
}
