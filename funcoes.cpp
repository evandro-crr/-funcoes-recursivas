# include <iostream>
using namespace std;

// retorna 0
int z(int x) {
	return 0;
}

// sucessor
int s(int x) {
	return x + 1;
}

// x+y
int f(int x, int y) {
	if (y == 0)
		return x;
	return s(f(x, y - 1));
}

// x*y
int m(int x, int y) {
	if (y == 0)
		return z(x);
	return f(x, m(x, y - 1));
}

// x!
int fat(int x) {
	if (x == 0)
		return s(x);
	return m(x, fat(x - 1));
}

// retorna 0 se x = 0
int sg(int x) {
	if (x == 0)
		return z(x);
	return s(z(x - 1));
}

// retorna 1 se x = 0
int _sg(int x) {
	if (x == 0)
		return s(x);
	return z(x - 1);
}

// antecessor
int a(int x) {
	if (x == 0)
		return x;
	return x - 1;
}

// r = x-y | r >= 0 
int sp(int x, int y) {
	if (y == 0)
		return x;
	return a(sp(x, y - 1));
}
// mod 4
int mod4(int x) {
	if (x == 0)
		return 0;
	return m(_sg(sp(mod4(x-1),6)),s(mod4(x-1)));
}
// y mod x
int mod(int x, int y) {
	if (y == 0)
		return y;
	return m(sg(sp(a(x), mod(x, y - 1))), s(mod(x, y - 1)));
}

// x/2
int d2(int x) {
	if (x == 0)
		return z(x);
	return a(sp(x,d2(x-1)));
}

// x/3
int d3(int x) {
	if (x == 0)
		return z(x);
	return d2(a(a(sp(x,a(d3(x-1))))));
}

// retorna 1 se x = y
int ig(int x, int y) {
	if (x == 0 && y == 0)
		return s(x);
	return m(_sg(sp(x,y)),_sg(sp(y,x)));
}

// max(x,y)
int max(int x, int y) {
	if (y == 0)
		return x;
	return f(sp(x,y),y);
}

// min(x,y)
int min(int x, int y) {
	if (y == 0)
		return y;
	return sp(f(x,y),max(x,y));
}

// x^y
int pot(int x, int y) {
	if (y == 0)
		return s(y);
	return m(x,pot(x,y-1));
}

// mod 2
int mod2(int x) {
	if (x == 0)
		return z(x);
	return sp(x,m(2,d2(x)));
}

// mod 3
int mod3(int x) {
	if (x == 0)
		return z(x);
	return sp(x,m(3,d3(x)));
}

int main(){

	return 0;
}
