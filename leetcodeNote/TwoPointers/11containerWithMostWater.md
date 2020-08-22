# 最多的水量

## 思想

```c++
  1 2 3 4 5 6
1 x ------- o
2 x x
3 x x x 
4 x x x x
5 x x x x x
6 x x x x x x
```



```c++
  1 2 3 4 5 6
1 x ------- o
2 x x       o
3 x x x     |
4 x x x x   |
5 x x x x x |
6 x x x x x x
```



```c++
  1 2 3 4 5 6
1 x ------- o
2 x x - o o o
3 x x x o | |
4 x x x x | |
5 x x x x x |
6 x x x x x x
```

## 终止条件

```c++
在l == r时停止，因此使用while (l < r)
```

## 更新最大值

```c++
maxArea = std::max(maxArea, (r - l) * std::min(height[l], height[r]));
```

##  更新循环变量

```c++
if (height[l] < height[r]) {
    l++;
} else {
    r--;
}
```



