#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string t;
    cin >> t;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;

        int ans = 1e9;
        for(int x=0; x<t.size(); x++)
        {
            int i=0, j=x;
            while(i<s.size() && j<t.size())
            {
                if(s[i]==t[j]) i++;
                j++;
            }
            if(i==s.size()) ans = min(ans, j-i-x);
        }
        cout << (ans != 1e9 ? ans : -1) << endl;
    }
}