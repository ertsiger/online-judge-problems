/**
 * Author: Daniel F.B. (Ertsiger)
 * 27/10/2016
 * Time: 0.003
 */
#include <iostream>

using namespace std;

int S[405];

int main()
{
    int N, M;

    bool first = true;
    
    while (cin >> N >> M)
    {
        for (int i = 0; i < 405; ++i)
        {
            S[i] = 0;
        }
        
        int max = -1;
        
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                int sum = i + j;
                S[sum] += 1;
                
                if (S[sum] > max)
                {
                    max = S[sum];
                }
            }
        }
        
        if (!first)
        {
            cout << endl;
        }
        else
        {
            first = false;
        }
        
        for (int i = 0; i < 405; ++i)
        {
            if (S[i] == max)
            {
                cout << i << endl;
            }
        }
    }
    
    return 0;
}

