#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
int numAndDenom(bool type, int n) /*type = false for numerator, true for denominator. Recurrence starts at n=3*/ 
{
    int result =0;
    switch(n)
    {
        case 1:
            {
                result = 1;
            }
            break;
        case 2:
            {
                result = type?2:3;
            }
            break;  
        default:
            {
                result = n*numAndDenom(type,n-1)+numAndDenom(type,n-2);
            }       
            break;
    }
    return result;
}
double calcContFraction(int n) /*10 terms for ~14 digit precision*/
{
    double result = 0;
    result = (1.0*numAndDenom(false, n))/(1.0*numAndDenom(true, n)); 
    return result;
}
int main()
{
    cout << "Enter the amount of terms you need for the continued fraction" << endl;
    int n;
    cin >> n;
    double result = calcContFraction(n);
    cout << setprecision(20) << result << endl;
    char c;
    cin>>c;
    return 0;
}
