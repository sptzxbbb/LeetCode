#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#include <queue>
#define MOD 100007
using namespace std;
int dp[1005][1005];
char str[1005];
int main()
{
    int T,cnt=1;
    cin>>T;
    getchar();
    while(T--)
		{
			gets(str);
			int n=strlen(str);
			int i,j;
			for(i=0;i<n;i++)
				dp[i][i]=1;
			for(i=1;i<n;i++)
				{
					for(j=i-1;j>=0;j--)
						{
							dp[j][i]=(dp[j+1][i]+dp[j][i-1]-dp[j+1][i-1]+MOD)%MOD;
							if(str[i]==str[j])
								dp[j][i]=(dp[j][i]+dp[j+1][i-1]+1+MOD)%MOD;
						}
				}
			printf("Case #%d: %d\n",cnt++,dp[0][n-1]);
		}
    return 0;
}
