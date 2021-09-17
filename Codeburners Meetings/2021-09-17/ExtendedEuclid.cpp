#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct Bezout
{
	int gcd, x, y;
};

Bezout rExtendedEuclid(int a, int b) // Recursive
{
	a = abs(a); b = abs(b);
	if (b == 0)
		return { a, 1, 0 };
	Bezout prev = rExtendedEuclid(b, a % b);
	return { prev.gcd, prev.y, prev.x - a / b * prev.y };
}

Bezout iExtendedEuclid(int a, int b) // Iterative
{
	a = abs(a); b = abs(b);
	vector<pair<int, int>> stack;
	while (b != 0)
	{
		stack.emplace_back(a, b);
		tie(a, b) = make_pair(b, a % b);
	}
	Bezout ans = { a, 1, 0 };
	for (; !stack.empty(); stack.pop_back())
	{
		tie(a, b) = stack.back();
		ans = { ans.gcd, ans.y, ans.x - a / b * ans.y };
	}
	return ans;
}

int main()
{
	int a, b;
	while (std::cin >> a >> b)
	{
		Bezout rec = rExtendedEuclid(a, b), itr = iExtendedEuclid(a, b);
		cout << rec.gcd << ' ' << rec.x << ' ' << rec.y << ' ' << itr.gcd << ' ' << itr.x << ' ' << itr.y << endl;
	}
}