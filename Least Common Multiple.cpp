#include <iostream>

using namespace std;

int GCD3(int, int, int);

int GCD2(int, int);

int LCM3(int, int, int);

int main()
{
	long long n1, n2, n3;
	
	cout << "Enter 3 numbers to find the lowest common multiple:\n";
	cin >> n1 >> n2 >> n3;
	cout << endl;
	
	cout << "The lowest common multiple is " << LCM3(n1,n2,n3) << endl;
	
	return 0;
}

int GCD3(int a, int b, int c)
{
	int gcd=1;
	
	for(int i=1;i<=a && i<=b && i<=c;i++)
		if(a%i==0 && b%i==0 && c%i==0)
			gcd=i;
	
	return gcd;
}

int GCD2(int x, int y)
{
	int gcd=1;
	
	for(int i=1;i<=x && i<=y;i++)
		if(x%i==0 && y%i==0)
			gcd=i;
	
	return gcd;
}

int LCM3(int a, int b, int c)
{
	long long int lcm=1;
	int tempGcd=GCD3(a,b,c);
	
	lcm*=tempGcd;
	
	a/=tempGcd;
	b/=tempGcd;
	c/=tempGcd;
	
	tempGcd=GCD2(a,b);
	lcm*=tempGcd;
	
	a/=tempGcd;
	b/=tempGcd;
	
	tempGcd=GCD2(b,c);
	lcm*=tempGcd;
	
	b/=tempGcd;
	c/=tempGcd;
	
	tempGcd=GCD2(a,c);
	lcm*=tempGcd;
	
	a/=tempGcd;
	c/=tempGcd;
	
	lcm*=a*b*c;
	
	return lcm;
}
