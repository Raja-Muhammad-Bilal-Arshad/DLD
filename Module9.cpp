#include <iostream>
using namespace std;

// FROM MODULE 1
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
  
// FROM MODULE 2 
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
  
    
//FOR MODULE 9
void Weather_Coder(string decimal)
{
    if(decimal.length()<8)
    {
        cout<<"Invalid code...";
        return;
    }
    string First_bit=decimal.substr(0,3);
    string Last_Bits=decimal.substr(3,5);

    if(First_bit=="001")
    cout<<"Freezing";
    else if(First_bit=="010")
    cout<<"Cold";
    else if(First_bit=="011")
    cout<<"Cool";
    else if(First_bit=="100")
    cout<<"Warm";
    else
    cout<<"Unknown Weather"<<endl;
    cout<<" with ";
    if(Last_Bits=="00001")
    cout<<"Meteor Shower"<<endl;
    else if(Last_Bits=="00010")
    cout<<"Solar Flare"<<endl;
    else if(Last_Bits=="00011")
    cout<<"Lunar Eclipse"<<endl;
    else
    cout<<"Unknown Phenomenom"<<endl;
    
}

int main() 
{
    string Number;
    cout<<"Alert Code: ";
    cin>>Number;
    Binary_Number_Validator(Number);
    cout<<"Alert: ";
    Weather_Coder(Number);
}
