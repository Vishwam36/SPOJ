// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/PT07Y/
// Easy

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool bfs(int source, vector<int> v[], int visited[])
{
    queue<int> q;
    
    q.push(source);
    visited[source] = 1;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i < v[curr].size(); ++i)
        {
            int child = v[curr][i];
            if(visited[child] == 0)
            {
                visited[child] = 1;
                q.push(child);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 0, e = 0, x = 0, y = 0;
    bool ans = true;
    cin >> n;
    cin >> e;
    vector<int> v[n+1];
    int visited[n+1] = {0};
    for(int i = 0; i < e; ++i)
    {
        cin >> x >> y;
        v[x].push_back(y);
    }
    
    for(int i = 1; i <= n; ++i)
    {
        if(visited[i] == 0)
        {
            ans = ans && bfs(i, v, visited);
        }
        if(ans == false)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
