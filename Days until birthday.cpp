#include <iostream>

using namespace std;

short DaysM(short&, int&);

bool Check(short&, short&, int&);

void validate(short& ,short&, short&, short&, int&, int&);

int main()
{
	short actualDay, actualMonth, Bday, Bmonth, days;
	int actualYear, Byear;
	char c;

	cout << "This programs shows the amount of days left until your next birthday.\n"
		 << "Enter the actual date.\n";
	do
	{
	validate(actualDay,actualMonth,Bday,Bmonth,actualYear,Byear);
	days=0;

	if(Bmonth<actualMonth || (Bmonth==actualMonth && Bday<actualDay))
	{
		days=DaysM(actualMonth,actualYear)-actualDay;
		actualMonth++;

		if(actualMonth>12)
		{
			actualMonth=1;
			actualYear++;
		}

		while(actualMonth>Bmonth)
		{
			days+=DaysM(actualMonth,actualYear);
			actualMonth++;

			if(actualMonth>12)
			{
				actualMonth=1;
				actualYear++;
			}
		}

		while(actualMonth<Bmonth)
		{
			days+=DaysM(actualMonth,actualYear);
			actualMonth++;
		}
		days+=Bday;
	}
	else
	{
		days=-actualDay;

		if(Bmonth>actualMonth)
			days+=DaysM(actualMonth,actualYear);
		else
			days+=Bday;
		actualMonth++;

		while(Bmonth>=actualMonth)
		{
			if(Bmonth>actualMonth)
				days+=DaysM(actualMonth,actualYear);
			else
				days+=Bday;
			actualMonth++;
		}
	}

	cout << "Your birthday is in " << days << " day";

	if(days!=1)
		cout << 's';
	cout << ".\n";

	cout << "Run again? [Y/y] ";
	cin >> c;

	if(c=='Y' || c=='y')
		system("cls");

	}while(c=='Y' || c=='y');

	return 0;
}

short DaysM(short& m, int& y)
{
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		default:
			return (y%4==0) ? 29 : 28;
	}
}

void validate(short& ad, short& am, short& bd, short& bm, int& ay, int& by)
{
	do
	{
		cout << "Actual day: ";
		cin >> ad;

		cout << "Actual month:";
		cin >> am;

		cout << "Actual year: ";
		cin >> ay;

		if(!Check(ad,am,ay))
		{
			cerr << "Enter valid data.\n";
			system("pause");
			system("cls");
		}
	} while(!Check(ad,am,ay));

	do
	{
		cout << "Day of birth: ";
		cin >> bd;

		cout << "Month of birth: ";
		cin >> bm;

		cout << "Year of birth: ";
		cin >> by;

		if(!Check(bd,bm,by))
		{
			cerr << "Enter valid data.\n";
			system("pause");
			system("cls");
		}
	} while(!Check(bd,bm,by));
}

bool Check(short& d, short& m, int& y)
{
	if(d<1 || d>31 || m<1 || m>12 || ((m==4 || m==6 || m==9 || m==11) && d>30))
		return false;
	if(m==2 && y%4!=0 && d>28 || (m==2 && d>29))
		return false;
	return true;
}
