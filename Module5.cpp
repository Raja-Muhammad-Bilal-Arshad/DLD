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
// FOR MODULE 5
void Signal_Validator(string num)
{
    int counter =0,a=0;
    for(int i=0;i<num.length();i++)
    {
        if(num[i]=='0')
        {
            counter++;
        }
        else if(num[i]=='1')
        {
            counter--;
        }
        if(i%2==0 && counter==0)
        {
            a++;
        }
        
    }
    if(a!=num.length()/2)
    {
        cout<<"Invalid";
        exit(0);
    }
    if(a<2 || a>4)
    {
        cout<<"Invalid";
        exit(0);
    }
    else
    cout<<"Valid";
    
    
}
        
int main() 
{
    string Number;
    {
     cout<<"Signal: ";
     cin>>Number;
     cout<<"Signal Status: ";
     Binary_Number_Validator(Number);
     Signal_Validator(Number);
       }
}
