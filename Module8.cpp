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
     
int main() 
{
    string Number;
    cout<<"Votes: ";
    getline(cin, Number);
    Voting_Tally_System(Number);
}
