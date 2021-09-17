#include <iostream>
#include <vector>

using namespace std;

vector<int64_t> primeFactors(int64_t n)
{
	if (n < 2)
		return {};

	vector<int64_t> P;
	for (int64_t i = 2; i * i <= n; i++)
		while (n % i == 0)
		{
			P.push_back(i);
			n /= i;
		}

	if (n > 1)
		P.push_back(n);

	return P;
}

int main()
{
	int64_t n;
	while (cin >> n)
	{
		for (int64_t p : primeFactors(n))
			cout << p << ' ';
		cout << endl;
	}
}