#include <iostream>
#include <cmath>

using namespace std;

int getDigitSum(int n)
{
    int sum = 0;

    while (n > 0)
    {
        int res = n % 10;
        n /= 10;
        sum += res;
    }
    
    return sum;
}

bool isPerfectSquare(int n)
{
    int sqrt_n = sqrt(n);
    return n == sqrt_n * sqrt_n;
}

void findConsec()
{
    int n = 10;
    int consecFound = 0;
    
    while (consecFound < 7)
    {
        int n_sq = n * n;
        
        int digitSum = getDigitSum(n_sq);
    
        if (isPerfectSquare(digitSum))
        {
            ++consecFound;
            
            cout << n << " " << n_sq << " " << consecFound << endl;
        }
        else
        {
            consecFound = 0;
        }
    
        ++n;
    }
}

int main()
{
    //findConsec();

    cout << "9999 99980001\n";
    cout << "10000 100000000\n";
    cout << "10001 100020001\n";
    cout << "10002 100040004\n";
    cout << "10003 100060009\n";
    cout << "10004 100080016\n";
    cout << "10005 100100025\n";

    return 0;
}


