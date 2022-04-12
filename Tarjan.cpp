#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
stack<int> st;
int t=1,cnt=0;
int dist[1000005]={0},low[1000005]={0};
bool mark[1000005];
void tarjan(int n){
	dist[n]=low[n]=t++;
	st.push(n);
	mark[n]=1;
	for(int i=0;i<v[n].size();i++){
		if(!dist[v[n][i]]){
			tarjan(v[n][i]);
			low[n]=min(low[v[n][i]],low[n]);
		}
		else if(mark[v[n][i]])
			low[n]=min(dist[v[n][i]],low[n]);
	}
	if(low[n]==dist[n]){
		cnt++;
		while(st.top()!=n){
			mark[st.top()]=0;
			low[st.top()]=low[n];
			st.pop();
		}
		mark[n]=0;
		st.pop();
	}
}
int main(){
	int n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!low[i]) tarjan(i);
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(!mark[i]){
			cout<<i<<' ';
			mark[i]=1;
			for(int j=i+1;j<=n;j++)
				if(low[j]==low[i]){
					cout<<j<<' ';
					mark[j]=1;
				}
			cout<<endl;
		}		
}
