## 3 c++ and libraries

## 4 other people's code

## 5 discoverability

```cpp
std::vector<int> v{1, 2, 3, 4, 5, 6};
v.
    emplace_back
    empty
    end
    erase
    front
    get_allocator
    insert
    max_size
    
not everything is a member function;
```

## 6 collections, algorithms, iterators

```cpp
collections: templates;
algorithms: templates;
iterators: 
```

## 7 algorithms

>work on any container
>
>no matter what it contains
>
>work on ranges
>
>typically work through iterators
>
>iterators provide significant functionality
>
>live in their own header  file

## 8 headers you should know

><algorithm>
>
><vector> <array> <list> <stack> <map> <queue>
>
><string>
>
><iterator>
>
><utitily> <tuple>
>
><numeric>
>
><complex> <cmath>
>
><regex> <chrono>

##  9 do not write raw loops

```cpp
1. loop through a collection and count;
count or count_if;
2. find the first element in a collection;
find or find_if;
3. create a copy of a collection;
copy_if
```

## 10 algorithms in this course

```cpp
counting and finding;
sorting;
comparing and accumulating;
generating and manipulating collections;
using the power of iterators;
unexpectedly useful operations;
conventions;
```

## 11 summary

## 12 introduction

## 13

>what are you trying to do?

## 14 count

```cpp
int twos = 0; // need to reset to zero
const int target = 2;
for (size_t i = 0; i < v.size(); i++) {
    if (v[i] == target) {
        twos++;
    }
}

const int target = 2;
int simple = count(v.begin(), v.end(), target);
int simple = count(begin(v), end(v), target);
```

## 15 member or non-member begin and end

```cpp
v.begin(), v.end();
begin(v), end(v); // works for c-style arrays too
```

## 16 count_if

```cpp
int odds = 0;
for (auto elem : v) {
    if (elem % 2 != 0) {
        odds++;
    }
}

odds = count_if(begin(v), end(v), [] (auto elem) {
    return elem % 2 != 0;
});
```

## why count anyway?

## 18 finding

```cpp
first element. returns an iterator;
auto res = find(begin(v), end(v), 0);
res = find(res, end(v), 2);
```

## 19 variations on finding

```cpp
find_if_not;
find_first_of;
search;
find_end;
search_n;
adjacent_find;
```

## 22 sorting

```cpp
sort(it1, it2);
overload operator <;
sort(it1, it2, lambda);
```

## 23 stable sort

```cpp
stable_sort
```

## is it sorted

```cpp
is_sorted(it1, it2);
is_sorted(it1, it2, lambda);
```

## find the largest

```cpp
unsorted collection:
max_element();
min_element();
find();

sorted collection:
largets is last, smallest is first;
upper_bound(), lower_bound, binary_search;
```

## shuffle

```cpp
#include <random>
random_device randomdevice;
mt19937 generator(randomdevice());
shuffle(it1, it2, generator);
```

## partial sorting

```cpp
partial_sort();
is_sorted_until;
partial_sort_copy();
```

## nth element

```cpp
nth_element(begin(v2), begin(v2) + 4, end(v2));
```

## summary

sorting is trivial for elements with <

provide a lambda for complete control

when sorting multiple times, consider stable_sort

is_sorted()

faster searches

shuffle(unsort)

partial sort

## 32 comparing collections

```cpp
equal();
mismatch();
```

## pair

```cpp
std::pair: any combination of types;
strongly typed;
get the elements with .first and .second;
```

## demo comparing

```cpp
vector<int> a{};
vector<int> b{};
bool same = equal(begin(a), end(a), begin(b), end(b));
auto firstChange = mismatch(begin(a), end(a), begin(b));
int avalue = *(firstchange.first);
int bvalue = *(firstchange.second);
auto distance = firstchange.first - begin(a);
```

## total the elements of a collection

```cpp
accumulate();
uses +;
or your lambda;
total does not have to be same type as elements;

total = accumulate(begin(a), end(a), 0);
total = accumulate(begin(a), end(a), 0, [](int toal, int i) {
	if (i % 2 == 0) {
        return total + i;
    } else {
        return total;
    }
});
total = accumulate(begin(a), end(a), 1, [](int total, int i) {
    return total * i;
})
```

## a loop in disguise

