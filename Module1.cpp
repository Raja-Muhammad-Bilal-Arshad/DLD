#include <iostream>
using namespace std;

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
void Base_Validator(int base)
{
if(base<2 || base>32)
{
    cout<<"Invalid base.."<<endl;
    exit(1);
}
}
void Number_Validator(string s, int base) {
    if (s == "0") return; 

    for (int i = 0; i < s.length(); i++) {
        char c = toupper(s[i]); 
        int digit;

        if (isdigit(c)) 
            digit = c - '0'; 
        else if (isalpha(c) && c >= 'A' && c <= 'Z') 
            digit = c - 'A' + 10; 
        else {
            cout << "Invalid character '" << c << "' in the number." << endl;
            exit(1);
        }
        
        if (digit >= base) {
            cout << "Your numbers are invalid with respect to your base." << endl;
            exit(1);
        }
    }
}
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

     
int main() 
{
    string Number;
        int From_Base;
        int To_Base;
        cout<<"Number: ";
        cin>>Number;
        cout<<"From Base: ";
        cin>>From_Base; 
        Base_Validator(From_Base);
        Number_Validator(Number,From_Base);
        cout<<"To Base: ";
        cin>>To_Base;
        Base_Validator(To_Base);
    
        int decimal=Convert_to_Decimal(Number,From_Base);
        // Now Convert your base in your desired base
        // Convert to string
        string s=Convert_From_Decimal_to_Desired_Base(decimal,To_Base);
        cout<<"Expected Output: "<<endl<<s;
        return 0;
}