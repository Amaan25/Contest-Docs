### [CodeChef Starters 117 (Div. 2)](https://www.codechef.com/START117B?order=desc&sortBy=successful_submissions)
[Contest Editorial](https://discuss.codechef.com/tags/c/editorial/5/start117)

## [Spell Shortening](https://www.codechef.com/problems/SHORTSPELL) (1192)

Iterate through the string and check if a character is lexicographically larger than its next character and delete it. Otherwise, delete the last character.

## [Not Prime Permutation](https://www.codechef.com/problems/NPRPE) (1447)

If N is odd, print N+1-x for every element x in the array. If N is even, print N for N, and print N+1-x for all other elements x. 

## [Equality Etiquette](https://www.codechef.com/problems/EQUAL2) (1898)

Take D as difference between A and B. Our aim is to find the smallest integer N such that there's a way to assign + or - to every integer from 1 to N such that the resulting expression evaluates to D.
Find smallest N for which N(N+1)/2 >= D using binary search (O(logD)).
D should have the same parity as N(N+1)/2 else it is impossible to reach D.
So, the answer is N, N+1 or N+2, whichever lowest number that matches the parity.

## [Spread Spree](https://www.codechef.com/problems/SPREADCT) (2188)

Take M >= N
Minimum possible f(x, y) is floor(M/2)

If M is odd (2k+1):
Only middle column satisfies(k+1)
For choosing row x:
1. x - k <= 1 => x <= k + 1
2. x + k >= N => x >= N - k
3. Also, 1 <= x <= N

So, max(1, N-k) <= x <= min(N, 1+k) for fixed y = k+1

Sum of integers from left to right: R(R+1)/2 - L(L-1)/2

If M is even (2k):
Two middle columns, k or k+1
Same condition holds for rows, max(1, N-k) <= x <= min(N, 1+k), multiply by k + (k + 1)

## [Stingy Arrays](https://www.codechef.com/problems/STINGY) (2537)


## [Go Away, Goose!](https://www.codechef.com/problems/AVOIDWALK) (2866)


## [Roads and Flights](https://www.codechef.com/problems/ROADAIR) (2927)






















## Code

# Spell Shortening

```

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s, ans;
        cin >> s;
        int z = 1;
        for (int i = 0; i < n-1; i++) {
            if (s[i] > s[i+1] && z) {
                z--;
            }
            else {
                ans += s[i];
            }
        }
        if (z) cout << ans << '\n';
        else {
            ans += s[n-1];
            cout << ans <<'\n';
        }
    }
    return 0;
}

```

# Not Prime Permutation

```

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        if (n <= 2) cout << -1 << "\n";
        else if (n%2) {
            for (int x : v) {
                cout << n+1-x << " ";
            }
            cout << '\n';
        }
        else {
            for (int x : v) {
                if (x == n) cout << n << " ";
                else cout << n-x << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}


```

# Equality Etiquette 

```

#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>((x).size())
#define int long long


signed main() {

        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int t;
        cin >> t;

        while (t--) {
                int a, b;
                cin >> a >> b;
                int d = abs(a - b);

                int l = 0, r = (int)1e5;
                while (l < r) {
                        int m = (l + r) / 2;
                        int x = m * (m + 1) / 2;
                        if (x >= d) r = m;
                        else l = m + 1;
                }
                
                int x = l;
                if (x * (x + 1) / 2 % 2 == d % 2) {
                        cout << x << "\n";
                        continue;
                }
                x++;
                if (x * (x + 1) / 2 % 2 == d % 2) {
                        cout << x << "\n";
                        continue;
                }
                x++;
                if (x * (x + 1) / 2 % 2 == d % 2) {
                        cout << x << "\n";
                        continue;
                }
        }       
}

```

# Spread Spree

```

#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>((x).size())
#define int long long

const int mod = 998244353;

signed main() {

        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int t;
        cin >> t;

        while (t--) {

                int n, m;
                cin >> n >> m;
                if (n < m) swap(n, m);

                int d = n / 2;
                int r = min(d + 1, m);
                int l = max(1ll, m - d);
                int sm = (r - l + 1) * (l + r) / 2 % mod;
                
                int ans = (n + 1) / 2 * sm % mod;
                if (n % 2 == 0) ans += (n + 2) / 2 * sm % mod;
                ans %= mod;

                cout << ans << "\n";

        }
        
}

```

# Stingy Arrays

```

```

# Go Away, Goose!

```

```

# Roads and Flights

```

```