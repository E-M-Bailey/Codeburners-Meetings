#include <iostream>
#include <vector>

using namespace std;

int modPow(int a, int b, int m)
{
	a = (a % m + m) % m;
	vector<int> P{ a }; // P[p] := a ** (2 ** p)
	int64_t p = 2;
	for (; p <= b; p *= 2)
		P.push_back((int64_t)P.back() * P.back() % m);

	int64_t ans = 1;
	p = 1;
	for (int i = 0; p <= b; i++, p *= 2)
		if (p & b)
			ans = ans * P[i] % m;

	return ans;
}

int main()
{
	int a, b, m;
	while (cin >> a >> b >> m)
		cout << modPow(a, b, m) << endl;
}