#include <iostream>
using namespace std;



         // FOR MODULE 2 
void Binary_Number_Validator(string num)
{
    int total_digits=num.length();
    for(int i=0;i<total_digits;i++)
    {
        if(num[i]!='1' && num[i]!='0')
        {
            cout<<"INVALID INPUT OF DIGITS...";
            exit(0);

        }
    }
}
void Energy_Status_Calculator(int num)
{
    if(num>=0 && num<=100)
    cout<<"Decimal usage: "<<num<<", status: "<<"Efficient";
    else if(num>=101 && num<=500)
    cout<<"Decimal usage: "<<num<<", status: "<<"Moderate";
    else
    cout<<"Decimal usage: "<<num<<", status: "<<"Critical";
    exit(0);
}
    // MODULE 1
   int Convert_to_Decimal(string user, int base)
   {
     
       int rem=0,decimal=0,power =1;
       for(int i=user.length()-1;i>=0;i--)
       {
           char digit=toupper(user[i]);
   
           if(isalpha(digit))
           {
               rem=(digit-'A')+10;
           }
           else if(isdigit(digit))
           {
               rem=digit-'0';
           }
           else
           {
               cout<<"Digit "<<digit<<" is invalid ";
               exit(1);
           }
           if(rem>=base)
           {
               cout<<" You have used invalid digit for the corresponding base which is not allowed..."<<endl;
               exit(1);
   
           }
   
           decimal += rem * power;
           power*=base;
   
   
       }
       return decimal;
   }
   
int main() 
{
    string Number;
    cout<<"Binary energy reading: ";
    cin>>Number;
    Binary_Number_Validator(Number);
    int Decimal=Convert_to_Decimal(Number,2);
    Energy_Status_Calculator(Decimal);
    return 0;
}
