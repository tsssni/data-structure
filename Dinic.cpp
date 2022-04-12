#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v,val,next;
} node[1000005];
int ans=0,top=2,n,m;
int s,t,head[1000005],dep[1000005];
bool mark,vis[1000005];
queue<int> q;
void insert(int u,int v,int w){
	node[top].v=v;
	node[top].val=w;
	node[top].next=head[u];
	head[u]=top++;
}
bool bfs(){
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) cur[i]=head[i],dep[i]=1<<30;
	memset(vis,0,sizeof(vis));
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=cur[u];i;i=node[i].next){
			cur[u]=i;
			int d=node[i].v;
			if(dep[u]+1<dep[d]&&node[i].val){
				dep[d]=dep[u]+1;
				if(!vis[d]){
					vis[d]=1;
					q.push(d);
				}
			}
		}
	}
	return 0;
}
int dfs(int u,int flow){
	if(u==t){
		mark=1;
		ans+=flow;
	}
	int low=0,used=0;
	while(low=bfs()){
		for(int i=head[u];i;i=node[i].next){
			int d=node[i].v;
			if(node[i].val&&dep[d]==dep[u]+1
			&&(low=dfs(d,min(flow-used,node[i].val)))){
				used+=low;
				node[i].val-=low;
				node[i^1].val+=low;
				if(used==flow) break;
			}
		}
	}
	return used;
}
void dinic(){
	while(bfs()){
		mark=1;
		while(vis){
			mark=0;
			dfs(s,1<<30);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		insert(u,v,w);
		insert(v,u,0);
	}
	dinic();
	cout<<ans;
	return 0;
}
