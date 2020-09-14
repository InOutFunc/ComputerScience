#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n = input.size();
        if (n < k || k == 0) {
            return {};
        }
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            q.push(input[i]);
        }
        for (int i = k; i < n; i++) {
            if (input[i] < q.top()) {
                q.pop();
                q.push(input[i]);
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i++) {
            res[i] = q.top();
            q.pop();
        }
        
        return res;
    }
};

int main()
{
    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;
    Solution sol;
    vector<int> res = sol.GetLeastNumbers_Solution(input, k);

    return 0;
}