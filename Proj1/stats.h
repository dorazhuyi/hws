// Provided by:   ____________(Yi Zhu)__________
// Email Address: ____________(zhuy13@mail.lcc.edu)________
// FILE: stats.h
// CLASS PROVIDED: statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC MODIFICATION member functions for the statistician class:
//   void next(double r)
//     The number r has been given to the statistician as the next number in
//     its sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.
//   
// PUBLIC CONSTANT member functions for the statistician class:
//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).
//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tinyest number in the
//     statistician's sequence.
//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.
//
// NON-MEMBER functions for the statistician class:
//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.
//   statistician operator *(double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: The return value is true if s1 and s2 have the zero
//     length. Also, if the length is greater than zero, then s1 and s2 must
//     have the same length, the same  mean, the same minimum, 
//     the same maximum, and the same sum.
//     
// VALUE SEMANTICS for the statistician class:
// Assignments and the copy constructor may be used with statistician objects.

#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>

namespace main_savitch_2C
{
    class statistician
    {
    public:
        // CONSTRUCTOR
        statistician( );
        // MODIFICATION MEMBER FUNCTIONS
        void next(double r);
        void reset( );
        // CONSTANT MEMBER FUNCTIONS
        int length( ) const;
        double sum( ) const;
        double mean( ) const;
        double minimum( ) const;
        double maximum( ) const;
        // FRIEND FUNCTIONS
        friend statistician operator +
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
        friend statistician operator *
            (double scale, const statistician & s)
		{
			statistician result;
			if(s.length() == 0)
				return s;
			result.count = s.count;
			result.total = scale * s.total;
			if(scale > 0){
				result.tinyest = scale * s.tinyest;
				result.largest = scale * s.largest;
			}
			else{
				result.largest = scale * s.tinyest;
				result.tinyest = scale * s.largest;
			}

			return result;
		}   
	private:
        int count;       // How many numbers in the sequence
        double total;    // The sum of all the numbers in the sequence
        double tinyest;  // The smallest number in the sequence
        double largest;  // The largest number in the sequence
    };// end of class

    // NON-MEMBER functions for the statistician class
    bool operator ==(const statistician& s1, const statistician& s2);
	
}//end of namespace

#endif

