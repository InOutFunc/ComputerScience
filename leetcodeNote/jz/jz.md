# 问题 + 思路 + 算法 + 技巧

## 1

* 问题

二维数组，每行递增、每列递增，查找一个数

* 思路

查找该数时该如何移动？当从右上角开始时，若小于目标则该行舍弃，若大于目标则该列舍弃。

* 算法

for循环遍历查找

* 技巧

```cpp
for (int i = 0, j = cols - 1; i < row && j >= 0;) {
    
}

for (int i = 0; i < row;) {
    for (int j = cols - 1; j >= 0;) {
        
    }
}
```

一中是单层循环，循环由两个变量i, j同时控制

二中是双层循环，外层由i控制，内层由j控制

## 2

* 问题

字符串，查找空格并且替换为%20

* 思路
  * 若是新建字符串，则可以从前向后扫描
  * 若在原字符串替换，当成新字符串和原字符串部分重合，从新字符串后面开始插入。因此需要计算出新字符串的长度

* 算法

以原字符串作为基准遍历、遍历时同时更新新字符串

* 技巧

```cpp
str[j--] = '0';
str[j--] = str[i--];
```

## 3

* 问题

链表，从尾到头打印

* 思路

倒序，因此考虑栈。先遍历链表的value存入栈中，然后从栈中打印

* 算法

while遍历

* 技巧

```cpp
while (head != nullptr); // 可以访问到最后一个node
while (head->next != nullptr); // 可以访问到倒数第二个node
```

## 4

* 问题

二叉树前序遍历，中序遍历。不包含重复数字。重建二叉树

* 思路

先重建root，前序遍历分为左子树和右子树，中序遍历分为左子树和右子树。分治实现。

* 算法

分治法、用递归实现

* 技巧
  * pre和vin序列恒定、用left和right来表示子树序列的范围
  * 新生产的子树通过返回值来得到，有root->left = divede(), root->right = divide();

```cpp
4;
TreeNode *divide(const vector<int> &pre, int pLeft, int pRight, const vector<int> &vin, int vLeft, int vRight)
{
    root->left = divide(pre, pLeft + 1, pLeft + leftCnt, vin, vLeft, i - 1);
    root->right = divide(pre, pRight - rightCnt + 1, pRight, vin, i + 1, vRight);
}
```

## 5

* 问题

两个栈，实现先进先出

* 思路

连续进栈两次，相当于先进先出了。不过需要一批数据同时处理，在这一批数据生效。因此需要第一批二次入栈的数据用完后，才能接着二次入栈

* 算法

while遍历栈1中的数据到栈2

* 技巧

若栈2为空，先给栈2填上数据再读。void pop(); int top(); void push();

```cpp
if (stack2.empty()) {
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }
}
```

## 6

* 问题
* 思路
* 算法
* 技巧

## 7

- 问题
- 思路
- 算法
- 技巧

## 8

- 问题
- 思路
- 算法
- 技巧

## 9

- 问题
- 思路
- 算法
- 技巧

## 10

- 问题
- 思路
- 算法
- 技巧

## 11

- 问题
- 思路
- 算法
- 技巧

## 12

- 问题
- 思路
- 算法
- 技巧

## 13

- 问题
- 思路
- 算法
- 技巧

## 14

- 问题
- 思路
- 算法
- 技巧

## 15

- 问题
- 思路
- 算法
- 技巧

## 16

- 问题
- 思路
- 算法
- 技巧

## 17

- 问题
- 思路
- 算法
- 技巧

## 18

- 问题
- 思路
- 算法
- 技巧

## 19

- 问题
- 思路
- 算法
- 技巧

## 20

- 问题
- 思路
- 算法
- 技巧

## 21

- 问题
- 思路
- 算法
- 技巧

## 22

- 问题
- 思路
- 算法
- 技巧

## 23

- 问题
- 思路
- 算法
- 技巧

## 24

- 问题
- 思路
- 算法
- 技巧

## 25

- 问题
- 思路
- 算法
- 技巧

## 26

- 问题
- 思路
- 算法
- 技巧

## 27

- 问题
- 思路
- 算法
- 技巧

## 28

- 问题
- 思路
- 算法
- 技巧

## 29

- 问题
- 思路
- 算法
- 技巧

## 30

- 问题
- 思路
- 算法
- 技巧

## 31

- 问题
- 思路
- 算法
- 技巧

## 32

- 问题
- 思路
- 算法
- 技巧

## 33

- 问题
- 思路
- 算法
- 技巧

## 34

- 问题
- 思路
- 算法
- 技巧

## 35

- 问题
- 思路
- 算法
- 技巧

## 36

- 问题
- 思路
- 算法
- 技巧

## 37

- 问题
- 思路
- 算法
- 技巧

## 38

- 问题
- 思路
- 算法
- 技巧

## 39

- 问题
- 思路
- 算法
- 技巧

## 40

- 问题
- 思路
- 算法
- 技巧

## 41

- 问题
- 思路
- 算法
- 技巧

## 42

- 问题
- 思路
- 算法
- 技巧

## 43

- 问题
- 思路
- 算法
- 技巧

## 44

