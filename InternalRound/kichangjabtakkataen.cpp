#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,m,h,q;
    cin >> n >> m >> h >> q;
 
    vector<pair<int,int>> v(n);
    vector<int> ans;
    multiset<int> net;
 
    for(auto& i:v) cin >> i.first >> i.second;
    for(int i=0;i<m;i++) 
    {
        int x;
        cin >> x;
        net.insert(x);
    }
 
    for(auto i:v)
    {
        auto it = net.lower_bound(abs(i.second-h));
        if(it != net.end())
        {
            ans.push_back(i.first);
            net.erase(it);
        }
    }
    
    while(q--)
    {
        int x;
        cin >> x;
        if(x > ans.size()) cout << -1 << endl;
        else cout << ans[x-1] << endl;
    }
}