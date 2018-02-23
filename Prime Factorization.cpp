#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long unsigned number, div;

	cout << "Enter a number to show its prime factorization: ";
	cin >> number;

	while(number%2==0 && number>=2)
    {
        cout << '2';

        if(number > 2)
        cout << '*';

        number/=2;
    }

    div = 3;

    while(div<=number)
    {
        if(number%div==0)
        {
            cout << div;

            if(number > div)
                cout << '*';
            number/=div;
        }
        else
            div+=2;
    }
	return 0;
}
