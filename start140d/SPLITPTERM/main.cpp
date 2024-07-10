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
        int N;
        cin >> N;

        for (int i = 0; i < N/2; ++i)
        {
            if (i > 0)
            {
                cout << ' ';
            }
            cout << (i+1) << ' ' << (N-N%2-i);
        }
        if (N%2 == 1)
        {
            if (N > 1)
            {
                cout << ' ';
            }
            cout << N;
        }
        cout << endl;
    }
}
