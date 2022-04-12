#include<bits/stdc++.h>
#define MAX 0xfffffff
using namespace std;
struct edge{
	int ver,cost;
};
edge e[10];
vector<edge> v[10];
int lowcost[10],vex[10],mark[10]={0},cnt=0;
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		vex[i]=-1;
		lowcost[i]=MAX;
	}
	for(int i=0;i<n;i++){
		int x,y;
		edge e;
		cin>>x>>y>>e.cost;
		e.ver=y;
		v[x].push_back(e);
		e.ver=x;
		v[y].push_back(e);
	}
	mark[1]=1;
	for(int i=0;i<v[1].size();i++){
		lowcost[v[1][i].ver]=v[1][i].cost;
		vex[v[1][i].ver]=1;
	}
	for(int i=1;i<m;i++){
		int mine=MAX,u;
		for(int j=1;j<=m;j++)
			if(lowcost[j]<mine&&!mark[j]){
				mine=lowcost[j];
				u=j;
			}
		mark[u]=1;
		printf("mine:%d vex: %d u:%d\n",mine,vex[u],u);
		for(int j=0;j<v[u].size();j++)
			if(v[u][j].cost<lowcost[v[u][j].ver]&&!mark[j]){
				lowcost[v[u][j].ver]=v[u][j].cost;
				vex[v[u][j].ver]=u;
			}
	}
	for(int i=1;i<=m;i++){
		if(vex[i]!=-1)
			printf("l:%d r:%d c:%d\n",vex[i],i,lowcost[i]);
	}
}
