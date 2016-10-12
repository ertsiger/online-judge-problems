#include <iostream>

using namespace std;

unsigned long fibo[86];

int main()
{
    fibo[0] = fibo[1] = 1;
    
    for (int i = 2; i <= 85; ++i)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    int n = 0;
    
    while (cin >> n)
    {
        if (n == 0) break;
    
        cout << fibo[n - 1] << endl;
    }

    return 0;
}


