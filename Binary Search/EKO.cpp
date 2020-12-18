// By Vishwam Mundada

#include <iostream>
typedef long long ll;
using namespace std;
 
ll cutSum(ll x, ll a[], ll n)
{
    ll sum=0;
    for(ll i=0;i<n;++i)
    {
        if(a[i]>x)
            sum+=a[i]-x;
    }
    return sum;
}
 
ll height(ll a[], ll n, ll m, ll max)
{
    ll l=0,r=max,mid;
    while(r-l > 1)
    {
        mid=(l+r)/2;
        if(cutSum(mid,a,n)==m)
        {
            return mid;
        }
        else if(cutSum(mid,a,n)>m)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}
 
int main()
{
    ll n=0,m=0,max=0;
    cin>>n>>m;
    ll a[n];
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>max)
            max=a[i];
    }
    cout<<height(a,n,m,max);
    return 0;
}
