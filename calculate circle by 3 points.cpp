#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cassert>
using namespace std;

#define MAXVALUE 1000000
double INF = 1e100;
double EPS = 1e-12;

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (double c) const { return PT(x*c, y*c ); }
    PT operator / (double c) const { return PT(x/c, y/c ); }
};
PT RotateCW90(PT p) { return PT(p.y,-p.x); }
double dot(PT p, PT q) { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q) { return dot(p-q,p-q); }
double cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}
PT ComputeCircleCenter(PT a, PT b, PT c) {
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

int main()
{
    double x1,y1,x2,y2,x3,y3;
    while(cin>>x1){
        cin>>y1>>x2>>y2>>x3>>y3;
        PT point1=PT(x1,y1);
        PT point2=PT(x2,y2);
        PT point3=PT(x3,y3);
        PT center=ComputeCircleCenter(point1,point2,point3);

        double r=sqrt(dist2(center,point1));
        double circum=2*3.141592653589793*r;
        printf("%.2f\n",circum);
    }
}


