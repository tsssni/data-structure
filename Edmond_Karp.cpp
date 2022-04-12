#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v,val,next;
} node[1000005];
struct Pre{
	int v,edge;
} pre[1000005];
int top=2,s,t,head[1000005];
bool vis[1000005];
queue<int> q;
void insert(int u,int v,int w){
	node[top].v=v;
	node[top].val=w;
	node[top].next=head[u];
	head[u]=top++;
}
bool bfs(){
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=node[i].next){
			int d=node[i].v;
			if(!vis[d]&&node[i].val){
				pre[d].v=u;
				pre[d].edge=i;
				if(d==t) return 1;
				vis[d]=1;
				q.push(d);
			}
		}
	}
	return 0;
}
long long EK(){
	long long ans=0;
	while(bfs()){
		int minc=0xfffffff;
		for(int i=t;i!=s;i=pre[i].v)
			minc=min(minc,node[pre[i].edge].val);
		for(int i=t;i!=s;i=pre[i].v){
			int num=pre[i].edge;
			node[num].val-=minc;
			node[num^1].val+=minc;
		}
		ans+=minc;
	}
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		insert(u,v,w);
		insert(v,u,0);
	}
	cout<<EK();
	return 0;
}
