#include <iostream>
using namespace std;



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
// FOR MODULE 4
void Password_Validator(string num)
{
   int ones_count =0;
    int last_Index=num.length()-1;
    for(int i=0;i<last_Index;i++)
    {
        if(num[i]=='1')
        ones_count++;
    }

    if(num.length()<8)
    {
        cout<<"Your Length of the Password should be at least 8 bits.. Exiting..";
        exit(0);
    }
    if(num[0]!='1')
        {
            cout<<"Your First number is not equal to one, Hence Exiing code...";
            exit(0);
        }
    if(ones_count<3)
    {
        cout<<"Your Password Must contain at least 3 ones so exiting ....";
        exit(0);
    }

      // FOR MIRRORING CHECKING
      int Mirror_Checker=0;
    for(int i=0;i<num.length()/2;i++)
    {
        if(num[i]!=num[last_Index-i])
        {
            Mirror_Checker++;
            break;
        }
    }
    if(Mirror_Checker!=0)
    {
        cout<<"Weak";
    }
    else
    {
        cout<<"Strong";
    }
    }
            
int main() 
{
    string Number;
    {
        cout<<"Password: ";
        cin>>Number;
        cout<<"Password Strength: ";
        Binary_Number_Validator(Number);
        Password_Validator(Number);
       }
}
