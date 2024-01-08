class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0], i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1] + 1) s += nums[i];
            else break;
            i++;
        }
        unordered_map<int, int> m;
        for (int num : nums) m[num]++;
        while (m[s]) s++;
        return s;
    }
};