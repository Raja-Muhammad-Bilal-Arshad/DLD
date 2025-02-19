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
// for MODULE 3
void Binary_Sensor(string num)
{
    int zero_count=0, ones_count=0;
    int total_digit=num.length();
    for(int i=0;i<num.length();i++)
    {
        if(num[i]=='0')
        zero_count++;
        else
        ones_count++;
    }
    cout<<"Alert Status: ";
    if((zero_count* 100.0/total_digit)>60)
    cout<<"Triggered "<<endl;
    else
    cout<<"Normal"<<endl;
}
int main() 
{
    string Number;
    cout<<"Sensor data: ";
        cin>>Number;
        Binary_Number_Validator(Number);
        Binary_Sensor(Number);
}
