#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 30001
#define min(a,b) ((a) <(b)?(a):(b))
using namespace std;
vector <int>tree[maxn];
int pnt[maxn],cnt[maxn],mm[maxn];
bool cut[maxn];
int n,k,root,tot;
int opt,sel,kid;
void build(int node,int parent)
{
    pnt[node]=parent; mm[node]=node; cnt[node]=1;
    for(int i=0;i <tree[node].size();i++)
    {
        int p=tree[node][i];
        if(!cut[p]&&p!=parent)
        {
            build(p,node);
            mm[node]=min(mm[node],mm[p]);
            cnt[node]+=cnt[p];
        }
    }
}
void update(int node)
{
    mm[node]=node;
    for(int i=0;i <tree[node].size();i++)
    {
        int p=tree[node][i];
        if(!cut[p])
        {
            update(p);
            mm[node]=min(mm[node],mm[p]);
        }
    }
}
void solve(int node)
{
    int tcnt=cnt[node],tkid=0,sum=tcnt < <1;
    if(sum>tot || sum==tot&&mm[root] <mm[node]) tcnt=tot-tcnt,tkid=1;
    if(opt <tcnt) opt=tcnt,kid=tkid,sel=node;
    else if(opt==tcnt)
    {
        if(kid!=tkid) sel= kid?sel:node,kid=1;
        else if(kid==0&&mm[node] <mm[sel] || kid&&node>sel) sel=node;
    }
    for(int i=0,p;i <tree[node].size();i++)
    {
        p=tree[node][i];
        if(!cut[p]) solve(p);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    int i,p1,p2;
    for(i=1;i <n;i++)
    {
        scanf("%d%d",&p1,&p2);
        tree[p1].push_back(p2);
        tree[p2].push_back(p1);
    }
    root=1,tot=n;
    build(root,-1);
    for(i=2;i <=n;i++)
        tree[i].erase(find(tree[i].begin(),tree[i].end(),pnt[i]));

    while(--k)
    {
        opt=0;
        solve(root);
        printf("%d ",opt);
        tot-=opt;
        if(kid==1) root=sel,pnt[root]=-1;
        else
        {
            cut[sel]=true;
            for(int delta=cnt[sel];pnt[sel]!=-1;cnt[pnt[sel]]-=delta,sel=pnt[sel]);
            update(root);
        }
    }
    printf("%d\n",tot);
    return 0;
}