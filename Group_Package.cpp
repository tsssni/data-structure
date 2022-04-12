#include<bits/stdc++.h>
using namespace std;
int sol[105][105],f[20005];
int main(){
	std::ios::sync_with_stdio(false);
	int s,n,m;
	cin>>s>>n>>m;
	for(int i=1;i<=s;i++)
		for(int j=1;j<=n;j++){
			cin>>sol[j][i];
			sol[j][i]=sol[j][i]*2+1;
		}
	for(int i=1;i<=n;i++)
		sort(sol[i]+1,sol[i]+s+1);
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
			for(int k=1;k<=s;k++)
				if(j>=sol[i][k]&&f[j]<f[j-sol[i][k]]+i*k)
					f[j]=f[j-sol[i][k]]+i*k;
	cout<<f[m];
	return 0;
}
