#include<vector>
#include<stack>
using namespace std;
struct edge{
	int x,y,c;
} e0[100];
vector<int> vy[100],vc[100];
stack<int> s;
int vtopo[100],ve[100]={0},vl[100],e[100],l[100],cnt[100]={0};
bool topo(int n,int m){
	int t;
	s.push(0);
	for(int i=0;i<=n+1;i++){
		if(s.empty()) return 0;
		t=s.top();
		s.pop();
		vtopo[i]=t;
		for(int j=0;j<vy[t].size();j++){
			cnt[vy[t][j]]--;
			if(cnt[vy[t][j]]==0)
				s.push(vy[t][j]);
		}
	}
	return 1;
}
int main(){
	int n,m,x,y,c;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y>>c;
		vy[x].push_back(y);
		vc[x].push_back(c);
		cnt[y]++;
		e0[i]=edge{x,y,c};
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]==0){
			vy[0].push_back(i);
			vc[0].push_back(0);
			cnt[i]++;
		}
	for(int i=1;i<=n;i++)
		if(vy[i].size()==0){
			vy[i].push_back(n+1);
			vc[i].push_back(0);
			cnt[n+1]++;
		}
	if(!topo(n,m)) return 0;
	for(int i=0;i<=n+1;i++)
		vl[i]=0xfffffff;
	for(int i=0;i<=n;i++){
		int p=vtopo[i];
		for(int j=0;j<vy[p].size();j++)
			if(ve[p]+vc[p][j]>ve[vy[p][j]])
				ve[vy[p][j]]=ve[p]+vc[p][j];
	}
	vl[n+1]=ve[n+1];
	for(int i=n;i>0;i--){
		int p=vtopo[i];
		for(int j=0;j<vy[p].size();j++)
			if(vl[vy[p][j]]-vc[p][j]<vl[p])
				vl[p]=vl[vy[p][j]]-vc[p][j];
	}
	for(int i=0;i<m;i++){
		e[i]=ve[e0[i].x];
		l[i]=vl[e0[i].y]-e0[i].c;
	}
	for(int i=0;i<m;i++)
		if(e[i]==l[i])
			cout<<e0[i].x<<' '<<e0[i].y<<endl;
}
