#include<iostream>
using namespace std;
int main()
{
	int Number;
	int base,Answer =0,rem=0;
	string s;
	char c;
	cout << "Enter the Base you want to Convert the Decimal number to be Converted into : ";
	cin >> base;
	if (base < 2)
	{
		cout << "Invalid Base ... Exiting...";
		return 1;
	}
	cout << "Enter your Number:";
	cin >> Number;
	if (Number == 0)
	{
		cout << "Your Answer is 0" << endl;
		return 1;
	}
	while (Number > 0)
	{
		rem= Number % base;
		if (rem < 10)
			c = rem + '0';
		else
			c = 'A' + (rem - 10);


		s = s + c;
		Number = Number / base;
	}
	int length = s.length()-1;
	cout <<"The Final Answer is : "<< endl;
	for (int i = length;i >= 0;i--)
	{
		cout << s[i] << " ";
	}


}