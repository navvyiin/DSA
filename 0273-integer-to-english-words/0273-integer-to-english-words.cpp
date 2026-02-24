#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> belowTwenty = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety"
    };

    vector<string> thousands = {
        "", "Thousand", "Million", "Billion"
    };

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string result;
        int idx = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + thousands[idx] + " " + result;
            }
            num /= 1000;
            idx++;
        }

        // remove trailing space
        while (!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }

private:
    string helper(int num) {
        if (num == 0) return "";
        if (num < 20)
            return belowTwenty[num] + " ";
        if (num < 100)
            return tens[num / 10] + " " + helper(num % 10);
        return belowTwenty[num / 100] + " Hundred " + helper(num % 100);
    }
};