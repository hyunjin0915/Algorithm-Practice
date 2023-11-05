#include <iostream>
//#include <algorithm>

using namespace std;


int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}
int main()
{
	int n, m;
	cin >> n >> m;
	if (n < m)
	{
		swap(n, m);
	}
	int a = gcd(n, m);
	cout << a <<'\n' << n * m / a;
}