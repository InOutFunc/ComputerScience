/*
  * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
  * Description: 自动售货系统
  * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
  */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码
    pair<bool, vector<int>> PurchaseResult(const vector<int>& goods, const vector<int>& coins,
        vector<pair<string, vector<int>>> &buyItems)
    {
        return make_pair(false, vector<int>());
    }

};

// 以下为考题输入输出框架，此部分代码不建议改动
inline int ReadInt()
{
    int number;
    std::cin >> number;
    return number;
}

inline std::string ReadWord()
{
    std::string word;
    std::cin >> word;
    return word;
}

template<typename T>
inline std::vector<T> ReadVectorWithDelim(int size)
{
    std::vector<T> objects(size);
    for (int i = 0; i < size - 1; ++i) {
        std::cin >> objects[i];
        char delimiter;
        std::cin >> delimiter;
    }
    std::cin >> objects[size - 1];
    return objects;
}

template<typename T>
inline void WriteVector(const std::vector<T>& objects, char delimeter = ' ')
{
    auto it = objects.begin();
    if (it == objects.end()) {
        return;
    }
    std::cout << *it;
    for (++it; it != objects.end(); ++it) {
        std::cout << delimeter << *it;
    }
    std::cout << std::endl;
}

int main()
{
    auto goods = ReadVectorWithDelim<int>(6);
    auto coins = ReadVectorWithDelim<int>(4);
    int count = ReadInt();
    vector<pair<string, vector<int>>> buyItems(count);
    for (int i = 0; i < count; ++i) {
        buyItems[i].first = ReadWord();
        buyItems[i].second = ReadVectorWithDelim<int>(4);
    }
    Solution solu;
    auto result = solu.PurchaseResult(goods, coins, buyItems);
    cout << (result.first ? "T" : "F") << ' ';
    WriteVector(result.second, '-');

    return 0;
}

