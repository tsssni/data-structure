#include <iostream>
using namespace std;
class A{
public:
	A(int& ma):a(ma){}
	A& operator(const A& rhs):a(rhs.a){}
private:
	int& a;
};
int main( ) {
	int n=1;
	A a(n);
	A a1(n);
	a1=a;
	return 0;
}
