// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/PARTY/
// Used 0/1 knapsack

#include<bits/stdc++.h>
using namespace std;

int cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first == p2.first)
    {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

int main()
{
    while(1)
    {
        int budget=0, n=0, i=0, j=0;
    	cin>>budget>>n;
    	string str;
    	getline(cin, str);
    	if(budget == 0 && n == 0)
    	{
    	    break;
    	}
    	int a[n+1][budget+1];
    	memset(a,0,sizeof(a));
    
    	int cost[n], fun[n];
    	vector<pair<int, int> > v;
    	v.push_back(make_pair(0,0));
    
    	for(i=0;i<n;++i)
    	{
    		cin>>cost[i]>>fun[i];
    		v.push_back(make_pair(cost[i], fun[i]));
    	}
    	sort(v.begin(), v.end(), cmp);
    
    	for(i=1;i<=n;++i)
    	{
    		for(j=1;j<=budget;++j)
    		{
    			if(j < v[i].first)
    				a[i][j] = a[i-1][j];
    			
    			else
    				a[i][j] = max(a[i-1][j], a[i-1][j-v[i].first] + v[i].second);
    		}
    	}

        // First time fun got maximum(a[n][budget]) wil be the minimum cost
        for(i=0;i<=budget;++i)
        {
            if(a[n][i] == a[n][budget])
            {
                totalCost = i;
                break;
            }
        }
    	cout<<totalCost<<" "<<a[n][budget]<<endl;
    }
	return 0;
}
