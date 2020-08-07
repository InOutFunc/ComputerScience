#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getGcd(const int a, const int b)
    {
        if(a==0) return b;
        return getGcd(b%a, a);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int v, res=0,len=points.size();
        if(len<3) return len;
        for(int i=0;i+res<len;i++)
        {
            unordered_map<string,int> m;
            int x1 = points[i][0], y1 = points[i][1], v=0, maxv=0, dups=0;
            int nIdentical=0;

            for(int j=i+1;j<len;j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2-x1, dy = y2-y1;

                if(dx==0 && dy==0)
                {
                    dups++;
                }
                else
                {
                    int gcd = getGcd(dx,dy);
                    dy/=gcd; dx/=gcd;

                    string key = to_string(dx) + '/'+ to_string(dy);
                    if(m.find(key) != m.end()) {m[key]++; v=m[key]; }
                    else { m[key]=1; v=1; }
                }

                if(maxv < v) maxv = v;
                if(res < dups + maxv + 1) res = dups + maxv + 1;
            } 
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    Solution sol;
    int res = sol.maxPoints(points);

    return 0;
}