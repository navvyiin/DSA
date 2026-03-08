#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeSame(string s, int i) {
        if (i < 0) return s;

        int left = i, right = i;

        while (left > 0 && s[left - 1] == s[i])
            left--;

        while (right + 1 < s.size() && s[right + 1] == s[i])
            right++;

        int length = right - left + 1;

        if (length >= 3) {
            string newS = s.substr(0, left) + s.substr(right + 1);
            return removeSame(newS, left - 1);
        }

        return s;
    }

    int findMinStep(string board, string hand) {

        sort(hand.begin(), hand.end());

        queue<tuple<string,string,int>> q;
        set<pair<string,string>> visited;

        q.push({board, hand, 0});
        visited.insert({board, hand});

        while (!q.empty()) {

            auto [currBoard, currHand, step] = q.front();
            q.pop();

            for (int i = 0; i <= currBoard.size(); i++) {

                for (int j = 0; j < currHand.size(); j++) {

                    if (j > 0 && currHand[j] == currHand[j-1])
                        continue;

                    if (i > 0 && currBoard[i-1] == currHand[j])
                        continue;

                    bool pick = false;

                    if (i < currBoard.size() && currBoard[i] == currHand[j])
                        pick = true;

                    if (i > 0 && i < currBoard.size() &&
                        currBoard[i-1] == currBoard[i] &&
                        currBoard[i] != currHand[j])
                        pick = true;

                    if (pick) {

                        string newBoard =
                            currBoard.substr(0, i) +
                            currHand[j] +
                            currBoard.substr(i);

                        newBoard = removeSame(newBoard, i);

                        string newHand =
                            currHand.substr(0, j) +
                            currHand.substr(j + 1);

                        if (newBoard.empty())
                            return step + 1;

                        if (!visited.count({newBoard, newHand})) {
                            q.push({newBoard, newHand, step + 1});
                            visited.insert({newBoard, newHand});
                        }
                    }
                }
            }
        }

        return -1;
    }
};