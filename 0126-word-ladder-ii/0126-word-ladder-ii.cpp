#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!dict.count(endWord)) return result;

        // BFS
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> distance;

        queue<string> q;
        q.push(beginWord);
        distance[beginWord] = 0;

        int wordLen = beginWord.length();
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                string original = word;

                for (int j = 0; j < wordLen; j++) {
                    char oldChar = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;

                        if (!dict.count(word)) continue;

                        if (!distance.count(word)) {
                            distance[word] = distance[original] + 1;
                            q.push(word);
                            visitedThisLevel.insert(word);
                        }

                        if (distance[word] == distance[original] + 1) {
                            parents[word].push_back(original);
                        }

                        if (word == endWord) {
                            found = true;
                        }
                    }

                    word[j] = oldChar;
                }
            }

            for (auto& w : visitedThisLevel) {
                dict.erase(w);
            }
        }

        if (!found) return result;

        // DFS backtracking
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, result);

        return result;
    }

private:
    void dfs(string word,
             string beginWord,
             unordered_map<string, vector<string>>& parents,
             vector<string>& path,
             vector<vector<string>>& result) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (auto& parent : parents[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};