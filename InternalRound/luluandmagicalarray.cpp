#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n-1);
        for(int i=0;i<n-1;i++)
        {
            cout << "? 1 " << i+2 << endl;
            cin >> v[i]; 
        }
        sort(v.begin(),v.end());
 
        int mi=*min_element(v.begin(),v.end());
        for(int i=1;i<n-1;i++) mi = min(mi, v[i]^v[i-1]);
        cout << "! " << mi << endl;
 
        cout.flush();
    }
    
}