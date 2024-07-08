using namespace std;
#include <iostream>

int
main ()
{
  int dp[5001];
  int N;
  cin >> N;

  dp[1] = -1;
  dp[2] = -1;
  dp[3] = 1;
  dp[4] = -1;
  dp[5] = 1;

  for (int i = 6; i <= N; i++)
	{
	  int a, b;
	  a = dp[i - 3];
	  b = dp[i - 5];
	  if (b != -1)
		dp[i] = b + 1;
	  else if (a != -1)
		dp[i] = a + 1;
	  else
		dp[i] = -1;
	}
   cout<<dp[N];
}