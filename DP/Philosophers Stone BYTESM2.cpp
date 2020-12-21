// By Vishwam Shriram Mundada

#include<bits/stdc++.h>
using namespace std;

int h, w;
int a[101][101];
int dp[101][101];

bool valid(int i, int j)
{
	if(i<h && i>=0 && j<w && j>=0)
		return true;
	return false;
}

int rec(int i, int j)
{
	if(!valid(i,j))
		return 0;

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
	int ans1 = rec(i+1, j-1);
	int ans2 = rec(i+1, j);
	int ans3 = rec(i+1, j+1);

	int ans = max(ans1, max(ans2, ans3)) + a[i][j];
	dp[i][j] = ans;
	return ans;
}

int main()
{
	int t=0;
	cin>>t;
	for(int k=0;k<t;++k)
	{
	    memset(dp, -1, sizeof(dp));
		cin>>h>>w;
		for(int i=0;i<h;++i)
		{
		    for(int j=0;j<w;++j)
		    {
	    		cin>>a[i][j];
	    	}
	    }
	    int maxx = 0;
	    for(int i=0;i<w;++i)
	    {
	        int temp = rec(0,i);
	        maxx = max(maxx, temp);
	    }
	    cout<<maxx<<endl;
	}
	return 0;
}
