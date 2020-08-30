#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    string str;
    int count;
};

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码;
    vector<string> ReArrangeArray(const vector<string> &stringInfo)
    {
        if (stringInfo.empty()) {
            return {"Impossible"};
        }
        if (stringInfo[0].empty()) {
            return {"Impossible"};
        }
        for (int i = 1; i < stringInfo.size(); i++) {
            if (stringInfo[i].size() != stringInfo[i - 1].size()) {
                return {"Impossible"};
            }
            if (stringInfo[i].empty()) {
                return {"Impossible"};
            }
        }
        vector<string> tmp = stringInfo;
        sort(begin(tmp), end(tmp));
        vector<string> result;
        vector<Node> cur;
        Dfs(tmp, cur);
        for (int i = 0; i < cur.size(); i++) {
            string tmp = cur[i].str;
            result.push_back(tmp);
        }
        return result;
    }
    
private:
    void Dfs(const vector<string> &nums, vector<Node> &cur)
    {
        if (cur.size() == nums.size()) {
            flag = true;
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (flag) {
                return;
            }
            auto iter = std::find_if(cur.begin(), cur.end(), [&](const auto &item) {
                return item.str == nums[i];
            });
            if (iter != cur.end() && (*iter).count == i) {
                continue;
            }
            if (!cur.empty() && !Diff(nums[i], cur.back().str)) {
                continue;
            }
            Node node;
            node.str = nums[i];
            node.count = i;
            cur.push_back(node);
            Dfs(nums, cur);
            if (flag == true) {
                return;
            }
            cur.pop_back();
        }
        
    }

    bool Diff(const string &s1, const string &s2) const
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
