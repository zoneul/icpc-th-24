#include <bits/stdc++.h>
using namespace std;
 
bool dfs(int u, vector<vector<int>>& g, vector<bool>& vi, vector<int>& cat, vector<int>& food)
{
    if(vi[u]) return false;
    vi[u]=true;
    for(auto v:g[u])
    {
        if(cat[v]==-1 || dfs(cat[v], g, vi, cat, food))
        {
            food[u]=v;
            cat[v]=u;
            return true;
        }
    }
    return false;
}
 
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
 
    int l=1, r=1e9;
    vector<int> ans_list;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
 
        vector<vector<int>> g(m+1, vector<int>());
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]>=mid) g[j].push_back(i);
 
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        for(auto& i:g) shuffle(i.begin(), i.end(), rng);
 
        vector<int> cat(n+1, -1);
        vector<int> food(m+1, -1);
        int ma=0;
        for(int i=1; i<=m; i++)
        {
            vector<bool> vi(m+1, false);
            if(dfs(i, g, vi, cat, food)) ma++;
        }
        
        if(ma == n) 
        {
            if(mid > ans)
            {
                ans=mid;
                ans_list = cat;
            }
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans << endl;
    for(int i=1;i<=n;i++) cout << ans_list[i] << " ";
}