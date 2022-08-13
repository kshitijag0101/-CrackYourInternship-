// C++ program to acquire all
// n coins at minimum cost
// with multiple values of k.
#include<bits/stdc++.h>
using namespace std;

void preprocess(int coin[], int n){
	sort(coin, coin + n);
	for (int i = 1; i <= n - 1; i++)
		coin[i] += coin[i - 1];
}
int minCost(int coin[], int n, int k){
	int coins_needed = ceil(1.0 * n / (k + 1));
	return coin[coins_needed - 1];
}

// Driver Code
int main()
{
	int coin[] = {8, 5, 3, 10,
				2, 1, 15, 25};
	int n = sizeof(coin) / sizeof(coin[0]);
	preprocess(coin, n);
	int k = 3;
	cout << minCost(coin, n, k) << endl;
	k = 7;
	cout << minCost(coin, n, k) << endl;
	return 0;
}
