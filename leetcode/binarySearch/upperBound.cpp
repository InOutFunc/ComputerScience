#include <bits/stdc++.h>

using namespace std;

int right_bound(int nums[], int length, int target) {
    if (length == 0) return -1;
    int left = 0, right = length;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // note
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left; // note
}

int main()
{
    int nums[] = {1, 2, 3, 5};
    int target = 4;
    int res = right_bound(nums, 4, target);

    return res;
}