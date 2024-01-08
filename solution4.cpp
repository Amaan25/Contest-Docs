// solution of LC profile: erel3

class Solution {
    long long count(long long x, long long lim, string s) {
        long long d1 = 0, d2 = 0, dd = 1;
        while (!s.empty()) {
            if (s.back() > '0' + lim) return 0;
            d2 = d2 + (s.back() - '0') * dd;
            dd *= 10;
            s.pop_back();
        }
        if (x % dd >= d2) {
            x /= dd;
        } else {
            x /= dd;
            x--;
        }
        if (x < 0) return 0;
        vector<int> z;
        while (x) {
            z.push_back(x % 10);
            x /= 10;
        }
        bool w = false;
        for (int i = z.size() - 1; i >= 0; i--) {
            if (z[i] > lim) w = true;
            if (w) z[i] = lim;
        }
        lim++;

        long long ans = 0;
        dd = 1;
        for (int i = 0; i < z.size(); i++) {
            ans += z[i] * dd;
            dd *= lim;
        }
        // cout << ans << endl;
        return ans + 1;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return count(finish, limit, s) - count(start - 1, limit, s);
    }
};