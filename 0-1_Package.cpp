#include <bits/stdc++.h>
using namespace std;
struct cmdt{//Commodity，商品 
	int p;//价格 
	double w;//重量 
} a[1000005],s[1000005];//a数组记录每个商品，s数组记录序偶 
int pl[1000005],pr[100005];//pl[i]记录s[i]最左端的位置，pr[i]记录最右端 
int main(){
	int n;//n为商品数量  
	double M;//M为背包重量 
	scanf("%d%lf",&n,&M);
	for(int i=1;i<=n;i++){
		scanf("%d%lf",&a[i].p,&a[i].w);
	}
	s[0].p=s[0].w=0;//初始化 
	pl[0]=pr[0]=0;
	for(int i=1;i<=n;i++){
		pl[i]=pr[i-1]+1;//s[i]的左指针为s[i-1]右指针+1 
		int p1=pl[i-1],p2=pl[i-1],p3=pl[i];//p1从左到右遍历s[i-1]，p2记录s[i-1]中下一个可能被加入s[i]的元素
		for(p1;p1<=pr[i-1];p1++){//p3记录s[i]目前最后一个元素的下一位 
			int pp=s[p1].p+a[i].p;//由s[i-1]中的元素生成的序偶 
			double ww=s[p1].w+a[i].w;
			if(ww>M) break;//重量大于背包容量则结束循环，因为后产生的重量更大 
			while(p2<=pr[i-1]&&s[p2].w<ww){//将重量小于该序偶的s[i-1]中的元素全部加入s[i] 
				s[p3]=s[p2];
				p2++,p3++;
			}
			if(pp<s[p2-1].p) continue;//被支配，舍弃 
			if(p2>pr[i-1]){//p2遍历完所有的元素，当前序偶没有被支配，则加入s[i] 
				s[p3].p=pp;
				s[p3].w=ww;
				p3++;
			}
			else if(p2<=pr[i-1]&&s[p2].w>=ww){
				if(s[p2].w==ww){//若重量与当前序偶相等，取p大的加入s[i] 
					s[p3].p=max(pp,s[p2].p),s[p3].w=ww,p2++,p3++;
				}
				else{
					s[p3].p=pp,s[p3].w=ww,p3++;//将当前序偶加入s[i] 
					while(p2<=pr[i-1]&&s[p2].p<=pp){//若价值小重量大则被支配 
						p2++;
					}
				}
			}
		}
		if(p2<=pr[i-1]){
			s[p3++]=s[p2++];//将s[i-1]中剩余的元素加入 
		}
		pr[i]=p3-1;//s[i]右指针为循环结束后p3的前一个位置 
	}
	printf("Price:%d Weight:%.1lf\n",s[pr[n]].p,s[pr[n]].w);
	printf("The commodities chosen:");
	int p=s[pr[n]].p;
	double w=s[pr[n]].w;
	//(p,w)最右上角的序偶，由它开始寻找哪些商品被放进背包 
	for(int i=n;i>=1;i--){
		bool flag=0;
		for(int j=pl[i-1];j<=pr[i-1];j++){
			if(p==s[j].p&&w==s[j].w) flag=1;//若s[i-1]中有和（p，w）序偶相同的元素，则第i个元素没有被放进背包 
		}
		if(flag) continue;
		else{
			printf("%d ",i);
			p-=a[i].p;//更新序偶 
			w-=a[i].w;
		}
	}
	return 0;
}
