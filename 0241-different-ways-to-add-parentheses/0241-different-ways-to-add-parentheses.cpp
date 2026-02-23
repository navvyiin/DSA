#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        // If already computed, return cached result
        if (memo.count(expression)) {
            return memo[expression];
        }

        vector<int> results;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            // If the character is an operator, split
            if (c == '+' || c == '-' || c == '*') {
                string leftExpr = expression.substr(0, i);
                string rightExpr = expression.substr(i + 1);

                vector<int> leftResults = diffWaysToCompute(leftExpr);
                vector<int> rightResults = diffWaysToCompute(rightExpr);

                // Combine results from left and right
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+') {
                            results.push_back(l + r);
                        } else if (c == '-') {
                            results.push_back(l - r);
                        } else { // '*'
                            results.push_back(l * r);
                        }
                    }
                }
            }
        }

        // Base case: no operator found, just a number
        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        memo[expression] = results;
        return results;
    }
};