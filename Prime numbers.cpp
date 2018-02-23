// Alexander Gerena

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool IsPrime(long long unsigned);

void ShowFactors(long long unsigned);

int main()
{
	long long unsigned value;
	char ans;

	do
	{
        cout << "Enter a number: ";
        cin >> value;

        cout << "Number = " << value << endl;

        if(IsPrime(value))
            cout << "Prime\n";
        else
        {
            cout << "Not prime\n";
            if(value > 1)
            {
                cout << "Its factors are:\n";
                ShowFactors(value);
            }
        }

		cout << "\nInput another number? 1 - yes, Other key > Exit " << endl;
		cin >> ans;

		if(ans=='1')
			system("cls");

	} while(ans=='1');

	return 0;
}

bool IsPrime(long long unsigned num)
{
    if (num % 2 == 0 && num > 2 || num < 2)
        return false;

    long long unsigned s = floor(sqrt(num));

    for(long long unsigned i=3;i<=s;i+=2)
        if(num % i == 0)
            return false;
    return true;
}

void ShowFactors(long long unsigned num)
{
    long long unsigned c, s = floor(sqrt(num));

    for(c=2;c<s;c++)
        if(num % c == 0)
        {
            cout << c << " , "
                 << num/c << endl;
        }
    if(num % c == 0)
        cout << c << endl;
}
