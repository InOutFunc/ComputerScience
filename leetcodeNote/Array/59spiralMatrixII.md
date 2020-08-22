## 旋转矩阵

## 变量定义

```cpp
int startRow = 0;
int endRow = n - 1;
int startCol = 0;
int endCol = n - 1;
int count = 0;
int dir = 0;
vector<vector<int>> res(n, vector<int>(n, 0));
```

## 循环终止条件

```cpp
while (startRow <= endRow && startCol <= endCol)
```

## 从左向右

```cpp
case 0:
	for (int col = startCol; col < endCol; col++) {
        count++;
        res[startRow][col] = count;
    }
	startRow++;
	break;
```

## 从上到下

```cpp
case 1:
	for (int row = startRow; row <= endRow; row++) {
        count++;
        res[row][endCol] = count;
    }
	endCol--;
	break;
```

## 从右向左

```cpp
case 2:
	for (int col = endCol; col >= startCol; col--) {
        count++;
        res[endRow][col] = count;
    }
	endRow--;
	break;
```

## 从下到上

```cpp
case 3:
	for (int row = endRow; row >= startRow; row--) {
        count++;
        res[row][startCol] = count;
    }
	startCol++;
	break;
```

## 更改方向

```cpp
dir = (dir + 1) % 4;
```

