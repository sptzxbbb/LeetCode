//搜索，暴力
//这题卡了我几天，检查到最后，居然是我的minID维护错误！我艹！这种错误居然卡了我几天！！！我就是一个超级无敌大水人！
//不过卡了这几天也好，程序也经过不断优化
//做法是预处理出以每个结点为根的子树有多少个结点cnt，以每个结点为根的子树最小编号minID
//接着枚举所有边，暴力找出每个可行方案
//在搜寻每一个可行方案，都以编号最小的结点作为根，这一个优化方案，可以省去搜索比较上下两部分的最小编号值
//这题有几个重要结论是需要证明的
//1、在树中仅存在一条边能将一棵树均分成数目相等的两棵树
//2、在树中不存在两条边能将一棵树划分成X个(X<N/2)结点且包含根结点
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 30005;
int N,K;
int head[MAX],next[MAX*2],V[MAX*2],edge;
int prt[MAX],cnt[MAX],minID[MAX],ans[MAX];
bool del[MAX],vis[MAX];

// edge: 边的数目
// V[edge]: edge边箭头指向的节点
// next[edge]: 发出edge边
void addEdge(int u,int v) {
	V[edge] = v;
	next[edge] = head[u];
	head[u] = edge++;
}

void init(int x,int fa)//预处理以x为根的情况
{
	cnt[x] = 1;
	prt[x] = fa;
	minID[x] = x;
	for(int e = head[x];e != -1;e = next[e])
	{
		int y = V[e];
		if(fa == y || del[y])	continue;
		init(y,x);
		cnt[x] += cnt[y];
		minID[x] = min(minID[x],minID[y]);//之前这里写成min(x,minID[y])，WA了一天
	}
}
void dfs(int x,int fa,int flag) {
	del[x] = 1;
	for(int e = head[x];e != -1;e = next[e]) {
		int y = V[e];
		if(fa == y || del[y] || y == flag)	continue;
		dfs(y,x,flag);
	}
}
void solve() {
	int flag,_max,_min;
	for(int i = 1;i < K;++i) {
		int root = 1;
		while(del[root])	root++;//每次都取编号值最小的结点为根
		init(root,0);
		_max = 0;
		_min = MAX;
		for(int i = 1;i <= N;++i) {
			if(i == root ||del[i])	continue;
			int t1 = cnt[root] - cnt[i];//t1是包含根的部分
			int t2 = cnt[i];//t2是以i为根的子树部分
			if(t1 == t2)//用结论一，可以立即得到答案，只会有一条边满足这种情况
			{
				_max = t1;
				flag = i;
				_min = minID[root];
				break;
			}
			if(t1 > _max && t1*2 <= cnt[root]) {
				flag = i;
				_max = t1;
				_min = minID[root];
			}
			if(t2 >= _max && t2*2 <= cnt[root]) {
				if(t2 == _max && minID[i] < _min) {
					_max = t2;
					flag = i;
					_min = minID[i];
				}
				else if(t2 > _max) {
					_max = t2;
					flag = i;
					_min = minID[i];
				}
			}
		}
		if(cnt[flag] >= cnt[root] - cnt[flag]) {
			ans[i] = cnt[root] - cnt[flag];
			dfs(root,0,flag);
		} else {
			ans[i] = cnt[flag];
			dfs(flag,prt[flag],prt[flag]);
		}
	}
	ans[K] = N;
	for(int i = 1;i < K;++i) {
		printf("%d ",ans[i]);
		ans[K] -= ans[i];
	}
	printf("%d/n",ans[K]);
}
int main() {
    //	freopen("in.txt","r",stdin);
	int u,v;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&N,&K);
	for(int i = 1;i < N;++i) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	solve();
}