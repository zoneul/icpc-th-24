#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int n,m;
    cin >> n >> m;
 
    vector<vector<int>> s(n, vector<int>(m));
    for(auto& i:s) for(auto& j:i) cin >> j;
 
    vector<vector<int>> ma(s);
    for(auto& i:ma) for(int j=m-2;j>=0;j--) i[j] = max(i[j], i[j+1]);
 
    vector<int> res(n); 
    res.back() = ma.back().front();
    for(int i=n-2;i>=0;i--) res[i] = res[i+1] + ma[i].front();
 
    vector<int> dp(10*n+1, -1);
    dp[s.front().front()] = s.front().back();
 
    int ans = 0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<dp.size();j++) if(dp[j]!=-1) ans = max(ans, j * (dp[j]+res[i])); // Alice finished
        for(int j=0;j<dp.size();j++) if(dp[j]!=-1) ans = max(ans, (j+res[i]) * dp[j]); // Bob finished
 
        // Both continue
        vector<int> first(10, 1e9);
        for(int j=m-2;j>=0;j--) first[s[i][j]] = j; // Won't count rightmost, it's mean bob finished
 
        vector<int> tmp(dp);
        for(int j=0;j<10;j++)
        {
            if(first[j]==1e9) continue;
 
            for(int k=dp.size()-1;k>=j;k--)
            {
                if(dp[k-j] == -1) continue;
                int b = dp[k-j] + ma[i][first[j]+1];
                tmp[k] = max(tmp[k], b);
            }
        }
        for(int i=0;i<10*n+1;i++) dp[i] = max(dp[i], tmp[i]);
    }
 
    for(int i=0;i<dp.size();i++) ans = max(ans, i*dp[i]);
    cout << ans;
}