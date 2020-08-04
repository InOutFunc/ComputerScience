#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        static vector<unordered_map<string, int>> states = {
            {},                                                    // state 0
            {{"blank", 1}, {"sign", 2}, {"digit", 3}, {"dot", 4}}, // state 1
            {{"digit", 3}, {"dot", 4}},                            // state 2
            {{"digit", 3}, {"dot", 5}, {"e", 6}, {"blank", 9}},    // state 3, final
            {{"digit", 5}},                                        // state 4
            {{"digit", 5}, {"e", 6}, {"blank", 9}},                // state 5, final
            {{"sign", 7}, {"digit",8}},                            // state 6
            {{"digit", 8}},                                        // state 7
            {{"digit", 8}, {"blank", 9}},                          // state 8, final
            {{"blank", 9}}                                         // state 9, final
        };
        int currState = 1;
        string transition;

        for(auto c : s) {
            if(c>='0' && c<='9') transition = "digit";
            else if(c=='-' || c=='+') transition = "sign";
            else if(c == ' ') transition = "blank";
            else if(c == '.') transition = "dot";
            else if(c == 'e') transition = "e";
            else return false;

            auto it = states[currState].find(transition);
            if  (it == states[currState].end()) 
                return false;
            else
                currState = it->second;
        }
        if  (currState == 3 || currState == 5 || currState == 8 || currState == 9)
            return true;
        else
            return false;
    }
};

int main()
{
    string str(" -90e3   ");
    Solution sol;
    bool ret = sol.isNumber(str);

    return 0;
}