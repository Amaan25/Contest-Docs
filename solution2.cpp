class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s = 0;
        for (int n : nums) s ^= n;
        s ^= k;
        int ans = 0;
        while (s) {
            s = (s & (s - 1));
            ans++;
        }
        return ans;
    }
};