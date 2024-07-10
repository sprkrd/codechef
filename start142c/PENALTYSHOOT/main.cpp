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
        int X1, Y1;
        cin >> X1 >> Y1;
        int X2 = X1 + 2;
        int Y2 = Y1 + 1;

        if ((X1 <= Y1 && Y1 <= X2) ||
            (Y1 <= X1 && X1 <= Y2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
