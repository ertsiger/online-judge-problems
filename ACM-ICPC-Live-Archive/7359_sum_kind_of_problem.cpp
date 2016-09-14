#include <iostream>

using namespace std;

int main()
{
    int p = 0;
    cin >> p;
    
    while (p--)
    {
        int k, n;
        cin >> k >> n;
        
        int n_sq = n * n;
        int n_sq_plus_n = n_sq + n;
        
        cout << k << " " << n_sq_plus_n / 2 << " " << n_sq << " "  << n_sq_plus_n << endl;
    }
    
    return 0;
}


