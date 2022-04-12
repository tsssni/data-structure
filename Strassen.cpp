#include<iostream>
#include<vector>
using namespace std;
//矩阵加法 
vector<vector<int> > Plus(int n,vector<vector<int> > & a,vector<vector<int> > & b){
	vector<vector<int> > ret(n+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ret[i].push_back(0);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ret[i][j]=a[i][j]+b[i][j];
	return ret;
}
//矩阵减法 
vector<vector<int> > Minus(int n,vector<vector<int> > & a,vector<vector<int> > & b){
	vector<vector<int> > ret(n+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ret[i].push_back(0);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ret[i][j]=a[i][j]-b[i][j];
	return ret;
}
//矩阵乘法 
vector<vector<int> > Mul(int n,vector<vector<int> > & a,vector<vector<int> > & b){
	if(n==1){
		vector<vector<int> > v(2);
		v[0].push_back(0),v[0].push_back(0),v[1].push_back(0);
		v[1].push_back(a[1][1]);
		v[1][1]*=b[1][1];
		return v;
	}
	vector<vector<int> > s[11],p[8];
	vector<vector<int> > A[3][3],B[3][3],C11,C12,C21,C22;
	vector<vector<int> > T(n/2+1);
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=1;i<=n/2;i++){
		T[i].push_back(0);
		for(int j=1;j<=n/2;j++)
			T[i].push_back(a[i][j]);
	}
	A[1][1]=T;
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=1;i<=n/2;i++){
		T[i].push_back(0);
		for(int j=1;j<=n/2;j++)
			T[i].push_back(b[i][j]);
	}
	B[1][1]=T;
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=1;i<=n/2;i++){
		T[i].push_back(0);
		for(int j=n/2+1;j<=n;j++)
			T[i].push_back(a[i][j]);
	}
	A[1][2]=T;
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=1;i<=n/2;i++){
		T[i].push_back(0);
		for(int j=n/2+1;j<=n;j++)
			T[i].push_back(b[i][j]);
	}
	B[1][2]=T;
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=n/2+1;i<=n;i++){
		T[i-n/2].push_back(0);
		for(int j=1;j<=n/2;j++)
			T[i-n/2].push_back(a[i][j]);
	}
	A[2][1]=T;
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=n/2+1;i<=n;i++){
		T[i-n/2].push_back(0);
		for(int j=1;j<=n/2;j++)
			T[i-n/2].push_back(b[i][j]);
	}
	B[2][1]=T;
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=n/2+1;i<=n;i++){
		T[i-n/2].push_back(0);
		for(int j=n/2+1;j<=n;j++)
			T[i-n/2].push_back(a[i][j]);
	}
	A[2][2]=T;
	for(int i=0;i<=n/2;i++) T[i].clear();
	for(int i=0;i<=n/2;i++) T[0].push_back(0);
	for(int i=n/2+1;i<=n;i++){
		T[i-n/2].push_back(0);
		for(int j=n/2+1;j<=n;j++)
			T[i-n/2].push_back(b[i][j]);
	}
	B[2][2]=T;
	s[1]=Minus(n/2,B[1][2],B[2][2]);
	s[2]=Plus(n/2,A[1][1],A[1][2]);
	s[3]=Plus(n/2,A[2][1],A[2][2]);
	s[4]=Minus(n/2,B[2][1],B[1][1]);
	s[5]=Plus(n/2,A[1][1],A[2][2]);
	s[6]=Plus(n/2,B[1][1],B[2][2]);
	s[7]=Minus(n/2,A[1][2],A[2][2]);
	s[8]=Plus(n/2,B[2][1],B[2][2]);
	s[9]=Minus(n/2,A[1][1],A[2][1]);
	s[10]=Plus(n/2,B[1][1],B[1][2]);
	p[1]=Mul(n/2,A[1][1],s[1]);
	p[2]=Mul(n/2,s[2],B[2][2]);
	p[3]=Mul(n/2,s[3],B[1][1]);
	p[4]=Mul(n/2,A[2][2],s[4]);
	p[5]=Mul(n/2,s[5],s[6]);
	p[6]=Mul(n/2,s[7],s[8]);
	p[7]=Mul(n/2,s[9],s[10]);
	vector<vector<int> > v1,v2;
	v1=Minus(n/2,p[6],p[2]);
	v2=Plus(n/2,p[4],v1);
	C11=Plus(n/2,p[5],v2);
	C12=Plus(n/2,p[1],p[2]);
	C21=Plus(n/2,p[3],p[4]);
	v1=Minus(n/2,p[1],p[3]);
	v2=Minus(n/2,v1,p[7]);
	C22=Plus(n/2,p[5],v2);
	vector<vector<int> > ret(n+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ret[i].push_back(0);
	for(int i=1;i<=n/2;i++)
		for(int j=1;j<=n/2;j++)
			ret[i][j]=C11[i][j];
	for(int i=1;i<=n/2;i++)
		for(int j=n/2+1;j<=n;j++)
			ret[i][j]=C12[i][j-n/2];
	for(int i=n/2+1;i<=n;i++)
		for(int j=1;j<=n/2;j++)
			ret[i][j]=C21[i-n/2][j];
	for(int i=n/2+1;i<=n;i++)
		for(int j=n/2+1;j<=n;j++)
			ret[i][j]=C22[i-n/2][j-n/2];
	return ret;
}
int main(){
	std::ios::sync_with_stdio(false);
	int N,n=2;
	vector<vector<int> > a,b,c; 
	int chart[15]={1,2,4,8,16,32,64,128,256,512,1024};
	cin>>N;
	while(n<N) n<<=1;//将矩阵大小扩大为2的n次方 
	a.resize(n+1);
	b.resize(n+1);
	c.resize(n+1);
	vector<int> v(n+1,0);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			a[i].push_back(0),b[i].push_back(0),c[i].push_back(0);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>a[i][j];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>b[i][j];
	c=Mul(n,a,b);//n代表方阵的大小 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<c[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}