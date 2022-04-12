#include<iostream>
using namespace std;
int a[10][10];
bool vis[10];
int n,maxn=0;
void dfs(int layer,int tot){
	if(layer==n){
		maxn=max(maxn,tot);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(layer+1,tot+a[layer][i]);
			vis[i]=0;
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
