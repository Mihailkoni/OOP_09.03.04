#include <iostream>

void FuncY(double x, int n, double& y) {
	double mul = 1;
	for (int i = 6; i <= n; i++) {
		mul = mul * ((x / (x + 1)) + (pow(i, 2) / (1 + pow(i, 2))));
	}
	y = 2.4 * sin(x) + mul;
}

void ChekerDouble(double &a) {
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}

}

void ChekerInt(int &a) {
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}

}

int main() {
	double x, y;
	int n;
	std::cout << "Input x:" << '\n';
	ChekerDouble(x);
	std::cout << "Input n>=6:" << '\n';
	ChekerInt(n);
	if (n >= 6) {
		FuncY(x, n, y);
		std::cout << y;
	}
	else { std::cout << "Error: n<6"; }
}