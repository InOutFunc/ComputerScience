#include <bits/stdc++.h>

using namespace std;

class Solution {public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        backtrack(s, temp, result, 0);
        return result;        
    }
    
    void backtrack(string& s, vector<string>& temp, vector<vector<string>>& result, int start){
        if(start == s.size()){
            result.emplace_back(temp);
        }else{
            
            for(int i=start; i<s.size(); i++){
                if(isPalindrome(s, start, i)){
                    temp.emplace_back(s.substr(start, i-start+1));
                    backtrack(s, temp, result, i+1);
                    temp.pop_back();
                }
            }            
        }        
    }
    
    bool isPalindrome(string s, int low, int high){
        while(low<high){
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
    
};

int main()
{
    string str("aab");
    Solution sol;
    vector<vector<string>> res = sol.partition(str);

    return 0;
}