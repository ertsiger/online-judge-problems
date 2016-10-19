/**
 * Ertsiger
 * 19/10/2016
 * Time: 0.003
 */
#include <iostream>

using namespace std;

int main()
{
    string s;
    
    while (cin >> s)
    {
        int x = 0, y = 0;
        
        for (int i = 0; i < s.length(); ++i)
        {
            x *= 2;
            y *= 2;
        
            int d = s[i] - '0';
            
            if (d == 1)
            {
                ++x;
            }
            else if (d == 2)
            {
                ++y;
            }
            else if (d == 3)
            {
                ++x;
                ++y;
            }
        }
        
        cout << s.length() << " " << x << " " << y << endl;
    }

    return 0;
}


