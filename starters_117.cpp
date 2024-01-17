// Q1

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
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

// Q2

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
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
