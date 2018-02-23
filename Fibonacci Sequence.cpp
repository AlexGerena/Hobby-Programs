#include <iostream>

using namespace std;

unsigned long long f(unsigned l);

int main()
{
	unsigned long long num;

	cout << "Enter the position of the Fibonacci number you want to see: ";
	cin >> num;

	cout << "The Fibonacci number at position " << num
		 << " is " << f(num)
		 << endl;

	return 0;
}

unsigned long long f(unsigned n)
{
	if(n==1 || n==2)
		return 1;
	return f(n-1)+f(n-2);
}
