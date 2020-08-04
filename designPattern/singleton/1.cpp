#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    Singleton &s1 = Singleton::instance();
    Singleton &s2 = Singleton::instance();

    return 0;
}