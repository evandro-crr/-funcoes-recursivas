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

int main(){

int x;
int y;

cout << "x: ";
cin >> x;
cout << "y: ";
cin >> y;

if (ig(x,y) == 1)
	cout << x << " = " << y << endl;
else
	cout << x << " != " <<y << endl;
cout << "min(" << x << ", " << y << ") = " << min(x,y) << endl;
cout << "max(" << x << ", " << y << ") = " << max(x,y) << endl; 
cout << "x+y = " << f(x,y) << endl;
cout << "x-y = " << sp(x,y) << endl;
cout << "x*y = " << m(x,y) << endl;
cout << "x! = " << fat(x) << endl;
cout << y << " mod "<< x << " = " << mod(x,y) << endl;
cout << "x^y =" << pot(x,y) << endl;

return 0;
}
