#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v,w,val,next;
} node[1000005];
struct Pre{
	int v,edge;
} pre[1000005];
int top=2,n,m,head[1000005];
int s,t,cost,dist[1000005];
bool vis[1000005];
queue<int> q;
void insert(int u,int v,int val,int w){
	node[top].v=v;
	node[top].val=val;
	node[top].w=w;
	node[top].next=head[u];
	head[u]=top++;
}
bool spfa(){
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)
		dist[i]=1<<30;
	q.push(s);
	vis[s]=1;
	dist[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=node[i].next){
			int d=node[i].v;
			if(node[i].val&&dist[u]+node[i].w<dist[d]){
				pre[d].v=u;
				pre[d].edge=i;
				dist[d]=dist[u]+node[i].w;
				if(!vis[d]){
					vis[d]=1;
					q.push(d);
				}
			}
		}
	}
	return dist[t]!=1<<30;
}
void EK(){
	long long ans=0;
	while(spfa()){
		int minc=0xfffffff;
		for(int i=t;i!=s;i=pre[i].v)
			minc=min(minc,node[pre[i].edge].val);
		for(int i=t;i!=s;i=pre[i].v){
			int num=pre[i].edge;
			node[num].val-=minc;
			node[num^1].val+=minc;
		}
		ans+=minc;
		cost+=minc*dist[t];
	}
	cout<<ans<<' '<<cost;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int u,v,val,w;
		cin>>u>>v>>val>>w;
		insert(u,v,val,w);
		insert(v,u,0,-w);
	}
	EK();
	return 0;
}
