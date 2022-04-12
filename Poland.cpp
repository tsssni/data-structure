#include<iostream>
using namespace std;
class A;
class B;
class C;
class D;
class A {
public:
	void fA() {
		cout << 0;
	}
};
class B :public A {

};
class C :public A {

};
class D :public B, public C {
public:
	using B::fA;
	void k() {
		fA();
	}
};
int main() {
	D d;
	d.k();
	return 0;
}