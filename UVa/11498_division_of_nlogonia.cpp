/**
 * Author: Daniel F.B. (Ertsiger)
 * 21/112/2015
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    int N, M, X, Y, K;
    
    while (cin >> K)
    {
        if (K == 0) break;
    
        cin >> N >> M;
        
        for (int k = 0; k < K; ++k)
        {
            cin >> X >> Y;
            
            int Xp = X - N;
            int Yp = Y - M;
            
            if (Xp == 0 || Yp == 0)
            {
                cout << "divisa";
            }
            else if (Xp > 0)
            {
                if (Yp > 0) cout << "NE";
                else cout << "SE";
            }
            else if (Xp < 0)
            {
                if (Yp > 0) cout << "NO";
                else cout << "SO";
            }
            
            cout << endl;
        }
    }

    return 0;
}

