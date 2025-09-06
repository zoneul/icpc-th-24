#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll p = 1e9+7;
 
ll powmod(ll n, ll x)
{
    if(x==0) return 1;
 
    ll tmp = powmod(n,x/2)%p;
    tmp = (tmp*tmp)%p;
    if(x%2) tmp = (tmp*n)%p;
    return tmp;
}
 
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    ll n, r, b;
    cin >> n;

    vector<vector<ll>> dp(n, vector<ll>(2,0));
    cin >> dp[0][0] >> dp[0][1];

    for(ll i=1;i<n;i++)
    {
        cin >> r >> b;
        dp[i][0] = (dp[i-1][0]*r + dp[i-1][1]*b)%p;
        dp[i][1] = (dp[i-1][1]*r + dp[i-1][0]*b)%p;
    }

    cout << (a[n-1]*powmod(a[n-1]+b[n-1], p-2))%p;
}