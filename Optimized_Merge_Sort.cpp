#include<bits/stdc++.h>
using namespace std;
int link[10000005]={0},p[10000005],a[10000005];
void merge_no_recursion(int n){
	int r=1;
	while(r<=(n<<1)){
		int t=r;
		r<<=1;
		for(int k=1;k<=n;k+=r){
			int i=k,j=k+t;
			for(int l=k;l<=k+r-1;l++)
				if((j>k+r-1||j>n)||(i<=k+t-1&&a[i]<=a[j])) p[l]=a[i++];
				else p[l]=a[j++];
		}
		for(int i=1;i<=n;i++) a[i]=p[i];
	}
	return;
}
int insert_sort(int l,int r){
	for(int i=l+1;i<=r;i++){
		int j=i-1;
		while(j>l-1&&a[p[j]]>a[p[i]]) j--;
		for(int k=i;k>j+1;k--) p[k]=p[k-1];
		p[j+1]=i;
	}
	for(int i=l;i<r;i++) link[p[i]]=p[i+1];
	link[p[r]]=0;
	return p[l];
}
int merge_link(int l,int r){
	if(r-l+1<=5) return insert_sort(l,r);
	int mid=(l+r)>>1,ret=0;
	int head1=merge_link(1,mid),head2=merge_link(mid+1,r);
	int i=head1,j=head2;
	if(a[i]<=a[j]) ret=i;
	else ret=j;
	int pp=0;
	while(i!=0&&j!=0){
		if(i<=mid&&a[i]<=a[j]){
			link[pp]=i,pp=i,i=link[i];
		}
		else if(j<=r&&a[j]<a[i]){
			link[pp]=j,pp=j;j=link[j];
		}
	}
	while(i!=0){
		link[pp]=i;
		pp=i;
		i=link[i];
	}
	while(j!=0){
		link[pp]=j;
		pp=j;
		j=link[j];
	}
	link[pp]=0;
	return ret;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int head=merge_link(1,n);
	for(int i=1;i<=n;i++) cout<<a[head]<<' ',head=link[head];
	return 0;
}

