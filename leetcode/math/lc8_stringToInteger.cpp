#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int i = 0;
        int n = str.size();
        while (i < n && str[i] == ' ') {
            ++i;
        }

        int sign = 1;
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i++] == '+') ? 1 : -1;
        }

        int base = 0;
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};

int main()
{
    string str("  a-42");
    Solution sol;
    int res = sol.myAtoi(str);
    return 0;
}