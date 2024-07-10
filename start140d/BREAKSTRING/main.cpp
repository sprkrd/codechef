#include <bits/stdc++.h>
using namespace std;

std::vector<unsigned> z_function(const std::string& s)
{
    std::vector<unsigned> z(s.size());
    unsigned l = 0;
    unsigned r = 0;

    for (unsigned i = 1; i < s.size(); ++i)
    {
        if (i < r)
        {
            z[i] = std::min(z[i-l], r - i);
        }

        for (; z[i] < s.size()-i && s[i+z[i]]==s[z[i]]; ++z[i]);

        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    
    return z;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        if (S.size()%2 == 1)
        {
            cout << 0 << endl;
            continue;
        }
        
        string S_reversed = S;
        reverse(S_reversed.begin(), S_reversed.end());
        
        auto z = z_function(S);
        auto z_rev = z_function(S_reversed);
        
        unsigned count = 0;
        for (unsigned win_end = S.size()/2-1; win_end < S.size(); ++win_end)
        {
            unsigned win_begin = win_end + 1 - S.size()/2;
            unsigned size_P = win_begin;
            unsigned size_R = S.size() - win_end - 1;
            
            count += z[win_begin]>=size_P && z_rev[S.size()-win_end-1]>=size_R;
        }
        
        cout << count << endl;
        
    }
}
