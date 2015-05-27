// source code of submission 854276, Zhongshan University Online Judge System
#include <stdio.h>
 
//man[i][j],i号男第j喜欢的女士的编号。now[i]，记录最小的j，使得i号男未被man[i][j]号女拒绝。
int man[1001][1001],now[1001]={0};
//wom[i][j],i号女给j号男的评分，越喜欢分越高。Wmatch[i],i号女当前最佳匹配，0值代表未匹配过。
int wom[1001][1001],Wmatch[1001]={0},i,j,n,t;
 
//ManToNext(num)即让num号男向下一位未被拒绝的女士求婚！
void ManToNext(int num){
  int w=man[num][++now[num]];    //下一位未被拒绝的女士编号
  if(Wmatch[w]==0)               //若该女未匹配过，则直接匹配
    Wmatch[w]=num;
  //否则与以匹配男士PK，输了的男士继续向下一位未被拒绝的女士求婚（递归）。
  else if(wom[w][Wmatch[w]]>wom[w][num])
    ManToNext(num);
  else{
    t=Wmatch[w];
    Wmatch[w]=num;
    ManToNext(t);
  }
}

int main()
{  
  scanf("%d",&n);
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		     scanf("%d",&man[i][j]);            
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
      scanf("%d",&t);
      wom[i][t]=n-j;     
    }
  for(i=1;i<=n;i++)ManToNext(i);
  for(i=1;i<=n;i++)printf("%d\n",man[i][now[i]]);
  return 0;
}
