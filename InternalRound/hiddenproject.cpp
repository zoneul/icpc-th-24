#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n,a;
        cin >> n >> a;
        cout << max(n*(n+1)/2,n*a) << endl;
    }
}