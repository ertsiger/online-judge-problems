/**
 * Author: Ertisger
 * 22/04/2016
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int keys[129];

int main()
{
    keys['a'] = keys['d'] = keys['g'] = keys['j'] = keys['m'] = 
    keys['p'] = keys['t'] = keys['w'] = keys[' '] = 1;

    keys['b'] = keys['e'] = keys['h'] = keys['k'] =
    keys['n'] = keys['q'] = keys['u'] = keys['x'] = 2;
    
    keys['c'] = keys['f'] = keys['i'] = keys['l'] =
    keys['o'] = keys['r'] = keys['v'] = keys['y'] = 3;
    
    keys['s'] = keys['z'] = 4;
    
    int T = 0;
    cin >> T;
    
    string S = "";
    
    getline(cin, S);
    
    for (int t = 1; t <= T; ++t)
    {
        getline(cin, S);
        
        int c = 0;
        
        for (int i = 0; i < S.length(); ++i)
        {
            c += keys[S[i]];
        }
        
        cout << "Case #" << t << ": " << c << endl;
    }
    
    return 0;
}

