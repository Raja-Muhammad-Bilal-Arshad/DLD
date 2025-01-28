#include<iostream>
#include<string>
#include<cmath>
#include<ctype.h>

using namespace std;
int main()
{
	string Input;
	int Base;
	cout << "Enter your Input: ";
	cin >> Input;
	cout << "Enter you Base: ";
	cin >> Base;
	int rem=0,Sum=0;
	int length = Input.length();
	for (int i = 0;i < Input.length();i++)
	{
		char EachDigit = Input[i];

		if (isalpha(EachDigit))
		{
			rem = (toupper(EachDigit) - 'A' + 10);
		}
		else if(isdigit(EachDigit))
		{
			rem = EachDigit - '0';
		}
		if (rem >= Base)
		{
			cout << "Your " << i + 1 << "th Digit is incorrect: " << endl;
			return 1;
		}
		Sum = Sum * Base + rem;
	}

	cout << "Sum  =  " << Sum;
}