#include<bits/stdc++.h>
using namespace std;
int g[1005][1005],pre[1005][1005];
void Floyd(int n){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(g[i][k]+g[k][j]<g[i][j]){
					pre[i][j]=k;
					g[i][j]=g[i][k]+g[k][j];
				}
			}
}
void print(int i,int j){
	if(pre[i][j]==0xfffffff){
		cout<<j<<' ';
		return;
	}
	print(pre[i][j],j);
	print(i,pre[i][j]);
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			pre[i][j]=g[i][j]=0xfffffff;
	for(int i=0;i<m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		g[x][y]=c;
	}
	Floyd(n);
	print(1,n);
	cout<<1;
	return 0;
}
