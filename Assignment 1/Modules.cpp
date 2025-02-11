#include<iostream>
#include<cmath>
#include<ctype.h>
#include<string>

using namespace std;


  // Module 1
void Number_Validator(string s, int base);
void Entered_Number_Validator(int &num, int base);
int Convert_to_Decimal(string user, int base);
string Convert_From_Decimal_to_Desired_Base(string s,int base);


//Module 2: Energy Consumption Monitor
void Binary_Number_Validator(string num);
void Energy_Status_Calculator(int num);

// Module 3:Environmental Sensor Analyzer
void Binary_Sensor(string num);

//Module 4:Secure Access Password Validator
void Password_Validator(string num);
//Module 5: Communication Signal Validator
void Signal_Validator(string num)
{
    int counter =0;
        
    for(int i=0;i<num.length();i++)
    {
        if(num[i]==0)
        {
            counter++;
        }
        else if(num[i]==1)
        {
            counter--;
        }
    }
    
}




int main()
{
    int ch;
    cout<<"Choose the Module you want to Select: ";
    cin>>ch;
    string Number;
    int From_Base;
    int To_Base;

    //      FOR MODULE 1
    if(ch==1)
    {
    cout<<"Number: ";
    cin>>Number;
    Base_Validator(From_Base);
    cout<<"From Base: ";
    cin>>From_Base; 
    Number_Validator(Number,To_Base);
    cout<<"To Base: ";
    cin>>To_Base;
    Base_Validator(To_Base);

    // So Make a Generic Convertor Which can convert any base into it;s desired base
    // Firstly Convert the Your base in decimal then in the Desired base
    // Converting your base into decimal

    int decimal=Convert_to_Decimal(Number,From_Base);
    // Now Convert your base in your desired base
    string s=Convert_From_Decimal_to_Desired_Base(decimal,To_Base);
    cout<<"Expected Output: "<<endl<<s;
    }


             // FOR MODULE 2
    else if(ch==2)
    {
        cout<<"Binary energy reading: ";
        cin>>Number;
        Binary_Number_Validator(Number);
        int Decimal=Convert_to_Decimal(Number,2);
        Energy_Status_Calculator(Decimal);


    }


//              FOR MODULE 3
    else if(ch==3)
    {
        cout<<"Sensor data: ";
        cin>>Number;
        Binary_Number_Validator(Number);
        Binary_Sensor(Number);

    }
//          FOR MODULE 4
   else if(ch==4)
   {
    cout<<"Password: ";
    cin>>Number;
    Binary_Number_Validator(Number);
    Password_Validator(Number);
   }

//         FOR MODULE 5
    else if(ch==5)
    {
     cout<<"Signal: ";
     cin>>Number;
     Binary_Number_Validator(Number);


    }
    
}
void Base_Validator(int base)
{
if(base<2 || base>32)
{
    cout<<"Invalid base.."<<endl;
    exit(1);
}
}
void Number_Validator(string s, int base)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=base)
        {
            cout<<"Invalid Number entered with respect to your base...";
            exit(0);
        }
    }
}
int Convert_to_Decimal(string user, int base)
{
    char digit;
    int rem=0,decimal=0,power =0;
    for(int i=user.length()-1;i>=0;i--)
    {
        digit=toupper(user[i]);

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

        decimal+=rem*power;
        power*=base;

    }
    return decimal;
}
string Convert_From_Decimal_to_Desired_Base(int decimal,int base)
    {

    int rem=0;
    if(decimal==0)
    {
        cout<<"your answer is 0 "<<endl;
        exit(1);
    }
    string s;
    char c;
    while(decimal>0)
    {
        rem=decimal%base;
        if(rem<10)
            c=rem+'0';
        else
            c='A'+ (rem- 10);
        
            s=c+s;
            decimal/=base;
    }
    return s;
}

            // FOR MODULE 2 
void Binary_Number_Validator(string num)
{
    int total_digits=num.length();
    for(int i=0;i<total_digits;i++)
    {
        if(num[i]!=1 && num[i]!=0)
        {
            cout<<"INVALID INPUT OF DIGITS...";
            exit(0);

        }
    }
}
void Energy_Status_Calculator(int num)
{
    if(num>=0 && num<=100)
    cout<<"Efficient";
    else if(num>=101 && num<=500)
    cout<<'Moderate';
    else
    cout<<"Critical";
    exit(0);
}
            // for MODULE 3
void Binary_Sensor(string num)
{
    int zero_count=0, ones_count=0;
    int total_digit=num.length();
    for(int i=0;i<num.length();i++)
    {
        if(num[i]==0)
        zero_count++;
        else
        ones_count++;
    }
    cout<<"Alert Status: ";
    if((zero_count/total_digit)*100>60)
    cout<<"Triggered "<<endl;
    else
    cout<<"Normal"<<endl;
}
            // FOR MODULE 4
void Password_Validator(string num)
{
    int ones_count=0;
    int Mirror_Validator=0;
    int last_Index=num.length()-1;
    if(num.length()<8)
    {
        cout<<"Your Length of the Password should be at least 8 bits.. Exiting..";
        exit(0);
    }

    for(int i=0;i<num.length();i++)
    {
        if(num[0]!=0)
        {
            cout<<"Your First number is not equal to one, Hence Exiing code...";
            exit(0);
        }
        if(num[i]==1)
        ones_count++;
        if(i<=num.length()/2 && num[i]==num[last_Index--])
        Mirror_Validator++;
    }

    if(ones_count<3)
    {
        cout<<"Your Password Must contain at least 3 ones so exiting ....";
        exit(0);

    }
    if(Mirror_Validator!=num.length()/2)
    cout<<"Your Password is not Mirrored, Weak Password...";
        exit(0);
}



