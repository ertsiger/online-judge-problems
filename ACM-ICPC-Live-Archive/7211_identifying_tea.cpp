/**
 * xErtsiger
 * 22/09/2016
 * Time: 0.003
 */
#include <iostream>

using namespace std;

int main()
{
    int T = 0;
    
    while (cin >> T)
    {
        int t = 0, n = 0;
        
        for (int i = 0; i < 5; ++i)
        {
            cin >> t;
            
            if (t == T)
            {
                ++n;
            }
        }
        
        cout << n << endl;
    }

    return 0;
}


