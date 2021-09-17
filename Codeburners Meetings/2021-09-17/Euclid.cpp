#include <iostream>
#include <tuple>

using namespace std;

int rEuclid(int a, int b) // Recursive
{
	a = abs(a); b = abs(b);
	if (b != 0)
		return rEuclid(b, a % b);
	return a;
}

int iEuclid(int a, int b) // Iterative
{
	a = abs(a); b = abs(b);
	while (b != 0)
		tie(a, b) = make_pair(b, a % b);
	return a;
}

int main()
{
	int a, b;
	while (std::cin >> a >> b)
		cout << rEuclid(a, b) << ' ' << iEuclid(a, b) << endl;
}