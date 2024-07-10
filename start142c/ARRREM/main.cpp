#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        unsigned N;
        cin >> N;
        vector<unsigned> A(N);
        for (auto& x : A)
        {
            cin >> x;
        }

        unsigned xor_res = 0;
        for (auto x : A)
        {
            xor_res |= x;
        }

        unsigned mask = xor_res + 1;

        unsigned count = 0;
        for (auto x : A)
        {
            count += (x&mask)>0;
        }

        cout << count << endl;

    }
}
