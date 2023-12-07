#include <iostream>
using namespace std;

int arr[128][128] = { 0, };
int blue = 0;
int white = 0;

void check(int x, int y, int size)
{
	bool cut = false;
	int firstColor = arr[x][y];
	for (int i = x; i < x+size; i++)
	{
		for (int j = y; j < y+size; j++)
		{
			if (firstColor != arr[i][j])
			{
				cut = true;
				break;
			}
		}
	}

	if (cut)
	{
		check(x, y, size / 2);
		check(x, y + size / 2, size / 2);
		check(x + size / 2, y, size / 2);
		check(x + size / 2, y + size / 2, size / 2);
	}
	else
	{
		if (firstColor == 1) blue++;
		else white++;
	}
}

int main()
{
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> arr[i][j];
		}
	}
	check(0, 0, k);
	cout << white << '\n' << blue << '\n';
	return 0;
}