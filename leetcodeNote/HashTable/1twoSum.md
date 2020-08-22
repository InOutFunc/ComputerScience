# 将值和索引关联

## hash

`map<value, index>`

如果不需要返回索引，只需要返回`value`，用`vector<value>`也是可以的

## 转换

`a + b = target`

需要双重`for`循环，一个循环`a`，一个循环`b`。

转换成`b = target - a`的话，只需要一个循环来循环`a`就可以了。但是`target - a`要存在一个容器中，遍历到`a`时，容器中现有的值是`target - a`的可选值。遍历到`a`时，`a`的`index`是可以获得的。但是`target - a`的index需要通过`map`绑定起来。

## 总结

```c++
a + b = target;
a: a;
b: target - a;

for loop nums:
	在map中找b，也就是找target - a;
```



