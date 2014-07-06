#include <iostream>
#include <climits>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

int main()
{
    int numCases = 0;
    int sal1 = 0, sal2 = 0, sal3 = 0; 
      
    cin >> numCases;
    
    for (unsigned int i = 1; i <= numCases; ++i)
    {
        cin >> sal1 >> sal2 >> sal3;
        int maxSal = MAX(MAX(sal1, sal2), sal3);
        int minSal = MIN(MIN(sal1, sal2), sal3);
        int currSal = maxSal;
        
        if (sal1 != maxSal && sal1 != minSal) currSal = sal1;
        if (sal2 != maxSal && sal2 != minSal) currSal = sal2;
        if (sal3 != maxSal && sal3 != minSal) currSal = sal3;
        
        cout << "Case " << i << ": " << currSal << endl;
    }
    
    return 0;
}
