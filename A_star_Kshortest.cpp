#include<queue>
using namespace std;
int dist[100005];
int A_star(int shrt){
	int cnt=0;
	bool flag=0;
	priority_queue<edge> pq;
	pq.push(edge{1,dist[1]});
	while(!pq.empty()){
		edge ed=pq.top();
		pq.pop();
		if(ed.e==n){
			cnt=(++cnt)%p;
			if(!flag) flag=1,shrt=ed.c;
			else if(ed.c>shrt+k) return cnt-1;
		}
		for(int i=0;i<g[ed.e].size();i++){
			edge next=g[ed.e][i];
			pq.push(edge{next.e,ed.c-dist[ed.e]+next.c+dist[next.e]});
		}
	}
}
int main(){
	return 0;
}

