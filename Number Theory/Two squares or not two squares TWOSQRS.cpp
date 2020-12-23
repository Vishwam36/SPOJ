// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/TWOSQRS/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int c=0;
	cin>>c;
	long long n;
	while(c--)
	{
		cin>>n;
		int flag = 0;
		for(long long i=0;i*i<n;++i)
		{
			if(ceil(sqrt(n-i*i)) == sqrt(n - i*i))
			{
				flag = 1;
				cout << "Yes" << endl;
				break;
			}
		}
		if(flag == 0)
		{
			cout << "No" << endl;
		}
	}
	return 0;
} 
