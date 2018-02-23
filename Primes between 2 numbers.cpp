#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool isPrime(long long unsigned);

int main()
{
	long long unsigned start, limit, count = 0;
	char ans;

	cout << "This program will find the prime numbers between to given values." << endl;

	do
	{
        cout << "Enter the range of search:\n"
             << "Starting value: ";
        cin >> start;

        cout << "Ending value: ";
        cin >> limit;

        cout << "The primes are : " << endl << endl;

            for(long long unsigned num=start;num<=limit;num++)
                {
                    if(isPrime(num))
                    {
                        count++;
                        cout << num << endl;
                    }
                }
        cout << "\n" << count << " primes were found." << endl
            << "Do you want to continue? (Y/y - yes , other key - no) " << endl;
        cin >> ans;

        if(ans=='Y' || ans=='y')
            system("cls");

	}	while(ans=='Y' || ans=='y');
}

bool isPrime(long long unsigned num)
{
	if (num % 2 == 0 && num > 2 || num < 2)
        return false;

    long long unsigned s = floor(sqrt(num));

    for(long long unsigned i=3;i<=s;i+=2)
        if(num % i == 0)
            return false;
    return true;
}
