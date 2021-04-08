// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/MST/
// Easy normal MST

// App 1 : 
// Kruskal algo

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int p[100005];

bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[2] < v2[2];
}

int find_parent(int a)
{
    if(p[a] == a)
        return a;
    
    int parent = find_parent(p[a]);
    p[a] = parent;
    return parent;
}

bool union_set(int a, int b)
{
    int pa = find_parent(a);
    int pb = find_parent(b);
    
    if(pa == pb)
        return true;
    
    p[pb] = pa;
    return false;
}

int main()
{
    int n = 0, e = 0;
    ll ans = 0;
    cin >> n >> e;
    for(int i = 1; i <= n; ++i)
        p[i] = i;
    
    vector<vector<int> > edges(e, vector<int>(3));
    for(int i = 0; i < e; ++i)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    
    sort(edges.begin(), edges.end(), cmp);
    
    for(int i = 0; i < e; ++i)
        if(!union_set(edges[i][0], edges[i][1]))
            ans += edges[i][2];
    
    cout << ans;
}

// App 2:
// Prims algo

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int> > myp;

struct cmp
{
    bool operator() (myp p1, myp p2)
    {
        return p1.second.second > p2.second.second;
    }
};

int main()
{
    int n = 0, e = 0, a, b, w;
    ll ans = 0;
    cin >> n >> e;
    
    bool vis[n+1];
    for(int i = 0; i <= n; ++i)
        vis[i] = 0;
    
    vector<pair<int, int> > adj[n+1];
    for(int i = 0; i < e; ++i)
    {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    priority_queue<myp, vector<myp>, cmp> pq;
    pq.push({1, {-1, 0}});
    
    while(!pq.empty())
    {
        myp p = pq.top();
        pq.pop();
        int curr = p.first;
        // cout << curr << " ";
        w = p.second.second;
        if(vis[curr])
            continue;
        
        vis[curr] = 1;
        ans += w;
        
        for(int i = 0; i < adj[curr].size(); ++i)
        {
            pair<int, int> child = adj[curr][i];
            if(vis[child.first])
                continue;
            
            pq.push({child.first, {curr, child.second}});
        }
    }
    
    cout << ans << endl;
}
