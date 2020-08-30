#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码;
    vector<string> ReArrangeArray(const vector<string> &stringInfo)
    {
        vector<string> tmp = stringInfo;
        sort(begin(tmp), end(tmp));
        vector<string> result;
        dfs(tmp, result);
        return result;
    }
private:
    void dfs(const vector<string> &nums, vector<string> &cur)
    {
        if (cur.size() == nums.size()) {
            flag = true;
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (flag) {
                return;
            }
            if (std::find(cur.begin(), cur.end(), nums[i]) != cur.end()) {
                continue;
            }
            if (!cur.empty() && !diff(nums[i], cur.back())) {
                continue;
            }
            cur.push_back(nums[i]);
            dfs(nums, cur);
            if (flag = true) {
                return;
            }
            cur.pop_back();
        }
        
    }
    bool diff(const string &s1, const string s2)
    {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
            }
        }
        return count == 1;
    }
    bool flag = false;
};

inline int ReadInt()
{
    int number;
    cin >> number;
    return number;
}

template<typename T>
inline vector<T> ReadVector(int size)
{
    vector<T> objects(size);
    for (int i = 0; i < size; ++i) {
        cin >> objects[i];
    }
    return objects;
}

template<typename T>
inline void WriteVector(const vector<T>& objects, char delimeter = ' ')
{
    auto it = objects.begin();
    if (it == objects.end()) {
        return;
    }
    cout << *it;
    for (++it; it != objects.end(); ++it) {
        cout << delimeter << *it;
    }
    cout << endl;
}

int main()
{
    int lines = ReadInt();
    vector<string> stringInfo = ReadVector<string>(lines);
    Solution solu;
    auto result = solu.ReArrangeArray(stringInfo);
    if (result.size() == 0) {
        cout << "Impossible";
    }
    WriteVector(result, '\n');

    return 0;
}
