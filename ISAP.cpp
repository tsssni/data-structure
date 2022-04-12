#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v,val,next;
} node[1000005];
int ans=0,top=2,n,m;
int s,t,head[1000005],cur[1000005];
int dep[1000005],gap[1000005];
bool mark,vis[1000005];
queue<int> q;
void insert(int u,int v,int w){
	node[top].v=v;
	node[top].val=w;
	node[top].next=head[u];
	head[u]=top++;
}
void bfs(){
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) cur[i]=head[i],dep[i]=-1,gap[i]=0;
	dep[t]=0;
	gap[0]=1;
	q.push(t);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=node[i].next){
			int v=node[i].v;
			if(dep[v]!=-1) continue;
			q.push(v);
			dep[v]=dep[u]+1;
			gap[dep[v]]++;
		}
	}
}
int dfs(int u,int flow){
	if(u==t){
		ans+=flow;
		return flow;
	}
	int used=0;
	for(int i=cur[u];i;i=node[i].next){
		int d=node[i].v;
		cur[u]=i;
		if(node[i].val&&dep[u]==dep[d]+1){
			int minc=dfs(d,flow-used);
			node[i].val-=minc;
			node[i^1].val+=minc;
			used+=minc;
		}
		if(used==flow) return used;
	}
	gap[dep[u]]--;
	if(!gap[dep[u]]) dep[s]=n+1;
	dep[u]++;
	gap[dep[u]]++;
	return used;
}
void ISAP(){
	bfs();
	while(dep[s]<=n) dfs(s,1<<30);
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
	ISAP();
	cout<<ans;
	return 0;
}
