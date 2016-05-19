#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

const int maxn = 30005;
int fir[maxn], adj[2*maxn], next1[2*maxn]; //adj表示一条有向边指向的节点
int nodenum[maxn], minnode[maxn];
int p[maxn]; //父亲节点
int gett, getroot, getmin;
int e = 0;
int lef;
int curminn;
bool used[maxn];
int n, k;

 //把一条边当成两条有向边
void add_edge(int u, int v) {
    next1[e] = fir[u];
    adj[e] = v;
    fir[u] = e++;
}

//每一次王子分财产都重新建树，选择最小的节点为根。这样当某一子树与它的补集的节点数一样的时候一定选择包含根的那部分；若两个子树有公共节点，则两棵子树比为包含关系。所以当两棵子树的节点数一样时，他们要么重合，要么没有相同的节点，这样只要他们的最小节点最小则“字典序”最小。

//第一个dfs先统计每一棵子树的节点数中最大的。
void dfs(int u, int fa) {
    nodenum[u] = 1;
    minnode[u] = u;
    for (int i = fir[u]; i != -1; i = next1[i])
    if (adj[i] != fa && !used[adj[i]]) {
        dfs(adj[i], p[adj[i]] = u);
        nodenum[u] += nodenum[adj[i]];
        minnode[u] = min(minnode[u], minnode[adj[i]]);
        if ((nodenum[adj[i]] <= lef / 2 && nodenum[adj[i]] > gett) || (nodenum[adj[i]] == gett && minnode[adj[i]] < getmin)) {
            gett = nodenum[adj[i]];
            getmin = minnode[adj[i]]; //得到的那部分中最小的节点
            getroot = adj[i];
        }
    }
}
 //第二个dfs统计每一棵子树的补集是否包含更多的节点数目
void dfs2(int u, int fa) {
    int num;
    for (int i = fir[u]; i != -1; i = next1[i])
    if(adj[i] != fa && !used[adj[i]]) {
        dfs2(adj[i], u);
        num = lef - nodenum[adj[i]];
        bool ok = 0;
        if(num <= lef / 2 && num > gett) {
            ok = 1;
        } else if(num == gett && getroot > 0) {
            ok = 1;    //相等，优先选根
        }
        if(ok) {
            gett = num;
            getmin = minnode[adj[i]];
            getroot = -adj[i];  //当取得包含根的那部分时标记为负
        }
    }
}

//选取子树，标记
void update1(int u, int fa) {
    used[u] = 1;
    for (int i = fir[u]; i != -1; i = next1[i])
    if(adj[i] != fa && !used[adj[i]]) {
        update1(adj[i], u);
    }
}
//选取子树的补集，标记
void update2(int u, int fa) {
    used[u] = 1;
    for (int i = fir[u]; i != -1; i = next1[i])
    if(adj[i] != fa && !used[adj[i]] && adj[i] != -getroot) {
        update2(adj[i], u);
    }
}
int main() {
    int u, v;
    memset(fir, -1, sizeof(fir));
    scanf("%d%d", &n, &k);
    e = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    memset(used, 0, sizeof(used));
    curminn = 1;
    lef = n;
    for (int i = 0; i < k - 1; i++) {
        while(used[curminn]) {
            curminn++;
        }
        gett = 0;
        p[curminn] = 0;
        dfs(curminn, 0);
        dfs2(curminn, 0);
        if (getroot > 0) {
            update1(getroot, p[getroot]);
        } else {
            update2(curminn, 0);
        }
        printf("%d ", gett);
        lef -= gett;
    }
    printf("%d\n", lef);
    return 0;
}