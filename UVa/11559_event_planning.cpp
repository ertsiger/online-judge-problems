/**
 * Author: Ertisger
 * 26/12/2015
 * Time: 0.000
 */
#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int N, B, H, W;
    
    while (cin >> N >> B >> H >> W)
    {
        int minCost = INT_MAX;
        int hotelCost = 0;
        int weekCapacity = 0;
        
        for (int i = 0; i < H; ++i)
        {
            cin >> hotelCost;
            
            for (int j = 0; j < W; ++j)
            {
                cin >> weekCapacity;
                
                if (weekCapacity >= N)
                {
                    int totalCost = N * hotelCost;
                    
                    if ((totalCost <= B) && (totalCost < minCost))
                    {
                        minCost = totalCost;
                    }
                }
            }
        }
        
        if (minCost == INT_MAX)
        {
            cout << "stay home\n";
        }
        else
        {
            cout << minCost << '\n';
        }
    }
    
    return 0;
}

