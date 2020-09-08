#include <stdio.h> 
#include <algorithm>
using namespace std;

int n,m,a[100005],b[100005],dp[100005],idx[100005];

int cmp(int x,int y){
	return a[x]<a[y];
}

int main(){
	scanf("%d %d",&n,&m);

	if(n==0){
		printf("%d\n",m);
		return 0;
	}

	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
		idx[i]=i;
	}

	sort(idx+1,idx+1+n,cmp);
	sort(a+1,a+1+n);

	dp[n]=m-a[n]-b[idx[n]];
	for(int i=n-1;i>=1;i--){

		dp[i]=dp[i+1]+a[i+1]-a[i];
		int lb=(int)(lower_bound(a+i,a+1+n,a[i]+b[idx[i]])-a);
		if(lb<=n){
			dp[i]=min(dp[i],dp[lb]+a[lb]-a[i]-b[idx[i]]);
		}
		else{
			dp[i]=min(dp[i],m-a[i]-b[idx[i]]);
		}
	}

	printf("%d\n",dp[1]+a[1]);

	return 0;
}