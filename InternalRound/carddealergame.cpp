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

    ll n, x, y, wa, wb;
    cin >> n;
    cin >> wa >> wb;

    for(ll i=0;i<n-1;i++)
    {
        cin >> x >> y;
        ll tmp = (wa*x + wb*y)%p;
        wb = (wb*x + wa*y)%p;
        wa = tmp;
    }
 
    cout << (wa*powmod(wa+wb, p-2))%p;
}