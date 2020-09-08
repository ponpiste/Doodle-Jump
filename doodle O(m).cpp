/*

5 10
1 2
2 3
4 1
6 2
7 3

*/

/*

Programmation dynamique ou Dijkstra

idées: 	échelles pour redescendre
		0 < a[i] < 1e9
		jetpack, trampoline
		doodle jump

*/

#include <stdio.h> 
#include <algorithm>
using namespace std;

int n,m,a[105],b[105],c[105],idx[105],dp[105];

int cmp(int x,int y){
	return a[x]<a[y];
}

int main(){
	
	scanf("%d %d",&n,&m);
	memset(c,-1,sizeof(c));

	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
		c[a[i]]=i;
		idx[i]=i;
	}

	sort(idx+1,idx+1+n,cmp);

	for(int i=0;i<m;i++)dp[i]=1e9;

	for(int i=m;i>=0;i--){

		dp[i]=min(dp[i],1+dp[i+1]);
		if(c[i]!=-1){
			dp[i]=min(dp[i],dp[a[c[i]]+b[c[i]]]);
		}
	}

	printf("%d\n",dp[0]);

	return 0;
}