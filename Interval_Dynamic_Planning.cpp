#include<bits/stdc++.h>
using namespace std;
int a[205],pre[205];
int f1[205][205],f2[205][205];
int main(){
	std::ios::sync_with_stdio(false);
	int n,ans1=0xfffffff,ans2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=n+n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int p=1;p<n;p++)
		for(int i=1,j=p+1;i<n+n&&j<n+n;i++,j++){
			f1[i][j]=0xfffffff;
			for(int k=i;k<j;k++){
				f1[i][j]=min(f1[i][j],pre[j]-pre[i-1]+f1[i][k]+f1[k+1][j]);
				f2[i][j]=max(f2[i][j],pre[j]-pre[i-1]+f2[i][k]+f2[k+1][j]);
			}
		}
	for(int i=1;i<=n;i++){
		ans1=min(ans1,f1[i][i+n-1]);
		ans2=max(ans2,f2[i][i+n-1]);
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}
