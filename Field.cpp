#include<iostream>
#include<iomanip>
using namespace std;
int a[16][4]={0};
int main(){
	a[0][0]=1;
	a[1][1]=1;
	a[2][2]=1;
	a[3][3]=1;
	a[4][3]=a[4][0]=1;
	a[5][3]=a[5][1]=a[5][0]=1;
	a[6][3]=a[6][2]=a[6][1]=a[6][0]=1;
	a[7][2]=a[7][1]=a[7][0]=1;
	a[8][3]=a[8][2]=a[8][1]=1;
	a[9][2]=a[9][0]=1;
	a[10][3]=a[10][1]=1;
	a[11][3]=a[11][2]=a[11][0]=1;
	a[12][1]=a[12][0]=1;
	a[13][2]=a[13][1]=1;
	a[14][3]=a[14][2]=1;
	cout<<"PLUS"<<endl;
	cout<<setw(11)<<' ';
	for(int i=15;i<=30;i++){
		string s;
		int k=i%16;
		for(int j=3;j>=1;j--){
			if(a[k][j]){
				s+='x';
				if(j>1){
					s+=j+'0';
				}
				s+='+';
			}
		}
		if(a[k][0]) s+='1';
		else{
			s=s.substr(0,s.length()-1);
		}
		if(s.length()==0) s='0';
		cout<<setw(11)<<s;
	}
	cout<<endl;
	for(int i=15;i<=30;i++){
		int k=i%16;
		string s;
		for(int j=3;j>=1;j--){
			if(a[k][j]){
				s+='x';
				if(j>1){
					s+=j+'0';
				}
				s+='+';
			}
		}
		if(a[k][0]) s+='1';
		else{
			s=s.substr(0,s.length()-1);
		}
		if(s.length()==0) s='0';
		cout<<setw(11)<<s;
		for(int j=15;j<=30;j++){
			int l=j%16;
			int form[4];
			for(int m=3;m>=0;m--){
				form[m]=(a[k][m]+a[l][m])%2;
			}
			string s;
			for(int j=3;j>=1;j--){
				if(form[j]){
					s+='x';
					if(j>1){
						s+=j+'0';
					}
					s+='+';
				}
			}
			if(form[0]) s+='1';
			else{
				s=s.substr(0,s.length()-1);
			}
			if(s.length()==0) s='0';
			cout<<setw(11)<<s;
		} 
		cout<<endl;
	}
	
	cout<<"MULTIPLY"<<endl;
	cout<<setw(11)<<' ';
	for(int i=15;i<=30;i++){
		string s;
		int k=i%16;
		for(int j=3;j>=1;j--){
			if(a[k][j]){
				s+='x';
				if(j>1){
					s+=j+'0';
				}
				s+='+';
			}
		}
		if(a[k][0]) s+='1';
		else{
			s=s.substr(0,s.length()-1);
		}
		if(s.length()==0) s='0';
		cout<<setw(11)<<s;
	}
	cout<<endl;
	for(int i=15;i<=30;i++){
		int k=i%16;
		string s;
		for(int j=3;j>=1;j--){
			if(a[k][j]){
				s+='x';
				if(j>1){
					s+=j+'0';
				}
				s+='+';
			}
		}
		if(a[k][0]) s+='1';
		else{
			s=s.substr(0,s.length()-1);
		}
		if(s.length()==0) s='0';
		cout<<setw(11)<<s;
		for(int j=15;j<=30;j++){
			int l=j%16;
			int form[4];
			if(i==15||j==15){
				for(int m=3;m>=0;m--){
					form[m]=0;
				}
			}
			else{
				int n=(k+l)%15;
				for(int m=3;m>=0;m--){
					form[m]=a[n][m];
				}
			}
			string s;
			for(int j=3;j>=1;j--){
				if(form[j]){
					s+='x';
					if(j>1){
						s+=j+'0';
					}
					s+='+';
				}
			}
			if(form[0]) s+='1';
			else{
				s=s.substr(0,s.length()-1);
			}
			if(s.length()==0) s='0';
			cout<<setw(11)<<s;
		} 
		cout<<endl;
	}
	return 0;
}
