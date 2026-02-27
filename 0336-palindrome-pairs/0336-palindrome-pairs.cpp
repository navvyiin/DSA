#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        int index;
        vector<int> palSuffix;
        TrieNode* next[26];
        TrieNode() : index(-1) {
            memset(next, 0, sizeof(next));
        }
    };

    TrieNode* root;

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void insert(const string& word, int idx) {
        TrieNode* node = root;
        for (int i = word.size() - 1; i >= 0; --i) {
            if (isPalindrome(word, 0, i))
                node->palSuffix.push_back(idx);

            int c = word[i] - 'a';
            if (!node->next[c])
                node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = idx;
        node->palSuffix.push_back(idx);
    }

    void search(const string& word, int idx, vector<vector<int>>& res) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->index != -1 &&
                node->index != idx &&
                isPalindrome(word, i, word.size() - 1)) {
                res.push_back({idx, node->index});
            }

            int c = word[i] - 'a';
            if (!node->next[c]) return;
            node = node->next[c];
        }

        for (int j : node->palSuffix) {
            if (j != idx)
                res.push_back({idx, j});
        }
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i)
            insert(words[i], i);

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i)
            search(words[i], i, res);

        return res;
    }
};