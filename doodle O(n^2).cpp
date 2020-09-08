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

		départs et arrivés différents

a[i] = position du jetpack i
b[i] = carburant du jetpack i

n = nombre de jetpacks (100 000)
m = hauteur du drapeau d'arrivée (1 000 000 000)

*/

#include <stdio.h> 
#include <algorithm>
using namespace std;

int n,m,a[1005],b[1005],dp[1005];

int main(){

	freopen("/Users/Sacha/Desktop/in.txt", "r", stdin);
	
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}

	for(int i=m;i>=0;i--){

		dp[i]=m-i;
		for(int j=1;j<=n;j++){
			if(a[j]>=i){
				dp[i]=min(dp[i],dp[a[j]+b[j]]+a[j]-i);
			}
		}
	}

	printf("%d\n",dp[0]);

	return 0;
}