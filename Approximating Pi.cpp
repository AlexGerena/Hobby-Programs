#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

bool CoPrimes(int, int);

int randomNumbers(int);

double returnPi(int, int);

int main()
{
	long long limit;
	short a;
	int counter=0;
	
	do
	{
		cout << "Numbers to be generated: ";
		cin >> limit;
		
		counter=randomNumbers(limit);
		
		//system("cls");
		
		cout << fixed << showpoint << setprecision(2);
		cout << counter << " out of " << limit
			 << " were coprime numbers.(" << 100.0*counter/limit << "%)\n"
			 << setprecision(5)
			 << "The approximated value of pi is "
		 	 << returnPi(limit,counter) << endl;
	
		cout << "Run again? [1]\n";
		cin >> a;
		
		if(a==1)
			system("cls");
	} while(a==1);
	
	return 0;
}

bool CoPrimes(int a, int b)
{
	for(int i=2;i<=a && i<=b;i++)
		if(a%i==0 && b%i==0)
			return false;
	return true;
}

int randomNumbers(int l)
{
	int count=0;
	int number1=0;
	int number2=0;
	
	srand(time(0));
	
	for(int n=1;n<=l;n++)
	{
		number1=rand()+1;
		number2=rand()+1;
		
		if(CoPrimes(number1,number2))
			count++;
	}
	return count;
}

double returnPi(int l, int c)
{
	return sqrt(6.0*l/c);
}
