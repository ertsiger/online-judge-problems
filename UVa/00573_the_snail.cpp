/**
 * Author: Ertsiger
 * 26/12/2015
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    int H;
    double U, D, F;
    
    while (cin >> H)
    {
        if (H == 0) break;
        cin >> U >> D >> F;
        
        double fatigue = U * F * 0.01;
        
        int maxDays = 101;
        double currentHeight = 0.0;
        
        for (int i = 0; i < maxDays; ++i)
        {
            double distanceUp = (U - double(i) * fatigue);
            
            if (distanceUp < 0.0)
            {
                distanceUp = 0.0;
            }
            
            currentHeight += distanceUp;
            
            if (currentHeight > H)
            {
                cout << "success on day " << i + 1 << endl;
                break;
            }
            
            currentHeight -= D;
            
            if (currentHeight < 0.0)
            {
                cout << "failure on day " << i + 1 << endl;
                break;
            }            
        }
    }
    
    return 0;
}

