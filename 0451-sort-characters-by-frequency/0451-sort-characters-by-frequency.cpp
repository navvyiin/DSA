class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        
        for(char c : s)
            freq[c]++;
        
        vector<pair<char,int>> v(freq.begin(), freq.end());
        
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        
        string res;
        
        for(auto &p : v)
            res.append(p.second, p.first);
        
        return res;
    }
};