#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int key[MAXN],lson[MAXN],rson[MAXN],pa[MAXN];
int cnt[MAXN],size[MAXN],color[MAXN],sp=0,root;
void update(int x);
void leftrotate(int x);
void rightrotate(int x);
int find(int x);
void insert(int x);
int findmin(int x);
int findmax(int x);
void transplant(int x,int y);
void Delete(int x);
void fix(int x);
int main(){
	return 0;
}
void update(int x){
	size[x]=cnt[x];
	size[x]+=size[lson[x]];
	size[x]+=size[rson[x]];
}
void leftrotate(int x){
	int y=pa[x],z=pa[y];
	rson[y]=lson[x];if(rson[y]) pa[rson[y]]=y;
	lson[x]=y;pa[y]=x;
	pa[x]=z;
	if(z){
		if(rson[z]==y) rson[z]=x;
		else lson[z]=x;
	}
	update(x),update(y);
}
void rightrotate(int x){
	int y=pa[x],z=pa[y];
	lson[y]=rson[x];if(lson[y]) pa[lson[y]]=y;
	rson[x]=y;pa[y]=x;
	pa[x]=z;
	if(z){
		if(rson[z]==y) rson[z]=x;
		else lson[z]=x;
	}
	update(x),update(y);
}
int find(int x,int y){
	int p=root;
	while(p!=0&&key[p]!=x){
		size[p]+=y;
		if(x<key[p]) p=lson[p];
		else p=rson[p];
	}
	return p;
}
void insert(int x){
	int pp=0,p=find(x,1);
	if(p) cnt[p]++;
	else{
		p=++sp;
		color[p]=1;size[p]=1;cnt[p]=1;
		pa[p]=pp;
		if(pp==0) root=p;
		else if(x>key[pp]) rson[pp]=p;
		else lson[pp]=p;
		while(p!=root&&pp!=root&&color[pp]==1){
			int pw;
			if(pp==lson[pa[pp]]) pw=rson[pa[pp]];
			else pw=lson[pa[pp]];
			if(color[pw]==1){
				color[pp]=color[pw]=0;
				color[pa[pp]]=1;
				p=pa[pp],pp=pa[p];
				size[pp]++;
			}
			else if(rson[pp]==p){
				leftrotate(p);
				swap(p,pp);
			}
			else{
				color[pp]=0;
				color[pa[pp]]=1;
				rightrotate(pp);
			}
		}
		color[root]=0;
	}
}
int findmin(int x){
	if(x==0) return 0;
	while(lson[x]!=0) x=lson[x];
	return x;
}
int findmax(int x){
	if(x==0) return 0;
	while(rson[x]!=0) x=rson[x];
	return x;
}
void transplant(int x,int y){
	if(lson[pa[x]]==x) lson[pa[x]]=y;
	else rson[pa[x]]=y;
	if(y) pa[y]=pa[x];
}
void Delete(int x){
	int p=find(x,-1),oc=color[p];//original color
	cnt[p]--;
	if(cnt[p]==0){
		int tmp;
		if(!lson[p]) transplant(p,rson[p]),tmp=rson[p];
		else if(!rson[p]) transplant(p,lson[p]),tmp=lson[p];
		else{
			int np=successor(key[p]);
			oc=color[np];tmp=rson[np];
			if(rson[p]!=np){
				transplant(np,rson[np]);
				rson[np]=rson[p];
				pa[rson[np]]=np;
			}
			lson[np]=lson[p];
			pa[lson[np]]=np;
			color[np]=color[p];
		}
		if(oc==0) fix(tmp);
	}
}
void fix(int x){
	while(x!=root&&color[x]==0){
		int p=pa[x],w;
		if(lson[pa[x]]==x) w=rson[pa[x]];
		else w=lson[pa[x]];
		if(color[w]==1){
			color[p]=1;
			color[w]=0;
			leftrotate(w);
		}
		else if(color[lson[w]]==0&&color[rson[w]]==0){
			color[w]=0;
			x=x.p;
		}
		else if(color[lson[w]]==1&&color[rson[w]]==0){
			color[lson[w]]=0;
			color[w]=1;
			rightrotate(lson[w]);
		}
		else if(color[rson[w]]==1){
			color[w]=1;
			color[p]=0;
			leftrotate(w);
		}
	}
}
