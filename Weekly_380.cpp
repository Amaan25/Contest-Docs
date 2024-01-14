// Q1
class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        // Step 1: Frequency Calculation
        std::unordered_map<int, int> um;
        for (int x : nums) {
            um[x]++;
        }

        // Step 2: Find Maximum Frequency
        int maxi = 0;
        for (auto x : um) {
            if (x.second > maxi) {
                maxi = x.second;
            }
        }

        // Step 3: Calculate Total Frequency with Maximum Frequency
        int ans = 0;
        for (auto x : um) {
            if (x.second == maxi) {
                ans += maxi;
            }
        }

        // Step 4: Return Result
        return ans;
    }
};

// Q2 - KMP algo

void getPatternMatchingIndex(string& s, string& a, vector<int>& v){
    string t = a + "@" + s;
    vector<int> lps(1, 0);
    for(int i = 1; i < t.size(); ++i){
        int ind = lps[i-1]; 
        while(ind > 0 && t[ind] != t[i]) { ind = lps[ind-1]; }
        lps.push_back((t[ind] == t[i])?ind + 1 : 0);
    }
    for(int i = 0; i < lps.size(); ++i){
        if(lps[i] == a.size()) v.push_back(i - 2*a.size());
    }
}

vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> ans, v1, v2;
    getPatternMatchingIndex(s, a, v1);
    getPatternMatchingIndex(s, b, v2);
    for(int i = 0, j = 0; i < v1.size(); ++i){
        while(j < v2.size() && v1[i] > v2[j] && abs(v1[i] - v2[j]) > k) j++;
        if(j < v2.size() && abs(v1[i] - v2[j]) <= k) ans.push_back(v1[i]);
    }
    return ans;
}
