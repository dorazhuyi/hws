#include <iostream>
#include <assert.h>
#include "stats.h"

using namespace std;
using namespace main_savitch_2C;

statistician::statistician()
{
	count = 0;
	total = 0;
}

void statistician::next(double r)
{
	if(length()==0) {
		tinyest = r;
		largest = r;
	}
	else {
		tinyest = tinyest > r ? r : tinyest;
		largest = largest < r ? r : largest;
	}
	++count;
	total += r;
}

void statistician::reset()
{
	count = 0;
	total = 0;
}

int statistician::length() const
{
	return count;
}

double statistician::sum() const
{
	return total;
}

double statistician::mean() const
{	
	assert(length() > 0);
	return total/count;
}

double statistician::minimum() const
{
	assert(length() > 0);
	return tinyest;
}

double statistician::maximum() const
{
	assert(length() > 0);
	return largest;
}

bool main_savitch_2C::operator ==(const statistician& s1, const statistician& s2)
{
	if(s1.length() == 0 && s2.length() ==0)
		return true;
	else if( s1.length() > 0 && s2.length() >0)
		return (s1.length() == s2.length()) && (s1.mean() == s2.mean()) 
			&& (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()) 
			&& (s1.sum() == s2.sum());
	else
		return false;
}
