/**
 * xErtsiger
 * 22/09/2016
 * Time: 0.013
 */
#include <iostream>

using namespace std;

int main()
{
    int points[5] = {1, 10, 100, 1000, 10000};

    int N = 0, M = 0; // players and rounds

    while (cin >> N >> M)
    {
        int maxSum = 0;
        int originalExtraSum = 0;
    
        for (int i = 0; i < M; ++i)
        {
            int B = 0; // budget
            int C1 = 0; // points player 1
            int Csum = 0; // sum of points players 2 .. N
        
            cin >> B >> C1;
            
            for (int j = 1; j < N; ++j)
            {
                int Cj = 0;
                cin >> Cj;
                Csum += Cj;
            }
            
            int originalExtra = 0;
            
            if ((Csum + C1) <= B)
            {
                originalExtra = C1;
            }
            
            originalExtraSum += originalExtra;
            
            int currentMax = 0;
            
            for (int j = 0; j < 5; ++j)
            {
                int q = Csum + points[j];
                
                if (q <= B)
                {
                    currentMax = points[j];
                }
            }
            
            maxSum += currentMax;
        }
        
        cout << maxSum - originalExtraSum << endl;
    }

    return 0;
}


