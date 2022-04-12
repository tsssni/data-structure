#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,c;
};
struct cmp{
	bool operator () (node n1,node n2){
		return n1.c>n2.c;
	}
};
vector<node> g[1000005];
bool vis[1000005];
int dist[1000005],h[1000005];
int n,dis[1005][1005];
bool bf(int s){
	for(int i=1;i<=n;i++)
		dist[i]=0xfffffff;
	dist[s]=0;
	for(int k=0;k<n;k++){
		bool relax=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<g[i].size();j++){
				int next=g[i][j].y,cost=g[i][j].c;
				if(dist[next]>dist[i]+cost){
					dist[next]=dist[i]+cost;
					relax=1;
				}
			}
		if(!relax) break;
	}
	for(int i=0;i<=n;i++)
			for(int j=0;j<g[i].size();j++){
				int next=g[i][j].y,cost=g[i][j].c;
				if(dist[next]>dist[i]+cost)
					return 0;
			}
	return 1;	 
}
void dij(int s){
	priority_queue<node,vector<node>,cmp> pq;
	for(int i=1;i<=n;i++)
		dist[i]=0xfffffff;
	vis[s]=1,dist[s]=0;
	for(int i=0;i<g[s].size();i++){
		int next=g[s][i].y,cost=g[s][i].c;
		if(cost!=0xfffffff){
			dist[next]=cost;
			pq.push(g[s][i]);
		}
	}
	for(int i=0;i<n-1;i++){
		int t=pq.top().y;
		pq.pop();
		vis[t]=1;
		for(int j=0;j<g[t].size();j++){
			int next=g[t][j].y,cost=g[t][j].c;
			if(dist[next]>dist[t]+cost){
				dist[next]=dist[t]+cost;
				pq.push(node{t,next,dist[next]});
			}
		}
	}
}
void johnson(){
	for(int i=1;i<=n;i++)
		g[0].push_back(node{0,i,0});
	if(!bf(0)) return;
	for(int i=1;i<=n;i++)
		for(int j=0;j<g[i].size();j++){
			int next=g[i][j].y,cost=g[i][j].c;
			g[i][j].c=cost+h[i]-h[next];
		}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++){
			dis[i][j]=dist[j]+h[j]-h[i];
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		g[x].push_back(node{x,y,c});
	}
	johnson();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<dis[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
