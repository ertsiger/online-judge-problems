/**
 * Ertsiger
 * 06/10/2016
 * Time: 0.000s
 */
#include <iostream>
#include <vector>
#include <locale>

using namespace std;

int main()
{
    string s;
    locale loc;
    
    while (getline(cin, s))
    {
        if (s == "DONE")
            break;
    
        vector<char> v;
    
        for (int i = 0; i < s.length(); ++i)
        {
            char lowerChar = tolower(s[i], loc);
            
            if (lowerChar >= 'a' && lowerChar <= 'z')
            {
                v.push_back(lowerChar);
            }
        }

        int left = 0, right = v.size() - 1;
        bool isPal = true;
        
        while (left < right)
        {
            if (v[left] != v[right])
            {
                isPal = false;
                break;
            }
            
            ++left;
            --right;
        }
        
        if (isPal)
        {
            cout << "You won't be eaten!" << endl;
        }
        else
        {
            cout << "Uh oh.." << endl;
        }
    }

    return 0;
}


