#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int key[MAXN],lson[MAXN],rson[MAXN],pa[MAXN];
int cnt[MAXN],size[MAXN],sp=0,root;
int Ans[MAXN],num=0;
void update(int x);
void leftrotate(int x);
void rightrotate(int x);
void splay(int x,int target);
int find(int x);
void insert(int x);
int findmin(int x);
int findmax(int x);
int join(int t1,int t2);
int split(int x,int& t1,int& t2);
void Delete(int x);
int kth(int k);
int rank(int x);
int predecessor(int p);
int successor(int p);
int main(){
	std::ios::sync_with_stdio(false);
	int n,opt,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>opt>>x;
		switch(opt){
			case 1: insert(x);break;
			case 2: Delete(x);break;
			case 3: Ans[num++]=rank(x);break;
			case 4: Ans[num++]=key[kth(x)];break;
			case 5: Ans[num++]=predecessor(x);break;
			case 6: Ans[num++]=successor(x);
		}
	}
	for(int i=0;i<num;i++)
		cout<<Ans[i]<<endl;
	return 0;
}
void update(int x){
	if(x){
		size[x]=cnt[x];
		if(lson[x]) size[x]+=size[lson[x]];
		if(rson[x]) size[x]+=size[rson[x]];
	}
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
	update(x);update(y);
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
	update(x);update(y);
}
void splay(int x,int target=0){
	int px;
	while(pa[x]!=target){
		px=pa[x];
		if(pa[px]==target){
			if(lson[px]==x) rightrotate(x);
			else leftrotate(x);
			break;
		}
		if(lson[px]==x){
			if(lson[pa[px]]==px){
				rightrotate(px);
				rightrotate(x);
			}
			else{
				rightrotate(x);
				leftrotate(x);
			}
		}
		else{
			if(rson[pa[px]]==px){
				leftrotate(px);
				leftrotate(x);
			}
			else{
				leftrotate(x);
				rightrotate(x);
			}
		}
	}
	if(target==0) root=x,pa[x]=0;
}
int find(int x){
	int p=root;
	while(p!=0&&key[p]!=x)
		if(x<key[p]) p=lson[p];
		else p=rson[p];
	if(p!=0) splay(p);
	return p;
}
void insert(int x){
	int pp=0,p=root;
	while(p!=0&&key[p]!=x){
		pp=p;
		if(x<key[p]) p=lson[p];
		else p=rson[p];
	}
	if(p) cnt[p]++;
	else{
		p=++sp;
		if(pp==0) root=p;
		else if(x<key[pp]) lson[pp]=p;
		else rson[pp]=p;
		pa[p]=pp;
		key[p]=x,cnt[p]=1,size[p]=1;
	}
	splay(p);
}
int findmin(int x){
	if(x==0) return 0;
	while(lson[x]!=0) x=lson[x];
	splay(x);
	return x;
}
int findmax(int x){
	if(x==0) return 0;
	while(rson[x]!=0) x=rson[x];
	splay(x);
	return x;
}
int join(int t1,int t2){
	if(t1==0) return t2;
	if(t2==0) return t1;
	int p=findmax(t1);
	rson[p]=t2;pa[t2]=p;update(p);
	return p;
}
int split(int x,int& t1,int& t2){
	int p=find(x);
	t1=lson[p],t2=rson[p];
	lson[p]=0,rson[p]=0;
	pa[t1]=0,pa[t2]=0;
}
void Delete(int x){
	int p=find(x);
	cnt[p]--;
	if(cnt[p]==0){
		pa[lson[p]]=pa[rson[p]]=0;
		root=join(lson[p],rson[p]);
	}
}
int kth(int k){
	int p=root,lsize;
	if(p==0||k>size[p]) return 0;
	while(p){
		lsize=size[lson[p]];
		if(k<=lsize) p=lson[p];
		else if(k<=lsize+cnt[p]){
			splay(p);
			return p;
		}
		else{
			k-=lsize+cnt[p];
			p=rson[p];
		}
	}
}
int rank(int x){
	int p=find(x);
	return size[lson[p]]+1;
}
int predecessor(int x){
	int p,ans;
	insert(x);
	p=find(x);
	if(lson[p]){
		p=lson[p];
		while(rson[p]) p=rson[p];
		ans=key[p];
	}
	else ans=0;
	Delete(x);
	return ans;
}
int successor(int x){
	int p,ans;
	insert(x);
	p=find(x);
	if(rson[p]){
		p=rson[p];
		while(lson[p]) p=lson[p];
		ans=key[p];
	}
	else ans=0;
	Delete(x);
	return ans;
}
