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
        vector<int> A(N);
        for (auto& x : A)
        {
            cin >> x;
        }

        vector<set<int>> adjacency(N+1);

        for (int i = 0; i < N-1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adjacency[u].insert(v);
            adjacency[v].insert(u);
        }

        stack<int> leaves;
        for (int u = 1; u <= N; ++u)
        {
            if (adjacency[u].size() == 1)
            {
                leaves.push(u);
            }
        }

        int min_idx = min_element(A.begin(), A.end()) - A.begin() + 1;

        bool first = true;

        cout << (N-1) << endl;
        while (!leaves.empty())
        {
            int u = leaves.top();
            leaves.pop();
            if (u == min_idx)
            {
                continue;
            }
            if (!first)
            {
                cout << ' ';
            }
            // remove vertex
            cout << u;

            for (int v : adjacency[u])
            {
                adjacency[v].erase(u);
                if (adjacency[v].size() == 1)
                {
                    leaves.push(v);
                }
            }
            adjacency[u].clear();
            first = false;
        }
        cout << endl;
    }
}
