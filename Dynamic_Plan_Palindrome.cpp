#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001],prel[1001][1001],prer[1001][1001];
bool mark[1001][1001];
string str,ans;
void palindrome(string str){
	int n=str.size();
	for(int i=0;i<n;i++) dp[i][i]=1,prel[i][i]=prer[i][i]=-1;
	for(int l=1;l<n;l++)
		for(int i=0;i+l<n;i++)
			if(str[i]==str[i+l])
				if(l==1){
					dp[i][i+l]=2;
					prel[i][i+l]=-1;
					prer[i][i+l]=-1;
					mark[i][i+l]=1;
				}
				else{
					dp[i][i+l]=dp[i+1][i+l-1]+2;
					prel[i][i+l]=i+1;
					prer[i][i+l]=i+l-1;
					mark[i][i+l]=1;
				}
			else if(dp[i+1][i+l]>dp[i][i+l-1]){
				dp[i][i+l]=dp[i+1][i+l];
				prel[i][i+l]=i+1;
				prer[i][i+l]=i+l;
				mark[i][i+l]=0;
			}
			else{
				dp[i][i+l]=dp[i][i+l-1];
				prel[i][i+l]=i;
				prer[i][i+l]=i+l-1;
				mark[i][i+l]=0;	
			}
}
void output(int l,int r){
	if(prel[l][r]==-1){
		if(l==r) ans+=str[l];
		else{
			ans+=str[l];
			ans=str[l]+ans;
		}
		return;
	} 
	output(prel[l][r],prer[l][r]);
	if(mark[l][r]){
		ans+=str[l];
		ans=str[l]+ans;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>str;
	palindrome(str);
	output(0,str.size()-1);
	cout<<ans;
	return 0;
}
