#include<bits/stdc++.h>
using namespace std;
int f[10000];
void fail(string s){
	int m=s.length(),i=0,j=-1;
	f[0]=-1;
	while(i<m-1){
		if(s[i+1]==s[j+1]){
			i++,j++;
			f[i]=j;
		}
		else if(j>-1) j=f[j];
		else f[++i]=-1;
	}
}
int KMP(string& str,string& s){
	int n=str.length(),m=s.length(),i=0,j=0;
	while(i<n&&j<m){
		if(j==-1||str[i]==s[j]) i++,j++;
		else if(j>0) j=f[j-1]+1;
		else j=-1;
	}
	return j==m?i-j:-1;
}
int main(){
	string str,s;
	cin>>str>>s;
	if(s.length()>str.length()||(s.length()==str.length()&&s!=str)){
		cout<<-1;
		return 0;
	}
	fail(s);
	cout<<KMP(str,s);
	return 0;
} 
