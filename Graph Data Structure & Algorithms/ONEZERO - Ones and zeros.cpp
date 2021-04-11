// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/ONEZERO/
// Good Question 
// Also on Interviewbit playlist, solved with different approach
// Interviewbit Link : https://github.com/Vishwam36/InterviewBit/blob/main/Graph%20Data%20Structure%20%26%20Algorithms/Smallest%20Multiple%20With%200%20and%201.cpp
// Ref : https://www.youtube.com/watch?v=sdTubUR99OA

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        
        if(n == 0 || n == 1)
        {
            cout << to_string(n) << endl;
            continue;
        }
        
        map<int, string> m;
        
        queue<int> q;
        q.push(1);
        m[1] = "1";
        
        while(!q.empty())
        {
            int r = q.front();
            q.pop();
            
            if(r == 0)
            {
                cout << m[0] << endl;
                continue;
            }
            
            int r0 = (r*10) % n;
            int r1 = (r*10 + 1) % n;
            
            if(m.find(r0) == m.end())
            {
                m[r0] = m[r] + to_string(0);
                q.push(r0);
            }
            if(m.find(r1) == m.end())
            {
                m[r1] = m[r] + to_string(1);
                q.push(r1);
            }
        }
    }
}
