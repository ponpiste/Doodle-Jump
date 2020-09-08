#include <stdio.h> 
#include <algorithm>
using namespace std;

int n,m,a[100005],b[100005],c[100005],dp[100005];

int cmp(int x,int y){
	return a[x]<a[y];
}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
		c[i]=i;
	}

	sort(c+1,c+1+n,cmp);
	sort(a+1,a+1+n);

	dp[n]=b[c[n]];
	for(int i=n-1;i>=1;i--){
		
		int k=(int)(lower_bound(a+i,a+1+n,a[i]+b[c[i]])-a);
		dp[i]=max(dp[i+1],dp[k]+b[c[i]]);
	}

	printf("%d\n",m-dp[1]);

	return 0;
}