```cpp
for_each();
takes a lambda;
touches each element once;
does not have to apply to the entire collection;

for_each(begin(a), end(b), [](int &elem) {
    elem = 2;
});
```

## copy

```cpp
operator=;
you could write a loop;
copy();
copy_if();
copy_n();
copy_backward();

vector<int> source {};
vector<int> v2(source.size());
copy(begin(source), end(source), begin(v2));
auto v3 = source;
auto position = find(begin(source), end(source), 1);
vector<int> v4(source.size());
copy(begin(source), position, begin(v4));
```

## collection of noncopyable types

```cpp
move();
move_backward();
```

## removing elements

```cpp
remove();
remove_if();
erase();
```

## creating and filling collections

```cpp
non empty collections default-initialize elements;
fill();
fill_n();
iota();
generate();
generate_n();
```

## replacing values

```c++
repalce();
replace_if();
```

## transform

```cpp
transform(begin(source), end(source), begin(source), [](int elem) {
    return elem * 2;
});
transform(begin(source), end(source) - 1, begin(source) + 1, begin(v6), [](int elem1, int elem2) {
    return elem1 - elem2;
})
```

## eliminating duplicates

```cpp
sort(), unique();
sort(), unique_copy();
```

## reversing and swapping

```cpp
reverse();
iter_swap();
reverse_copy();
```

## 48 using the power of iterators

## preallocating

```cpp
vector<int> v1(10);
fill(begin(v1), end(v1), 1);
fill_n(begin(v1), 6, 2);
iota(begin(v1), end(v1), 1);
what if you don't know the size? no default constructor? default constructor is expensive;
```

## use different iterators

```cpp
back_inserter;
front_inserter;

vector<int> v2;
fill_n(back_inserter(v2), 6, 2);
generate_n(back_inserter(v2), 10, [n = 0]()mutable {
    return n++;
})
```

## changing values with iterators

```cpp
begin(v);
front_inserter(v);
```

## reverse iterators

```cpp
rend(), begin(), rbegin(), end();
```

## iterator arithmetic

```cpp
auto;
++, --;
+=, -=;
+, -;
```

## iterators to const elements

```cpp
cbegin() returns const_iterator;
end() and cend(), reverse too;
express intent, beyond const correctness;
array<const int, 5> ca = {3, 1, 1, 1, 1};
auto it = begin(ca);
it++;
// *it = 7;
// vector<const int> vc;
it = find(begin(ca), end(ca), 1);
it++;
// *it = 7;
// it = cbegin(ca);
auto cit = cbegin(v2);
cit++;
// *cit = 7;
```

## summary

>inserters: save preallocating
>
>reverse
>
>const
>
>iterator arithmetic is safe, sometimes convenient
>
>means less algorithms

## 56 introduction

## remember partial_sort_copy?

topN entries

## swapping

```cpp
swap();
iter_swap();
swap_ranges();
```

## rotate

```cpp
1 2 3 4 5 6 -> 2 3 4 5 6 1;
1 2 3 4 5 6 -> 1 (2 3 4) 5 6 -> 1 4 2 3 5 6;
```

## partition

```cpp
auto selected = stable_partition(begin(numbers), end(numbers), [](int i) {
    return i % 2 == 0;
});
auto four = find(begin(numbers), end(numbers), 4);
rotate(begin(numbers), selected, four);
```

## summary

>what they do, not what they are for
>
>partial_sort_copy as top_n
>
>rotate as move_within_collection
>
>stable_partition as gather

## 64 remembering

```c++
parameters are consistent;
integer parameters are rare, well named;
prefixes and suffixes are consistent;
good documentation exists;
```

## iterator parameters

```cpp
two iterators;
iterator and a number;
three iterators;
four iterators;
rotate(first, newfirst, last);
rotate_copy(first, newfirst, last, destfirst);
partial_sort(first, middle, last);
nth_element(first, nth, last);
inplace_merge(first, middle, last);
```

## integer parameters

```cpp
size only for functions with _n;
value for <int>;
starting value for <int>;
```

## predicate last

```cpp
overloads with and without predicate have same leading parameters;

overloads replace "value" with "predicate" parameter;

replace_if and replace_copy_if have 
```

## modifiers in names

```cpp
ends with _if;
end with _n;
starts with is_;
starts with stable_;
```

## memorize

```cpp
#include <algorithm>
```

