// By Vishwam Mundada
/*
a+b+c+d = 0  =>  a+b = -(c+d)
make two arrays one for all posiible sums from list A and B and same for C and D
sort any one of them so that we can calculate frequency using upper_bound and Lower_bound
*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n=0;
    cin>>n;
    int a[n], b[n], c[n], d[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    int sumAB[n*n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            sumAB[(n*i)+j] = -1*(a[i]+b[j]);
        }
    }
    int sumCD[n*n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            sumCD[(n*i)+j] = c[i]+d[j];
        }
    }
    sort(sumCD, sumCD+(n*n));
    int sum=0;
    for(int i=0;i<(n*n);++i)
    {
        sum += (upper_bound(sumCD, sumCD+(n*n), sumAB[i]) - lower_bound(sumCD, sumCD+(n*n), sumAB[i]));
    }
    cout<<sum<<endl;
    return 0;
} 
