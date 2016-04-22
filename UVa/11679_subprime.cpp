/**
 * Author: Ertsiger
 * 22/04/2016
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int B; // number of banks
int N; // number of debentures printed by the banks
int R[22]; // monetary reserves of each bank
int D; // debtor bank
int C; // creditor bank
int V; // debenture value

int main()
{
    while (cin >> B >> N)
    {
        if (!B && !N) break;
    
        for (int b = 1; b <= B; ++b)
        {
            cin >> R[b];
        }
        
        for (int n = 0; n < N; ++n)
        {
            cin >> D >> C >> V;
            R[D] -= V;
            R[C] += V;
        }
        
        bool allPos = true;
        
        for (int b = 1; b <= B; ++b)
        {
            if (R[b] < 0)
            {
                allPos = false;
                break;
            }
        }
        
        if (allPos)
        {
            cout << "S\n";
        }
        else
        {
            cout << "N\n";
        }
    }

    return 0;
}

