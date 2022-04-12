#include<stdio.h>
int n,cnt=0,cnt_1,a[14]={0},b[28]={0},c[28]={0},d[92][14],g[14];
void queen(int k){
	for(int i=1;i<=n;i++){
		if(!a[i]&&!b[k-i+n]&&!c[k+i]){
			a[i]=b[k-i+n]=c[k+i]=1;
			g[k]=i;
			if(k==n){
				for(int j=1;j<=n;j++) d[cnt][j]=g[j];
				cnt++;
			}
			else queen(k+1);
			a[i]=b[k-i+n]=c[k+i]=0;
		}
	}
}
void updown(int e){
	int flag;
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0||i==e) continue;
		flag=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]!=d[e][n-j+1]) flag=1;
		if(!flag){
			d[i][1]=0;
			return;
		}
	}
}
void leftright(int e){
	int flag;
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0||i==e) continue;
		flag=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]!=n-d[e][j]+1) flag=1;
		if(!flag){
			d[i][1]=0;
			return;
		}
	}
}
void reverse(int e){
	int flag,f[n+1];
	for(int i=1;i<=n;i++)
		f[d[e][i]]=i;
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0||i==e) continue;
		flag=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]!=f[j]) flag=1;
		if(!flag){
			d[i][1]=0;
			return;
		}
	}		
}
void Reverse(int e){
	int flag,f[n+1];
	for(int i=1;i<=n;i++)
		f[n-d[e][i]+1]=n-i+1;
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0||i==e) continue;
		flag=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]!=f[j]) flag=1;
		if(!flag){
			d[i][1]=0;
			return;
		}
	}		
}
void _90(int e){
	int flag,f[n+1];
	for(int i=1;i<=n;i++)
		f[d[e][i]]=n-i+1;
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0||i==e) continue;
		flag=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]!=f[j]) flag=1;
		if(!flag){
			d[i][1]=0;
			return;
		}
	}		
}
void _180(int e){
	int flag,f[n+1];
	for(int i=1;i<=n;i++)
		f[n-i+1]=n-d[e][i]+1;
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0||i==e) continue;
		flag=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]!=f[j]) flag=1;
		if(!flag){
			d[i][1]=0;
			return;
		}
	}		
}
void _270(int e){
	int flag,f[n+1];
	for(int i=1;i<=n;i++)
		f[n-d[e][i]+1]=i;
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0||i==e) continue;
		flag=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]!=f[j]) flag=1;
		if(!flag){
			d[i][1]=0;
			return;
		}
	}		
}
void valid(){
	for(int i=0;i<cnt;i++){
		if(d[i][1]==0) continue;
		cnt_1++;
		for(int j=1;j<=n;j++){
			if(j==1) printf("No%d:%d ",cnt_1,d[i][j]);
			else if(j!=n&&j!=1) printf("%d ",d[i][j]);
			else if(cnt_1!=12) printf("%d \n",d[i][j]);
			else printf("%d ",d[i][j]);
		}
		updown(i);
		leftright(i);
		reverse(i);
		Reverse(i);
		_90(i);
		_180(i);
		_270(i);
	}
}        
int main(){
	n=8;
	queen(1);
	valid();
	return 0;
}


