# 插入排序

```cpp
void InsertSort(int A[], int n)
{
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            int tmp = A[i];
            int j = i - 1;
            for (; j >= 0 && A[j] > tmp; j--) {
                A[j + 1] = A[j];
            }
            A[j + 1] = tmp;
        }
    }
}
```

## 冒泡排序

```cpp
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (flag == false) {
            return;
        }
    }
}
```

