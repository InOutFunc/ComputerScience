#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int leftBound(vector<int> nums, int target)
{
    if (nums.empty()) {
        return -1;
    }
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return left;
}

int rightBound(vector<int> nums, int target)
{
    if (nums.empty()) {
        return -1;
    }
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left;
}
int main()
{
    vector<int> nums = {1, 2, 3, 5, 6};
    int target = 4;
    int res = leftBound(nums, target);

    return 0;
}