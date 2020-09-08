#include <stdio.h> 
#include <string>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int cmp(int x,int y){
	return a[x]<a[y];
}

int main(){

	srand(time(NULL));
    for(int i=1;i<=1000;i++){

    	string s="/Users/Sacha/Desktop/in/";
    	s+=to_string(i);
    	s+=".in";
    	freopen(s.c_str(), "w", stdout);


    	int n=rand()%10;
    	int m=rand()%10;
    	

    	printf("%d %d\n",n,m);

    	for(int j=0;j<n;j++){
    		int a=rand()%(m+1);
    		int b=rand()%(m-a+1);
    		printf("%d %d\n",a,b);
    	}


    }

    return 0;
}