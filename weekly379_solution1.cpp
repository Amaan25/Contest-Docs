class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, cur = 0, mx = 0;
        for (vector<int> v : dimensions) {
            cur = v[0]*v[0] + v[1]*v[1];
            if (cur > mx) {
                mx = cur;
                ans = v[0]*v[1];
            }  
            if (cur == mx) {
                ans = max(ans, v[0]*v[1]);
            }
        }
        return ans;
    }
};
