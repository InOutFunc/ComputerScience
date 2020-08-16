#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> val(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                cout << "i:" << i << "j:" << j << endl;
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int high = i + j;
                int low = i + j + 1;
                int sum = mul + val[low];
                val[high] += sum / 10;
                val[low] = sum % 10;
            }
        }
        
        string res;
        for (int i = 0; i < val.size(); i++) {
            if (val[i] != 0 || !res.empty()) {
                res.push_back(val[i] + '0');
            }
        }
        
        if (res.empty()) {
            res.push_back('0');
        }
        return res;
    }
};

int main()
{
    string nums1("89");
    string nums2("76");
    Solution sol;
    string res = sol.multiply(nums2, nums1);

    return 0;
}