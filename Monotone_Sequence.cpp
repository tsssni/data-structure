#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	std::ios::sync_with_stdio(false);
	int n=1,cnt=0,tail=0;
	while((scanf("%d",&a[n++]))!=EOF);
	n-=2;
	for(int i=1;i<=n;i++){
		int p=upper_bound(b+1,b+tail+2,a[i],greater<int>())-b;
		b[p]=a[i];
		tail=max(tail,p);
	}
	cout<<tail<<endl;
	tail=0;
	for(int i=1;i<=n;i++)
		b[i]=50005;
	for(int i=1;i<=n;i++){
		int p=lower_bound(b+1,b+tail+2,a[i])-b;
		b[p]=a[i];
		tail=max(tail,p);
	}
	cout<<tail;
	return 0;
}
