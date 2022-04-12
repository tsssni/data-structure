#include<bits/stdc++.h>
using namespace std;
int f[10000];
void fail(string s){
	int m=s.length(),j=-1;
	f[0]=-1;
	for(int i=1;i<m;i++){
		while(j>=0&&s[j+1]!=s[i]) j=f[j];
		if(s[j+1]==s[i]) j++;
		f[i]=j;
	}
}
int KMP(string& str,string& s){
	int n=str.length(),m=s.length(),j=-1;
	for(int i=0;i<n;i++){
		while(j>=0&&s[j+1]!=str[i]) j=f[j];
		if(s[j+1]==str[i]) j++;
		if(j==m-1) return i-j;
	}
	return -1;
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
