#include<bits/stdc++.h>
using namespace std;
int next[10000];
void fail(string s){
	int m=s.length(),i=0,j=-1;
	next[0]=-1;
	while(i<m-1){
		if(j==-1||s[i]==s[j]){
			i++,j++;
			if(s[i]!=s[j]) next[i]=j;
			else next[i]=next[j];
		}
		else j=next[j];
	}
}
int KMP(string& str,string& s){
	int n=str.length(),m=s.length(),i=0,j=0;
	while(i<n&&j<m){
		if(j==-1||str[i]==s[j]) i++,j++;
		else j=next[j];
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
