#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int d;
    string s;
    
    while (cin >> d)
    {
        if (d == 0)
            break;
        
        cin.ignore();
        getline(cin, s);
        
        string sf = "";
        
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
    
            bool mayus = (c >= 'A' && c <= 'Z');
            bool minus = (c >= 'a' && c <= 'z');
            
            int cc = 0;
            
            if (mayus)
            {
                cc = c - 'A';
            }
            else if (minus)
            {
                cc = c - 'a';
            }
            
            if (d > 0)
            {
                cc = (cc + d) % int('Z' - 'A' + 1);
            }
            else if (d < 0)
            {
                cc = cc+('Z' - 'A' + 1) - int(abs(d)) % int('Z' - 'A' + 1);
                cc %= int('Z' - 'A' + 1);	
            }
      
            if (mayus)
            {
                c = cc + 'A';
            }
            else if (minus)
            {
                c = cc + 'a';
            }
            
            s[i] = c;
        }
        
        cout << s << endl;
    }

    return 0;
}

