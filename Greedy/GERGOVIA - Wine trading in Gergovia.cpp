// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/GERGOVIA/
// Easy

/*


Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city. Every day each 
inhabitant decides how much wine he wants to buy or sell. Interestingly, demand and supply is always the same, so that each inhabitant gets what he wants.

There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good, the inhabitants of Gergovia don't 
care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.

In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume that the houses are built along a straight 
line with equal distance between adjacent houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work.

Input
The input consists of several test cases.

Each test case starts with the number of inhabitants N (2 ≤ N ≤ 100000).

The following line contains n integers ai (-1000 ≤ ai ≤ 1000).

If ai ≥ 0, it means that the inhabitant living in the ith house wants to buy ai bottles of wine. If ai < 0, he wants to sell -ai bottles of wine.

You may assume that the numbers ai sum up to 0.

The last test case is followed by a line containing 0.

Output
For each test case print the minimum amount of work units needed so that every inhabitant has his demand fulfilled.

Example

Input:
5
5 -4 1 -3 1
6
-1000 -1000 -1000 1000 1000 1000
0

Output:
9
9000
*/

// TC : O(N)

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    while(1)
    {
        int n = 0;
        cin >> n;
        
        if(n == 0)
            return 0;
        
        vector<int> a, pos, neg;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if(x >= 0)
            {
                pos.push_back(i);
                a.push_back(x);
            }
            else
            {
                a.push_back(-x);
                neg.push_back(i);
            }
        }
        long long ans = 0, i = 0, j = 0;
        while(i < pos.size())
        {
            int pi = pos[i]; // positive index
            int ni = neg[j]; // negative index
            
            int num = min(a[pi], a[ni]);
            a[pi] -= num;
            a[ni] -= num;
            
            ans += num * abs(pi-ni);
            
            if(a[pi] == 0)
                ++i;
            if(a[ni] == 0)
                ++j;
        }
        cout << ans << endl;
    }
	return 0;
}
