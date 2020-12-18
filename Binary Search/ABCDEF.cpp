// By Vishwam Mundada
/*
our equation becomes  a*b+c = (e+f)*d
so we will create two vectors arrL and arrR and sort them so that we can apply binary serch
using upper_bound and lower_bound we will calcuate frequency
*/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int> arrL, arrR;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                arrL.push_back(a[i]*a[j]+a[k]);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                if(a[k] != 0)
                {
                    arrR.push_back((a[i]+a[j])*a[k]);
                }
            }
        }
    }
    int ans=0;
    sort(arrR.begin(),arrR.end());
    sort(arrL.begin(),arrL.end());
    for(int i=0;i<arrL.size();++i)
    {
        ans += upper_bound(arrR.begin(),arrR.end(), arrL[i]) - lower_bound(arrR.begin(), arrR.end(), arrL[i]);
    }
    cout<<ans<<endl;
 return 0;
} 
