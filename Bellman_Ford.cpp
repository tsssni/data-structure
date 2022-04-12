#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,cost;
};
vector<edge> g[1000005];
int dist[1000005];
bool bellman_ford(int n){
	for(int i=0;i<=n;i++)
		dist[i]=0xfffffff;
	dist[0]=0;
	for(int t=1;t<=n;t++){
		bool relax=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<g[i].size();j++){
				int next=g[i][j].to,cost=g[i][j].cost;
				if(dist[i]+cost<dist[next]){
					dist[next]=dist[i]+cost;
					relax=0;
				}
			} 
		if(relax) break;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<g[i].size();j++){
			int next=g[i][j].to,cost=g[i][j].cost;
			if(dist[i]+cost<dist[next])
				return 0;
		} 
	return 1;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		g[0].push_back(edge{i,0});
	for(int i=0;i<m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		g[x].push_back(edge{y,c});
	}
	if(!bellman_ford(n)) cout<<-1;
	else for(int i=1;i<=n;i++)
		cout<<dist[i]<<' ';
	return 0;
}
