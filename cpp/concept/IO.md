## OJ输入

```cpp
1，输入一个数据
int n;while(cin>>n)
2，输入一个定长的一维数组
vector<int> a(3)for(int i=0; i<3; i++)
cin>>a[i];
3，输入一个不定长的一维数组
int n;cin>>n;vector<int> a(n);for(int i=0;i<n;i++)
cin>>a[i];
4，输入一个定长的二维数组
vector<vector<int> > a(2）for(int i=0; i<2; i++)
for(int j=0; j<3; j++){
int tmp;
cin >> tmp;
a[i].push_back(tmp);
}
5，输入一个不定长的二维数组
int n;int m;cin >> n >> m;vector<vector<int> > a(n);for(int i=0; i<n; i++)
for(int j=0; j<m; j++){
int tmp;
cin >> tmp;
a[i].push_back(tmp);
}
int N;
cin>>N;
vector <vector<int> > Matrix1(N);
vector <vector<int> > Matrix2(N);
vector <vector<int> > Matrix(N);
for(int i=0; i<N;i++){
Matrix1[i].resize(N);
Matrix2[i].resize(N);
Matrix[i].resize(N);
}
for(int i=0;i<N;i++){
for(int j=0;j<N;j++){
cin>>Matrix1[i][j];
}
}
6，输入一个字符串
string str;cin >> str;
7，输入一行字符
string str;
getline(cin, str);
8，二维数组
初始化二维vector，为r*c的vector，所有值为0.
1.直接用初始化方法


vector<vector<int> > newOne(r, vector<int>(c, 0));
1
2.用resize()来控制大小


vector<vector<int> > res;
res.resize(r);//r行
for (int k = 0; k < r; ++k){
res[k].resize(c);//每行为c列
}

```

