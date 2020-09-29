1、友元什么都能访问、继承只能访问protected和public

 

2、class默认是private、因为是对象要控制访问权限。而struct为了兼容c、则只能默认为public。因为c中没有Public和private的概念、c中struct都是public的。

[default visibility of C++ class/struct members](https://stackoverflow.com/questions/1247745/default-visibility-of-c-class-struct-members)

 

来自 <https://stackoverflow.com/questions/1247745/default-visibility-of-c-class-struct-members> 

## 构造函数属性

在phycon数据库管理类、单例模式中、构造函数应该是private的

[Do constructors always have to be public? [duplicate\]](https://stackoverflow.com/questions/30995942/do-constructors-always-have-to-be-public)