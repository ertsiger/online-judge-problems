/**
 * Author: Daniel F.B. (Ertsiger)
 * 21/12/2015
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    int T = 0, N = 0, c = 0;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> N;
        
        int cmax = -1;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> c;
            
            if (c > cmax)
            {
                cmax = c;
            }
        }
        
        cout << "Case " << t << ": " << cmax << endl;
    }

    return 0;
}

