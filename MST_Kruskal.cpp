#include<bits/stdc++.h>
#define MAX 0xfffffff
using namespace std;
struct edge{
	int x,y,cost;
};
vector<edge> v,out;
int father[10]={0};
int find(int x){
	if(father[x]<=0)
		return x;
	if(father[father[x]]<0)
		return father[x];
	int x0=x,x1,ret;
	while(father[x0]>0)
		x0=father[x0];
	ret=x0;
	while(father[x]>0){
		x1=father[x];
		father[x]=x0;
		x=x1;
	}
	return ret;
}
void Union(int x,int y){
	int f1=find(x),f2=find(y);
	if(father[f1]<=father[f2]){
		father[f2]=f1;
		father[f1]--;
	}
	else{
		father[f1]=f2;
		father[f2]--;
	}
}
int main(){
	int m,n;
	edge e;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>e.x>>e.y>>e.cost;
		v.push_back(e);
	}
	for(int i=1;i<m;i++){
		edge mine;
		mine.cost=MAX;
		for(int j=0;j<v.size();j++)	
			if(v[j].cost<mine.cost){
				if(!father[v[j].x]||!father[v[j].y])
					mine=v[j];
				else if(find(v[j].x)!=find(v[j].y))
					mine=v[j];
			}
		Union(mine.x,mine.y);
		out.push_back(mine);
	}
	for(int i=0;i<out.size();i++)
		printf("l:%d r:%d cost:%d\n",out[i].x,out[i].y,out[i].cost);
}
