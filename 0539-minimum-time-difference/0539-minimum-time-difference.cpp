class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        // Convert time to minutes
        for (auto &t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        
        sort(minutes.begin(), minutes.end());
        
        int ans = INT_MAX;
        
        // Check adjacent differences
        for (int i = 1; i < minutes.size(); i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }
        
        // Check circular difference (last and first across midnight)
        ans = min(ans, 1440 - minutes.back() + minutes[0]);
        
        return ans;
    }
};