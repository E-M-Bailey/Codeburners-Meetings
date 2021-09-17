#include <iostream>
#include <vector>

using namespace std;

struct Bezout
{
	int gcd, x, y;
};

Bezout extendedEuclid(int a, int b)
{
	a = abs(a); b = abs(b);
	if (b == 0)
		return { a, 1, 0 };
	Bezout prev = extendedEuclid(b, a % b);
	return { prev.gcd, prev.y, prev.x - a / b * prev.y };
}

void multiInverse(vector<int>& B, vector<int>& A, vector<int>& Bi, vector<int>& Ai, int m)
{
	for (int& b : B)
		b %= m;
	int n = B.size();
	A.resize(n); Bi.resize(n); Ai.resize(n);

	A[n - 1] = B[n - 1];
	for (int i = n - 2; i >= 0; i--)
		A[i] = (int64_t)A[i + 1] * B[i] % m;

	Ai[0] = (extendedEuclid(A[0], m).x % m + m) % m;
	
	for (int i = 0; i < n - 1; i++)
	{
		Bi[i] = (int64_t)A[i + 1] * Ai[i] % m;
		Ai[i + 1] = (int64_t)B[i] * Ai[i] % m;
	}

	Bi[n - 1] = Ai[n - 1];
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> B(n), A, Bi, Ai;
		for (int i = 0; i < n; i++)
			cin >> B[i];
		multiInverse(B, A, Bi, Ai, m);
		for (int b : B) cout << b << ' ';
		cout << endl;
		for (int a : A) cout << a << ' ';
		cout << endl;
		for (int bi : Bi) cout << bi << ' ';
		cout << endl;
		for (int ai : Ai) cout << ai << ' ';
		cout << endl << endl;
	}
}