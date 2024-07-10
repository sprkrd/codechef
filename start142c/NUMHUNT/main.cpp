#include <bits/stdc++.h>
using namespace std;


constexpr uint64_t N = 1'000'000'009;

vector<uint64_t> get_primes(uint64_t M)
{
    vector<bool> SIEVE(M+1, true);
    SIEVE[0] = SIEVE[1] = false;
    for (uint64_t i = 4; i <= M; i += 2)
    {
        SIEVE[i] = false;
    }
    for (uint64_t i = 3; i*i <= M; i += 2)
    {
        if (SIEVE[i])
        {
            for (uint64_t j = i*i; j <= M; j += i)
            {
                SIEVE[j] = false;
            }
        }
    }
    vector<uint64_t> PRIMES{2};
    PRIMES.reserve(M);
    for (uint64_t i = 3; i <= M; i += 2)
    {
        if (SIEVE[i])
        {
            PRIMES.push_back(i);
        }
    }
    return PRIMES;
}

uint64_t next_prime(uint64_t x, bool include = false)
{
    const static auto PRIMES = get_primes(floor(sqrt(N)));

    if (x == 1 || (x == 2 && include))
    {
        return 2;
    }
    
    uint64_t  lo = x%2==0? x + 1 : include? x : x + 2;

    for (uint64_t y = lo; ; y += 2)
    {
        bool prime = true;
        for (uint64_t p : PRIMES)
        {
            if (p >= y)
            {
                break;
            }
            if (y % p == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            return y;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        uint64_t X;
        cin >> X;
        uint64_t prime1 = next_prime(X, true);
        uint64_t prime2 = next_prime(prime1);
        auto ans = prime1*prime2;
        cout << ans << endl;
    }
}
