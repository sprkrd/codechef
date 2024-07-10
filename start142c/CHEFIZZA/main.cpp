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
        int X;
        cin >> X;

        int s = 1;
        while (s < X)
        {
            s *= 2;
        }

        int ans = s > X? 2*X - s : 0;

        cout << ans << endl;

    }
}
