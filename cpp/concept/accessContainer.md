## vector

```cpp
for (int i = 0; i < vec.size(); i++){
    for (int j = 0; j < vec[i].size(); j++)
    {
        cout << vec[i][j];
    }}

std::vector<std::vector<std::string>> v;//...
for ( const auto &row : v ){
   for ( const auto &s : row ) std::cout << s << ' ';
   std::cout << std::endl;}

```

