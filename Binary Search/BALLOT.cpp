// By Vishwam Mundada

#include<bits/stdc++.h>
using namespace std;
 
bool can(int a[], int n, int b, int mid)
{
    for(int i=0;i<n;++i)
    {
        if(a[i] <= mid)
        {
            --b;
        }
        else
        {
            b -= ceil((double)a[i]/mid);
        }
        if(b<0)
        {
            return false;
        }
    }
    return true;
}
 
int binary(int a[], int n, int b, int max)
{
    int l=0, r=max, mid=0;
    while(r-l > 1)
    {
        mid = (l+r)/2;
        bool temp = can(a,n,b,mid);
        if(temp)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(can(a,n,b,l))
    {
        return l;
    }
    return r;
}
 
int main()
{
    int n=0, b=0, maximum=0, a=0;
    string s;
    while(1)
    {
        cin>>a;
        if(a==-1)
        {
            break;
        }
        else
        {
            n=a;
            cin>>b;
            int a[n];
            for(int i=0;i<n;++i)
            {
                cin>>a[i];
                maximum=max(maximum, a[i]);
            }
            cout<<binary(a,n,b,maximum)<<endl;
        }
        getline(cin, s);
    }
    return 0;
}
