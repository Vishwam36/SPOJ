#include<bits/stdc++.h>
using namespace std;

long long n=0;
long long dp[200004];

int main()
{
	cin>>n;
	long long a[n+1];
	a[0] = 0;
	a[1] = 0;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	long long minSum = INT_MAX;
	for(long long i=2;i<=n;++i)
	{
		minSum = INT_MAX;
		for(long long j=0;j<=n;++j)
		{
			if((i-(1<<j)) > 0)
				minSum = min(minSum, dp[i-(1<<j)] + abs(a[i] - a[i-(1<<j)]));
			else
				break;
		}
		dp[i] = minSum;
	}
	cout<<dp[n]<<endl;
	return 0;
}
