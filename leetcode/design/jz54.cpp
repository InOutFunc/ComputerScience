#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         auto iter = find_if(begin(s), end(s), [=](const auto &item) {
             return item.first == ch;
         });
         if (iter == s.end()) {
             s.push_back(make_pair(ch, 1));
             return;
         }
         if (iter->second == 1) {
             iter->second = 2;
         }
         return;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        auto iter = find_if(begin(s), end(s), [](const auto &item) {
            return item.second == 1;
        });
        if (iter == s.end()) {
            return '#';
        }
        return iter->first;
    }

    vector<pair<char, int>> s;
};

int main()
{
    return 0;
}