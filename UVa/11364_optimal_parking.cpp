/**
 * Author: Daniel F.B. (Ertsiger)
 * 23/04/2016
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    
    int n = 0;
    
    while (t--)
    {
        cin >> n;
        
        int minShop = 101;
        int maxShop = -1;
        
        int sumPositions = 0;
        
        int shop = 0;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> shop;
            
            if (shop < minShop)
            {
                minShop = shop;
            }
            
            if (shop > maxShop)
            {
                maxShop = shop;
            }
            
            sumPositions += shop;
        }
        
        int meanPosition = sumPositions / n;
        
        int distance = (meanPosition - minShop) + (maxShop - minShop) + (maxShop - meanPosition);
        cout << distance << endl;
    }

    return 0;
}

