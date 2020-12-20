#include<bits/stdc++.h>
using namespace std;

long long dp[10004];
long long n=0;

long long rec(long long index, long long a[])
{
	if(index >= n)
	{
		return 0;
	}
	if(dp[index] != -1)
	{
		return dp[index];
	}
	long long ans1 = rec(index+2, a) + a[index];
	long long ans2 = rec(index+1, a) + 0;

	long long ans = max(ans1, ans2);
	dp[index] = ans;
	return ans;
}

int main()
{
	long long t=0;
	cin>>t;
	for(long long j=0;j<t;++j)
	{
	    memset(dp,-1,sizeof(dp));
		cin>>n;
		long long a[n];
		for(long long i=0;i<n;++i)
		{
			cin>>a[i];
		}
		cout<<"Case "<<j+1<<": "<<rec(0, a)<<endl;
	}
}
