//FILE: sequence1.cpp
//CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)
//INVARIANT for the sequence class:
//	1. The number of items in the sequence is in the member variable used.
//	2. For an empty sequence, we do not care what is stored in any of 
//     data; for a non-empty sequence, the items in the sequence are 
//     stored in data[0] through data[used-1], and we don't care what's in
//     the rest of data.
//  3. If there is a current item, than it lies in data[current_index]; if//	 there is no current item, then current_index equals used.

#include <algorithm>    // Provides copy function
#include <cassert>      // Provides assert function
#include "sequence1.h"

using namespace std;

namespace main_savitch_3
{
	// CONSTRUCTOR
	sequence::sequence()
	{
		used = 0;
	}

	// MODIFICATION MEMBER FUNCTIONS
	void sequence::start()
	{
		if(size()>0) 	
			current_index = 0;
	}

	void sequence::advance()
	{
		if(is_item()) {
			++current_index;
		}
	}

	void sequence::insert(const value_type& entry)
	{
		assert( size() < CAPACITY);
		if(is_item()) {
			++used;
			for(size_type i = used-1; i>current_index; --i) 
			{
				data[i] = data[i-1];
			}
			data[current_index] = entry;
		} else {
			++used;
			current_index = 0;
			for(size_type i = used-1; i>current_index; --i) 
			{
				data[i] = data[i-1];
			}
			data[current_index] = entry;
		}
	}

	void sequence::attach(const value_type& entry)
	{
		assert( size() < CAPACITY);
		if(is_item()) {
			++used;
			++current_index;
			for(size_type i = used-1; i>current_index; --i)
			{
				data[i] = data[i-1];
			}
			data[current_index] = entry;
		} else {
			++used;
			current_index = used - 1;
			data[current_index] = entry;
		}
	}

	void sequence::remove_current()
	{
		if( is_item() ) {
			for(size_type i = current_index; i<used-1; ++i) {
				data[i] = data[i+1];
			}
			--used;
		}
	}

	// CONSTANT MEMBER FUNCTIONS
	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const
	{
		return (current_index >=0 && current_index < used);
	}

	sequence::value_type sequence::current() const
	{
		if( is_item() ) 
			return data[current_index];
	}

}//end namespace
