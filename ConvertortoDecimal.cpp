#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, i = 0, p=0;
    int ans = 0;
    cout << "Enter the Number you want to change to decimal: ";
    cin >> a;
    cout << "Enter the Index of the Number you can changing: ";
    cin >> i;
    if(i<=10){
    while (a != 0)
    {
        int rem;
        rem = a % 10;
        ans = ans + (rem * (pow(i, p)));
        cout << rem << " x " << i << " ^ " << p << "     ";
        p++;
        a = a / 10;
    }
    cout << " =   " << ans;}
// else if (i>10)
// {

// }
}
