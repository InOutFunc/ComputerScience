#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string res = convertHundred(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for (int i = 0; i < 3; i++) {
            num /= 1000;
            res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
        }
        while (res.back() == ' ') {
            res.pop_back();
        }
        return res.empty() ? "Zero" : res;
    }
    
private:
    string convertHundred(int num)
    {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100;
        int b = num % 100;
        int c = num % 10;
        res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
        if (a > 0) {
            res = v1[a] + " Hundred" + (b ? " " + res : "");
        }
        return res;
    }
};

int main()
{
    int num = 1234567891;
    Solution sol;
    string ret = sol.numberToWords(num);

    return 0;
}