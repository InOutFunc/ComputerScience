# the essence of cpp

## link 

https://www.youtube.com/watch?v=86xWVb4XIyE

## overview

* what is c++?
  * aims and constraints
* resource management
  * in some detail
* oop: classes and hierachies
  * very briefly
* gp: templates
  * requirements checking
* challenges

## what is c++?

* type safety
  * encapsulate necessary unsafe operations
* resource safety
  * it's not all memory
* performance
  * for some parts of almost all systems, it's important
* predictability
  * for hard and soft real time
* teachability
* readability

## resource management

* a resource is something that must be acquired and later released
* a resource should have an owner
* all the standard-library containers manage their elements
  * vector
  * list, forward_list
  * map, unordered_map
  * set, multi_set
  * string
* other standard-library classes manage other resources
  * not just memory
  * thread, lock_guard,
  * istream, fstream
  * unique_ptr, shared_ptr
* use constructors and destructor

```cpp
template<typename T>
class Vector{
    Vector(initializer_list<T>);
    ~Vector();
private:
    T *elem;
    int sz;
};

void fct()
{
    Vector<double> vd{1.0, 2.0};
    Vector<string> vs{"a", "b"};
}
```

* Pointer misuse

  ```cpp
  void f(int n, int x)
  {
      Gadget *p = new Gadget{n};
      if (x < 100) {
          throw std::runtime_error{"Weird!"};
      }
      if (x < 200) {
          return;
      }
      delete p; // I want my garbage collector!
  }
  ```

* resource handles and pointers

  ```cpp
  // A std::shared_ptr releases its object at when the last shared_ptr to it is destroyed
  void f(int n, int x)
  {
      auto p = make_shared<Gadget>(n);
      if (x < 100) {
          throw std::runtime_error{"Weird!"};
      }
      if (x < 200) {
          return;
      }
  }
  // shared_ptr provides a form of garbage collection, but I'm not sharing anything!
  
  // A std::unique_ptr releases its object at when it goes out of scope
  void f(int n, int x)
  {
      auto p = make_unique<Gadget>(n);
      if (x < 100) {
          throw std::runtime_error{"Weird!"};
      }
      if (x < 200) {
          return;
      }
  }
  // This is simple and cheap, no more expensive than a "plain old pointer"
  
  // but why use a pointer at all
  void f(int n, int x)
  {
      Gadget g {n};
      if (x < 100) {
          throw std::runtime_error{"Weird!"};
      }
      if (x < 200) {
          return;
      }
  }
  ```

## Error handling and resources

## Why do we use pointers?

* and references, iterators, etc.
* To represent ownership
  * don't! Stop! Instead, use handles
* 