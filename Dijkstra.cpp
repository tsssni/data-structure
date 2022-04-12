#include<bits/stdc++.h>
using namespace std;
#define max 10000
int dis[1005][1005],vis[1005][1005]={0};
void dijkstra(int x,int n){
	bool flag=1;
	while(flag){
		int min=x+1;
		flag=0;
		for(int i=x+1;i<n;i++){
			if(!vis[x][i]&&dis[x][i]<dis[x][min]){
				min=i;
			}
		}
		vis[x][min]=vis[min][x]=1;
		for(int i=x+1;i<n;i++){
			if(i==min) continue;
			if(dis[x][min]+dis[min][i]<dis[x][i]){
				flag=1;
				dis[x][i]=dis[i][x]=dis[x][min]+dis[min][i];
			}
		}
	}
}
int main(){
	int n;
	bool flag=1;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			cin>>dis[i][j];
			dis[j][i]=dis[i][j];
		}
	for(int i=0;i<n;i++){
		dijkstra(i,n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}

