/**
 * Author: Daniel F.B. (Ertsiger)
 * 23/04/2016
 * Time: 0.000
 */
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string line = "";

    bool opening = true;
    
    while (getline(cin, line))
    {
        stringstream stream;
        stream << "";
                
        for (int i = 0; i < line.length(); ++i)
        {
            if (line[i] == '\"')
            {
                if (opening)
                {
                    stream << "``";
                }
                else
                {
                    stream << "\'\'";
                }
                
                opening = !opening;
            }
            else
            {
                stream << line[i];
            }
        }
        
        cout << stream.str() << endl;
    }

    return 0;
}

