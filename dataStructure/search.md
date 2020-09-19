## 顺序查找

```cpp
int seqSearch(int A[], int len, int target)
{
    for (int i = 0; i < len; i++) {
        if (A[i] == target) {
            return i;
        }
    }
    return -1;
}
```

## 二分查找

```cpp
int binarySearch(int A[], int len, int target)
{
    int low = 0;
    int high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
```

## 分块查找

