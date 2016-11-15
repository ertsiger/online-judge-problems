/**
 * Authors: drako9, toorx, Ertsiger
 * 15/11/2016
 * Time: 0.980
 */
#include <bits/stdc++.h>

#define PB(a) push_back(a)
#define MP(a,b) make_pair(a,b)
#define FOR(i,j) for(int i = 0 ; i < j; ++i)

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

int n , m;
char mymap[41][41];
bool visited[41][41][41][41];
struct PT { 
  int x, y;
  PT() {}
  PT(int x, int y ) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y){}
  //PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  //PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  //PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator < (const PT &p)     const { 
      if(p.x != x)return x < p.x;
      else return y < p.y;
  }
  bool operator == (const PT &p)     const { return p.x == x && p.y == y;}
  
  bool operator != (const PT &p)     const { return !(*this == p );}
  void print()     const {
      cout<<"x: "<<x<<" y: "<<y<<endl;
  }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { 
    double dist = (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
    return sqrt(dist);
}
 
double diference(set<pair<int,PT> >::iterator it){    //quitar el dos , diferencia de distancias
    PT pu , pd = (*it).second , pt;
    it--;
    pu= (*it).second;
    it++;it++;
    pt = (*it).second;
    double dif = dist2(pu,pt)-(dist2(pu,pd)+dist2(pd,pt));
    cout<<"Diference: ";pu.print();pd.print();pt.print();cout<<" "<<dif<<endl;
    return dif;
}


struct State{
    PT p1 , p2;
    int jumps;
    State():jumps(0){
        
    }
    State(PT p , PT q): p1(p),p2(q),jumps(0){
        
    }
    
    bool operator == (const State &s)     const {
        return s.p1 == p1 && s.p2 == p2;
    }
    bool operator != (const State &s)     const {
        return s.p1 != p1 || s.p2 != p2;
    }
    bool operator < (const State &s)     const { 
        if(*this == s)return false;
        else{
            if(p1 != s.p1)return p1 < s.p1;
            if(p2 != s.p2)return p2 < s.p2;
        }
    }
    void print(){
        cout<<"p1: ";p1.print();cout<<" p2: ";p2.print();cout<<" jumps: "<<jumps<<endl;
    }
};

PT heart;

bool pingLove(State s){
    return s.p1 == s.p2 && s.p1 == heart;
}

bool canMove(PT p,int move){
    switch(move){
        case 4:
            if(p.x > 0 && mymap[p.x-1][p.y] != '#')
                return true;
            return false;
        case 3:
            if(p.x < n-1 && mymap[p.x+1][p.y] != '#')
                return true;
            return false;
        case 2:
            if(p.y < m-1 && mymap[p.x][p.y+1] != '#')
                return true;
            return false;
        case 1:
            if(p.y > 0 && mymap[p.x][p.y-1] != '#')
                return true;
            return false;
    }
}

PT movept(PT p,int move){
    switch(move){
        case 4:
            p.x--;
            break;
        case 3:
            p.x++;
            break;
        case 2:
            p.y++;
            break;
        case 1:
            p.y--;
            break;
    }
    return p;
}
State move(State state,int move){
    //1 iz , 2 der , 3 abajo , 4 arriba
    State ret(state.p1,state.p2);
    ret.jumps = state.jumps +1;//No depende jumps
    
    switch(move){
        case 1:
            if(canMove(state.p1,move))
                ret.p1 = movept(state.p1,move);
            if(canMove(state.p2,2))
                ret.p2 = movept(state.p2,2);
            break;
        case 2:
            if(canMove(state.p1,move))
                ret.p1 = movept(state.p1,move);
            if(canMove(state.p2,1))
                ret.p2 = movept(state.p2,1);
            break;
        case 3:
            if(canMove(state.p1,move))
                ret.p1 = movept(state.p1,move);
            if(canMove(state.p2,move))
                ret.p2 = movept(state.p2,move);
            break;
        case 4:
            if(canMove(state.p1,move))
                ret.p1 = movept(state.p1,move);
            if(canMove(state.p2,move))
                ret.p2 = movept(state.p2,move);
            break;
    }
    return ret;
}
int main() {
    while(cin>>n>>m){
        //cout<<n<<"-------------------"<<m<<endl;
        memset(visited, 0, sizeof(visited));
        PT ping1 , ping2;
        int x , y;
        cin>>x>>y;
        x--;y--;
        heart = PT(x,y);
        
        cin>>x>>y;
        x--;y--;
        ping1 = PT(x,y);
        
        cin>>x>>y;
        x--;y--;
        ping2 = PT(x,y);
        
        FOR(i,n){
            FOR(j,m){
                cin>>mymap[i][j];
            }
        }
        
        State initState(ping1,ping2);
        
        queue<State> q;
        q.push(initState);
        //cout<<"heart ";heart.print();cout<<endl;
        bool love = false;
        while(!q.empty()){
            State state = q.front();
            
            q.pop();
            if(pingLove(state)){
                cout<<state.jumps<<endl;
                love = true;
                break;
            }
            if(!visited[state.p1.x][state.p1.y][state.p2.x][state.p2.y]){
                //state.print();
                visited[state.p1.x][state.p1.y][state.p2.x][state.p2.y] = true;
                for(int i = 1 ; i <= 4 ; ++i){
                    State s = move(state,i);
                    //s.print();
                    if(!visited[s.p1.x][s.p1.y][s.p2.x][s.p2.y])
                        q.push(s);
                }
                
                
            }
            
        }
        if(!love)cout<<"NO LOVE"<<endl;
    }
}
