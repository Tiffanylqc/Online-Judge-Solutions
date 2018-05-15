#include <iostream>
#include <cmath>
using namespace std;
 
typedef long long ll;
 
ll gcde(ll a, ll b, ll& x, ll& y){
  if( b == 0 ){
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll gcd = gcde(b, a%b, x1, y1);
  x = y1;
  y = x1 - (a/b)*y1;
  return gcd;
}
 
int main(){
  ll n, n1, n2, c1, c2;
  while( cin >> n >> c1 >> n1 >> c2 >> n2 ){
    ll x, y;
    ll gcd = gcde(n1, n2, x, y);
    if( n % gcd != 0 ){
      cout << "failed\n";
    }else{
      ll t1 = (ll)ceil(-(double)x*n/n2);
      ll t2 = (ll)floor((double)y*n/n1);
      if( t2 < t1 )
	cout << "failed\n";
      else{
	ll cost1 = (n/gcd)*(c1*x+c2*y)+t1*(c1*n2-c2*n1)/gcd;
	ll cost2 = (n/gcd)*(c1*x+c2*y)+t2*(c1*n2-c2*n1)/gcd;
	ll t;
	if( cost1 < cost2 ) t = t1;
	else t = t2;
	ll k1 = (x*n + n2*t)/gcd;
	ll k2 = (y*n - n1*t)/gcd;
	cout << k1 << " " << k2 << "\n";
      }
    }
  }
  return 0;
}