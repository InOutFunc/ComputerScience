#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) {
            return false;
        }
        map<int, int> count;
        for (int i = 0; i < numbers.size(); i++) {
            count[numbers[i]]++;
        }
        auto iter = count.begin();
        int start = (iter->first == 0 ? (++iter)->first : iter->first);
        int end = count.rbegin()->first;
        if (end - start > 4) {
            return false;
        }
        
        iter = find_if(count.begin(), count.end(), [](const auto &item) {
            return item.second > 1;
        });
        
        if (iter != count.end() && iter->first != 0) {
            return false;
        }
        
        return true;
    }
};

int main()
{
    vector<int> nums = {0, 3, 2, 6, 4};
    Solution sol;
    bool res = sol.IsContinuous(nums);

    return 0;
}