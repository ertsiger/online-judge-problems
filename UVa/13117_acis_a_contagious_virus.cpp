/**
 * Author: toorx
 * 14/11/2016
 * Time: 0.000
 */
#include <iostream>
#include <math.h>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

int main (){

	cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);

	int N,x,y;


	while(cin>>N){
		PT points[N];
		double distances[N];
		double shortest_distance;
		cin>>x>>y;
		PT center = PT(x,y);

		for(int i = 0; i < N; i++){
			cin>>x>>y;
			points[i] = PT(x,y);
		}

		for(int i = 0; i < N; i++){
			if(i == N-1){
				distances[i] = DistancePointSegment(points[i], points[0], center);
			}else{
				distances[i] = DistancePointSegment(points[i], points[i+1], center);
			}

			//cout << i << ": " << distances[i] << endl;
		}

		for(int i = 0; i < N; i++){
			if(i == 0){
				shortest_distance = distances[i];
			}else{
				if(distances[i]<shortest_distance){
					shortest_distance = distances[i];
				}
			}
		}

		//cout << endl;
		
		cout << shortest_distance << endl;
	}



	return 0;
}
