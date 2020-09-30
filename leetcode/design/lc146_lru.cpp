#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

#include<unordered_map>
class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    int capacity;
    list<pair<int,int>> lrulst;
    unordered_map<int,list<pair<int,int>>::iterator > lruhash;
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        vector<int> result; capacity = k;
        result.reserve(operators.size());
        if(k!=0)
        {
            for(const vector<int>& opt: operators)
            {
                if(opt[0]==1)    set(opt[1],opt[2]);
                else if(opt[0]==2)    result.push_back(get(opt[1]));
            }
        }
        return result;
    }
    
    void set(int key,int val){
        auto iter = lruhash.find(key);
        if(iter == lruhash.end()) 
        {
            if(capacity == lrulst.size())
            {
                lruhash.erase(lrulst.back().first);
                lrulst.pop_back();
            }
        }
        else    lrulst.erase(iter->second);
        lrulst.push_front({key,val});
        lruhash[key] = lrulst.begin();
    }
    
    int get(int key){
        auto iter = lruhash.find(key);
        if(iter == lruhash.end())    return -1;
        int val = iter->second->second;
        auto node = *(iter->second);
        lrulst.erase(iter->second);
        lrulst.push_front(node);
        lruhash[key] = lrulst.begin();
        return val;
    }

};

int main()
{
    vector<vector<int>> op = 
    {{1,1,1},{1,2,2},{1,3,2},{2,1},{1,4,4},{2,1}};
    int k = 3;
    Solution sol;
    vector<int> res = sol.LRU(op, k);

    return 0;
}