#include <map>
#include <unordered_map>

using namespace std;

int func(string s)
{
    unordered_map<char, int> m;
    int res = 0;
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
        while (m.size() > 2) {
            if (--m[s[left]] == 0) {
                m.erase(s[left]);
            }
            ++left;
        }
        res = max(res, i - left + 1);
    }
}