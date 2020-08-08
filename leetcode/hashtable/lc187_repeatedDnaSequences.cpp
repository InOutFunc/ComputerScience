#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> seen;
        unordered_set<int> dup;
        vector<string> result;
        vector<char> m(26);
        m['A' - 'A'] = 0;
        m['C' - 'A'] = 1;
        m['G' - 'A'] = 2;
        m['T' - 'A'] = 3;
        
        for (int i = 0; i + 10 <= s.size(); ++i) {
            string substr = s.substr(i, 10);
            int v = 0;
            for (int j = i; j < i + 10; ++j) { //20 bits < 32 bit int
                v <<= 2;
                v |= m[s[j] - 'A'];
            }
            if (seen.count(v) == 0) { //not seen
                seen.insert(v);
            } else if (dup.count(v) == 0) { //seen but not dup
                dup.insert(v);
                result.push_back(substr);
            } //dup
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> res = sol.findRepeatedDnaSequences(s);

    return 0;
}