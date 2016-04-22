/**
 * Author: Daniel F.B. (Ertsiger)
 * 22/04/2016
 * Time: 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    string one = "one";
    string two = "two";
    string three = "three";

    int N = 0;
    cin >> N;

    string W = "";
    
    while (N--)
    {
        cin >> W;
        
        if (W.length() == three.length())
        {
            cout << "3\n";
        }
        else // the length is surely 3 (one, two)
        {
            int numConOne = 0;
            int numConTwo = 0;
        
            for (int i = 0; i < W.length(); ++i)
            {
                if (W[i] == one[i])
                {
                    ++numConOne;
                }
                
                if (W[i] == two[i])
                {
                    ++numConTwo;
                }
            }
            
            if (numConOne > numConTwo)
            {
                cout << "1\n";
            }
            else
            {
                cout << "2\n";
            }
        }        
    }

    return 0;
}

