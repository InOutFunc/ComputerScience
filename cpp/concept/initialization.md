## struct

struct address {

int street_no;

char *street_name;

char *city;

char *prov;

char *postal_code;

};

 

address temp_addres = {

0, // street_no

nullptr, // street_name

"Hamilton", // city

"Ontario", // prov

nullptr, // postal_code

};

 

[Proper way to initialize C++ structs](https://stackoverflow.com/questions/5914422/proper-way-to-initialize-c-structs)

## vector

C++11

std::vector<int> v = {1, 2, 3, 4};

One method would be to use the array to initialize the vector

static const int arr[] = {16,2,77,29};

vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

## 初始化结构体成员变量

StrToPara.componentInfo的初始化

[Correct way of initializing a struct in a class constructor](https://stackoverflow.com/questions/17080975/correct-way-of-initializing-a-struct-in-a-class-constructor)