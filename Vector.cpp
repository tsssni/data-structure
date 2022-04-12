#include<bits/stdc++.h>
using namespace std;
int main(){	
	vector<int> coll,voll;
	vector<int>::iterator pos,pos_1,pos_2,pos_3;
	for(int i=0;i<5;i++)
		coll.push_back(i);
	for(pos=coll.begin();pos!=coll.end();pos++) cout<<*pos<<' ';
	cout<<endl;
	pos=coll.begin();
	pos_1=coll.insert(pos,10);
	cout<<*pos_1<<endl;
	for(pos=coll.begin();pos!=coll.end();pos++) cout<<*pos<<' ';
	cout<<endl;
	pos_2=coll.erase(pos_1);
	cout<<*pos_2<<endl;
	for(pos=coll.begin();pos!=coll.end();pos++) cout<<*pos<<' ';
	cout<<endl;
	pos_3=coll.erase(pos_1,pos_1+2);
	cout<<*pos_3<<endl;
	for(pos=coll.begin();pos!=coll.end();pos++) cout<<*pos<<' ';
	cout<<endl;
	cout<<coll.front()<<' '<<coll.back()<<endl;
	cout<<coll.at(2)<<' '<<coll[2]<<endl;
	cout<<coll.size()<<' '<<coll.capacity()<<endl;
	for(int i=0;i<10;i++) voll.push_back(i);
	cout<<voll.size()<<' '<<voll.capacity()<<endl;
	coll.swap(voll);
	for(pos=coll.begin();pos!=coll.end();pos++) cout<<*pos<<' ';
	cout<<endl;
	coll.reserve(30);
	cout<<coll.size()<<' '<<coll.capacity()<<' '<<voll.size()<<' '<<voll.capacity()<<endl;
	coll.clear();
	cout<<coll.size()<<' '<<coll.capacity();
	return 0;
}

