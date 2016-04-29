/**
 * Author: Ertsiger
 * 29/04/2016
 * Time: 0.000
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int input[3005];
bool numbers[3005];

int main()
{
    int n = 0;

    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> input[i];
            numbers[i] = false;
        }
        
        for (int i = 0; i < n - 1; ++i)
        {
            int diff = abs(input[i] - input[i + 1]);
            numbers[diff] = true;
        }
        
        bool isJolly = true;
        
        for (int i = 1; i < n && isJolly; ++i)
        {
            if (!numbers[i])
            {
                isJolly = false;
            }
        }
        
        cout << (isJolly ? "Jolly" : "Not jolly") << endl;
    }
    
    return 0;
}

