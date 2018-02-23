//Created by Alexander Gerena Bordoy

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

short countDigits(unsigned);

void showProbability(unsigned , unsigned, unsigned l[], unsigned);

void showResults(unsigned, unsigned, unsigned l[], unsigned);

void RollDice(unsigned, unsigned, unsigned l[], unsigned);

void getData(unsigned&, unsigned&, unsigned&);

int main()
{
	unsigned lim;
	unsigned max;
	unsigned min;
	
	srand(time(0));
	
	cout << "This program shows the outcome of dice rolls.\n"
		 << "Enter the number of dice rolls to be done: ";
	getData(max,min,lim);
	
	unsigned list[2*(max-min)+1]={0};
	
	system("cls");
	
	showProbability(max,min,list,lim);
	
	for(int n=0;n<2*(max-min)+1;n++)
		list[n]=0;
	
	RollDice(max,min,list,lim);
	
	showResults(max,min,list,lim);
	
	system("pause");
	
	return 0;
}

// Functions

short countDigits(unsigned num)
{
	short count=0;
	
	while(num>0)
	{
		num/=10;
		count++;
	}
	return count;
}

void showResults(unsigned maxValue, unsigned minValue, unsigned l[], unsigned limit)
{
	cout << fixed << showpoint << setprecision(3);
	
	cout << "The outcome with " << limit << " dice rolls is the following:\n";
	
	short biggest=countDigits(l[0]);
	
	for(int i=0;i<2*(maxValue-minValue)+1;i++)
	{
		double percent=100.0*l[i]/limit;
		
		for(int n=0;n<2*maxValue-2*minValue+1;n++)
			if(i<2*(maxValue-minValue)+1 && biggest<countDigits(l[n+1]))
				biggest=countDigits(l[n+1]);
		
		cout << left << setw(biggest+1) << i+2*minValue
			 << "- " << right << setw(biggest+3) << l[i]
			 << "  " << right << setw(biggest+4) << percent << '%'
			 << endl;
	}
}

void RollDice(unsigned maxValue, unsigned minValue, unsigned l[], unsigned limit)
{
	unsigned dice1;
	unsigned dice2;
	
	for(int i=1;i<=limit;i++)
	{
		dice1=rand() % (maxValue-minValue+1) + minValue;
		dice2=rand() % (maxValue-minValue+1) + minValue;
		
		l[dice1+dice2-2*minValue]++;
	}
}

void getData(unsigned& maxValue, unsigned& minValue, unsigned& limit)
{
	cin >> limit;
	
	cout << "Now enter the range of the dices.\n"
		 << "Enter the minimum value: ";
	cin >> minValue;
	
	cout << "Enter the maximum value: ";
	cin >> maxValue;
}

void showProbability(unsigned maxValue, unsigned minValue, unsigned l[], unsigned limit)
{
	for(int row=minValue;row<=maxValue;row++)
	{
		for(int column=minValue;column<=maxValue;column++)
			l[row+column-2*minValue]++;
	}
	
	short biggest=countDigits(maxValue);
	
	cout << "The probability of each number appearing is shown below:\n";
	
	for(int i=0;i<2*(maxValue-minValue)+1;i++)
	{
		cout << showpoint << fixed << setprecision(3);
		
		double percent=100.0*l[i]/((maxValue-minValue+1)*(maxValue-minValue+1));
		
		cout << left << setw(biggest+1) << i+2*minValue
			 << " - " << right << setw(biggest+4) << percent
			 << '%' << endl;
	}
	
	cout << "The number with the highest "
		 << "probability is "
		 << maxValue+minValue
		 << " with " << 100.0*l[maxValue+minValue-2*minValue]/((maxValue-minValue+1)*(maxValue-minValue+1))
		 << '%' << endl;
	
	system("pause");
}
