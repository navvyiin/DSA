#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        string result;
        result.reserve(max(a.size(), b.size()) + 1);

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            result.push_back((sum & 1) + '0');
            carry = sum >> 1;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};