#include <iostream>
#include <vector>

using namespace std;

// Finds primes in [2, n]
vector<int> eratosthenes(int n, vector<bool>& C) // C is set to true for composite numbers, false for others
{
	C.clear(); C.resize(n + 1, false);
	vector<int> P; // primes
	
	for (int p = 2; p <= n; p++)
	{
		if (C[p]) continue; // Skip composites
		P.push_back(p);
		for (int i = p * 2; i <= n; i += p) // Multiples of p
			C[i] = true;
	}

	return P;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<bool> C;
		vector<int> P = eratosthenes(n, C);
		for (bool c : C) cout << c;
		cout << endl;
		for (int p : P) cout << p << ' ';
		cout << endl;
	}
}