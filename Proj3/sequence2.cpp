#include <algorithm>
#include <assert.h>
#include "sequence2.h"

namespace main_savitch_4
{
	// ctor
	sequence::sequence(size_type initial_capacity)
	{
		data = new value_type [initial_capacity];
		capacity = initial_capacity;
		used = 0;
	}

	// Copy ctor
	sequence::sequence(const sequence& source)
	{
		if(this != &source) {
			data = new value_type [source.capacity];
			std::copy(source.data, source.data+source.used, data);
			capacity = source.capacity;
			used = source.used;
			if(source.is_item())
				current_index = source.current_index;
		}
	}

	// dtor
	sequence::~sequence()
	{
		delete [] data;
	}

	// Modification member funcs
	void sequence::resize(size_type new_capacity)
	{
		if(new_capacity > used) {
			value_type *new_data = new value_type [new_capacity];
			std::copy(data, data+used, new_data);
			delete [] data;
			data = new_data;
			capacity = new_capacity;
		}
	}

	void sequence::start() 
	{
		if(size() > 0)
			current_index = 0;
	}

	void sequence::advance()
	{
		if(is_item())
			++current_index;
	}

	void sequence::insert(const value_type& entry)
	{
		if( size() == capacity ) 
			resize(capacity+DEFAULT_CAPACITY);
		if(!is_item()) current_index = 0;
		for(size_type i = used; i>current_index; --i)
			data[i] = data[i-1];
		data[current_index] = entry;
		++used;
	}

	void sequence::attach(const value_type& entry)
	{
		if( size() == capacity )
			resize(capacity+DEFAULT_CAPACITY);
		if(!is_item()) current_index = used-1;
		++current_index;
		for(size_type i = used; i>current_index;--i)
			data[i] = data[i-1];
		data[current_index] = entry;
		++used;
	}

	void sequence::remove_current()
	{
		if(is_item()) {
			for(size_type i=current_index; i<used-1;++i)
				data[i] = data[i+1];
			--used;
		}
	}

	// Const member funcs
	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const 
	{
		return (current_index >= 0 && current_index < used);
	}

	sequence::value_type sequence::current() const
	{
		if(is_item())
			return data[current_index];
	}

	// Operator overload
	void sequence::operator=(const sequence& source) 
	{
		if(this == &source) return;
		value_type *new_data = new value_type [source.capacity];
		std::copy(source.data, source.data+source.used, new_data);
		delete [] data;
		data = new_data;
		used = source.used;
		capacity = source.capacity;
		if(source.is_item())
			current_index = source.current_index;
		else
			current_index = used;

	}

	void sequence::operator +=(const sequence& source) 
	{
		if(capacity < used + source.used)
			resize(used+source.used);
		for(size_type i = used; i<used+source.used;++i)
			data[i] = source.data[i];
		used += source.used;
	}

	void sequence::operator +(const sequence& source)
	{
		*this+=source;
	}

	sequence::value_type sequence::operator[](sequence::size_type index) const
	{
		if(index < used)
			return data[index];
	}

}//end namespace
