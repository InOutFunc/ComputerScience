#include <iostream>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length == 0) {
            return false;
        }
        int i = 0;
        while (i < length) {
            if (i == numbers[i]) {
                if (i + 1 < length && numbers[i + 1] < i + 1) {
                    break;
                }
                i++;
                continue;
            }
            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
            
        }
        duplication = &numbers[i];
        return i == length - 1;
    }
};

int main()
{
    Solution sol;
    int numbers[] = {2, 3, 1, 0, 2, 5, 3};
    int len = 7;
    int *p;
    sol.duplicate(numbers, len, p);

    return 0;
}