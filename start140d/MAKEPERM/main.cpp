#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
	    int N;
	    cin >> N;
	    vector<int> A(N);
	    for (auto& x : A)
	    {
	        cin >> x;
	    }
	    priority_queue<int,vector<int>,greater<int>> q(A.begin(), A.end());
	    
	    int expected = 0;
	    while (!q.empty())
	    {
            ++expected;
	        int a = q.top();
	        q.pop();
	        if (expected < a)
	        {
	            break;
	        }
	    }

	    
	    cout << (expected==N? "YES" : "NO") << endl;
	}

}

