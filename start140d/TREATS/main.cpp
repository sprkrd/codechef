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
        int M;
        cin >> M;
        vector<int> A(N);
        for (auto& x : A)
        {
            cin >> x;
        }
        vector<int> B(N);
        for (auto& x : B)
        {
            cin >> x;
        }

        multiset<int> U, V;
        
        for (int i = 0; i < N; ++i)
        {
            U.insert(A[i]%M);
            V.insert(B[i]%M);
        }

        uint64_t ans = 0;
        for (auto it = U.begin(); it != U.end();)
        {
            int m = *it;
            int c = U.count(m);
            ans += c*V.count((M-m)%M);
            advance(it, c);
        }

        cout << ans << endl;
    }
}
