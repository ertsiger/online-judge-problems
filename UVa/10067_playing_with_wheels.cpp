/**
 * Author: Ersiger
 * 07/05/2016
 * Time: 1.270
 * Comment: Maybe I finally made the code more complex than it should be :P
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>

using namespace std;

struct State
{
    int a, b, c, d;

    State(){}

    State(int xa, int xb, int xc, int xd) :
        a(xa), b(xb), c(xc), d(xd)
    {
    }

    bool operator<(const State& s) const
    {
        int n1 = a * 1000 + b * 100 + c * 10 + d;
        int n2 = s.a * 1000 + s.b * 100 + s.c * 10 + s.d;

        return n1 < n2;
    }
};

map<State, int> stateToInt;
map<int, State> intToState;
set<int> forbiddenStates;
set<int> visitedStates;
int lastId = 0;

void addState(const State& s)
{
    if (stateToInt.find(s) == stateToInt.end())
    {
        stateToInt[s] = lastId;
        intToState[lastId] = s;
        ++lastId;
    }
}

int getUp(int n)
{
    int np = n + 1;
    return (np == 10 ? 0 : np);
}

int getDown(int n)
{
    int np = n - 1;
    return (np == -1 ? 9 : np);
}

void addChild(int s, int depth, queue<pair<int, int> >& queue)
{
    const State& sp = intToState[s];

    State s1(getDown(sp.a), sp.b, sp.c, sp.d);
    addState(s1);
    queue.push(make_pair(stateToInt[s1], depth + 1));

    State s2(getUp(sp.a), sp.b, sp.c, sp.d);
    addState(s2);
    queue.push(make_pair(stateToInt[s2], depth + 1));

    State s3(sp.a, getDown(sp.b), sp.c, sp.d);
    addState(s3);
    queue.push(make_pair(stateToInt[s3], depth + 1));

    State s4(sp.a, getUp(sp.b), sp.c, sp.d);
    addState(s4);
    queue.push(make_pair(stateToInt[s4], depth + 1));

    State s5(sp.a, sp.b, getDown(sp.c), sp.d);
    addState(s5);
    queue.push(make_pair(stateToInt[s5], depth + 1));

    State s6(sp.a, sp.b, getUp(sp.c), sp.d);
    addState(s6);
    queue.push(make_pair(stateToInt[s6], depth + 1));

    State s7(sp.a, sp.b, sp.c, getDown(sp.d));
    addState(s7);
    queue.push(make_pair(stateToInt[s7], depth + 1));

    State s8(sp.a, sp.b, sp.c, getUp(sp.d));
    addState(s8);
    queue.push(make_pair(stateToInt[s8], depth + 1));
}

int getNumStepsToSolution(int iState, int fState)
{
    queue<pair<int, int> > states; // state id, depth
    states.push(make_pair(iState, 0));

    while (!states.empty())
    {
        const pair<int, int> s = states.front();
        int sid = s.first;
        int sdepth = s.second;

        if (sid == fState)
        {
            return sdepth;
        }
        else
        {
            bool isForbidden = forbiddenStates.find(sid) != forbiddenStates.end();
            bool isVisited = visitedStates.find(sid) != visitedStates.end();

            if (!isForbidden && !isVisited)
            {
                addChild(sid, sdepth, states);
            }
        }

        visitedStates.insert(sid);
        states.pop();
    }

    return -1;
}

int main()
{
    int N = 0;
    cin >> N;

    while (N--)
    {
        stateToInt.clear();
        intToState.clear();
        forbiddenStates.clear();
        visitedStates.clear();
        lastId = 0;

        State iState;
        cin >> iState.a >> iState.b >> iState.c >> iState.d;
        addState(iState);
        
        State fState;
        cin >> fState.a >> fState.b >> fState.c >> fState.d;
        addState(fState);
        
        int numForbidden = 0;
        cin >> numForbidden;

        for (int i = 0; i < numForbidden; ++i)
        {
            State forbState;
            cin >> forbState.a >> forbState.b >> forbState.c >> forbState.d;
            addState(forbState);
            forbiddenStates.insert(stateToInt[forbState]);
        }

        cout << getNumStepsToSolution(stateToInt[iState], stateToInt[fState]) << endl;
    }

    return 0;
}

