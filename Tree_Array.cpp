#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,val;
};
node a[500005];
int c[500005],rank[500005],n;
long long tot=0;
bool cmp(node n1,node n2){
	if(n1.val==n2.val) return n1.num<n2.num;
	else return n1.val<n2.val;
}
void insert(int i){
	for(int p=i;p<=n;p+=p&(-p))
		c[p]++;
}
int sum(int i){//求比它先出现的rank小于rank[i]的个数
	int ret=0;
	for(int p=i;p>=1;p-=p&(-p))
 		ret+=c[p];
 	return ret;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		rank[i]=a[i].num;
		insert(rank[i]);
		tot+=i-sum(rank[i]);
	}
	cout<<tot;
	return 0;
}

