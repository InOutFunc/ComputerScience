# singleton

## static实现

```c++
class Singleton
{
private:
   Singleton() = default;

public:
   static Singleton& instance()
   {
      static Singleton INSTANCE;
      return INSTANCE;
   }
};
```

`static Singleton INSTANCE;`这条语句只会调用一次

[How to understand Singleton in c++?](https://stackoverflow.com/questions/63112299/how-to-understand-singleton-in-c)

