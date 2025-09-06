#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for(auto& i:v) cin >> i;
    sort(v.begin(),v.end());
    cout << v[n-1]*v[n-2];
}