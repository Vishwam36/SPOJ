// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/MCOINS/
// Simple DP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char dp[1000001];
int k = 0, l = 0, m = 0;

void calculate()
{
    dp[1] = 'A';
    dp[k] = 'A';
    dp[l] = 'A';
    for(int i = 0; i < 1000001; ++i)
    {
        if(dp[i] != 'Z')
        {
            continue;
        }
        else if(i - 1 >= 1 && dp[i-1] == 'B' && dp[i] == 'Z')
        {
            dp[i] = 'A';
        }
        else if(i - k >= 1 && dp[i-k] == 'B' && dp[i] == 'Z')
        {
            dp[i] = 'A';
        }
        else if(i - l >= 1 && dp[i-l] == 'B' && dp[i] == 'Z')
        {
            dp[i] = 'A';
        }
        else
        {
            dp[i] = 'B';
        }
    }
}

int main()
{
    memset(dp, 'Z', sizeof(dp));
    cin >> k >> l >> m;
    calculate();
    
    string ans = "";
    int a[m];
    for(int i = 0; i < m; ++i)
    {
        cin >> a[m];
        ans += dp[a[m]];
    }
    cout << ans << endl;
}
