#include <iostream>
#include <assert.h>
#include "stats.h"

using namespace std;

namespace main_savitch_2C
{
	//Member functions for class statistician
	statistician::statistician()//constructor
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

	//Friend functions for class statistician 
	statistician operator +
		(const statistician & s1, const statistician & s2)
	{
		statistician result;
		if(s1.length() == 0) 
			return s2;
		else if (s2.length() == 0)
			return s1;
		result.count = s1.count + s2.count;
		result.total = s1.total + s2.total;
		result.tinyest = s1.tinyest > s2.tinyest ? s2.tinyest : s1.tinyest;
		result.largest = s1.largest < s2.largest ? s2.largest : s1.largest;
		return result;
	}

	statistician operator *(double scale, const statistician & s)
	{
		statistician result;
		if(s.length() == 0)
			return s;
		result.count = s.count;
		result.total = scale * s.total;
		if(scale > 0){
			result.tinyest = scale * s.tinyest;
			result.largest = scale * s.largest;
		} else{
			result.largest = scale * s.tinyest;
			result.tinyest = scale * s.largest;
		}
		return result;
	}

	// Non-member function for the statiscian class
	bool operator ==(const statistician& s1, const statistician& s2)
	{
		if(s1.length() == 0 && s2.length() ==0)
			return true;
		else if( s1.length() > 0 && s2.length() >0)
			return (s1.length() == s2.length()) 
				&& (s1.mean() == s2.mean()) 
				&& (s1.minimum() == s2.minimum()) 
				&& (s1.maximum() == s2.maximum()) 
				&& (s1.sum() == s2.sum());
		else
			return false;
	}

}//end namespace
