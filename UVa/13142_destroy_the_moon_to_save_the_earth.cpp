#include <iostream>

using namespace std;

/**
 * This problem can be solved using a simple equation, which would be:
 *  (S + x) * T - S * T = D
 * The units must match between the parameters given by the problem
 * (S, T, D). The x is the amount of rotation speed that will be added
 * or decreased. The amount of tons is just -x.
 * Note that the previous equation can be very simplified to find x:
 *  x = D / T
 * Since the transformation of units involves large numbers, overflow can
 * occur. So what I have done is to compute firstly the amount of meters
 * per hour. Then get the amount of meters per second, and finally the number
 * of milimeters per second.
 */
int main()
{
    int tests = 0;
    cin >> tests;

    int T = 0, S = 0, D = 0;

    while (tests--)
    {
        cin >> T >> S >> D;
        
        double mPerHour = double(1000.0 * D) / double(24.0 * T);
        double mPerSecond = mPerHour / (3600.0);
        double mmPerSecond = mPerSecond * 1000.0;
        
        long tons = -long(mmPerSecond);
        
        if (tons >= 0)
        {
            cout << "Add " << tons << " tons\n";
        }
        else
        {
            cout << "Remove " << -tons << " tons\n"; 
        }
    }

    return 0;
}


