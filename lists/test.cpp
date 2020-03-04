#include <iostream>
#include <list>
#include <typeinfo>
using namespace std;
/*int operator[](int n) {
	for(list<int>::iterator i = this->begin());
	advance(i, n);
	return *i;
}*/
int main() {
	list<int> a;
	for(int i=0; i<10; i++) a.push_back(i);
	auto it = a.begin();
	advance(it, 4);
	cout << *it << endl;
	return 0;
}