/**
 * Author: Ertsiger
 * 05/05/2016
 * Time: 0.730
 */
#include <iostream>
#include <set>

#define MAX_NUM_TRACKS 20

using namespace std;

// input
int tracks[MAX_NUM_TRACKS];
int N; // tape duration
int T; // num of tracks

//
int cSum = 0; // current sum
int bSum = 0; // best sum

set<int> cTracks; // current tracks
set<int> bTracks; // best tracks

void findTracks(int index)
{
    for (int i = index + 1; i < T; ++i)
    {
        int idur = tracks[i];
    
        cSum += tracks[i];
        cTracks.insert(i);
    
        if (cSum > bSum && cSum <= N)
        {
            bTracks = cTracks;
            bSum = cSum;
        }
        
        findTracks(i);
        
        cTracks.erase(i);
        cSum -= tracks[i];
    }
}

int main()
{
    while (cin >> N >> T)
    {        
        for (int i = 0; i < T; ++i)
        {
            cin >> tracks[i];
        }
        
        cSum = bSum = 0;
        cTracks.clear();
        bTracks.clear();
        
        findTracks(-1);
        
        for (set<int>::const_iterator it = bTracks.begin(); it != bTracks.end(); ++it)
        {
            cout << tracks[*it] << " ";
        }
        
        cout << "sum:" << bSum << endl;
    }
    
    return 0;
}

