// By Vishwam Shriram Mundada

#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[101][101];
int dp[101][101];

// while calling recursion with two indexes check whether (i,j) exists or not 
bool valid(int i, int j)
{
	if(i<n && i>=0 && j<m && j>=0)
		return true;
	return false;
}

int rec(int i, int j)
{
    if(dp[i][j] != -1)
        return dp[i][j];
        
    // return some big number s.t in min() function it will be neglected
    if(!valid(i,j))
		return 1000000;
		
	int ans1 = rec(i+1, j-1);
	int ans2 = rec(i+1, j);
	int ans3 = rec(i+1, j+1);

	int ans = min(ans1, min(ans2, ans3)) + a[i][j];
	dp[i][j] = ans;
	return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
	    for(int j=0;j<m;++j)
	    {
	        cin>>a[i][j];
	    }
	}
  
  // minimum fare for last row(city) a[n-1][i] will be the value itself
	for(int i=0;i<m;++i)
	{
	    dp[n-1][i] = a[n-1][i];
	}
    int minn = INT_MAX;
    for(int i=0;i<m;++i)
    {
        int temp = rec(0,i);
        minn = min(minn, temp);
    }
	cout<<minn<<endl;
	return 0;
}
