#include<iostream>
#include<cmath>
#include<ctype.h>
#include<string>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


using namespace std;

void displaymenu();
  // Module 1
void Base_Validator(int base);
void Number_Validator(string s, int base);
void Entered_Number_Validator(int &num, int base);
int Convert_to_Decimal(string user, int base);
string Convert_From_Decimal_to_Desired_Base(int decimal,int base);

//Module 2: Energy Consumption Monitor
void Binary_Number_Validator(string num);
void Energy_Status_Calculator(int num);

// Module 3:Environmental Sensor Analyzer
void Binary_Sensor(string num);

//Module 4:Secure Access Password Validator
void Password_Validator(string num);

//Module 5: Communication Signal Validator
void Signal_Validator(string num);

//Module 6: Binary Data Compressor
string Data_Compressor(string num);
//Module 7:
void Gray_Coder(int k);
//Module 8: Binary Voting Tally System
void Output_Votes(int Array[], int n);
void Voting_Tally_System(string votes);

//Module 9: Weather Station Alert Decoder
void Weather_Coder(string decimal);

int main()
{
    int ch=1;
    // displaymenu();
    // cin>>ch;
    string Number;
    while(ch!=0)
{
    displaymenu();
    cin>>ch;
   switch(ch)
{
    //      FOR MODULE 1
    case 1:
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

//         FOR MODULE 2
    case 2:
    {
        cout<<"Binary energy reading: ";
        cin>>Number;
        Binary_Number_Validator(Number);
        int Decimal=Convert_to_Decimal(Number,2);
        Energy_Status_Calculator(Decimal);


    }


//          FOR MODULE 3
    case 3:
    {
        cout<<"Sensor data: ";
        cin>>Number;
        Binary_Number_Validator(Number);
        Binary_Sensor(Number);

    }
//          FOR MODULE 4
   case 4:
   {
    cout<<"Password: ";
    cin>>Number;
    cout<<"Password Strength: ";
    Binary_Number_Validator(Number);
    Password_Validator(Number);
   }

//          FOR MODULE 5
    case 5:
    {
        cout<<"Signal: ";
        cin>>Number;
        cout<<"Signal Status: ";
        Binary_Number_Validator(Number);
        Signal_Validator(Number);
    }
//          FOR MODULE 6
    case 6:
    {
     cout<<"Binary data: ";
     cin>>Number;
     Binary_Number_Validator(Number);
     cout<<"Compressed data: "<<endl<<Data_Compressor(Number);     
    }
//          FOR MODULE 7
    case 7:
    {

        int n;
        cout<<"Number of bits: ";
        cin>>n;
        cout<<"[";
        Gray_Coder(n);
        return 0;
    }
//          FOR MODULE 8
    case 8:
    {
        cout<<"Votes: ";
        getline(cin, Number);
        Voting_Tally_System(Number);

    }

//          FOR MODULE 9
    case 9:
    {
        cout<<"Alert Code: ";
        cin>>Number;
        Binary_Number_Validator(Number);
        cout<<"Alert: ";
        Weather_Coder(Number);

    }
    default:
    {
        cout<<"Wrong Selection...";
    }
}
}
    
}

// Menu
void displaymenu()
{
    cout << BOLD << CYAN << "============================================\n";
    cout << "       🔬 The Stellar Data Management System      \n";
    cout << "============================================" << RESET << endl;

    cout << BOLD << GREEN << ".. 1. " << MAGENTA << "Scientific Data Converter" << endl;
    cout << BOLD << GREEN << ".. 2. " << MAGENTA << "Energy Consumption Monitor" << endl;
    cout << BOLD << GREEN << ".. 3. " << MAGENTA << "Environmental Sensor Analyzer" << endl;
    cout << BOLD << GREEN << ".. 4. " << MAGENTA << "Secure Access Password Validator" << endl;
    cout << BOLD << GREEN << ".. 5. " << MAGENTA << "Communication Signal Validator" << endl;
    cout << BOLD << GREEN << ".. 6. " << MAGENTA << "Binary Data Compressor" << endl;
    cout << BOLD << GREEN << ".. 7. " << MAGENTA << "Gray Code Sequence Generator" << endl;
    cout << BOLD << GREEN << ".. 8. " << MAGENTA << "Binary Voting Tally System" << endl;
    cout << BOLD << GREEN << ".. 9. " << MAGENTA << "Weather Station Alert Decoder" << endl;
    cout << BOLD << RED   << ".. 0. " << RED << "Exit" << endl;

    cout << BOLD << CYAN << "============================================" << RESET << endl;
    cout << BOLD << YELLOW << "Enter your choice: " << RESET;
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
    cout<<"Efficient";
    else if(num>=101 && num<=500)
    cout<<"Moderate";
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
     
// FOR MODULE 8
void Output_Votes(int Array[], int n)
{
    int m=10;
    int Result[m],k=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(Array[i]!=0)
    {  
         count=0;
        int num=Array[i];

        for(int j=i;j<n;j++)
        {
            if(Array[j]==num)
        {
            count++;
            Array[j]=0;
        }
    }
    Result[k++]=num;
    Result[k++]=count;
    }
    }
    for(int i=0;i<k;i+=2)
    {cout<<"Candidate "<<Result[i]<<": "<<Result[i+1];
    if(Result[i+1]>1)cout<<" votes,";else cout<<" vote";}
}
void Voting_Tally_System(string votes)
{
    int n=10,j=-1;
    int k=0;

    int decimal_Container[10]={};
    string vote_bank[n]={};

    for(int i=0;i<votes.length();i++)
    {
        if(votes[i]=='"')
        {
            j++; k++;
            if(k%2==0)
            j--;
        }
        if(isalnum(votes[i])&& j>=0)
        {
            vote_bank[j] +=votes[i];
        }
    }
        for(int i=0;i<=j;i++)
        {
            if
        (vote_bank[i].length()>=5)
           {
          string last_five_digits=vote_bank[i].substr(vote_bank[i].length()-5,5);
          decimal_Container[i]=Convert_to_Decimal(last_five_digits,2); 
            }
            else
            {
                cout<<"Vote: "<<i<<" is not valid number"<<endl;
                exit(1);
            }
        }
        for(int i=0;i<=j;i++)
        cout<<decimal_Container[i]<<" "; 
        cout<<endl;
        Output_Votes(decimal_Container,j+1);  
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
