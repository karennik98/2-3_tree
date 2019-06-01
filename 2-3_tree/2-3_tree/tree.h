#pragma once

#include "I_tree.h"

#include <memory>
#include <iterator>

template <typename T>
struct node
{
	// ........ pointer to parent ........ //
	std::unique_ptr<node<T>> parent;

	// ........ pointers to children ........ //
	std::unique_ptr<node<T>> left;    
	std::unique_ptr<node<T>> middle;  
	std::unique_ptr<node<T>> right;   

	// ........ node values ........ //
	T val1;
	T val2;

	// ........ values number ........ //
	size_t num;
};

template<typename T>
class tree : public I_tree<T>
{
public:
	using pointer_type = std::unique_ptr<node<T>>;
	using value_type   = T;
	using self_type    = tree;

private:
	template<typename T>
	class iterator : public std::iterator<std::forward_iterator_tag, 
							pointer_type,
							std::ptrdiff_t>
	{
	public:
		using itr_reference_type = iterator<T>&;
		using itr_value_type     = iterator<T>;
	public:
		itr_reference_type operator ++ ();
		itr_value_type operator++(int);

		value_type& operator*();
		value_type* operator->();
		const value_type* operator->() const;

		bool operator==(const itr_reference_type) const;
		bool operator!=(const itr_reference_type) const;
	private:
		pointer_type itr;
	}

public:
	void insert() = 0;
	void find() = 0;
	void erase() = 0;
	iterator begin();
	iterator end();
private:
	std::unique_ptr<node<T>> m_root;
};