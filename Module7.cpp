#include <iostream>
using namespace std;

// FROM MODULE 1
string Convert_From_Decimal_to_Desired_Base(int decimal,int base)
{
if(decimal==0) return "0";
string s;
char c;
while(decimal>0)
{
  int  rem=decimal%base;
   char c=(rem<10)? (rem+'0'):('A'+(rem-10));
    s=c+s;
    decimal/=base;
}
return s;
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
  
// FOR MODULE 7
void Gray_Coder(int k)
{
    int n=1<<k;
   int max_length=k;

    string binary;
    for(int i=0;i<n;i++)
    {

        binary=Convert_From_Decimal_to_Desired_Base(i,2);

        while(binary.length() < max_length)
        binary='0'+binary;

       
        cout<<"'";
        cout<<binary[0];


        for(int j=1;j<binary.length();j++)
        {
            int a=binary[j-1]-'0';
            int b=binary[j]-'0';

            // cout<<",";
            cout<<(a^b);

        }
        cout<<"'";
        if(i<n-1)
        cout<<",";
        else
        cout<<"]";

    }
}
   
int main() 
{
    string Number;
    int n;
    cout<<"Number of bits: ";
    cin>>n;
    cout<<"[";
    Gray_Coder(n);
    return 0;
}
