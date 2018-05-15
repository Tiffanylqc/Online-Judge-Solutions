#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;
 
int main ()
{
    unsigned long long n;
 
    while ( cin >> n && n ) {
        set <unsigned long long> output;
 
        output.insert ((n * 10) / 9);
        set <unsigned long long> ::iterator it = output.begin();
 
        for ( unsigned long long i = (*it) - 10; i <= (*it) + 10; i++ ) {
            if ( i - i / 10 == n )
                output.insert (i);
        }
 
        bool space = false;
 
        for ( it = output.begin (); it != output.end (); it++ ) {
            if ( space )
                cout << " ";
            space = true;
            cout << *it;
        }
 
        cout << endl;
    }
 
    return 0;
}