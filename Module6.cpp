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
    // FOR MODULE 6
string Data_Compressor(string num)
{
    int count=0;
    char check=num[0];
    string compressed_data;
    for(int i=0;i<num.length();i++)
    {
        if(num[i]!=check)
        {
            compressed_data=compressed_data+to_string(count)+check;
            check=num[i];count=0;
        }
        count++;
    }
    return compressed_data+ to_string(count)+check;
}      
 
int main() 
{
    string Number;
    cout<<"Binary data: ";
    cin>>Number;
    Binary_Number_Validator(Number);
    cout<<"Compressed data: "<<endl<<Data_Compressor(Number);     
}
