//Dijkstra邻接表做法
//邻接表使得计算复杂度成为O(E*n),但图为稀疏图时效率比邻接矩阵高，但当图为稠密图时，E与n^2同阶,计算复杂度最坏可到O(n^3)
//Dijkstra优先队列实现(相当于堆优化)
//优先队列的实现的Dijstra可以使得算法在处理稠密图时速度也比使用邻接矩阵要快
//原因在于插入队列的元素的前提是边关系必须满足可松弛条件，对于稠密图而言，可松弛条件是常常不满足的
//因此插入队列的元素便比边数少很多
//下面使用vector容器实现邻接表的，因为直观易懂
//G[u]存放的是与结点u邻接的所有结点
//遍历邻接边：for(int i = 0;i < G[u].size();++i)
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int MAXN = 205;
const int INF = 1000000;
int dis[MAXN];
typedef pair<int,int> pii;

struct edge//建立边的结构体
{
    int u;
    int v;
    int w;
    edge(int uu,int vv,int ww)
    {
        u = uu;
        v = vv;
        w = ww;
    }
};
int dijkstra(int st,int ed,vector<edge> G[])
{
    priority_queue<pii> q;//优先队列是默认小元素先出队
    for(int i = 0;i < n;++i)
        dis[i] = (i == st ? 0 : INF);//初始化dis
    q.push(make_pair(dis[st],st));//将起点插入队列，pair默认是优先处理first元素，故插入优先队列先弹出队列的优先级是依据dis[]大小
    while(!q.empty())
    {
        pii u = q.top();
        q.pop();
        int x = u.second;
        if(u.first != dis[x]) continue;//可避免结点的重复拓展，提高优先队列处理速度。因为Dijkstra算法对每个结点都会进行一次标号。
                                        //这里每一个元素出队都相当于处理一次已标号结点，如果出队的这个元素，他带的dis,和当前的dis不相同，证明这个结点是被处理过的
        for(int  i = 0;i < G[x].size();++i)
        {
            int y = G[x][i].v;
            int w = G[x][i].w;
            if(dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push(make_pair(dis[y],y));
            }
        }
    }
    if(dis[ed] == INF)
        return -1;
    else return dis[ed];
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t,w;
    string u,v;
    cin >> t;
    while(t--)
    {
        int n = 0;//初始化结点数目
        int e;
        cin >> e;
        map<string,int> M;
        vector<edge> G[MAXN];//邻接表
        for(int i = 0;i < e;++i)
        {
            cin >> u >> v >> w;//输入点1，点2， 权值
            if(!M.count(u))
                M.insert(make_pair(u,n++));
            if(!M.count(v))
                M.insert(make_pair(v,n++));//利用map关联容器为字符串型的边进行标号
            edge E1(M[u],M[v],w);//初始化边，必须调换结点才能插入vector邻接表
            edge E2(M[v],M[u],w);
            G[M[u]].push_back(E1);//建立邻接表
            G[M[v]].push_back(E2);
        }
        string st,ed;
        cin >> st >> ed;
        if(st == ed)
            cout << 0 << endl;
        else if(!M.count(st) || !M.count(ed))
            cout << -1 << endl;
        else
            cout << dijkstra(M[st],M[ed],G) << endl;
    }
    return 0;
}