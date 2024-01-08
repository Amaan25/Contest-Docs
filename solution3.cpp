class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y) return y - x;
        int a = 10000;  // max possible difference

        a = min(a, x - y);
        a = min(a, 1 + x % 11 + minimumOperationsToMakeEqual(x / 11, y)); // add x%11 steps for reaching next multiple and 1 step for division
        a = min(a, 12 - x % 11 + minimumOperationsToMakeEqual((x + 11) / 11, y)); // add (11 - x%11) steps for reaching previous multiple of 11 and 1 step for division
        // similarly for 5:
        a = min(a, 1 + x % 5 + minimumOperationsToMakeEqual(x / 5, y));
        a = min(a, 6 - x % 5 + minimumOperationsToMakeEqual((x + 5) / 5, y));

        return a;
    }
};