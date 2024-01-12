class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e) {
            if (c == a) {
                if (b < f && b < d && d < f) return 2;
                if (b > f && b > d && d > f) return 2;
            }
            return 1;
        }
        if (b == f) {
            if (d == f) {
                if (a > e && a > c && c > e) return 2;
                if (a < e && a < c && c < e) return 2;
            }
            return 1;
        }
        if ((e-f) == (c-d)) {
            if ((e-f) == (a-b)) {
                if (c < e && c < a && a < e) return 2;
                if (c > e && c > a && a > e) return 2;
            }
            return 1;
        }
        if ((e+f) == (c+d)) {
            if ((a+b) == (e+f)) {
                if (c < e && c < a && a < e) return 2;
                if (c > e && c > a && a > e) return 2;
            }
            return 1;
        }
        return 2;
    }
};
