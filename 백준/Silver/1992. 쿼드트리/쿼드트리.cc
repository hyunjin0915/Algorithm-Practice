#include <iostream>
using namespace std;

int arr[64][64] = { 0, };

void check(int x, int y, int size)
{
	bool cut = false;
	int firstOne = arr[x][y];
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (firstOne != arr[i][j])
			{
				cout << "(";
				check(x, y, size / 2);
				check(x, y + size / 2, size / 2);
				check(x + size / 2, y, size / 2);
				check(x + size / 2, y + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	 cout << firstOne;

}
int main()
{
	int n;
	cin >> n;
	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = str[j]-'0';
		}
	}
	check(0, 0, n);
	return 0;
}