#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> eratosthenes(int n, vector<bool>& C)
{
	C.clear(); C.resize(n + 1, false);
	vector<int> P;
	for (int p = 2; p <= n; p++)
	{
		if (C[p]) continue;
		P.push_back(p);
		for (int i = p * 2; i <= n; i += p)
			C[i] = true;
	}
	return P;
}

struct SegmentedSieve
{
	int64_t n;
	vector<int> P;
	SegmentedSieve(int64_t n) : n(n)
	{
		vector<bool> C;
		P = eratosthenes((int)sqrt(n), C);
	}
	// Returns primes in the range [l, r]. C's indices are offset by l.
	vector<int64_t> sieve(int64_t l, int64_t r, vector<bool>& C)
	{
		if (l > r)
			return {};
		C.clear(); C.resize(r - l + 1, false);
		// Compute composite numbers
		for (int p : P)
		{
			int64_t first = p * max(2ll, (l + p - 1) / p);
			for (int64_t i = first; i <= r; i += p)
				C[i - l] = true;
		}
		// Remaining numbers are prime
		vector<int64_t> P;
		for (int64_t i = max(l, 2ll); i <= r; i++)
			if (!C[i - l])
				P.push_back(i);

		return P;
	}
};

int main()
{
	int64_t n;
	cin >> n;
	SegmentedSieve segsieve(n);
	int64_t l, r;
	while (cin >> l >> r)
	{
		vector<bool> C;
		vector<int64_t> P = segsieve.sieve(l, r, C);
		for (bool c : C) cout << c;
		cout << endl;
		for (int64_t p : P) cout << p << ' ';
		cout << endl;
	}
}