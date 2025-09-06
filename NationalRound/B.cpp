#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    string tmp = "", ans = "";
    map<string, char> m = {
        {"2", 'a'}, {"22", 'b'}, {"222", 'c'},
        {"3", 'd'}, {"33", 'e'}, {"333", 'f'},
        {"4", 'g'}, {"44", 'h'}, {"444", 'i'},
        {"5", 'j'}, {"55", 'k'}, {"555", 'l'},
        {"6", 'm'}, {"66", 'n'}, {"666", 'o'},
        {"7", 'p'}, {"77", 'q'}, {"777", 'r'}, {"7777", 's'},
        {"8", 't'}, {"88", 'u'}, {"888", 'v'},
        {"9", 'w'}, {"99", 'x'}, {"999", 'y'}, {"9999", 'z'}
    };

    for(int i=0;i<s.size();i++)
    {
        if(tmp.empty() || (s[i]==tmp.back() && tmp.size()<3)) tmp += s[i];
        else if(s[i]==tmp.back() && tmp.size()==3 && (s[i]=='7' || s[i]=='9')) tmp += s[i];
        else
        {
            ans += m[tmp];
            tmp = s[i];
        }
    }
    ans += m[tmp];
    reverse(ans.begin(), ans.end());

    cout << ans;
}