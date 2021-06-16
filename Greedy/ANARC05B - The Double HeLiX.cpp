// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/ANARC05B/
// Decent

/*


Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. 
Take for example the following two sequences where intersection points are
printed in bold:

    First= 3 5 7 9 20 25 30 40 55 56 57 60 62
    Second= 1 4 7 11 14 25 44 47 55 57 100

You can ‘walk” over these two sequences in the following way:

    You may start at the beginning of any of the two sequences. Now start moving forward.
    At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.

The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, 
which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

Input
Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and 
is speciﬁed using the following format:

n v1 v2 ... vn

Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. 
All elements are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.
Output

For each test case, write on a separate line, the largest possible sum that can be produced.
Sample

Input:
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0

Output:
450
2100
*/

// Greedy + Binary Search

#include <bits/stdc++.h>
using namespace std;

unordered_set<int> common;

bool found(int b[], int n2, int x)
{
    int up = upper_bound(b, b+n2, x) - b;
    int lb = lower_bound(b, b+n2, x) - b;
    
    if(up-lb == 0)
        return false;
    return true;
}

int sum_till(int i, int b[], int n2, int x)
{
    int sum = 0;
    for(; i < n2 && b[i] != x; ++i)
        sum += b[i];
    
    return sum;
}

int main() 
{
    while(1)
    {
        common.clear();

        int n1, n2;
        cin >> n1;
        if(n1 == 0)
            return 0;
        
        int a[n1];
        for(int i = 0; i < n1; ++i)
            cin >> a[i];
        
        cin >> n2;
        int b[n2];
        for(int i = 0; i < n2; ++i)
            cin >> b[i];
        
        for(int i = 0; i < n1; ++i)
            if(found(b, n2, a[i]))
                common.insert(a[i]);
        
        vector<int> sum1;
        vector<int> sum2;
        int commonSum = 0, sum = 0, i2 = 0;
        for(int i = 0; i < n1; ++i)
        {
            if(common.find(a[i]) != common.end())
            {
                commonSum += a[i];
                sum2.push_back(sum_till(i2, b, n2, a[i]));
                i2 = (lower_bound(b, b+n2, a[i])-b) + 1;
                sum1.push_back(sum);
                sum = 0;
            }
            else
            {
                sum += a[i];
            }
        }
        
        sum1.push_back(sum);
        sum2.push_back(0);
        for(i2; i2 < n2; ++i2)
            sum2.back() += b[i2];
        
        int ans = commonSum;
        for(int i = 0; i < sum1.size(); ++i)
            ans += max(sum1[i], sum2[i]);
        
        cout << ans << endl;
    }
	return 0;
}


// Below approach is solved using DP but its grredy only if you observe
// DP + Binary Search

#include <bits/stdc++.h>
using namespace std;

unordered_set<int> common;

int dp[100001][3];

bool found(int b[], int n2, int x)
{
    int up = upper_bound(b, b+n2, x) - b;
    int lb = lower_bound(b, b+n2, x) - b;
    
    if(up-lb == 0)
        return false;
    return true;
}

int rec(int idx, int a[], int n1, int b[], int n2, int seq)
{
    if(seq == 1 && idx >= n1)
        return 0;
    if(seq == 2 && idx >= n2)
        return 0;
    
    if(dp[idx][seq] != -1)
        return dp[idx][seq];
    
    if(seq == 1)
    {
        int sum = 0, i = 0;
        for(i = idx; i < n1 && common.find(a[i]) == common.end(); ++i)
            sum += a[i];
        
        if(i >= n1)
            return sum;
        
        sum += a[i];
        int a_i = i+1;
        int b_i = (lower_bound(b, b+n2, a[i])-b)+1;
        int ans1 = rec(a_i, a, n1, b, n2, 1) + sum;
        int ans2 = rec(b_i, a, n1, b, n2, 2) + sum;
        return dp[idx][seq] = max(ans1, ans2);
    }
    else
    {
        int i = 0, sum = 0;
        for(i = idx; i < n2 && common.find(b[i]) == common.end(); ++i)
            sum += b[i];
        
        if(i >= n2)
            return sum;
        
        sum += b[i];
        int a_i = (lower_bound(a, a+n1, b[i])-a)+1;
        int b_i = i+1;
        int ans1 = rec(a_i, a, n1, b, n2, 1) + sum;
        int ans2 = rec(b_i, a, n1, b, n2, 2) + sum;
        return dp[idx][seq] = max(ans1, ans2);
    }
}

int main() 
{
    while(1)
    {
        common.clear();
        memset(dp, -1, sizeof(dp));
        
        int n1, n2;
        cin >> n1;
        if(n1 == 0)
            return 0;
        
        int a[n1];
        for(int i = 0; i < n1; ++i)
            cin >> a[i];
        
        cin >> n2;
        int b[n2];
        for(int i = 0; i < n2; ++i)
            cin >> b[i];
        
        for(int i = 0; i < n1; ++i)
            if(found(b, n2, a[i]))
                common.insert(a[i]);
        
        int ans1 = rec(0, a, n1, b, n2, 1);
        int ans2 = rec(0, a, n1, b, n2, 2);
        
        cout << max(ans1, ans2) << endl;
    }
	return 0;
}