- 问题
- 思路
- 算法
- 技巧

## 45

- 问题
- 思路
- 算法
- 技巧

## 46

- 问题
- 思路
- 算法
- 技巧

## 47

- 问题
- 思路
- 算法
- 技巧

## 48

- 问题
- 思路
- 算法
- 技巧

## 49

- 问题
- 思路
- 算法
- 技巧

## 50

- 问题
- 思路
- 算法
- 技巧

## 51

- 问题
- 思路
- 算法
- 技巧

## 52

- 问题
- 思路
- 算法
- 技巧

## 53

- 问题
- 思路
- 算法
- 技巧

## 54

- 问题
- 思路
- 算法
- 技巧

## 55

- 问题
- 思路
- 算法
- 技巧

## 56

- 问题
- 思路
- 算法
- 技巧

## 57

- 问题
- 思路
- 算法
- 技巧

## 58

- 问题
- 思路
- 算法
- 技巧

## 59

- 问题
- 思路
- 算法
- 技巧

## 60

- 问题
- 思路
- 算法
- 技巧

## 61

- 问题
- 思路
- 算法
- 技巧

## 62

- 问题
- 思路
- 算法
- 技巧

## 63

- 问题

不断插入的数据流，获取中位数

- 思路

奇数时是位于中间的数，偶数时是中间两数的平均值。将数分成small和large两部分，small是最大堆，large是最小堆。small中数量大于等于large

- 算法

先将数据放入small中，取出混合后的最大值。然后放入large中。

若small大小小于large，则将large最小值放入small中。

- 技巧

```cpp
// 根据用途来命名
priority_queue<int> small;
// 最小堆的定义，greater<int>表示从小到大
priority_queue<int, vector<int>, greater<int>> large;
```

## 64

- 问题

一维数组，窗口大小，求每个窗口内的最大值

- 思路
  - 直接遍历每个窗口求最大值
  - 维护一个单调双端队列、队列的front是此刻滑动串口的最大值。为了比较下标，队列里存储的是下标值
- 算法

遍历数组，看此下标加入队列后，队列是否超过窗口大小了。

从后向前遍历，维护队列的单调递减性。插入新的下标。

在符合窗口大小时，每次都输出最大值

- 技巧

注意最后输出结果时不要输出下标了

```cpp
if (i >= size - 1) {
    res.push_back(num[dq.front()]);
}
```

## 65

- 问题

二维数组，路径是否包含字符串

- 思路

分治思想、当前点 &&（divide1 || divide2 || divide3 || divide4)，四个divide是并列的，visited改回来。cur也是并列的，也要改回来。

- 算法

超过边界了返回，visited也返回，成功了也返回

- 技巧

```cpp
// 直接比较最后一个字符是否符合;
if (level == len && matrix[row * cols + col] == str[level - 1]);
// 将return true的条件提到最后面
if (level == len && matrix[row * cols + col] == str[level - 1])
// 返回
bool res = ...;
...;
return res;
而不是;
return ...;
```



## 66

- 问题

二位数组，移动，坐标和小于等于18，格子数量

- 思路

分治的思想、当前点加上四个方向上的返回值。通过visited来表示分治后的子问题。当前点 + divide

- 算法

在超过边界或者已经visited了返回0，其它情况就是当前点加上四个子问题

- 技巧
  - 提取isValid函数，isValid里面还可以再调用函数

```cpp
int divide(int threshold, int rows, int cols, int row, int col, vector<vector<bool>> &visited)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return 0;
    }
    if (!isValid(row, col)) {
        return 0;
    }
    if (visited[row][col]) {
        return 0;
    }
    visited[row][col] = true;
    return 1 + divide(threshold, rows, cols, row + 1, col, visited)
        + divide(threshold, rows, cols, row - 1, col, visited)
        + divide(threshold, rows, cols, row, col + 1, visited)
        + divide(threshold, rows, cols, row, col - 1, visited);
}

bool isValid(int row, int col, int threshold)
{
    return getSum(row) + getSum(col) <= threshold;
}
int getSum(int n)
{
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10; // 注意sum +
        n = n / 10;
    }
    return sum // 注意要return
}
```

## 67

- 问题

长度n，分成m段，m >1，乘积最大是多少

- 思路

假设n分为m段，实际只需求(1-i) * (i + 1 ~ m)，因为那m段也是有1-i分来的

- 算法

遍历n，求dp[i]。

求dp[i]的时候、遍历j，将i在不同位置分成两段，取最大值

- 技巧
  - 相乘时123的长度和要求输出的不同，边界值返回
  - 方便起见，定义dp长度为n+1，这样dp[i]就表示长度为i
  - j的长度要明确，此处就表示第一段的长度

```cpp
if (n <= 1) {
    return 0;
}
if (n == 2) {
    return 1;
}
if (n == 3) {
    return 2;
}
vector<int> dp(n + 1);
dp[1] = 1;
dp[2] = 2;
dp[3] = 3;
for (int i = 4; i < n + 1; i++) {
    for (int j = 1; j < n / 2; j++) {
        dp[i] = max(dp[i], dp[j] * dp[i - j]);
    }
}
return dp[n]
```

