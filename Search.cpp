#include<bits/stdc++.h>
using namespace std;
int a[10005];
int binary_search(int x,int s,int e){
	if(s>e) return 0;
	int mid=(s+e)>>1;
	if(a[mid]==x) return mid;
	else if(a[mid]>x) return binary_search(x,s,mid-1);
	else return binary_search(x,mid+1,e);
}
int half_search(int x,int s,int e){
	int n=e-s+1,len,i,j=1;
	len=log(n)/log(2);
	int delta[len+3]={n+1};
	for(int i=1;i<=len+2;i++)
		delta[i]=(n+pow(2,i-1))/pow(2,i);
	i=delta[1];
	while(delta[j]!=0){
		if(x==a[i]) return i;
		else if(x>a[i])
			i+=delta[++j];
		else i-=delta[++j];
	}
	return 0;
}
int fibonacci_search(int x,int n){
	int m,t,i,y,p,q,pi,qi,fib[30]={0,1};
	bool flag=0;
	for(int i=2;i<30;i++)
		fib[i]=fib[i-1]+fib[i-2];
	for(int i=1;i<30;i++)
		if(fib[i]>=n&&fib[i-1]<n){
			y=i;
			break;
		}
	i=fib[y-1];
	m=fib[y]-1-n;
	p=fib[y-2];pi=y-2;
	q=fib[y-3];qi=y-3;
	while(q==0||p==1){
		if(x==a[i])
			return i;
		else if(x<a[i]){
			if(!flag){
				i-=m;
				flag=1;
			}
			i+=fib[qi];
			p=fib[qi-1];pi=qi-1;
			q=fib[qi-2];qi=qi-2;
		}
		else{
			i=fib[pi];
			p=fib[--pi];
			q=fib[--qi];
		}
	}
	return 0;
}
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	scanf("%d",&x);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("%d",half_search(x,1,n));
}
