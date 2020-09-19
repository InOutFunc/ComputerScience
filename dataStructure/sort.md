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

## 快速排序

```cpp
int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            high--;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
void QuickSort(int A[], int low, int high)
{
    if (low >= high) {
        return;
    }
    int pivotPos = Partition(A, low, high);
    QuickSort(A, low, pivotPos - 1);
    QuickSort(A, pivotPos + 1, high);
}
```

## 简单选择排序

```cpp
void SelectSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A[i], A[min]);
        }
    }
}
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = temp;
}
```

## 堆排序

## 归并排序

```cpp
int *B = (int *)malloc(n * sizeof(int));
void Merge(int A[], int low, int mid, int high)
{
    int i
}
```

## 基数排序

