#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
	    int N, X, Y;
	    cin >> N >> X >> Y;
	    int ans1 = X*N;
	    int ans2 = Y*(N/2) + X*(N%2);
	    cout << max(ans1,ans2) << endl;
	}

}

