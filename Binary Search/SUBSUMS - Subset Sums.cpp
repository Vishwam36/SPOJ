// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/SUBSUMS/
// Good question
// REF : https://www.youtube.com/watch?v=VCZ4lqfZRPk&ab_channel=CodeLibrary

/*
Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B
(-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

Input
The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.

Output
Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.

Example
Input:
3 -1 2
1
-2
3

Output:
5

The following 5 subsets have a sum between -1 and 2:
0 = 0 (the empty subset)
1 = 1
1 + (-2) = -1
-2 + 3 = 1
1 + (-2) + 3 = 2
*/

#include <bits/stdc++.h>
using namespace std;

void get_sums(vector<long long> &a, vector<long long> &v)
{
    for(int i = 0; i < (1 << a.size()); ++i)
    {
        long long x = i, j = 0, sum = 0;
        while(x)
        {
            if(((x) & (1)) != 0)
            {
                sum += a[j];
            }
            ++j;
            x = x >> 1;
        }
        v.push_back(sum);
    }
}

int main() 
{
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> a1(n/2);
    vector<long long> a2(n- n/2);
    for(int i = 0; i < n/2; ++i)
        cin >> a1[i];
    for(int i = n/2; i < n; ++i)
        cin >> a2[i - n/2];
    
    vector<long long> v1, v2;
    get_sums(a1, v1);
    get_sums(a2, v2);
    
    sort(v2.begin(), v2.end());
    long long ans = 0;
    for(auto num : v1)
    {
        int high = upper_bound(v2.begin(), v2.end(), b-num) - v2.begin();
        int low = lower_bound(v2.begin(), v2.end(), a-num) - v2.begin();
        
        ans += high - low;
    }
    cout << ans << endl;
	return 0;
}
