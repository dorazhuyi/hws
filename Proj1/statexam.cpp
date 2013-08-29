// FILE: statexam.cxx
// Written by Michael Main (main@colorado.edu)
// This program calls five test functions to test the statisitician class.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>    // Provides memcpy function
#include "stats.h"
using namespace main_savitch_2C;
using namespace std;

bool close(double a, double b)
{
    const double EPSILON = 1e-5;
    return (fabs(a-b) < EPSILON);
}

int test1( )
{
    // Test program for basic statistician functions.
    // Returns 62 if everything goes okay; otherwise returns 0.

    statistician s, t;
    int i;
    double r = 0;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    for (i = 1; i <= 10000; i++)
    {
	s.next(i);
	r += i;
    };

    if (t.length( ) || t.sum( )) return 0;
    if (s.length( ) != 10000) return 0;
    if (!close(s.sum( ), r)) return 0;
    if (!close(s.mean( ), r/10000)) return 0;
    
    // Reset and then retest everything
    s.reset( );
    t.reset( );
    r = 0;
    
    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    for (i = 1; i <= 10000; i++)
    {
	s.next(i);
	r += i;
    };

    if (t.length( ) || t.sum( )) return 0;
    if (s.length( ) != 10000) return 0;
    if (!close(s.sum( ), r)) return 0;
    if (!close(s.mean( ), r/10000)) return 0;

    return 62;
}

int test2( )
{
    // Test program for minimum/maximum statistician functions.
    // Returns 7 if everything goes okay; otherwise returns 0.

    statistician s, t, u;
    double r = 1000;
    char n[15] = "10000000000000";

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    memcpy(&r, n, sizeof(double));
    r = 1/r;
    s.next(r);
    if ((s.minimum( ) != r) || (s.maximum( ) != r)) return 0;
    r *= -1;
    t.next(r);
    if ((t.minimum( ) != r) || (t.maximum( ) != r)) return 0;

    u.next(100); u.next(-1); u.next(101); u.next(3);
    if ((u.minimum( ) != -1) || (u.maximum( ) != 101)) return 0;

    return 7;
}

int test3( )
{
    // Test program for + operator of the statistician
    // Returns 7 if everything goes okay; otherwise returns 0.

    statistician s, t, u, v;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    t.next(5);
    u.next(0); u.next(10); u.next(10); u.next(20);

    v = s + s;
    if (v.length( ) || v.sum( )) return 0;
    v = s + u;
    if (!(u == v)) return 0;
    v = t + s;
    if (!(t == v)) return 0;
    v = t + u;
    if (v.length( ) != 5) return 0;
    if (!close(v.sum( ), 45)) return 0;
    if (v.minimum( ) != 0) return 0;
    if (v.maximum( ) != 20) return 0;
    if (!close(v.mean( ), 45.0/5)) return 0;
    v = v + t;
    if (v.length( ) != 6) return 0;
    if (!close(v.sum( ), 50)) return 0;
    if (v.minimum( ) != 0) return 0;
    if (v.maximum( ) != 20) return 0;
    if (!close(v.mean( ), 50.0/6)) return 0;
    return 7;
}

int test4( )
{
    // Test program for * operator of the statistician
    // Returns 7 if everything goes okay; otherwise returns 0.

    statistician s, t, u;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    u.next(0); u.next(10); u.next(10); u.next(20);

    s = 2*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), 80)) return 0;
    if (s.minimum( ) != 0) return 0;
    if (s.maximum( ) != 40) return 0;
    if (!close(s.mean( ), 80.0/4)) return 0;

    s = -2*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), -80)) return 0;
    if (s.minimum( ) != -40) return 0;
    if (s.maximum( ) != 0) return 0;
    if (!close(s.mean( ), -80.0/4)) return 0;

    s = 0*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), 0)) return 0;
    if (s.minimum( ) != 0) return 0;
    if (s.maximum( ) != 0) return 0;
    if (!close(s.mean( ), 0)) return 0;

    s = 10 * t;
    if (s.length( ) != 0) return 0;
    if (s.sum( ) != 0) return 0;

    return 7;
}

int test5( )
{
    // Test program for == operator of the statistician.
    // Returns 7 if everything goes okay; otherwise returns 0.

    statistician s, t, u, v, w, x;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    t.next(10);
    u.next(0); u.next(10); u.next(10); u.next(20);
    v.next(5); v.next(0); v.next(20); v.next(15);
    w.next(0);
    x.next(0); x.next(0);
    
    if (!(s == s)) return 0;
    if (s == t) return 0;
    if (t == s) return 0;
    if (u == t) return 0;
    if (!(u == v)) return 0;
    if (w == x) return 0;

    return 7;
}

int main( )
{
    int value = 0;
    int result;
    
    cerr << "Running statistician tests:" << endl;
 
    cerr << "TEST 1:" << endl;
    cerr << "Testing next, reset, length, sum, and mean (62 points).\n";
    result = test1( );
    value += result;
    if (result > 0) cerr << "Test 1 passed." << endl << endl;
    else cerr << "Test 1 failed." << endl << endl; 
 
    cerr << "\nTEST 2:" << endl;
    cerr << "Testing minimum and maximum member functions (7 points).\n";
    result = test2( );
    value += result;
    if (result > 0) cerr << "Test 2 passed." << endl << endl;
    else cerr << "Test 2 failed." << endl << endl; 
 
    cerr << "\nTEST 3:" << endl;
    cerr << "Testing the + operator (7 points).\n";
    result = test3( );
    value += result;
    if (result > 0) cerr << "Test 3 passed." << endl << endl;
    else cerr << "Test 3 failed." << endl << endl; 
 
    cerr << "\nTEST 4:" << endl;
    cerr << "Testing the * operator (7 points).\n";
    result = test4( );
    value += result;
    if (result > 0) cerr << "Test 4 passed." << endl << endl;
    else cerr << "Test 4 failed." << endl << endl; 

    cerr << "\nTEST 5:" << endl;
    cerr << "Testing the == operator (7 points).\n";
    result = test5( );
    value += result;
    if (result > 0) cerr << "Test 5 passed." << endl << endl;
    else cerr << "Test 5 failed." << endl << endl; 

    cerr << "If you submit the statistician now, this part of the\n";
    cerr << "grade will be " << value << " points out of 90.\n";
    cerr << "\nThe TA will give you another \n";
	cerr <<	"0 - 10 points by looking into your program.\n";
    return EXIT_SUCCESS;

}












